/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstelmac <dstelmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:39:11 by dstelmac          #+#    #+#             */
/*   Updated: 2023/08/19 17:10:37 by dstelmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] && str[count] != '\n')
		count++;
	return (count + (str[count] == '\n'));
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*dest;
	size_t	i;
	size_t	j;

	dest = (char *)malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		dest[i] = line[i];
		i++;
	}
	free(line);
	j = 0;
	while (buffer[j])
	{
		dest[i + j] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_check_n(char *buffer)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (flag)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			flag = 1;
		buffer[i] = '\0';
		i++;
	}
	return (flag);
}
