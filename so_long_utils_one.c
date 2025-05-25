/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:53:58 by anlibrin          #+#    #+#             */
/*   Updated: 2025/03/29 01:12:58 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/usr/include/minilibx-linux/mlx.h"
#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int	free_game(t_long *nb)
{
	if (nb->c)
		mlx_destroy_image(nb->mlx, nb->c);
	if (nb->p)
		mlx_destroy_image(nb->mlx, nb->p);
	if (nb->f)
		mlx_destroy_image(nb->mlx, nb->f);
	if (nb->s)
		mlx_destroy_image(nb->mlx, nb->s);
	if (nb->xpm)
		mlx_destroy_image(nb->mlx, nb->xpm);
	if (nb->win)
		mlx_destroy_window(nb->mlx, nb->win);
	if (nb->mlx)
		mlx_destroy_display(nb->mlx);
	if (nb->mlx)
		free(nb->mlx);
	if (nb->map)
		free_array(nb->map);
	free(nb->cc);
	free(nb);
	exit(0);
	return (0);
}

void	calcul_window(char **maps, t_long *nb, int *c)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (maps[height])
		height++;
	while (maps[0][width])
		width++;
	nb->h = height;
	nb->w = width;
	nb->x = c[0];
	nb->y = c[1];
}

void	print(void)
{
	static int	i;

	if (i != 2147483647)
		i++;
	write(1, "Move :  ", 8);
	ft_putnbr(i);
	ft_putchar('\n');
}
