/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheaks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:09:31 by anlibrin          #+#    #+#             */
/*   Updated: 2025/03/29 01:36:53 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cheak_walls_res(char **str, int i, int len)
{
	i--;
	len = 0;
	while (str[i][len])
	{
		if (str[i][len] != '1')
			ft_exit(NULL, str);
		len++;
	}
}

static void	cheak_walls(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(str[i]);
	while (str[i][j])
	{
		if (str[i][j] != '1')
			ft_exit(NULL, str);
		j++;
	}
	i++;
	while (str[i])
	{
		if (str[i][0] != '1' || str[i][len - 1] != '1')
			ft_exit(NULL, str);
		i++;
	}
	cheak_walls_res(str, i, len);
}

void	cheak_invalid(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '\n')
		ft_exit(num, NULL);
	while (num[i])
	{
		if (num[i] != '1' && num[i] != '0' && num[i] != 'C' && num[i] != 'E'
			&& num[i] != 'P' && num[i] != '\n')
		{
			ft_exit(num, NULL);
		}
		else if (num[i] == '\n')
		{
			if (num[i + 1] == '\n' || num[i + 1] == '\0')
				ft_exit(num, NULL);
		}
		i++;
	}
}

static void	cheak_rectangle(char **str)
{
	int	i;
	int	j;
	int	count;
	int	c;

	i = 0;
	j = 0;
	count = 0;
	while (str[i][j])
	{
		count++;
		j++;
	}
	i++;
	while (str[i])
	{
		c = ft_strlen(str[i]);
		if (c != count)
		{
			ft_exit(NULL, str);
		}
		i++;
	}
}

void	full_cheak(char **maps)
{
	cheak_rectangle(maps);
	cheak_walls(maps);
	cheak_ele(maps);
}
