/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:58 by apple             #+#    #+#             */
/*   Updated: 2025/01/19 00:13:06 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

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
    while (buffer[buff_len])
        buff_len++;
    ptr = malloc(sizeof(char) * (line_len + buff_len) + 1);
    if (!ptr)
        return (NULL);
    i = 0;
    if (line)
    {
        while (i < line_len)
        {
            ptr[i] = line[i];
            i++;
        }
        // free(line);
    }
    j = 0;
    while (j < buff_len)
    {
        ptr[i] = buffer[j];
        j++;
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}
