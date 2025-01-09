/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:12:55 by liovino           #+#    #+#             */
/*   Updated: 2025/01/09 17:55:37 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*join_line(char *buff, char *n_buff)
{
	int		i;
	int		l_1;
	int		l_2;
	char	*superstr;

	i = -1;
	if (!buff || !n_buff)
		return (NULL);
	l_1 = ft_strlen(buff);
	l_2 = ft_strlen(n_buff);
	superstr = (char *) malloc(sizeof(char) * ((l_1 + l_2) + 1));
	if (!superstr)
		return (NULL);
	while (buff[++i] != '\0')
		superstr[i] = buff[i];
	i = -1;
	while (n_buff[++i] != '\0')
		superstr[l_1 + i] = n_buff[i];
	superstr[l_1 + i] = '\0';
	return (superstr);
}

char	*next_line(char *buff)
{
	char	*temp;
	char	*start;

	temp = NULL;
	start = ft_strchr(buff, '\n');
	start ++;
	temp = ft_strdup(start);
	return (temp);
}

char	*find_line(int fd, char *buff)
{
	size_t	nbytes;
	int		check_read;

	nbytes = (size_t)BUFFER_SIZE;
	check_read = read(fd, buff, nbytes);
	if (check_read == -1 || check_read == 0)
		return (NULL);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*new_buff;
	char		*line;

	while (find_line(fd, buffer) != NULL)
	{
		line = NULL;
		buffer = find_line(fd, buffer);
		while (find_line(fd, buffer) != NULL)
		{
			while (ft_strchr(buffer, '\n') == NULL)
			{
				new_buff = find_line(fd, new_buff);
				buffer = join_line(buffer, new_buff);
			}
			line = ft_strchrcpy(line, buffer, '\n');
			buffer = (char *)next_line;
		}
		return (line);
	}
	return (NULL);
}
