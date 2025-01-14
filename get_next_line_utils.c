/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:58 by apple             #+#    #+#             */
/*   Updated: 2025/01/14 16:31:21 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_strjoin(char *line, char *buff)
{
    int i;
    int j;

    i = 0;
    while (line[i])
        i++;
    j = 0;
    while (buff[j])
    {
        line[i + j] = buff[j];
        j++;
    }
    line[i + j] = '\0';
    return (line);
}

char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *read_fd(int fd)
{
    int nbytes;
    char *buff;
    static char *line = NULL;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buff == NULL)
        return (NULL);
    nbytes = read(fd, buff, BUFFER_SIZE);
    if (nbytes <= 0)
        return (free(buff), NULL);
    buff[nbytes] = '\0';
    if (line == NULL)
    {
        line = malloc(sizeof(char) * (nbytes + 1));
        if (line == NULL)
            return (free(line), NULL);
        line = ft_strcpy(line, buff);
    }
    else
        line = ft_strjoin(line, buff);
    free(buff);
    return (line);
}