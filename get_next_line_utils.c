/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:58 by apple             #+#    #+#             */
/*   Updated: 2025/01/15 15:44:15 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// char *ft_strjoin(char *line, char *buff)
// {
//     int i;
//     int j;

//     i = 0;
//     while (line[i])
//         i++;
//     j = 0;
//     while (buff[j])
//     {
//         line[i + j] = buff[j];
//         j++;
//     }
//     line[i + j] = '\0';
//     return (line);
// }

// char *ft_strcpy(char *dst, char *src)
// {
//     int i;

//     i = 0;
// 	while (src[i])
// 	{
//         dst[i] = src[i];
// 		i++;
// 	}
//     dst[i] = '\0';
//     return(dst);
// }

char	*ft_strdup(char *s1)
{
	static char *line;
	char	*p;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	p = line;
	i = 0;
	while (s1[i])
	{
		*p = s1[i];
		p++;
		i++;
	}
	*p = '\0';
	return (line);
}

char *read_fd(int fd)
{
    int nbytes;
    int i;
    char *buff;
    char *line;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buff == NULL)
        return (NULL);
    nbytes = read(fd, buff, BUFFER_SIZE);
    if (nbytes <= 0)
        return (free(buff), NULL);
    line = malloc(sizeof(char) * (nbytes + 1));
    if (line == NULL)
            return (free(line), NULL);
    i = 0;
    if (buff[nbytes] != '\n')
    {
        line = ft_strdup(buff);
        return ("false");
    }
    free(buff);
    return ("true");
}
