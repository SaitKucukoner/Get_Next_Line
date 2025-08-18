/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skucukon <skucukon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:43:13 by skucukon          #+#    #+#             */
/*   Updated: 2025/08/18 18:43:29 by skucukon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
#endif