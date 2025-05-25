/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:31:31 by anlibrin          #+#    #+#             */
/*   Updated: 2025/03/26 02:31:47 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int flag, char *s)
{
	if (flag == 1)
	{
		write(2, "Error\n", 6);
		write(2, s, ft_strlen(s));
		exit(1);
	}
}

static void	cheak_two(char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[j])
		j++;
	if (j == 4)
		ft_error(1, "Invalid Extention\n");
	j--;
	while (i < j)
	{
		if (av[j - 1] == '.' && (av[j] == '.'))
			return ;
		else if ((av[j] == '.') && (av[j - 1] == '/'))
			ft_error(1, "Invalid Extention\n");
		j--;
	}
}

int	cheak_path(char *av)
{
	size_t	m;

	m = ft_strlen(av);
	if (m < 4)
		ft_error(1, "Invalid Extention\n");
	m -= 4;
	if (av[m] != '.')
		ft_error(1, "Invalid Extention\n");
	m++;
	if (av[m] != 'b')
		ft_error(1, "Invalid Extention\n");
	m++;
	if (av[m] != 'e')
		ft_error(1, "Invalid Extention\n");
	m++;
	if (av[m] != 'r')
		ft_error(1, "Invalid Extention\n");
	cheak_two(av);
	return (1);
}

char	*read_maps(int fd)
{
	char	*num;
	char	*str;

	str = NULL;
	if (fd == -1)
		ft_error(1, "INVALID FD\n");
	num = get_next_line(fd);
	if (num == NULL)
		ft_error(1, "INVALID MAPS\n");
	while (num != NULL)
	{
		str = ft_strjoin(str, num);
		if (str == NULL)
		{
			free(num);
			ft_error(1, "Can't allocate memory\n");
		}
		free(num);
		num = get_next_line(fd);
	}
	close(fd);
	return (str);
}
