#include "minishell.h"

int	is_valid_var_name(char *var)
{
	if (!var || !*var) // If the variable name is empty, return 0
		return (0); 
	if (!ft_isalpha(*var) && *var != '_') // If the first character is not a letter or an underscore, 
		return (0);
	var++;
	while (*var && *var != '=')
	{
		if (!ft_isalnum(*var) && *var != '_') // If the character is not a letter, a number, or an underscore, return 0
			return (0);
		var++;
	}
	return (1);
}

void	export(char *input)
{
	char	*arg;
	char	*var_start;
	char	*var_copy;

	arg = input + 6;
	while (*arg == ' ') // Skip spaces
		arg++;
	if (!*arg) // If there is no argument, print the environment variables
	{
		env();
		return ;
	}
	var_start = arg; // Save the start of the variable name
	while (*arg) // Find the end of the variable name
	{
		while (*arg && *arg != ' ')
			arg++;
		if (*arg) //
		*arg++ = '\0'; // Null-terminate the variable name
		if (!is_valid_var_name(var_start))
			printf("minishell: export: '%s': not a valid identifier\n", var_start);
		else
		{
			var_copy = ft_strdup(var_start); // Copy the variable name
			if (!var_copy)
				printf("Error: malloc failed\n");
			else if (putenv(var_copy) == -1)
			{
				printf("Error: putenv failed\n");
				free(var_copy);
			}
		}
		while (*arg == ' ') // Skip spaces
			arg++;
		var_start = arg; // Save the start of the next variable name
	}
}