/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:41:03 by liovino           #+#    #+#             */
/*   Updated: 2025/01/09 17:57:01 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*join_line(char *buff, char *n_buff);
char	*next_line(char *buff);
char	*find_line(int fd, char *buff);
char	*ft_strchr(char *str, char c);
char	*ft_strchrcpy(char *dest, char *src, char c);
void	ft_bzero(void *mem, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
char	*ft_strdup(char *str);

#endif