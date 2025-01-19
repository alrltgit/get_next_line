/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/19 12:57:16 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *extract_line_remains(char **remains)
{
    char *line;
    char *newline_sign;
    char *temp;
    int line_len;
    int i;
    
    if (!*remains)
        return (NULL);
    newline_sign = ft_strchr(*remains, '\n');
    if (newline_sign)
    {
        line_len = newline_sign - *remains + 1;
        line = malloc(sizeof(char) * (line_len + 1));
        if (!line)
            return (NULL);
        i = 0;
        while (i < line_len)
        {
            line[i] = (*remains)[i];
            i++;
        }
        line[line_len] = '\0';
        temp = ft_strdup(newline_sign + 1);
        free(*remains);
        *remains = temp;
    }
    else
    {
        line = ft_strdup(*remains);
        free(*remains);
        *remains = NULL;
    }
    return (line);
}

char *read_buffer(int fd, char **remains)
{
    char *buffer;
    int nbytes_read;

    buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
    if (!buffer)
        return (NULL);
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
    return (extract_line_remains(remains));
}

char *get_next_line(int fd)
{
    static char *remains = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = read_buffer(fd, &remains);
    return (line);
}

// int main()
// {
//     char *s;
//     int fd = open("42_with_nl", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }
//     int n = 1;
//     while (n > 0)
//     {
//         s = get_next_line(fd);
//         printf("%s\n", s);
//         free(s);
//         n--;
//     }
//     close(fd);
//     return (0);
// }
