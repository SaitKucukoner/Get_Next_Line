#include "get_next_line.h"

char    *free_buffer(char *buffer)
{
        free(buffer);
        buffer = NULL;
        return (NULL);
}

char    *fill_line(char *buffer, int len)
{
    char    *line;
    int     i;

    if (!buffer)
        return (NULL);
    line = malloc(len + 1);
    if (!line)
        return (NULL);
    i = -1;
    while (++i < len)
        line[i] = buffer[i];
    line[i] = '\0';
    return (line);
}

char    *seperate_new_line(char **buffer)
{
    char    *print_line;
    char    *new_buf;
    char    *pos_newline;
    int     len;

    if (!*buffer || !*buffer[0])
        return (free_buffer(*buffer));
    pos_newline = ft_strchr(*buffer, '\n');
    if (pos_newline)
        len = pos_newline - *buffer + 1;
    else
        len = ft_strlen(*buffer);
    print_line = fill_line(*buffer, len);
    if (!print_line)
        return (free_buffer(*buffer));
    if (pos_newline)
        new_buf = ft_strdup((char *)(pos_newline+ 1));
    else
        new_buf = ft_strdup((char *)(buffer+ 1));
    if (!new_buf)
        return (free_buffer(*buffer));
    free_buffer(*buffer);
    *buffer = new_buf;
    return (print_line);
    
}


char    *read_file(int fd, char *buffer)
{
    char    *tmp_buf;
    int     bytes_read;
    char    *tmp;

    tmp_buf = malloc(BUFFER_SIZE + 1);
    if (!tmp_buf)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
    {
        bytes_read = read(fd, tmp_buf, BUFFER_SIZE);
        tmp_buf[bytes_read] = '\0';
        tmp = ft_strjoin(buffer, tmp_buf);
        free_buffer(buffer);
        buffer = tmp;
    }
    free_buffer(tmp_buf);
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *buffer;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0))
        return (NULL);
    buffer = read_file(fd, buffer);
    return (seperate_new_line(&buffer));
}