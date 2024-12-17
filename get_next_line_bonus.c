/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:19:08 by kapinarc          #+#    #+#             */
/*   Updated: 2024/12/16 19:20:36 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_buffclean(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = 0;
}

int	is_line(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer [1024][BUFFER_SIZE + 1];
	ssize_t		read_byte;
	char		*line;

	read_byte = 1;
	line = ft_strdup(buffer[fd]);
	if (!line)
		return (NULL);
	while (read_byte && is_line(line) == 0)
	{
		read_byte = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][read_byte] = '\0';
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (NULL);
	}
	ft_buffclean(buffer[fd]);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}