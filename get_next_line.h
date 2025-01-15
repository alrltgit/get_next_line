/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:51 by apple             #+#    #+#             */
/*   Updated: 2025/01/15 22:01:15 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char    *get_next_line(int );
char    *read_fd(char **);
char	*ft_strchr(const char *, int );
char	*ft_strndup(const char *, int );
char	*ft_strjoin(char *, char *);

#endif