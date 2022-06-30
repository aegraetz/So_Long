/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:40:18 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/06/10 09:44:37 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (0);
}

static char	*extract(char *line)
{
	char	*remainder;
	size_t	a;

	a = 0;
	while (line[a] != '\0' && line[a] != '\n')
	{
		a++;
	}
	if (line[a] == '\0' || line[1] == '\0')
	{
		return (NULL);
	}
	remainder = ft_substr(line, a + 1, ft_strlen(line)- a);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[a + 1] = '\0';
	return (remainder);
}

static char	*find_nl(int fd, char *buffer, char *store)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!store)
			store = ft_strdup("");
		temp = store;
		store = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*store;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
	{
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
	{
		return (NULL);
	}
	line = find_nl(fd, buffer, store);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		return (line);
	}
	store = extract(line);
	return (line);
}
