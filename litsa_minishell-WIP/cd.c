#include "minishell.h"

void    cd(char *input)
{
    char	*path;
    char	*home;

	path = input + 2; // Skip past "cd"
	while (*path == ' ' || *path == '\t') // Skip past any spaces or tabs
		path++;
	if (*path == '\0') // If the user types "cd" without any arguments, the program will change the current working directory to the home directory
	{
		home = getenv("HOME");
		if (!home)
		{
			if (chdir(home) == -1)
			{
				perror("cd: home not set\n");
				return;
			}
		}
		if (chdir(home) == -1) // Change the current working directory to the home directory
			perror("cd");
		return;
	}
	if (chdir(path) == -1) // Change the current working directory to the path specified by the user
		perror("cd");
}