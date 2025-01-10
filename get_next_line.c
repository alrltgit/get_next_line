/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/11 00:53:00 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    size_t nbytes;
    char *buf;
    
    fd = open("get_next_line.txt", O_RDONLY);
    if (fd == -1)
        return (NULL);
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    
    // nbytes = read(fd, buf, BUFFER_SIZE);
    return (buf);
}

int main(int argc, char *argv[])
{
    int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
    char *s = "111111111111111111\n111111111111111111\n111111111111111111\n111111111111111111";
    while(*s)
    {
        write(fd, s, 1);
        s++;
    }
    close(fd);
    get_next_line(fd);
    return (0);
}