/* ************************************************************************** */
/*  */
/*  :::	 ::::::::   */
/*   so_long.h	:+:   :+:	:+:   */
/*  +:+ +:+	+:+	*/
/*   By: agraetz <agraetz@student.42.fr>	+#+  +:+	   +#+  */
/*  +#+#+#+#+#+   +#+	*/
/*   Created: 2022/06/02 11:02:06 by anniegraetz	   #+#  #+#	*/
/*   Updated: 2022/06/09 13:34:28 by agraetz	  ###   ########.fr	*/
/*  */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include "mlx.h"

typedef struct Game
{
	char	**map;
	int		map_h;
	int		map_w;

	void	*mx;
	void	*win;

	void	*b;
	void	*g;
	void	*strawb;
	void	*e;
	void	*picker;

	int		locationw;
	int		locationh;
	int		berry;
	int		moves_count;

	int		p_count;
	int		c_count;
	int		e_count;
}	t_game;

int		create_map(t_game *sf, char *path);
void	convert_image(t_game *sf);
void	put_image(t_game *sf);
int		deal_key(int key, t_game *sf);
void	map_check(t_game *sf);
int		exit_game(t_game *sf);

#endif