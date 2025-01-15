/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/15 22:42:23 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    char *buff;
    static char *line;
    int nbytes;

    if (fd == -1 || BUFFER_SIZE < 1)
        return (NULL);
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buff == NULL)
        return (NULL);
    while (!ft_strchr(line, '\n'))
    {
        nbytes = read(fd, buff, BUFFER_SIZE);
        if (nbytes <= 0)
        {
            free(buff);
            if (*line && line)
                return (read_fd(&line));
            free(line);
            line = NULL;
            return (NULL);

        }
        buff[nbytes] = '\0';
        line = ft_strjoin(line, buff);
    }
    free(buff);
        if (!line || line[0] == '\0')
    {
        free(line);
        return (NULL);
    }
    return (read_fd(&line));
}

// int main()
// {
//     char *s;
// //     // int fd = open("get_next_line.txt", O_RDONLY);
//         // int fd = open("41_no_nl", O_RDONLY);
//     int fd = open("41_with_nl", O_RDONLY);
// //     // int fd = open("42_no_nl", O_RDONLY);
//     // int fd = open("42_with_nl", O_RDONLY);
// //     // int fd = open("43_no_nl", O_RDONLY);
//     // int fd = open("43_with_nl", O_RDONLY);
// //     // int fd = open("alternate_line_nl_no_nl", O_RDONLY);
//     // int fd = open("alternate_line_nl_with_nl", O_RDONLY);
// //     // int fd = open("big_line_no_nl", O_RDONLY);
//     // int fd = open("big_line_with_nl", O_RDONLY);
// //     // int fd = open("multiple_line_no_nl", O_RDONLY);
//     // int fd = open("multiple_line_with_nl", O_RDONLY);
//     // int fd = open("multiple_nlx5", O_RDONLY);
//     // int fd = open("nl", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }
//     int n = 2;
//     while (n > 0)
//     {
//         s = get_next_line(fd);
//         printf("%s\n", s);
//         n--;
//     }
//     // free(s);
//     return (0);
// }
