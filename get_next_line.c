/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/16 10:08:09 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *read_next_line(char *line)
{
    char *current_line;
    char *new_line;
    char *temp_buff;
    int line_len;

    new_line = ft_strchr(line, '\n');
    if (new_line)
    {
        line_len = new_line - line;
        current_line = ft_strndup(line, line_len);
        temp_buff = ft_strdup(new_line + 1);
        free(line);
        line = temp_buff;
    }
    else
    {
        current_line = ft_strdup(line);
        free(line);
        line = NULL;
    }
    return (current_line);
}

char *read_first_line(int fd, char *line)
{
    char *buff;
    int nbytes;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buff == NULL)
        return (NULL);
    while (!ft_strchr(line, '\n') && nbytes > 0)
    {
        nbytes = read(fd, buff, BUFFER_SIZE);
        if (nbytes == -1)
        {
            free(line);
            free(buff);
            return (NULL);
        }
        buff[nbytes] = '\0';
        line = ft_strjoin(line, buff);
        if (!line)
            return (NULL);
    }
    free(buff);
    return (line);
}

char *get_next_line(int fd)
{
    static char *line;
    char *next_line;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
    line = read_first_line(fd, line);
    if (!line)
        return (NULL);
    next_line = read_next_line(line);
    return (next_line);
}

int main()
{
    char *s;
    // int fd = open("get_next_line.txt", O_RDONLY);
        // int fd = open("41_no_nl", O_RDONLY);
    // int fd = open("41_with_nl", O_RDONLY);
    int fd = open("42_no_nl", O_RDONLY);
    // int fd = open("42_with_nl", O_RDONLY);
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
        n--;
    }
    // free(s);
    return (0);
}
