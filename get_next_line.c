/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstelmac <dstelmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:39:16 by dstelmac          #+#    #+#             */
/*   Updated: 2023/08/19 17:11:29 by dstelmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			i;

	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		i = 0;
		while (buffer[i])
		{
			buffer[i] = 0;
			i++;
		}
		return (NULL);
	}
	while (*buffer != 0 || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_check_n(buffer))
			break ;
	}
	return (line);
}
