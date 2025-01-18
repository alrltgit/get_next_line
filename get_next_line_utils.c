/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:54:58 by apple             #+#    #+#             */
/*   Updated: 2025/01/18 14:37:11 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
    if (s == NULL)
    {
        return (NULL);
    }
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

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char    *joined;
// 	int     s1_len;
// 	int		s2_len;
//     int     i;
//     int     j;

// 	s1_len = 0;
// 	while (s1[s1_len])
// 	{
// 		s1_len++;
// 	}
//     // printf("s1_len: %d", s1_len);
//     s2_len = 0;
// 	while (s2[s2_len])
// 	{
// 		s2_len++;	
// 	}
//     // printf("s2_len: %d", s1_len);
// 	joined = malloc((s1_len + s2_len + 1) * sizeof(char));
// 	if (joined == NULL)
// 		return (NULL);
//     i = 0;
// 	while (i < s1_len)
// 	{
// 		joined[i] = s1[i];
// 		i++;
// 	}
//     j = 0;
//     while (j < s2_len)
//     {
//         joined[i + j] = s2[j];
//         j++;
//     }
// 	joined[i + j] = '\0';
// 	return (joined);
// }

char	*ft_strndup(const char *s1, int n)
{
	char	*ptr;
	int		i;

    if (s1 == NULL)
    {
        return (NULL);
    }
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
	int		s1_len;

    if (s1 == NULL)
    {
        return (NULL);
    }
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	ptr = malloc(s1_len + 1);
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
