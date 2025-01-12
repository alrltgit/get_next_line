/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/12 17:59:02 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    char *rslt;
    
    if (fd == -1)
        return (NULL);
    else
        rslt = read_fd(fd);
    return (rslt);
}

int main()
{
    int fd = open("get_next_line.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    int n = 3;
    while (n > 0)
    {
        char *s = get_next_line(fd);
        printf("%s\n", s);
        n--;
    }
    return (0);
}
