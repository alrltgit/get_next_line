/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/03/29 09:31:03 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	update_remains(char **remains, char *newline_sign)
{
	char	*temp;

	temp = ft_strdup(newline_sign + 1);
	free(*remains);
	if (*temp == '\0')
	{
		free(temp);
		*remains = NULL;
	}
	else
		*remains = temp;
}

char	*no_nl_case(char *line, char **remains)
{
	line = ft_strdup(*remains);
	free(*remains);
	*remains = NULL;
	return (line);
}

char	*extract_line(char **remains)
{
	char	*line;
	char	*fin_line;
	char	*newline_sign;
	int		line_len;

	if (!*remains)
		return (NULL);
	fin_line = NULL;
	newline_sign = ft_strchr(*remains, '\n');
	if (newline_sign)
	{
		line_len = newline_sign - *remains + 1;
		line = malloc(sizeof(char) * line_len + 1);
		if (!line)
			return (NULL);
		fin_line = line;
		line = ft_strcpy(*remains, line, line_len);
		*line = '\0';
		update_remains(remains, newline_sign);
	}
	else
		fin_line = no_nl_case(fin_line, remains);
	return (fin_line);
}

char	*read_buffer(int fd, char **remains, char *buffer)
{
	int	nbytes_read;

	nbytes_read = 1;
	while (nbytes_read > 0)
	{
		nbytes_read = read(fd, buffer, BUFFER_SIZE);
		if (nbytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (nbytes_read == 0)
			break ;
		buffer[nbytes_read] = '\0';
		*remains = ft_strjoin(*remains, buffer);
		if (!*remains)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (*remains);
}

char	*get_next_line(int fd)
{
	static char	*remains = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	remains = read_buffer(fd, &remains, buffer);
	line = extract_line(&remains);
	return (line);
}

// int	main()
// {
// 	char	*s;
// 	int		fd;

// 	fd = open("get_next_line.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((s = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", s);
// 		free(s);
// 	}
// 	close(fd);
// 	return (0);
// }
