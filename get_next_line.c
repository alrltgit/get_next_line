/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/18 15:20:43 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_strjoin(char *line, char *buffer)
{
    char *ptr;
    int line_len;
    int buff_len;
    int i;
    int j;

    line_len = 0;
    if (line)
    {
        while (line[line_len])
            line_len++;
    }
    buff_len = 0;
    while (buffer[buff_len] && buffer[buff_len] != '\n')
        buff_len++;
    ptr = malloc(sizeof(char) * (line_len + buff_len) + 1);
    if (!ptr)
        return (NULL);
    i = 0;
    if (line)
    {
        while (line[i])
        {
            ptr[i] = line[i];
            i++;
        }
    }
    j = 0;
    while (buffer[j] && buffer[j] != '\n')
    {
        ptr[i + j] = buffer[j];
        j++;
    }
    ptr[i + j] = '\0';
    if (line)
        free(line);
    return (ptr);
}

char *read_line(int fd)
{
    char *buffer;
    char *line = NULL;
    int nbytes_read;
    int i;
    int j;

    buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
    if (!buffer)
        return (NULL);
    while (!(ft_strchr(buffer, '\n')) && nbytes_read > 0)
    {
        nbytes_read = read(fd, buffer, BUFFER_SIZE);
        if (nbytes_read < 0)
        {
            free(buffer);
            return (NULL);
        }
        else if (nbytes_read == 0)
        {
            free(buffer);
            break ;
        }
        buffer[nbytes_read] = '\0';
        i = 0;
        line = ft_strjoin(line, buffer);
        // printf("%s\n", line);
    }
    printf("%s", line);
    free(buffer);
    return (line);
}

char *get_next_line(int fd)
{
    static char *remains = NULL;
    char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_line(fd);
    if (!line)
        return (NULL);
    return(buffer);
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
    int n = 1;
    while (n > 0)
    {
        s = get_next_line(fd);
        // printf("%s\n", s);
        // free(s);
        n--;
    }
    return (0);
}
