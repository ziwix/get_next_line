/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:08:47 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/19 15:25:38 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_file(fd, stock);
	if (!stock)
		return (NULL);
	line = get_line(stock);
	stock = trim_stock(stock);
	if (stock && stock[0] == '\0')
		free(stock);
	return (line);
}

char	*read_file(int fd, char *stock)
{
	char	*buff;
	int		read_size;
	int		i;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (1)
	{
		i = 0;
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 0 || (read_size == 0 && !stock))
		{
			free(buff);
			return (NULL);
		}
		buff[read_size] = '\0';
		stock = ft_strjoin(stock, buff);
		while (buff[i] != '\n' && buff[i])
			i++;
		if (i != read_size || (read_size == 0 && stock[i] != 0))
			break ;
	}
	free(buff);
	return (stock);
}

char	*get_line(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] != '\n' && stock[i])
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*trim_stock(char *stock)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (stock[i])
		dest[j++] = stock[i++];
	dest[j] = '\0';
	free(stock);
	return (dest);
}
