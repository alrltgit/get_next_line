/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/19 21:51:14 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *extract_line_remains(char **remains) // 01234567890123456$12345678$012 // 12345678$01234567890123456
{
    char *line;
    char *newline_sign;
    char *temp;
    int line_len;
    int i;
    
    if (!*remains)
        return (NULL);
    newline_sign = ft_strchr(*remains, '\n'); // $12345678$012 // 12345678$
    // printf("newline_sign: %s\n", newline_sign);
    if (newline_sign)
    {
        line_len = newline_sign - *remains + 1; // $ - 0 == 17 + 1 = 18 // 9
        // printf("line_len: %d\n", line_len);
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
        temp = ft_strdup(newline_sign + 1); // 12345678$012 // 01234567890123456
        // printf("temp: %s\n", temp);
        free(*remains);
        if (*temp == '\0')
        {
            free(temp);
            *remains = NULL;
        }
        else
        {
            *remains = temp;
        } // 12345678$012 // 01234567890123456
    }
    else
    {
        line = ft_strdup(*remains);
        free(*remains);
        *remains = NULL;
    }
    return (line); // 12345678$ // 01234567890123456
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
        nbytes_read = read(fd, buffer, BUFFER_SIZE); // 012345678901234 (15) // 56$12345678$012(15) // 34567890123456 (14)
        // printf("nbytes_read: %d\n", nbytes_read);
        if (nbytes_read < 0)
        {
            free(buffer);
            return (NULL);
        }
        if (nbytes_read == 0)
            break ;
        buffer[nbytes_read] = '\0';
        *remains = ft_strjoin(*remains, buffer); // 012345678901234 // 01234567890123456$12345678$012 // 12345678$01234567890123456
        // printf("remains ft_strjoin: %s\n", *remains);
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

int main()
{
    char *s;
    int fd = open("42_with_nl", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    int n = 3;
    while (n > 0)
    {
        s = get_next_line(fd);
        printf("%s", s);
        free(s);
        n--;
    }
    close(fd);
    return (0);
}
