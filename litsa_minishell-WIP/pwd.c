#include "minishell.h"

void	pwd(void)
{
	char *path;

	path = getcwd(NULL, 0); // Get the current working directory
	if (path)
	{
		printf("%s\n", path);
		free(path);
	}
	else
		perror("pwd");
}
