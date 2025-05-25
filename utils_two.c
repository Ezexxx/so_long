/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 06:48:48 by anlibrin          #+#    #+#             */
/*   Updated: 2025/03/27 03:04:00 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_array(char *str)
{
	free(str);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_exit(char *str, char **s)
{
	if (str)
		ft_free_array(str);
	if (s)
		free_array(s);
	ft_error(1, "Invalid Map\n");
}
