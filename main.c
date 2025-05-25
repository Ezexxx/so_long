/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:09:55 by anlibrin          #+#    #+#             */
/*   Updated: 2025/05/25 22:40:56 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(t_long *nb)
{
	if (nb->map[nb->new_x][nb->new_y] != '1')
	{
		if (nb->map[nb->x][nb->y] == nb->map[nb->i_exit][nb->j_exit])
			nb->map[nb->x][nb->y] = 'E';
		else
			nb->map[nb->x][nb->y] = '0';
		nb->map[nb->new_x][nb->new_y] = 'P';
		nb->x = nb->new_x;
		nb->y = nb->new_y;
	}
	if ((nb->map[nb->x][nb->y] == nb->map[nb->i_exit][nb->j_exit])
		&& nb->collect == 0)
	{
		print();
		write(1, "YOU WIN!!\n", 10);
		free_game(nb);
	}
	put_images(nb->map, nb);
}

int	collec_count(t_long *nb)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (nb->map[i])
	{
		j = 0;
		while (nb->map[i][j])
		{
			if (nb->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	move_player(int keycode, t_long *nb)
{
	nb->new_x = nb->x;
	nb->new_y = nb->y;
	if (keycode == UP)
		nb->new_x -= 1;
	else if (keycode == DOWN)
		nb->new_x += 1;
	else if (keycode == LEFT)
		nb->new_y -= 1;
	else if (keycode == RIGHT)
		nb->new_y += 1;
	else if (keycode == ESC)
		free_game(nb);
	moves(nb);
	count_moves(keycode, nb);
	collec_count(nb);
	collect_exit(nb);
	return (0);
}
void   pit_image(t_long *nb , char **maps)
{
	int i = 0;
	int j = 0 ;
	while(maps[i])
	{
		j = 0;
		while(maps[i][j])
		{
			if(maps[i][j] == '0')
				mlx_put_image_to_window(nb->mlx,nb->win, nb->f, j*32 , i *32);
			else if(maps[i][j] == '1')
				mlx_put_image_to_window(nb->mlx, nb->win, nb->s, j * 32 , i *32);
			else if(maps[i][j] == 'P')
				mlx_put_image_to_window(nb->mlx, nb->win, nb->p, j * 32 , i *32);
			else if(maps[i][j] == 'E')
				mlx_put_image_to_window(nb->mlx, nb->win, nb->xpm, j * 32 , i *32);
			else if(maps[i][j] == 'C')
				mlx_put_image_to_window(nb->mlx, nb->win, nb->c, j * 32 , i *32);
			j++;
		}
		i++;
	}
}
void putt_image(t_long *nb, char **maps)
{
	int width;
	int hghit;
	nb->f =  mlx_xpm_file_to_image(nb->mlx, "textures/floor.xpm",  &width , &hghit);
	nb->c =  mlx_xpm_file_to_image(nb->mlx, "textures/collec.xpm",  &width , &hghit);
	nb->p =  mlx_xpm_file_to_image(nb->mlx, "textures/player.xpm",  &width , &hghit);
	printf(" play == %p",nb->p);
	nb->s = mlx_xpm_file_to_image(nb->mlx, "textures/walll.xpm", &width , &hghit);
	printf(" play == %p",nb->s);
	nb->xpm = mlx_xpm_file_to_image(nb->mlx, "textures/exit.xpm", &width , &hghit);
	printf(" play == %p",nb->xpm);
	pit_image(nb,maps);
}
int    moves_player(int keycode , t_long *nb)
{
	printf("ss == %d", keycode);
	//if(keycode ==  )
		return 0;
}
void	mlx_fun(char **maps, int *c)
{
	t_long	*nb;

	nb = malloc(sizeof(t_long));
	if (!nb)
	{
		free(c);
		ft_exit(NULL, maps);
	}
	initialize(nb);
	nb->map = maps;
	nb->cc = c;
	calcul_window(maps, nb, c);
	nb->mlx = mlx_init();
	nb->win = mlx_new_window(nb->mlx,nb->w* 32, nb->h* 32 , "so_long");
	putt_image(nb, maps);
	mlx_key_hook(nb->mlx, moves_player , nb);
	mlx_loop(nb->mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	char	**maps;
	int		*c;

	if (ac != 2)
		ft_error(1, "Invalid arguments\n");
	cheak_path(av[1]);
	fd = open(av[1], O_RDONLY);
	str = read_maps(fd);
	cheak_invalid(str);
	maps = ft_split(str, '\n');
	free(str);
	if (!maps)
		return (1);
	full_cheak(maps);
	c = flood_cheak(maps);
	mlx_fun(maps, c);
	free(c);
	free_array(maps);
	return (0);
}
