/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:58 by apple             #+#    #+#             */
/*   Updated: 2025/01/12 18:41:39 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ;
		s++;
	}
	if (*s == (char)c)
		return ;
}

char *read_fd(int fd)
{
    int nbytes;
    char *buff;
    // static int count = 0;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buff == NULL)
        return (NULL);
    nbytes = read(fd, buff, BUFFER_SIZE);
    ft_strchr(buff, '\n');
    if (nbytes <= 0)
    {
        free(buff);
        return (NULL);
    }
    buff[nbytes] = '\0';
    // if (nbytes)
    //     count++;
    return (buff);
}