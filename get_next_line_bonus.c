/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:36:45 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/18 14:31:01 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_buffer(char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (NULL);
}

static char	*get_line_tail(char *buf)
{
	int		b_read;
	char	*tail;

	b_read = 0;
	while (buf[b_read] != '\n' && buf[b_read] != '\0')
		b_read++;
	if (buf[b_read] == '\n')
		b_read++;
	if (buf[b_read] == '\0')
		tail = NULL;
	else
	{
		tail = ft_strdup(buf + b_read);
		buf[b_read] = '\0';
	}
	return (tail);
}

static char	*get_line(int fd, char *buf, char *tail)
{
	ssize_t	buf_size;
	char	*temp;

	while (1)
	{
		buf_size = read(fd, buf, BUFFER_SIZE);
		if (buf_size == -1)
			return (NULL);
		if (buf_size == 0)
			break ;
		buf[buf_size] = '\0';
		if (!tail)
			tail = ft_strdup("");
		temp = tail;
		tail = ft_strjoin(temp, buf);
		free_buffer(&temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail[ARR_FD];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > ARR_FD)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, tail[fd]);
	free_buffer(&buffer);
	if (!line)
		return (free_buffer(&tail[fd]));
	tail[fd] = get_line_tail(line);
	return (line);
}
