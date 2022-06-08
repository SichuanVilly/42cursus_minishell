/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:46:32 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/20 14:28:52 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenchar(char *str, char c)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (*str != c && *str++)
		len++;
	return (len);
}

static char	*ft_read_buffer_size(char *buffer_read, int *n, int fd)
{
	char	*temp;
	char	*temp2;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	*n = read(fd, temp, BUFFER_SIZE);
	if (*n == 0 || *n == -1)
	{
		*n = 0;
		free(temp);
		return (buffer_read);
	}
	temp[*n] = '\0';
	temp2 = ft_strjoin(buffer_read, temp);
	if (temp)
		free(temp);
	if (buffer_read)
		free(buffer_read);
	return (temp2);
}

static char	*ft_linecpy(char *buffer_read)
{
	char	*next_line;
	char	*p;

	if (!buffer_read)
		return (NULL);
	if (ft_strchr((const char *)buffer_read, '\n'))
		next_line = malloc(sizeof(char) * (ft_lenchar(buffer_read, '\n') + 2));
	else
		next_line = malloc(sizeof(char) * (ft_lenchar(buffer_read, '\n') + 1));
	if (!next_line)
		return (NULL);
	p = next_line;
	while (*buffer_read != '\n' && *buffer_read)
		*next_line++ = *buffer_read++;
	if (*buffer_read == '\n')
		*next_line++ = '\n';
	*next_line = '\0';
	return (p);
}

static char	*new_buffer_read(char *buffer_read)
{
	char	*new_buffer;
	char	*p;
	int		i;

	i = 0;
	while (buffer_read && buffer_read[i] != '\n' && buffer_read[i])
		i++;
	if (!buffer_read || buffer_read[i] == '\0')
	{
		free(buffer_read);
		return (NULL);
	}
	i++;
	new_buffer = malloc(sizeof(char) * (ft_strlen(&buffer_read[i]) + 1));
	if (!new_buffer)
		return (NULL);
	p = new_buffer;
	while (buffer_read[i])
		*new_buffer++ = buffer_read[i++];
	*new_buffer = 0;
	free(buffer_read);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*buffer_read = NULL;
	char		*next_line;
	int			n;

	n = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	while (!ft_strchr((const char *)buffer_read, '\n') && n)
		buffer_read = ft_read_buffer_size(buffer_read, &n, fd);
	if (!buffer_read)
		return (NULL);
	else if (!*buffer_read)
	{
		free(buffer_read);
		return (NULL);
	}
	next_line = ft_linecpy(buffer_read);
	buffer_read = new_buffer_read(buffer_read);
	return (next_line);
}
