/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:00 by kapinarc          #+#    #+#             */
/*   Updated: 2024/11/20 15:21:00 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer [BUFFER_SIZE + 1];
	ssize_t		read_byte;
	char		*line;

	read_byte = 1;
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (read_byte && is_line(line) == 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		buffer[fd][read_byte] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	ft_buffclean(buffer);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}
/*
int main (void)
{
	int fd;
	int fd2;
	char *line;
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	if (fd2 == -1)
		return (1);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (i < 50)
	{
		printf("line %i: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line %i: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}*/