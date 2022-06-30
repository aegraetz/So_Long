/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:47:44 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/06/30 09:59:43 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//start at map_check function

void	wall_check(t_game *sf)//checking that border of map is made up of walls
{
	int	h;
	int	w;

	w = 0;
	while (w < sf->map_w)
	{
		if (!(sf->map[0][w] == '1' && sf->map[sf->map_h - 1][w] == '1'))
		{
			printf("\e[31m\e[1mError\nOops, your map is missing bushes\e[0m \n");
			exit_game(sf);
		}
		w++;
	}
	h = 0;
	while (h < sf->map_h)
	{
		if (!(sf->map[h][0] == '1' && sf->map[h][sf->map_w - 1] == '1'))
		{
			printf("\e[31m\e[1mError\nOops, your map is missing bushes\e[0m \n");
			exit_game(sf);
		}
		h++;
	}
}

void	count_cpe(t_game *sf, int w, int h) //keep track to ensure correct amount of each element is present in map
{
	if (sf->map[h][w] == 'C')
		sf->c_count++;
	if (sf->map[h][w] == 'P')
		sf->p_count++;
	if (sf->map[h][w] == 'E')
		sf->e_count++;
}

void	only_10ecp(t_game *sf) //checking one element at a time, ensure that only the allowed chars are used in the map
{
	int	w;
	int	h;

	h = 0;
	while (h < sf->map_h - 1)
	{
		w = 0;
		while (w <= sf->map_w)
		{	
			count_cpe(sf, w, h);
			if (sf->map[h][w] != '1' && sf->map[h][w] != '0'
				&& sf->map[h][w] != 'P'
				&& sf->map[h][w] != 'E' && sf->map[h][w] != 'C'
				&& sf->map[h][w] != '\n')
			{
				printf("\e[31m\e[1mError\nHm seems there's an unknown char\e[0m \n");
				exit_game(sf);
			}
			w++;
		}
		h++;
	}
}

void	map_check(t_game *sf)
{
	wall_check(sf);
	only_10ecp(sf);
	if (!(sf->c_count > 1 && sf->p_count == 1 && sf->e_count == 1))
	{
		printf("\e[31m\e[1mError\nNeed 1 picker & exit and >1 strawberry\e[0m \n");
		exit_game(sf);
	}
}
