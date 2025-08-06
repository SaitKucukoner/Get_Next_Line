#include "get_next_line.h"

static char    *fill_line(char *buffer, int len)
{
    char    *line;
    int     i;

    if (!buffer)
        return (NULL);
    line = malloc(sizeof(char) * (len + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (i < len)
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

static char	*read_file(int fd, char *buffer)
{
	char	*tmp_buf;
	char	*tmp;
	int		bytes_read;

	tmp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buf)
		return (NULL);
	bytes_read = 1;
	while (!(ft_strchr(buffer, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, tmp_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp_buf);
			free(buffer);
			return (NULL);
		}
		tmp_buf[bytes_read] = '\0';
		tmp = ft_strjoin(buffer, tmp_buf);
		free(buffer); 
		buffer = tmp; 
	}
	free(tmp_buf);
	return (buffer);
}

static char	*seperate_new_line(char **buffer)
{
	char	*line;
	char	*newline_pos;
	char	*tmp;
	int		len;

	if (!*buffer || !*buffer[0])
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
		len = newline_pos - *buffer + 1;
	else
		len = ft_strlen(*buffer);
	
	line = fill_line(*buffer, len);
	if (!line)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	if (newline_pos)
		tmp = ft_strdup(newline_pos + 1);
	else
		tmp = NULL;
	
	free(*buffer);
	*buffer = tmp;
	
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	return (seperate_new_line(&buffer));
}
