/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:48:00 by evmouka           #+#    #+#             */
/*   Updated: 2024/02/01 16:42:03 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd)
{
	char	*buffer;
	char	*result;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	result = ft_strdup(buffer);
	free (buffer);
	return (result);
}

static char	*concat_strings(char *s1, char *s2)
{
	char	*result;

	if (!s2)
		return (ft_strdup(s1));
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*extract_line(char **content)
{
	ssize_t	i;
	char	*line;
	char	*new_content;

	line = NULL;
	i = 0;
	while ((*content)[i] != '\n' && (*content)[i] != '\0')
		i++;
	if ((*content)[i] == '\n')
		i++;
	line = ft_substr(*content, 0, i);
	if ((*content)[i] == '\0')
	{
		free(*content);
		*content = NULL;
	}
	else
	{
		new_content = ft_substr(*content, i, ft_strlen(*content));
		free(*content);
		*content = new_content;
	}
	return (line);
}

char	*read_and_concat(int fd, char **content)
{
	char		*read_result;

	read_result = read_file(fd);
	if (!read_result)
		return (NULL);
	*content = concat_strings(*content, read_result);
	free(read_result);
	return (*content);
}

char	*get_next_line(int fd)
{
	static char	*content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (content && ft_strchr(content, '\n'))
		return (extract_line(&content));
	if (!(read_and_concat(fd, &content)))
	{
		if (content)
			return (extract_line(&content));
		return (NULL);
	}
	while (content && !ft_strchr(content, '\n'))
	{
		if (!(read_and_concat(fd, &content)))
			break ;
	}
	if (!content || content[0] == '\0')
		return (NULL);
	return (extract_line(&content));
}
/*int main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 12)
	{
		line = get_next_line(fd);
//		line = get_next_line(0);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
*/