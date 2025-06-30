#include "minishell.h"

int	main(int argc, char **argv) 
{
  char *input; // to store the user input

  (void) argc;
  (void) argv;
  while (1) // Infinite loop to keep the shell running
  {
	input = readline("minishell->$ "); // Prompt the user for input
	if (!input) // If the user presses Ctrl+D, the program will exit
	  break;
	if (input[0] != '\0') // If the user presses Enter without typing anything, the program will not add an empty line to the history
	{	
		add_history(input); // Add the input to the history
		if (ft_strchr(input, '>'))
		{
			if (ft_strnstr(input, ">>", ft_strlen(input)))
				redirect_output_append(input);
			else
				redirect_output(input);
		}
		else if(ft_strchr(input, '<'))
		{
			if (ft_strnstr(input, "<<", ft_strlen(input)))
				redirect_input_heredoc(input);
			else
				redirect_input(input);
		}
		else
			execute_command(input); // Execute the command
	}
	free(input);
  }
  return 0;
}