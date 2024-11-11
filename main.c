/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:31:47 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/11 16:32:36 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("files.txt", O_RDONLY);
	buffer = get_next_line(fd);
	printf("%s\n", buffer);
	return (0);
}
