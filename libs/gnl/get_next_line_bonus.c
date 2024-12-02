/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-27 11:28:00 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-05-27 11:28:00 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

/**
 * The function "get_next_line" function reads a line from a file descriptor.
 * This implementation uses a static buffer to manage multiple descriptors.
 * 
 * @param int fd    				The file descriptor to read from.
 * 
 * @return 							If all goes well: the line read.
 *									On failure or if reading ends: NULL.
 * 
 * The function "read_fill_line" function reads from the given file descriptor
 * and concatenates the data into a buffer until a newline is found or the read
 * operation ends.
 * 
 * @param int fd					The file descriptor to read from.
 * @param char *buffer_readed		A temporary buffer to store the read data.
 * @param char *buffer_print		A buffer to accumulate the read data.
 * 
 * @return If all goes well: the buffer containing the read line.
 *         On failure: NULL.
 * 
 * The function "manage_readed_line" function processes the current line stored
 * in the buffer and updates it to prepare for the next read operation.
 * 
 * @param char *treat_line			The line to process.
 * 
 * @return If the operation succeeds: a new buffer with remaining content.
 *         If there is no remaining content or an error occurs: NULL.
 * 
 * The function "ft_strchr2" locates the first occurrence of a character in the
 * string pointed to by s.
 * 
 * @param const char *s				The string to search.
 * @param int c						The character to locate.
 * 
 * @return							If the character is found: a pointer to the
 * 									first occurrence.
 *									If the character is not found: NULL.
 * 
*/

char	*ft_strchr2(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		else
			s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (0);
}

static char	*manage_readed_line(char	*treat_line)
{
	char	*new_buffer_print;
	size_t	i;

	i = 0;
	while (treat_line[i] != '\n' && treat_line[i] != '\0')
		i++;
	if (treat_line[i] == 0 || treat_line[1] == 0)
		return (NULL);
	new_buffer_print = ft_substr2(treat_line, i + 1, ft_strlen2(treat_line) \
	- i);
	if (*new_buffer_print == 0)
	{
		free(new_buffer_print);
		new_buffer_print = NULL;
	}
	treat_line[i + 1] = '\0';
	return (new_buffer_print);
}

static char	*read_fill_line(int fd, char *buffer_readed, char *buffer_print)
{
	ssize_t			bytes_readed;	
	char			*buffer_tmp;	

	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buffer_readed, BUFFER_SIZE);
		if (bytes_readed < 0)
		{
			free(buffer_readed);
			return (NULL);
		}
		else if (bytes_readed == 0)
			break ;
		buffer_readed[bytes_readed] = '\0';
		if (!buffer_print)
			buffer_print = ft_strdup2("");
		buffer_tmp = buffer_print;
		buffer_print = ft_strjoin2(buffer_tmp, buffer_readed);
		free(buffer_tmp);
		buffer_tmp = NULL;
		if (ft_strchr2(buffer_readed, '\n'))
			break ;
	}
	return (buffer_print);
}

char	*get_next_line2(int fd)
{
	char			*buffer_readed;
	char			*line_print;
	static char		*buffer_print[FD_SETSIZE];

	buffer_readed = (void *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
	{
		free(buffer_print[fd]);
		free(buffer_readed);
		buffer_print[fd] = NULL;
		buffer_readed = NULL;
		return (NULL);
	}
	if (!buffer_readed)
		return (NULL);
	line_print = read_fill_line(fd, buffer_readed, buffer_print[fd]);
	free(buffer_readed);
	buffer_readed = NULL;
	if (!line_print)
		return (NULL);
	buffer_print[fd] = manage_readed_line(line_print);
	return (line_print);
}
