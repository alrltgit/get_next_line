/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/18 17:54:56 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_strdup(char *str)
{
    char *ptr;
    int i;

    i = 0;
    if (str)
    {
        while (str[i])
            i++;
    }
    ptr = malloc(sizeof(char) * i + 1);
    if (!ptr)
        return (NULL);
    i = 0;
    if (str)
    {
        while (str[i])
        {
            ptr[i] = str[i];
            i++;
        }
        ptr[i] = '\0';
    }
    return (ptr);
}

char *extract_line(char *remains)
{
    char *line;
    char *temp;
    char *newline_sign;
    int line_len;
    int i;
    
    if (!remains)
        return (NULL);
    newline_sign = ft_strchr(remains, '\n');
    if (newline_sign)
    {
        line_len = newline_sign - remains + 1;
        line = malloc(sizeof(char) * (line_len + 1));
        if (!line)
            return (NULL);
        i = 0;
        while (i < line_len)
        {
            line[i] = remains[i];
            i++;
        }
        line[line_len] = '\0';
        printf("line: %s\n", line);
        temp = ft_strdup(newline_sign + 1);
        printf("temp: %s\n", temp);
        free(remains);
        remains = temp;
    }
    else
    {
        // printf("in else\n");
        line = ft_strdup(remains);
        free(remains);
        remains = NULL;
    }
    return (line);
}

char *read_line(int fd, char *remains)
{
    char *buffer;
    int nbytes_read;
    int i;
    int j;

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
        else if (nbytes_read == 0)
            break ;
        buffer[nbytes_read] = '\0';
        remains = ft_strjoin(remains, buffer);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(buffer);
    // printf("%s", remains);
    return (extract_line(remains));
}

char *get_next_line(int fd)
{
    static char *remains = NULL;
    char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_line(fd, remains);
    if (!buffer)
        return (NULL);
    return(buffer);
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
    // int n = 2;
    while (s = get_next_line(fd))
    {
        // s = get_next_line(fd);
        printf("%s\n", s);
        free(s);
        // n--;
    }
    close(fd);
    return (0);
}
