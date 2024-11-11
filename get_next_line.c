/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:50:36 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/11 19:58:29 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *buf)
{
	char	*line;
	char	*next_line;
	char	*temp_line;
	ssize_t	read_bytes;

	read_bytes = read(fd, line, BUFFER_SIZE);
	temp_line = line;
	while (read_bytes > 0)
	{
		if (ft_strchr(line, '\n'))
		{
			next_line = (ft_strchr(line, '\n'));
			return(line);
		}
		else
		{
			read_bytes = read(fd, line, BUFFER_SIZE);
			ft_strjoin(temp_line, line);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	buffer = get_line(fd, buffer);
	return (0);
}
