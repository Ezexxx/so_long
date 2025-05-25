/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 06:33:51 by anlibrin          #+#    #+#             */
/*   Updated: 2025/03/26 18:21:28 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*cheak_ply(char **map)
{
	int	x;
	int	y;
	int	*tab;

	(1) && (x = 0, y = 0);
	tab = malloc(2 * sizeof(int));
	if (!tab)
		return (free_array(map), ft_error(1, "Can't allocate memory\n"), NULL);
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				tab[0] = x;
				tab[1] = y;
				return (tab);
			}
			y++;
		}
		x++;
	}
	return (NULL);
}

int	cheak_ele(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	(1) && ((i = 0), (j = 0), (p = 0), (e = 0), (c = 0));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		ft_exit(NULL, map);
	return (c);
}

void	collect_exit(t_long *nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	nb->collect = collec_count(nb);
	while (nb->map[i])
	{
		j = 0;
		while (nb->map[i][j])
		{
			if (nb->map[i][j] == 'E')
			{
				nb->i_exit = i;
				nb->j_exit = j;
			}
			j++;
		}
		i++;
	}
}
