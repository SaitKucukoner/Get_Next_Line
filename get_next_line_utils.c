#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}
char *ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;	
	}
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	char *s3;
	int	s1_len;
	int	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)malloc(s1_len + s2_len + 1);
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[i])
	{
		s3[i] = s2[i];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
// kucukoner kucuk 

char *ft_strdup(char *str)
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

char *ft_substr(char *str, int start, int len)
{
	char	*sub_str;
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (start > str_len)
		return (NULL);
}
