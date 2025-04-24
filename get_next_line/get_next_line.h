/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:08:24 by donheo            #+#    #+#             */
/*   Updated: 2025/04/24 17:06:20 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strjoin_and_free(char *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);

char	*save_file(int fd, char *buffer);
char	*save_lines(int fd, char *buffer, char *tmp_buffer);
char	*process_line(char **buffer);

#endif
