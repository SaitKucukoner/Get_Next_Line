#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = -1;
	while (s2[++j])
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	if (!s)
		return(NULL);
	s2 = malloc(ft_strlen(s) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

