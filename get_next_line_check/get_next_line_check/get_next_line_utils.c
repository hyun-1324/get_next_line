/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:19:32 by donheo            #+#    #+#             */
/*   Updated: 2025/04/25 17:17:52 by donheo           ###   ########.fr       */
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
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup_and_free(char *src)
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
	free(src);
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
