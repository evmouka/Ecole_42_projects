#include "minishell.h"

void	exit_shell(char *input)
{
	free(input);
	exit(0);
}