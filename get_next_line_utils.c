/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:09:41 by liovino           #+#    #+#             */
/*   Updated: 2025/01/09 18:09:44 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str ++;
	}
	return (NULL);
}

char	*ft_strchrcpy(char *dest, char *src, char c)
{
	if (!dest || !src)
		return (NULL);
	while (*src != c)
	{
		*dest = *src;
		dest ++;
		src ++;
	}
	if (c != '\0')
	{
		*dest = c;
		dest ++;
	}
	*dest = '\0';
	return (dest);
}

void	ft_bzero(void *mem, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = mem;
	while (i < n)
	{
		str[i] = 0;
		i ++;
	}
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*res;

	if (nelem != 0 && elsize > (SIZE_MAX / nelem))
		return (NULL);
	res = (void *) malloc(elsize * nelem);
	if (!res)
		return (NULL);
	ft_bzero(res, (elsize * nelem));
	return (res);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		len;

	len = 0;
	while (str[len])
		len ++;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strchrcpy(dest, str, '\0');
	return (dest);
}
