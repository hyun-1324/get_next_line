/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:06:35 by donheo            #+#    #+#             */
/*   Updated: 2025/05/24 21:27:10 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	delete_copied_line(char *buffer, size_t line_len)
{
	int		rest_len;

	rest_len = ft_strlen(buffer + line_len);
	ft_memmove(buffer, buffer + line_len, rest_len + 1);
}

static char	*copy_line(const char *buffer, size_t	*line_len)
{
	char	*line;

	*line_len = 0;
	while (buffer[*line_len] && buffer[*line_len] != '\n')
		(*line_len)++;
	if (buffer[*line_len] == '\n')
		(*line_len)++;
	line = ft_calloc(*line_len + 1, sizeof(char));
	if (!line)
		return (NULL);
	*line_len = 0;
	while (buffer[*line_len] && buffer[*line_len] != '\n')
	{
		line[*line_len] = buffer[*line_len];
		(*line_len)++;
	}
	if (buffer[*line_len] && buffer[*line_len] == '\n')
		line[(*line_len)++] = '\n';
	return (line);
}

static char	*save_lines(int fd, char *buffer)
{
	int		read_bytes;
	char	*tmp_buffer;

	tmp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buffer)
		return (free(buffer), NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(tmp_buffer), free(buffer), NULL);
		tmp_buffer[read_bytes] = '\0';
		buffer = ft_strjoin_and_free(buffer, tmp_buffer, 0, 0);
		if (!buffer)
			return (free(tmp_buffer), NULL);
	}
	free(tmp_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
	buffer = save_lines(fd, buffer);
	if (!buffer || buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	line = copy_line(buffer, &line_len);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	delete_copied_line(buffer, line_len);
	return (line);
}
