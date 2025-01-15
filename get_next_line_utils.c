/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:58 by apple             #+#    #+#             */
/*   Updated: 2025/01/15 22:33:04 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int ft_strlen(const char *s)
{
    int len = 0;

    if (s == NULL)
        return (0);
    while (s[len] != '\0')
        len++;
    return (len);
}

char	*ft_strchr(const char *s, int c)
{
    if (s == NULL)
        return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char    *joined;
	int     s1_len;
	int		s2_len;
    int     i;
    int     j;

	s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
	joined = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
    i = 0;
	while (i < s1_len)
	{
		joined[i] = s1[i];
		i++;
	}
    j = 0;
    while (j < s2_len)
    {
        joined[i + j] = s2[j];
        j++;
    }
	joined[i + j] = '\0';
    if (s1 != NULL)
        free(s1);
	return (joined);
}

char	*ft_strndup(const char *s1, int n)
{
	char	*ptr;
	int		i;

    if (s1 == NULL)
        return (NULL);
	i = 0;
	ptr = malloc(n + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

    if (s1 == NULL)
        return (NULL);
	i = 0;
	ptr = malloc(ft_strlen(s1) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char *read_fd(char **line)
{
    char *current_line;
    char *new_line;
    char *temp_buff;
    int line_len;

    new_line = ft_strchr(*line, '\n');
    if (new_line)
    {
        line_len = new_line - *line;
        current_line = ft_strndup(*line, line_len);
        temp_buff = ft_strdup(new_line + 1);
        free(*line);
        *line = temp_buff;
    }
    else
    {
        current_line = ft_strdup(*line);
        free(*line);
        *line = NULL;
    }
    return (current_line);
}
