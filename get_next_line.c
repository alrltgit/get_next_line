/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:55 by apple             #+#    #+#             */
/*   Updated: 2025/01/15 15:44:30 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    char *rslt;

    if (fd == -1 || BUFFER_SIZE < 1)
        return (NULL);
    else
        rslt = read_fd(fd);    
    return (rslt);
}

// int main()
// {
//     char *s = NULL;
// //     // int fd = open("get_next_line.txt", O_RDONLY);
//         int fd = open("41_no_nl", O_RDONLY);
// //     int fd = open("41_with_nl", O_RDONLY);
// //     // int fd = open("42_no_nl", O_RDONLY);
// //     // int fd = open("42_with_nl", O_RDONLY);
// //     // int fd = open("43_no_nl", O_RDONLY);
// //     // int fd = open("43_with_nl", O_RDONLY);
// //     // int fd = open("alternate_line_nl_no_nl", O_RDONLY);
// //     // int fd = open("alternate_line_nl_with_nl", O_RDONLY);
// //     // int fd = open("big_line_no_nl", O_RDONLY);
// //     // int fd = open("big_line_with_nl", O_RDONLY);
// //     // int fd = open("multiple_line_no_nl", O_RDONLY);
// //     // int fd = open("multiple_line_with_nl", O_RDONLY);
// //     // int fd = open("multiple_nlx5", O_RDONLY);
// //     // int fd = open("nl", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }
//     // int n = 1;
//     // while (n > 0)
//     // {
//         s = get_next_line(fd);
//         printf("%s\n", s);
//     //     n--;
//     // }
//     free(s);
//     return (0);
// }
