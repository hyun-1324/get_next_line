/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:08:24 by donheo            #+#    #+#             */
/*   Updated: 2025/05/24 21:23:35 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin_and_free(char *buffer, \
		char const *tmp_buffer, int buffer_len, int tmp_len);

char	*get_next_line(int fd);

#endif
