/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:08:24 by donheo            #+#    #+#             */
/*   Updated: 2025/04/25 10:30:14 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin_and_free(char *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);

char	*process_line(char **buffer);
char	*save_lines(int fd, char *buffer, char *tmp_buffer);
char	*save_file(int fd, char *buffer);
char	*get_next_line(int fd);

#endif
