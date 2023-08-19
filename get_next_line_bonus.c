/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstelmac <dstelmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:19:13 by dstelmac          #+#    #+#             */
/*   Updated: 2023/08/19 17:34:14 by dstelmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		i = 0;
		if (fd > 0 && fd < FOPEN_MAX)
		{
			while (buffer[fd][i])
			{
				buffer[fd][i] = 0;
				i++;
			}
		}
		return (NULL);
	}
	while (*buffer[fd] != 0 || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_check_n(buffer[fd]))
			break ;
	}
	return (line);
}
