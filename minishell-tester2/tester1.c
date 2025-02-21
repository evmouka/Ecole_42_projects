#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

typedef struct s_test {
    char *name;
    char *command;
    char *expected_output;
    int expected_exit_code;
}				t_test;

// Execute command by sending it through a pipe
char *execute_command(char *command, int *exit_code) 
{
    int input_pipe[2];   // For sending commands to minishell
    int output_pipe[2];  // For receiving output from minishell
    
    // Create pipes
    if (pipe(input_pipe) == -1 || pipe(output_pipe) == -1) 
	{
        perror("pipe");
        return NULL;
    }
    
    pid_t pid = fork(); // Fork a child process
    if (pid == -1) 
	{
        perror("fork");
        return NULL;
    }
    
    if (pid == 0) 
	{  // Child process for running minishell
        // Redirect stdin to our input pipe
        dup2(input_pipe[0], STDIN_FILENO); // Redirect stdin to read end of pipe
        // Redirect stdout/stderr to our output pipe
        dup2(output_pipe[1], STDOUT_FILENO); // Redirect stdout to write end of pipe
        dup2(output_pipe[1], STDERR_FILENO); // Redirect stderr to write end of pipe
        
        // Close unused pipe ends
        close(input_pipe[1]);
        close(output_pipe[0]);
        
        // Execute minishell
        execl("./minishell", "minishell", NULL); // Execute minishell with no arguments (interactive mode)
        perror("execl"); // This line should never be reached
        exit(1); // Exit with error
    }
    // Parent process for sending command and receiving output
    
    // Close unused pipe ends in parent process (we are only using the input_pipe to send commands and the output_pipe to receive output)
    close(input_pipe[0]);
    close(output_pipe[1]);
    
    // Write command to minishell
    write(input_pipe[1], command, strlen(command));
    write(input_pipe[1], "\n", 1);  // Send newline
    write(input_pipe[1], "exit\n", 5);  // Send exit command
    close(input_pipe[1]);  // Close pipe to signal EOF
    
    // Read output
    char buffer[4096]; // Buffer for reading from pipe
    char *output = malloc(1); // Output string to return to caller (will be reallocated)
    output[0] = '\0';
    int total_size = 0;
    int bytes_read;

    while ((bytes_read = read(output_pipe[0], buffer, sizeof(buffer)-1)) > 0) // Read from output pipe until EOF
	{
        buffer[bytes_read] = '\0'; 
        total_size += bytes_read; // Keep track of total size
        output = realloc(output, total_size + 1); // Reallocate output buffer because we are appending to it
        strcat(output, buffer); // Append buffer to output string so that we can return it
    }
    
    close(output_pipe[0]); 
    
    // Wait for minishell to exit
    waitpid(pid, exit_code, 0);
    
    return output;
}

void run_test(t_test test)
{
    printf("Testing: %s... ", test.name);
    
    int exit_code;
    char *output = execute_command(test.command, &exit_code);
    
    if (output == NULL) 
	{
        printf("%sTest failed: Could not execute command%s\n", RED, RESET);
        return;
    }
    
    int passed = 1;
    // Remove the prompt from output if present
    char *output_start = strstr(output, test.expected_output); // Find the expected output in the actual output
    if (!output_start) 
	{
        passed = 0;
        printf("%sFAILED%s\n", RED, RESET);
        printf("Expected output: '%s'\n", test.expected_output);
        printf("Actual output: '%s'\n", output);
    }
    
    if (WEXITSTATUS(exit_code) != test.expected_exit_code) 
	{
        passed = 0;
        printf("%sFAILED%s\n", RED, RESET);
        printf("Expected exit code: %d\n", test.expected_exit_code);
        printf("Actual exit code: %d\n", WEXITSTATUS(exit_code));
    }
    
    if (passed) 
	{
        printf("%sPASSED%s\n", GREEN, RESET);
    }
    
    free(output);
}

int main() {
    // Check if minishell executable exists
    if (access("./minishell", X_OK) == -1) // access() is used to check if the file exists and is executable, X_OK is a flag to check for execute permission
	{
        printf("%sError: ./minishell executable not found!%s\n", RED, RESET);
        printf("Please make sure:\n");
        printf("1. You have compiled your minishell\n");
        printf("2. The minishell executable is in the current directory\n");
        printf("3. The executable has proper permissions\n");
        return 1;
    }

    printf("Starting Minishell Tests\n\n");
    
    // Basic command tests
    t_test tests[] = 
	{
        {
            "Echo Test",
            "echo Hello World",
            "Hello World\n",
            0
        },
        {
            "PWD Test",
            "pwd",
            "/Users/litsa/Library/Mobile Documents/com~apple~CloudDocs/Documents/IT/C/42 common core/minishell/mini-shell/minishell-tester2\n",  // Will need to be adjusted
            0
        },
        {
            "Simple Pipe Test",
            "echo hello | cat",
            "hello\n",
            0
        }
        // Add more tests
    };
    
    int num_tests = sizeof(tests) / sizeof(t_test);
    for (int i = 0; i < num_tests; i++) {
        run_test(tests[i]);
    }
    
    return 0;
}