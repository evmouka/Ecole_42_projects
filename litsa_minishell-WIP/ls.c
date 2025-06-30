#include "minishell.h"

int execute_ls(char **args)
{
    pid_t pid;
    int status;
    char *ls_path = "/bin/ls";  // Full path to ls command

    pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        return (1);
    }
    if (pid == 0)  // Child process
    {
        if (execve(ls_path, args, NULL) == -1)
        {
            perror("execve failed");
            exit(1);
        }
    }
    else  // Parent process
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid failed");
            return (1);
        }
    }
    return (0);
}