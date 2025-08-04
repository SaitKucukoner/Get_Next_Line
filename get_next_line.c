#include "get_next_line.h"

char	*read_file(int fd, char *result)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*tmp;
	
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(result,buf);
		free(result);
		result = tmp;
	}
	return(result);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	return(buffer);
}