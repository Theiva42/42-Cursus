/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:14:11 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/28 11:14:23 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

long					ft_atoi(const char *str);
char				*ft_itoa(int n);

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *str, const char *to_find, \
					size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *str);

#endif
