/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:08:44 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/13 17:30:50 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/*****************************/
/*		get_next_line.c		 */
/*****************************/

char	*get_next_line(int fd);
char	*read_file(int fd, char *stock);
char	*get_line(char *stock);
char	*trim_stock(char *stock);

/*************************************/
/*		 get_next_line_utils.c		 */
/*************************************/

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif