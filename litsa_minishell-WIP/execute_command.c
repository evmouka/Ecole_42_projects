#include "minishell.h"

void	execute_command(char *input)
{
	if (ft_strncmp(input, "echo", 4) == 0) // If the user types "echo", the program will print the input
		echo(input);
	else if (ft_strncmp(input, "pwd", 3) == 0) // If the user types "pwd", the program will print the current working directory
		pwd();
	else if (ft_strncmp(input, "cd", 2) == 0) // If the user types "cd", the program will change the current working directory
		cd(input);
	else if (ft_strncmp(input, "env", 3) == 0) // If the user types "env", the program will print the environment variables
		env();
	else if (ft_strncmp(input, "export", 6) == 0) // If the user types "export", the program will add a new environment variable
		export(input);
	else if (ft_strncmp(input, "show_var", 8) == 0) // If the user types "show_var", the program will show the value of an environment variable
		show_var(input);
	else if (ft_strncmp(input, "unset", 5) == 0) // If the user types "unset", the program will remove an environment variable
		unset(input);
	else if (ft_strncmp(input, "exit", 4) == 0) // If the user types "exit", the program will exit
		exit_shell(input);
	else if (ft_strncmp(input, "cat", 3) == 0) // If the user types "cat", the program will print the contents of a file
		cat(input);
	else
		printf("Command not found: %s\n", input); // If the user types anything else, the program will print an error message
}