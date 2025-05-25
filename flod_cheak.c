/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flod_cheak.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:24:02 by anlibrin          #+#    #+#             */
/*   Updated: 2025/03/26 18:36:58 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**new_maps(char **maps)
{
	char	**new;
	int		i;
	int		j;
	int		y;
	int		len;

	(1) && (i = 0, j = 0, y = 0);
	while (maps[i])
		i++;
	len = i;
	i = 0;
	new = malloc((len + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (maps[i] && j < len)
	{
		new[j] = ft_strdup1(maps[i], ft_strlen(maps[0]));
		if (!new[j])
			return (free_array(new), NULL);
		i++;
		j++;
	}
	new[i] = NULL;
	return (new);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

int	*flood_cheak(char **maps)
{
	int		*c;
	char	**new;
	int		m;

	c = cheak_ply(maps);
	new = new_maps(maps);
	if (!new)
	{
		free(c);
		free_array(maps);
		ft_error(1, "Can't allocate memory\n");
	}
	flood_fill(new, c[0], c[1]);
	m = cheak_flood(new, maps);
	if (m == 0)
	{
		free(c);
		free_array(new);
		free_array(maps);
		ft_error(1, "INVALID MAP\n");
	}
	free_array(new);
	return (c);
}

int	cheak_flood(char **new, char **maps)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	(void)maps;
	while (new[i])
	{
		y = 0;
		while (new[i][y])
		{
			if (new[i][y] != '1' && new[i][y] != '0' && new[i][y] != 'V')
			{
				return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}
