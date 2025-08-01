/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skucukon <skucukon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:27:19 by skucukon          #+#    #+#             */
/*   Updated: 2025/08/01 15:29:00 by skucukon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
// kucukoner kucuk 

char	*ft_strdup(const char *str)
{
	char	*cpy_str;
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(str);
	cpy_str = (char *)malloc(str_len + 1);
	if (cpy_str == NULL)
		return (NULL);
	while (str[i])
	{
		cpy_str[i] = str[i];
		i++;
	}
	cpy_str[i] = '\0';
	return (cpy_str);
}

char	*ft_substr(const char *str, size_t start, size_t len)
{
	char	*substr;
	size_t	sub_len;
	size_t	i;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (ft_strlen(str) - start < len)
		sub_len = ft_strlen(str) - start;
	else
		sub_len = len;
	substr = (char *)malloc(sub_len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (sub_len--)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
