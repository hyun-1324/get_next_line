/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:18:50 by donheo            #+#    #+#             */
/*   Updated: 2025/04/25 21:48:46 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *buffer)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	len = ft_strlen(buffer);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_and_free(char *buffer, \
		char const *tmp_buffer, int *buffer_len, int *tmp_len)
{
	int		i;
	char	*new_s;

	*buffer_len = ft_strlen(buffer);
	*tmp_len = ft_strlen(tmp_buffer);
	new_s = (char *)malloc((*buffer_len + *tmp_len + 1) * sizeof(char));
	if (!new_s)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (i < *buffer_len)
	{
		new_s[i] = buffer[i];
		i++;
	}
	while (i < *buffer_len + *tmp_len)
	{
		new_s[i] = tmp_buffer[i - *buffer_len];
		i++;
	}
	new_s[i] = '\0';
	free(buffer);
	return (new_s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
