#include "minishell.h"

void	env(void)
{
	extern char **environ; // Global variable that contains all environment variables
	int i;

	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/*
- extern char **environ is a standard global variable that contains all environment variables
- Each environment variable is stored as a string in the format "NAME=value"
- The array ends with a NULL pointer, so we can loop until we hit NULL
- We simply print each variable with a newline
*/