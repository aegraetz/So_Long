/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:26:28 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/06/30 10:06:27 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*i;

	i = str;
	while (n > 0)
	{
	*i = c;
	i++;
	n--;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_game	sf;

	if (argc != 2)//if the argument count is less than 2 then we cannot go on
	{
		return (0);
	}
	ft_memset(&sf, 0, sizeof(t_game));//populate the variables in the struct
	create_map(&sf, argv[1]); //read the map document and get the specs
	map_check(&sf);
	sf.mx = mlx_init();//initialise the minilibx library
	sf.win = mlx_new_window(sf.mx, sf.map_w * 54, sf.map_h * 63,
			"strawberry fields");//open up a game window	
	convert_image(&sf);//set up the visual elements
	put_image(&sf);
	mlx_key_hook(sf.win, deal_key, &sf);//respond to player actions
	mlx_hook(sf.win, 17, 0, (void *)exit, 0);//exit cleanly when x button used
	mlx_loop(&sf.mx);
}

int	exit_game(t_game *sf)//freeing all the space used up by the game & map
{
	int	line;

	mlx_destroy_window(sf->mx, sf->win);
	free(sf->mx);
	line = 0;
	while (line < sf->map_h - 1)
	{
		free(sf->map[line++]);
	}
	free(sf->map);
	exit(0);
}
