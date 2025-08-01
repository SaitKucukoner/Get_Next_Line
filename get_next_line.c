#include "get_next_line.h"

char	*read_and_append(int fd, char *remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*tmp;

	if(!remainder)
		remainder = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(remainder,'\n'))
	{
		bytes_read = read(fd,buffer,BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(remainder);
			return (NULL);
		}
	buffer[bytes_read] = '\0';
	tmp = remainder;
	remainder = ft_strjoin(tmp,buffer);
	free(tmp);
	if (!remainder)
		return (NULL);
	}
	return (remainder);
	
}

char	*extract_line(char *remainder)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!remainder || !remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = remainder[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char *update_remainder(char *remainder)
{
    size_t	i;
    size_t	j;
    char	*new_remainder;

	i = 0;
	j = 0;
    if (!remainder)
        return NULL;
    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (!remainder[i])
    {
        free(remainder);
        return NULL;
    }
    i++;
    new_remainder = malloc(sizeof(char) * (ft_strlen(remainder) - i + 1));
    if (!new_remainder)
	{
		free(remainder);
		return (NULL);
	}
    while (remainder[i])
        new_remainder[j++] = remainder[i++];
    new_remainder[j] = '\0';
    free(remainder);
    return (new_remainder);
}
char *get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
		return (NULL);
	remainder = read_and_append(fd,remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
	remainder = update_remainder(remainder);
	return(line);
}