/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:50:36 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/11 19:18:21 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(int fd, char *buf)
{
}

char	*get_next_line(int fd)
{
	int			read_bytes;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = get_line(fd, buffer);
	return (0);
}
