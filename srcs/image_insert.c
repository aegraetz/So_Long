/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:20:06 by agraetz           #+#    #+#             */
/*   Updated: 2022/06/30 10:01:02 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_image(t_game *sf)//directing to xpm files that can be converted to new image instances
{
	int	x;
	int	y;

	sf->picker = mlx_xpm_file_to_image(sf->mx, "images/picker.xpm", &x, &y);
	sf->g = mlx_xpm_file_to_image(sf->mx, "images/ground.xpm", &x, &y);
	sf->strawb = mlx_xpm_file_to_image(sf->mx, "images/strawb.xpm", &x, &y);
	sf->b = mlx_xpm_file_to_image(sf->mx, "images/strawbbush.xpm", &x, &y);
	sf->e = mlx_xpm_file_to_image(sf->mx, "images/basket.xpm", &x, &y);
}

void	put_picker(t_game *sf, int h, int w)
{
	mlx_put_image_to_window(sf->mx, sf->win, sf->picker, w * 54, h * 63);
	sf->locationh = h;//remembering that the picker needs to move according to button commands
	sf->locationw = w;
}

void	berry_count(t_game *sf, int h, int w)
{
	mlx_put_image_to_window(sf->mx, sf->win, sf->strawb, w * 54, h * 63);
	sf->berry++;
}

void	put_image(t_game *sf)//put the images into the window as dictated by the map
{
	int	w;
	int	h;

	h = 0;
	sf->berry = 0;
	while (h < sf->map_h)//as long as we're not outside the height of the map
	{
		w = 0;
		while (sf->map[h][w])//as long as we're still on the map
		{
			if (sf->map[h][w] == '1')
				mlx_put_image_to_window(sf->mx, sf->win, sf->b, w * 54, h * 63);
			if (sf->map[h][w] == '0')
				mlx_put_image_to_window(sf->mx, sf->win, sf->g, w * 54, h * 63);
			if (sf->map[h][w] == 'C')
				berry_count(sf, h, w);
			if (sf->map[h][w] == 'E')
				mlx_put_image_to_window(sf->mx, sf->win, sf->e, w * 54, h * 63);
			if (sf->map[h][w] == 'P')
				put_picker(sf, h, w);
			w++;
		}
		h++;
	}
}
