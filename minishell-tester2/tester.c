#include "minishell_tester.h"
#include "test_cases.h"
#include "advanced_test_cases.h"

// Get output from bash for comparison
char *get_bash_output(char *command, int *exit_code) 
{
    int pipefd[2];
    char buffer[4096];
    char *output = malloc(1);
    output[0] = '\0';
    
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
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        dup2(pipefd[1], STDERR_FILENO);
        close(pipefd[1]);
        
        // Execute bash with command
        execl("/bin/bash", "bash", "-c", command, NULL);
        perror("execl");
        exit(1);
    }
    
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
    
    waitpid(pid, exit_code, 0);
    close(pipefd[0]);
    
    return output;
}

// Get output from minishell
char *get_minishell_output(char *command, int *exit_code) 
{
    int input_pipe[2];
    int output_pipe[2];
    
    if (pipe(input_pipe) == -1 || pipe(output_pipe) == -1) 
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
    {
        dup2(input_pipe[0], STDIN_FILENO);
        dup2(output_pipe[1], STDOUT_FILENO);
        dup2(output_pipe[1], STDERR_FILENO);
        close(input_pipe[1]);
        close(output_pipe[0]);
        
        execl("./minishell", "minishell", NULL);
        perror("execl");
        exit(1);
    }
    
    close(input_pipe[0]);
    close(output_pipe[1]);
    
    write(input_pipe[1], command, strlen(command));
    write(input_pipe[1], "\n", 1);
    write(input_pipe[1], "exit\n", 5);
    close(input_pipe[1]);
    
    char buffer[4096];
    char *output = malloc(1);
    output[0] = '\0';
    int total_size = 0;
    int bytes_read;
    
    while ((bytes_read = read(output_pipe[0], buffer, sizeof(buffer)-1)) > 0) 
    {
        buffer[bytes_read] = '\0';
        total_size += bytes_read;
        output = realloc(output, total_size + 1);
        strcat(output, buffer);
    }
    
    close(output_pipe[0]);
    waitpid(pid, exit_code, 0);
    
    return output;
}

int	run_test(t_test test) 
{
    printf("Testing: %s... ", test.name);
    
    // Get bash output first
    int bash_exit_code;
    char *bash_output = get_bash_output(test.command, &bash_exit_code);
    
    // Get minishell output
    int minishell_exit_code;
    char *minishell_output = get_minishell_output(test.command, &minishell_exit_code);
    
    if (!bash_output || !minishell_output) 
    {
        printf("%sFAILED%s (Could not execute commands)\n", RED, RESET);
        free(bash_output);
        free(minishell_output);
        return 0;
    }
    
    // Remove prompt from minishell output if present
    char *output_start = strstr(minishell_output, bash_output);
    int passed = output_start != NULL;
    
    if (!passed) 
    {
        printf("%sFAILED%s\n", RED, RESET);
        printf("Expected (bash):\n'%s'\n", bash_output);
        printf("Got (minishell):\n'%s'\n", minishell_output);
    }
    
    if (WEXITSTATUS(minishell_exit_code) != WEXITSTATUS(bash_exit_code)) 
    {
        passed = 0;
        printf("%sFAILED%s\n", RED, RESET);
        printf("Expected exit code: %d\n", WEXITSTATUS(bash_exit_code));
        printf("Got exit code: %d\n", WEXITSTATUS(minishell_exit_code));
    }
    
    if (passed) 
    {
        printf("%sPASSED%s\n", GREEN, RESET);
    }
    
    free(bash_output);
    free(minishell_output);
	return passed;
}

int main() 
{
    if (access("./minishell", X_OK) == -1) // Check if minishell executable exists x permission
    {
        printf("%sError: ./minishell executable not found!%s\n", RED, RESET);
        printf("Please make sure:\n");
        printf("1. You have compiled your minishell\n");
        printf("2. The minishell executable is in the current directory\n");
        printf("3. The executable has proper permissions\n");
        return 1;
    }

    printf("Starting Minishell Tests\n\n");
    
    size_t	passed = 0;
	size_t	total_tests = NUM_TESTS + NUM_ADVANCED_TESTS;
    for (size_t i = 0; i < NUM_TESTS; i++) 
    {
        // run_test(g_tests[i]);
		if (run_test(g_tests[i]) == 1)
			passed++;
    }

    for (size_t i = 0; i < NUM_ADVANCED_TESTS; i++) 
    {
        // run_test(g_advanced_tests[i]);
		if (run_test(g_advanced_tests[i]) == 1)
        	passed++;
    }
    printf("\nTest Summary: %zu/%zu tests completed\n", passed, total_tests);
    return (passed == total_tests) ? 0 : 1; // Return 0 if all tests passed, 1 otherwise
}