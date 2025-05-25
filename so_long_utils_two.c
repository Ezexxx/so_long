/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:41:59 by anlibrin          #+#    #+#             */
/*   Updated: 2025/03/27 02:46:05 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_long *nb)
{
	if (!nb)
		return ;
	nb->mlx = NULL;
	nb->win = NULL;
	nb->map = NULL;
	nb->xpm = NULL;
	nb->p = NULL;
	nb->s = NULL;
	nb->f = NULL;
	nb->c = NULL;
	nb->h = 0;
	nb->w = 0;
	nb->x = 0;
	nb->y = 0;
	nb->new_x = 0;
	nb->new_y = 0;
	nb->i_exit = 0;
	nb->j_exit = 0;
	nb->collect = 0;
	nb->cc = NULL;
}

void	image(t_long *nb)
{
	int	width;
	int	hghit;

	nb->xpm = mlx_xpm_file_to_image(nb->mlx, "textures/walll.xpm", &width,
			&hghit);
	nb->p = mlx_xpm_file_to_image(nb->mlx, "textures/player.xpm", &width,
			&hghit);
	nb->s = mlx_xpm_file_to_image(nb->mlx, "textures/exit.xpm", &width, &hghit);
	nb->f = mlx_xpm_file_to_image(nb->mlx, "textures/floor.xpm", &width,
			&hghit);
	nb->c = mlx_xpm_file_to_image(nb->mlx, "textures/collec.xpm", &width,
			&hghit);
	if (!nb->xpm || !nb->p || !nb->s || !nb->f || !nb->c)
		free_game(nb);
}

static void	put_image_two(char **maps, t_long *nb)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (maps[x])
	{
		y = 0;
		while (maps[x][y])
		{
			if (maps[x][y] == '0')
				mlx_put_image_to_window(nb->mlx, nb->win, nb->f, y * 32, x
					* 32);
			else if (maps[x][y] == 'C')
				mlx_put_image_to_window(nb->mlx, nb->win, nb->c, y * 32, x
					* 32);
			y++;
		}
		x++;
	}
}

void	put_images(char **maps, t_long *nb)
{
	int	x;
	int	y;

	(1) && ((x = 0), (y = 0));
	while (maps[x])
	{
		y = 0;
		while (maps[x][y])
		{
			if (maps[x][y] == '1')
				mlx_put_image_to_window(nb->mlx, nb->win, nb->xpm, y * 32, x
					* 32);
			else if (maps[x][y] == 'P')
				mlx_put_image_to_window(nb->mlx, nb->win, nb->p, y * 32, x
					* 32);
			else if (maps[x][y] == 'E')
				mlx_put_image_to_window(nb->mlx, nb->win, nb->s, y * 32, x
					* 32);
			put_image_two(maps, nb);
			y++;
		}
		x++;
	}
}

void	count_moves(int keycode, t_long *nb)
{
	if ((nb->map[nb->new_x][nb->new_y] != '1' && keycode == UP))
		print();
	else if (nb->map[nb->new_x][nb->new_y] != '1' && keycode == DOWN)
		print();
	else if (nb->map[nb->new_x][nb->new_y] != '1' && keycode == LEFT)
		print();
	else if (nb->map[nb->new_x][nb->new_y] != '1' && keycode == RIGHT)
		print();
}
