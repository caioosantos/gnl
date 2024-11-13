/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:50:36 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/13 19:49:46 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_buffer(char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

static char	*ft_strchr(const char *s, int c)
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

static char	*get_line_tail(char *line)
{
	int		b_read;
	char	*tail;

	b_read = 0;
	while (line[b_read] != '\n' && line[b_read] != '\0')
		b_read++;
	if (line[b_read] == '\n')
		b_read++;
	if (line[b_read] == '\0')
		return (NULL);
	tail = ft_strdup(line + b_read);
	line[b_read] = '\0';
	return (tail);
}

static char	*get_line(int fd, char *buffer)
{
	ssize_t	buffer_size;
	char	*temp;
	char	*rest;

	rest = ft_strdup(buffer);
	buffer_size = 1;
	while (buffer_size > 0)
	{
		buffer_size = read(fd, buffer, BUFFER_SIZE);
		if (buffer_size < 0)
			return (NULL);
		if (buffer_size == 0)
			break ;
		buffer[buffer_size] = '\0';
		temp = rest;
		rest = ft_strjoin(temp, buffer);
		free_buffer(&temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer);
	if (!line)
		return (free_buffer(&buffer));
	buffer = get_line_tail(line);
	return (line);
}
