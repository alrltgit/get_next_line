/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/17 11:31:16 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


char *free_line(char *line)
{
    int i;
    int j;
    char *temp_buff;
    char *new_line_sign;

    i = 0;
    j = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (!line[i])
    {
        free(line);
        return (NULL);
    }
    // new_line_sign = ft_strchr(line, '\n');
    temp_buff = malloc(sizeof(char) * i + 2);
    if (!temp_buff)
        return (NULL);
    while (line[i])
    {
        i++;
        temp_buff[j] = line[i];
        j++;
    }
    temp_buff[j] = '\0';
    free(line);
    return (temp_buff);
}

char *read_next_line(char *line)
{
    char *next_line;
    int i;

    if (!line[0])
        return (NULL);
    while (line[i] && line[i] != '\n')
        i++;
    next_line = malloc(sizeof(char) * (i + 2));
    i = 0;
    while (line[i] && line[i] != '\n')
    {
        next_line[i] = line[i];
        i++;
    }
    if (line[i] && line[i] == '\n')
        line[i++] = '\n';
    return (next_line);
}

char *read_first_line(int fd, char *line)
{
    char *buff;
    int nbytes;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buff == NULL)
        return (NULL);
    nbytes = 1;
    while (!(ft_strchr(line, '\n')) && nbytes > 0)
    {
        nbytes = read(fd, buff, BUFFER_SIZE);
        if (nbytes == -1)
        {
            free(line);
            free(buff);
            return (NULL);
        }
        line = ft_strjoin(line, buff);
        if (nbytes == 0)
            break ;
        if (!line)
            return (NULL);
        // printf("line: %s\n", line);
    }
    free(buff);
    return (line);
}

char *get_next_line(int fd)
{
    static char *line = "";
    char *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = read_first_line(fd, line);
    if (!line)
        return (NULL);
    next_line = read_next_line(line);
    line = free_line(line);
    return (next_line);
}

int main()
{
    char *s;
    // int fd = open("get_next_line.txt", O_RDONLY);
        // int fd = open("41_no_nl", O_RDONLY);
    // int fd = open("41_with_nl", O_RDONLY);
    // int fd = open("42_no_nl", O_RDONLY);
    int fd = open("42_with_nl", O_RDONLY);
    // int fd = open("43_no_nl", O_RDONLY);
    // int fd = open("43_with_nl", O_RDONLY);
    // int fd = open("alternate_line_nl_no_nl", O_RDONLY);
    // int fd = open("alternate_line_nl_with_nl", O_RDONLY);
    // int fd = open("big_line_no_nl", O_RDONLY);
    // int fd = open("big_line_with_nl", O_RDONLY);
    // int fd = open("multiple_line_no_nl", O_RDONLY);
    // int fd = open("multiple_line_with_nl", O_RDONLY);
    // int fd = open("multiple_nlx5", O_RDONLY);
    // int fd = open("nl", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    int n = 2;
    while (n > 0)
    {
        s = get_next_line(fd);
        printf("%s\n", s);
        // free(s);
        n--;
    }
    return (0);
}
