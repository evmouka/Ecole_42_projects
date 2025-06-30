#include "minishell.h"

void	unset(char *input)
{
	char	*arg;
	char	*var_start;

	arg = input + 5;
	while (*arg == ' ') // Skip spaces
		arg++;
	if (!*arg)
		return ;
	var_start = arg; // Save the start of the variable name
	while (*arg)
	{
		while (*arg && *arg != ' ')
			arg++;
		if (*arg)
			*arg++ = '\0'; // Null-terminate the variable name
		if (!ft_isalpha(*var_start) && *var_start != '_') //validating the variable name
			printf("minishell: unset: '%s': not a valid identifier\n", var_start);
		else if (ft_strchr(var_start, '=')) //just the variable name without the value
			printf("minishell: unset: '%s': not a valid identifier\n", var_start);
		else if (unsetenv(var_start) == -1)
			perror("unset");
		while (*arg == ' ') // Skip spaces
			arg++;
		var_start = arg; // Save the start of the next variable name
	}
}
