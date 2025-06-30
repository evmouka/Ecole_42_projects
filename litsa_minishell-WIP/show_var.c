#include "minishell.h"

void	show_var(char *inut)
{
	char	*name;
	char	*value;

	name = inut + 8;
	while (*name == ' ')
		name++;
	value = getenv(name); // Get the value of the environment variable
	if (value)
		printf("%s=%s\n", name, value); // Print the name and value of the environment variable
	else
		printf("Error: %s not found\n", name); // If the environment variable does not exist, print an error message
}