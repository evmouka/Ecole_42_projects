#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

typedef struct s_test 
{
    char *name;
    char *command;
    char *expected_output;
    int expected_exit_code;
} 				t_test;

// Utility function to execute command and capture output
char *execute_command(char *command, int *exit_code) 
{
    int pipefd[2]; // 0 is read end, 1 is write end
    char buffer[4096]; // Buffer for reading from pipe
    char *output = malloc(1); // Output string to return to caller (will be reallocated), malloc(1) to ensure it's not NULL
    output[0] = '\0'; // Initialize to empty string
    
    if (pipe(pipefd) == -1) 
	{
        perror("pipe");
        return NULL;
    }
    
    pid_t pid = fork();
    if (pid == -1) 
	{
        perror("fork");
        return NULL;
    }
    
    if (pid == 0) 
	{  // Child process
        close(pipefd[0]); // Close read end of pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to write end of pipe
        close(pipefd[1]); // Close write end of pipe
        
        execl("./minishell", "minishell", "-c", command, NULL);
        exit(1);
    } 
	else 
	{  // Parent process
        close(pipefd[1]);
        int total_size = 0;
        int bytes_read;
        
        while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer)-1)) > 0) 
		{
            buffer[bytes_read] = '\0';
            total_size += bytes_read;
            output = realloc(output, total_size + 1);
            strcat(output, buffer);
        }
        
        waitpid(pid, exit_code, 0); // Wait for child process to finish
        close(pipefd[0]);
    }
    
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
    
    int passed = 1; // Assume test passes until proven otherwise
    if (strcmp(output, test.expected_output) != 0) 
	{
        passed = 0; // If output doesn't match, test failed
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
    
    if (passed) // If both output and exit code match, passed = 1
	{
        printf("%sPASSED%s\n", GREEN, RESET);
    }
    
    free(output);
}

int main() 
{
    printf("Starting Minishell Tests\n\n");
    
    // Basic command tests
    t_test tests[] = {
        {
            "Echo Test",
            "echo Hello World",
            "Hello World\n",
            0
        },
        {
            "PWD Test",
            "pwd",
            "/Users/litsa/Library/Mobile Documents/com~apple~CloudDocs/Documents/IT/C/42 common core/minishell/mini-shell/minishell-tester2\n",  // This will need to be adjusted
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
    
    int num_tests = sizeof(tests) / sizeof(t_test); // Calculate number of tests
    for (int i = 0; i < num_tests; i++) 
	{
        run_test(tests[i]);
    }
    
    return 0;
}