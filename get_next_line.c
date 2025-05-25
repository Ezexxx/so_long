/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:13:27 by anlibrin          #+#    #+#             */
/*   Updated: 2025/03/25 06:32:58 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_remainder(char *p)
{
	int		j;
	int		i;
	char	*temp;

	j = 0;
	i = 0;
	while (p[j] != '\n' && p[j])
		j++;
	if (p[j] == '\0')
	{
		free(p);
		return (NULL);
	}
	j += 1;
	temp = malloc(ft_strlen(p) - j + 1);
	if (!temp)
		return (NULL);
	while (p[j])
	{
		temp[i++] = p[j++];
	}
	temp[i] = '\0';
	free(p);
	return (temp);
}

static char	*ft_line(char *p)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	if (!p[j])
		return (NULL);
	while (p[j] != '\n' && p[j])
		j++;
	temp = malloc(j + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (p[i] != '\n' && p[i])
	{
		temp[i] = p[i];
		i++;
	}
	if (p[i] == '\n')
	{
		temp[i] = p[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_read(int fd, char *p)
{
	char	*buff;
	ssize_t	bytes;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while ((!ft_strchr(p, '\n')) && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(p);
			return (NULL);
		}
		buff[bytes] = '\0';
		p = ft_strjoin(p, buff);
	}
	free(buff);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	p = ft_read(fd, p);
	if (!p)
		return (NULL);
	line = ft_line(p);
	p = ft_remainder(p);
	return (line);
}
