/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraetz <agraetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:01:07 by anniegraetz       #+#    #+#             */
/*   Updated: 2022-+
0

/06/20 10:00:41 by agraetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//start at deal_key function

static int	tile_check(t_game *sf, int w, int h)
{
	if (sf->map[h][w] == '0')//if player lands on a ground tile
	{
		sf->map[h][w] = 'P';//that place becomes a player tile
		sf->locationw = w;
		sf->locationh = h;
		sf->moves_count++;//increase the count for the number of moves
	}
	if (sf->map[h][w] == 'C')//if player lands on a collectable
	{
		sf->map[h][w] = 'P';//that place becomes a player tile
		sf->locationw = w;
		sf->locationh = h;
		sf->berry--;//decrease the number of strawberries as one has been picked
		sf->moves_count++;
	}
	if (sf->map[h][w] == 'E')//if player lands on the exit
	{
		if (sf->berry != 0)//if there are still collectables in the game then they cannot exit
			return (0);
		else//otherwise winner, winner chicken dinner
			printf("\e[35m\e[1m\nTime to make a strawberry shortcake!\e[0m \n");
		exit_game(sf);
	}
	return (1);
}

static int	up_or_down(t_game *sf, int key)
{
	int	w;
	int	h;

	w = sf->locationw;//tracking player's location
	h = sf->locationh;
	if (key == 13)//player pressed "W" key to move up
	{
		h--; //move up the map
		if (sf->map[h][w] == '1')//this is a bush and player cannot move into bushes
			return (0);
		if (!(tile_check(sf, w, h)))//function to check the tile the player is stepping onto and trigger the result accordingly
			return (0);
		sf->map[h + 1][w] = '0';//place ground image on the tile the player just left
	}
	else if (key == 1)//player pressed "S" key to move down
	{
		h++;//move down the map
		if (sf->map[h][w] == '1')
			return (0);
		if (!(tile_check(sf, w, h)))
			return (0);
		sf->map[h - 1][w] = '0';
	}
	printf("moves: %i\n", sf->moves_count);
	return (1);
}

static int	l_or_r(t_game *sf, int key)
{
	int	w;
	int	h;

	w = sf->locationw;
	h = sf->locationh;
	if (key == 0)//player pressed "A" key to move left
	{
		w--;//move left on the map
		if (sf->map[h][w] == '1')
			return (0);
		if (!(tile_check(sf, w, h)))
			return (0);
		sf->map[h][w + 1] = '0';
	}
	else if (key == 2)//player pressed "D" key to move right
	{
		w++;//move right on the map
		if (sf->map[h][w] == '1')
			return (0);
		if (!(tile_check(sf, w, h)))
			return (0);
		sf->map[h][w - 1] = '0';
	}
	printf("moves: %i\n", sf->moves_count);
	return (1);
}

int	deal_key(int key, t_game *sf)//check what key the player has hit
{
	int	action;

	if (key == 13 || key == 1)
	{
		action = up_or_down(sf, key);//function to determine if player is moving up or down
	}
	if (key == 0 || key == 2)
	{
		action = l_or_r(sf, key);//function to determine if player is moving left or right
	}
	if (key == 53)//if they hit ESC
	{
		exit_game(sf);
	}
	if (action)
	{
		put_image(sf);
	}
	return (1);
}
