#include "minishell.h"

void	redirect_output(char *input)
{
	int		fd;
	char	*file_name;
	char	*end;
	int		stdout_original;
	char	*rest = NULL;

	stdout_original = dup(STDOUT_FILENO); // Save the standard output file descriptor
	file_name = ft_strchr(input, '>'); // Find the first occurrence of '>'
	if (!file_name)
		return ;
	*file_name++ = '\0'; // Null-terminate the command at the position of '>' and move the pointer to the next character
	while (*file_name == ' ' || *file_name == '\t') // Skip spaces
		file_name++;
	end = file_name;
	while (*end && *end != ' ' && *end != '\t' && *end != '\0') // Find the end of the file name
		end++;
	// *end = '\0'; // Null-terminate the file name and move the pointer to the next character
    if (*end) // If there is any content after the file name
    {
        rest = ft_strdup(end + 1); // Copy the rest of the content
        *end = '\0'; // Null-terminate the file name
    }
// Open the file in write-only mode, create it if it does not exist, if it exists clear its contents
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644); // 0644 is the file permissions (rw-r--r--)
	if (fd == -1)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return ;
	}
// Redirect standard output to the file
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close(fd);
		return ;
	}
	close(fd);
	if (rest) // If there is any content after the file name
    {
        strcat(input, " "); // Add a space
        strcat(input, rest); // Add the rest of the content
        free(rest);
    }
	execute_command(input); // Execute the command
	dup2(stdout_original, STDOUT_FILENO); // Restore the standard output
	close(stdout_original);
}

void	redirect_input(char *input)
{
	char	*file_name;
	int	fd;
	int	stdin_original;

	stdin_original = dup(STDIN_FILENO); // Save the standard input file descriptor
	file_name = ft_strchr(input, '<'); // Find the first occurrence of '<'
	if (!file_name)
		return ;
	*file_name++ = '\0'; // Null-terminate the command at the position of '<' and move the pointer to the next character
	while (*file_name == ' ') // Skip spaces
		file_name++;
// Open the file in read-only mode
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return ;
	}
	// Redirect standard input to the file
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(fd);
		return ;
	}
	close(fd);
	execute_command(input); // Execute the command
	dup2(stdin_original, STDIN_FILENO); // Restore the standard input
	close(stdin_original);
}

void	redirect_output_append(char *input)
{
	int		fd;
	int		stdout_original;
	char	*file_name;
	char	*end;
	char	*rest = NULL;

	stdout_original = dup(STDOUT_FILENO); // Save the standard output file descriptor (1) to restore it later
	file_name = ft_strchr(input, '>'); // Find the first occurrence of '>'
	if (!file_name || *(file_name + 1) != '>')
		return ;
	*file_name++ = '\0'; // Null-terminate the command at the position of '>' and move the pointer to the next character
	file_name ++; // Skip past the second '>'
	while (*file_name == ' ' || *file_name == '\t') // Skip spaces
		file_name++;
	end = file_name;
	while (*end && *end != ' ' && *end != '\t' && *end != '\0') // Find the end of the file name
		end++;
	if (*end)
    {
        rest = ft_strdup(end + 1);
        *end = '\0';
    }

	// Open the file in write-only mode, create it if it does not exist, append to it if it exists
	fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644); // Open tthe file, if it exists append to it
	if (fd == -1)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return ;
	}
	if (dup2(fd, STDOUT_FILENO) == -1) // Redirect standard output to the file
	{
		perror("dup2");
		close(fd);
		return ;
	}
	close(fd);
	if (rest)
    {
        strcat(input, " ");
        strcat(input, rest);
        free(rest);
    }
	execute_command(input); // Execute the command
	dup2(stdout_original, STDOUT_FILENO); // Restore the standard output
	close(stdout_original);
}

void	redirect_input_heredoc(char *input)
{
	char	*delimeter;
	int		fd;
	int		stdin_original;
	char	*line;

	stdin_original = dup(STDIN_FILENO); // Save the standard input file descriptor
	delimeter = ft_strchr(input, '<'); // Find the first occurrence of '<'
	if (!delimeter || *(delimeter + 1) != '<')
		return ;
	*delimeter++ = '\0'; // Null-terminate the command at the position of '<' and move the pointer to the next character
	delimeter += 2; // Skip past the second '<'
	while (*delimeter == ' ') // Skip spaces
		delimeter++;
	fd = open(".delimeter_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644); // Open a temporary file to store the delimeter
	if (fd == -1)
	{
		perror("heredoc");
		return ;
	}
	// read lines untl the delimeter is found
	while (1)
	{
		line = readline("> "); // Prompt the user for input
		if (!line || ft_strncmp(line, delimeter, ft_strlen(delimeter)) == 0) // If the user presses Ctrl+D or types the delimeter, break the loop
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line)); // Write the line to the temporary file
		write(fd, "\n", 1); // Write a newline character
		free(line);
	}
	if (dup2(fd, STDIN_FILENO) == -1) // Redirect standard input to the file
	{
		perror("dup2");
		close(fd);
		return ;
	}
	close(fd);
	execute_command(input); // Execute the command
	dup2(stdin_original, STDIN_FILENO); // Restore the standard input
	close(stdin_original);
}