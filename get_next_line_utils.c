/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:06:10 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/11 16:35:45 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*dest;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (0);
	total = nmemb * size;
	dest = (char *)malloc(total * sizeof(char));
	if (!dest)
		return (0);
	while (total)
		dest[--total] = 0;
	return ((void *)dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && i < len)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
