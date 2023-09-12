/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:26:06 by mmeerber          #+#    #+#             */
/*   Updated: 2023/09/11 13:26:10 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *content)
{
	char	*buffer;
	int		return_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	return_read = 1;
	while (!ft_strchr(content, '\n') && return_read != 0)
	{
		return_read = read(fd, buffer, BUFFER_SIZE);
		if (return_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[return_read] = '\0';
		content = ft_strjoin(content, buffer);
	}
	free(buffer);
	return (content);
}

static char	*get_line(char *content)
{
	char	*line;
	int		x;

	x = 0;
	if (!content[x])
		return (NULL);
	while (content[x] && content[x] != '\n')
		x++;
	line = malloc(sizeof(char) * (x + 2));
	if (!line)
		return (NULL);
	x = 0;
	while (content[x] && content[x] != '\n')
	{
		line[x] = content[x];
		x++;
	}
	if (content[x] == '\n')
	{
		line[x] = content[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	content = read_file(fd, content);
	if (!content)
		return (NULL);
	line = get_line(content);
	content = backup(content);
	return (line);
}
