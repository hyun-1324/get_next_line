/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:19:32 by donheo            #+#    #+#             */
/*   Updated: 2025/04/10 19:28:16 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	len = ft_strlen(src);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_and_free(char *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*new_s;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_s = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new_s[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		new_s[i] = s2[i - len1];
		i++;
	}
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

char	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*buffer;

	buffer = malloc(elementSize * elementCount);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, elementSize * elementCount);
	return (buffer);
}
