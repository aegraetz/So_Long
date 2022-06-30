/* ************************************************************************** */
/*  */
/*  :::     ::::::::   */
/*   create_map.c      :+:   :+:    :+:   */
/*  +:+ +:+    +:+    */
/*   By: agraetz <agraetz@student.42.fr>    +#+  +:+       +#+  */
/*  +#+#+#+#+#+   +#+    */
/*   Created: 2022/06/02 10:56:53 by anniegraetz       #+#  #+#    */
/*   Updated: 2022/06/09 13:19:51 by agraetz      ###   ########.fr    */
/*  */
/* ************************************************************************** */

#include "so_long.h"

//start from create_map function

static int	add_a_line(t_game *sf, char *contents)//function to copy the map into the variable map and discover the map height
{
	char	**temp;
	int		i;

	if (!contents)
	{
		return (0);//if there's no line return NULL
	}
	i = 0;
	sf->map_h++;//the row which is currently being read (+1 for \0)
	temp = malloc(sizeof(char *) * (sf->map_h + 1));
	temp[sf->map_h] = NULL;
	while (i < sf->map_h - 1)//while the index is less than the number row we're currently reading
	{
		temp[i] = sf->map[i];//size allocated to map
		i++;//increment until we reach map_h
	}
	temp[i] = contents;//the index in temp then holds the whole line
	if (sf->map)
	{
		free(sf->map);//any previous lines in map are cleared to make way for fresh lines
	}
	sf->map = temp;// the multiple lines that are being kept in the temp array are put into map
	return (1);
}

static int	get_width(char *row)
{
	int	i;

	i = 0;
	while (row[i] != '\0')//while we're not at the end of the first row
	{
		i++;//increment till null
	}
	if (row[i - 1] == '\n')//if you go past the end of the row, go back
	{
		i--;
	}
	return (i);//return the count of columns in the row
}

int	create_map(t_game *sf, char *path)
{
	char	*map_contents;
	int		fd;

	fd = open(path, O_RDONLY);//open the map to read
	if (fd < 0)//if there's nothing to read, return null
	{
		printf("failed to read\n");
		return (0);
	}
	while (1)
	{
		map_contents = get_next_line(fd);//while there is something to read, extract line by line
		if (!add_a_line(sf, map_contents))//unless a line is not found in which case break
		{
			break ;
		}
	}
	close(fd);
	sf->map_w = get_width(sf->map[0]);//function to find the width of the map
	return (1);
}
