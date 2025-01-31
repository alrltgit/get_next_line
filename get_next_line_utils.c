/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:58 by apple             #+#    #+#             */
/*   Updated: 2025/01/31 15:53:51 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *line, char *ptr, int line_len)
{
	int	i;

	i = 0;
	while (line_len > 0)
	{
		*ptr = line[i];
		i++;
		line_len--;
		ptr++;
	}
	return (ptr);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*ptr;
	char	*fin_str;
	int		line_len;
	int		buff_len;

	line_len = 0;
	if (line)
		line_len = ft_strlen(line);
	buff_len = 0;
	buff_len = ft_strlen(buffer);
	ptr = malloc(sizeof(char) * (line_len + buff_len) + 1);
	if (!ptr)
		return (NULL);
	fin_str = ptr;
	if (line)
	{
		ptr = ft_strcpy(line, ptr, line_len);
		free(line);
	}
	ptr = ft_strcpy(buffer, ptr, buff_len);
	*ptr = '\0';
	return (fin_str);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
