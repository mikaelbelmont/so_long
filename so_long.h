/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:51 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/22 15:42:45 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32

# endif

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define X_WINBUTTON	17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_keys
{
	int	esc;
	int	a;
	int	w;
	int	s;
	int	d;
}t_keys;

typedef struct s_param
{
	int		x;
	int		y;
}t_param;

typedef struct s_images
{
	void	*img;
	int		width;
	int		height;
	int		count;
	int		n;
	int		x;
	int		y;
	int		speed;
}t_images;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			count;
	int			mvcount;
	char		**mapa;
	int			x_winparam;
	int			y_winparam;

	t_images	collect_img;
	t_images	wall_img;
	t_images	floor_img;
	t_images	exit_img;
	t_images	player_img;
	t_keys		keys;
}t_window;

int			ft_win_event(int keycode, t_window *window);

int			ft_map_prep(t_window *window, char **argv);
char		**ft_mapstr(char **mapa, int fd, int counter);
int			ft_checkmaprec(t_window *window, char **mapa);
int			ft_checkmapclosed(char **mapa);
int			ft_checkmapcomplete(t_window *window, char **mapa);
int			ft_validchar(t_window *window, char **mapa);
void		ft_gameinit(t_window *window);
void		ft_keysinit(t_window *window);
void		ft_mapinit(t_window *window);
void		ft_playerinit(t_window *window, char **mapa);
void		ft_initcollect(t_window *window, char **mapa);
int			ft_work(t_window *window);
void		ft_printmap(t_window *window, char **mapa);
void		ft_delcollect(t_window *window, int i, int j);
void		ft_initexit(t_window *window, char **mapa);
int			ft_startwalking(int key, t_window *window);
int			ft_stopwalking(int key, t_window *window);
int			ft_move(t_window *window);
void		ft_end(t_window *window);
void		ft_movecount(t_window *window);

void		ft_wichside(t_window *window);
void		ft_update_right(t_window *window);
void		ft_update_left(t_window *window);
void		ft_update_up(t_window *window);
void		ft_update_down(t_window *window);

int			ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*get_next_line(int fd);
int			searchn(char *buff);
char		*get_line(char *line, char *buff, int size);
int			checkn(char *buffer);

typedef unsigned long long int		t_ulli;

int			ft_printf(const char *type, ...);
int			ft_found_format(const char *format, int i, va_list *args);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_conv_base(t_ulli n, char *base, t_ulli base_size);
int			ft_putnumber(int n);
int			ft_putui(unsigned int n, char *base, int base_size);
int			ft_putul(unsigned long n);

#endif
