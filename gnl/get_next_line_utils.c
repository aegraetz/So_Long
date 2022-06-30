/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:01:36 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/06/10 09:44:31 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*newstr;
	int		size;
	int		i;

	size = ft_strlen(src);
	newstr = malloc(sizeof(*newstr) * (size + 1));
	if (newstr == 0)
	{
		return (0);
	}
	i = 0;
	while (src[i] != '\0')
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subsize;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	subsize = malloc(sizeof(char) * (len + 1));
	if (subsize == 0)
	{
		return (NULL);
	}
	while (s[i])
	{
		if (i >= start && j < len)
		{
			subsize[j] = s[i];
			j++;
		}
		i++;
	}
	subsize[j] = '\0';
	return (subsize);
}
