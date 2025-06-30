#include "minishell.h"

void	cat(char *input)
{
	int		fd;
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
	{
		perror("malloc");
		return ;
	}
	input = input + 3; // Skip past "cat"
	while (*input == ' ' || *input == '\t') // Skip past any spaces or tabs
		input++;
	if (*input == '\0') // If the user types "cat" without any arguments, 
		fd = STDIN_FILENO; // the program will read from standard input i.e. the keyboard
	else
	{
		fd = open(input, O_RDONLY); // Open the file in read-only mode
		if (fd == -1) // If the file does not exist, print an error message
		{
			perror("open");
			free(buffer);
			return ;
		}
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) // Read the file in chunks of BUFFER_SIZE
	{
		buffer[bytes_read] = '\0'; // Null-terminate the buffer
		printf("%s", buffer); // Print the contents of the file
	}
	if (fd != 0) // If the file is not standard input, close the file
		close(fd); // Close the file
	free(buffer);
}