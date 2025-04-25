/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:17:36 by donheo            #+#    #+#             */
/*   Updated: 2025/04/25 10:11:11 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*process_line(char **buffer)
{
	size_t	i;
	char	*line;
	char	*tmp;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
	{
		line[i] = (*buffer)[i];
		i++;
	}
	if ((*buffer)[i] && (*buffer)[i] == '\n')
		line[i++] = '\n';
	tmp = ft_strdup(&(*buffer)[i]);
	free(*buffer);
	*buffer = tmp;
	return (line);
}

char	*save_lines(int fd, char *buffer, char *tmp_buffer)
{
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		tmp_buffer[read_bytes] = 0;
		buffer = ft_strjoin_and_free(buffer, tmp_buffer);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*save_file(int fd, char *buffer)
{
	char	*tmp_buffer;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
	tmp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buffer)
		return (NULL);
	buffer = save_lines(fd, buffer, tmp_buffer);
	if (!buffer)
	{
		free(tmp_buffer);
		return (NULL);
	}
	free(tmp_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = save_file(fd, buffer[fd]);
	if (!buffer[fd] || (buffer[fd])[0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = process_line(&buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	return (line);
}
