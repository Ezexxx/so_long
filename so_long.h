/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin < anlibrin@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:30:42 by anlibrin          #+#    #+#             */
/*   Updated: 2025/05/25 18:44:54 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307

typedef struct so
{
	int		w;
	int		h;
	int		m;
	char	**map;
	void	*mlx;
	void	*win;
	void	*xpm;
	void	*p;
	void	*s;
	void	*f;
	void	*c;
	int		x;
	int		y;
	int		new_x;
	int		new_y;
	int		*cc;
	int		collect;
	int		i_exit;
	int		j_exit;
	int		n;
}			t_long;
void		free_array(char **str);
char		*get_next_line(int fd);
void		ft_free_array(char *str);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
char		*ft_strchr(char *s, int c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_exit(char *str, char **s);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
int			*cheak_ply(char **map);
int			cheak_ele(char **map);
void		cheak_invalid(char *num);
void		free_array(char **str);
char		*ft_strdup1(const char *s, int len);
char		**new_maps(char **maps);
int			cheak_flood(char **new, char **maps);
int			*flood_cheak_res(char **maps);
int			cheak_path(char *av);
char		*read_maps(int fd);
int			*flood_cheak(char **maps);
void		full_cheak(char **maps);
int			move_player(int keycode, t_long *nb);
int			free_game(t_long *nb);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		calcul_window(char **maps, t_long *nb, int *c);
void		initialize(t_long *nb);
void		print(void);
void		image(t_long *nb);
void		put_images(char **maps, t_long *nb);
void		count_moves(int keycode, t_long *nb);
void		collect_exit(t_long *nb);
void		ft_error(int flag, char *s);
int			collec_count(t_long *nb);
void		ft_exit(char *str, char **s);
#endif
