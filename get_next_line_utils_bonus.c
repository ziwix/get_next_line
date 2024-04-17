/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:28:01 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/13 17:27:22 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strcat(char *dest, char *src, char *f_str)
{
	size_t	pos;
	size_t	lendest;

	pos = 0;
	if (!dest)
		lendest = 0;
	else
	{
		lendest = ft_strlen(dest);
		while (dest[pos])
		{
			f_str[pos] = dest[pos];
			pos++;
		}
	}
	pos = 0;
	while (src[pos])
	{
		f_str[lendest + pos] = src[pos];
		pos++;
	}
	f_str[lendest + pos] = '\0';
	return (f_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	new_s_len;
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
		new_s_len = ft_strlen(s2) + 1;
	else
		new_s_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(*str) * new_s_len);
	if (!str)
		return (NULL);
	str = ft_strcat((char *)s1, (char *)s2, str);
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
