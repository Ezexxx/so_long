/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:32:34 by anlibrin          #+#    #+#             */
/*   Updated: 2025/03/27 03:01:51 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static void	*ft_calloc(size_t num, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(num * size);
	if (s == NULL)
		return (NULL);
	while (i < num * size)
	{
		s[i] = 0;
		i++;
	}
	return ((void *)(s));
}

char	*ft_strdup1(const char *s, int len)
{
	char	*p;
	char	*m;
	int		i;

	m = (char *)s;
	i = 0;
	p = (char *)malloc(len * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (i < len)
	{
		p[i] = m[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	*freesplit(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		len;
	int		big_len;
	int		j;

	big_len = countwords(s, c);
	p = (char **)ft_calloc(big_len + 1, (sizeof(char *)));
	if (!p)
		return (NULL);
	j = 0;
	while (*s && j < big_len)
	{
		len = 0;
		while (*s == c)
			s++;
		while (s[len] != c && s[len])
			len++;
		p[j] = ft_strdup1(s, len);
		if (!p[j])
			return (freesplit(p));
		s += len;
		j++;
	}
	return (p);
}
