/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:19:32 by donheo            #+#    #+#             */
/*   Updated: 2025/05/25 10:21:09 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (s < d)
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin_and_free(char *buffer, \
		char const *tmp_buffer, int buffer_len, int tmp_len)
{
	int		i;
	char	*new_s;

	buffer_len = ft_strlen(buffer);
	tmp_len = ft_strlen(tmp_buffer);
	new_s = (char *)malloc((buffer_len + tmp_len + 1) * sizeof(char));
	if (!new_s)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (i < buffer_len)
	{
		new_s[i] = buffer[i];
		i++;
	}
	while (i < buffer_len + tmp_len)
	{
		new_s[i] = tmp_buffer[i - buffer_len];
		i++;
	}
	new_s[i] = '\0';
	free(buffer);
	return (new_s);
}
