/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:26:03 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/02 13:26:58 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <../mlx/mlx.h>
# include <fcntl.h>
# include <math.h>

# define WIN_H 1080
# define WIN_W 1920
# define MENU_C 0xF7FD04
# define ALTITUDE_COLOR 0x9900F0
# define FLAT_COLOR 0xFFFF00
# define CLIMB_COLOR 0xF900BF

typedef struct s_fdf
{
	float			x;
	float			y;
	float			z;
	int				last;
}	t_fdf;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_data;

typedef struct s_global
{
	void			*mlx;
	void			*mlx_win;
	t_data			data;
	t_fdf			**map;
	int				x_max;
	int				y_max;
	float			zoom;
	float			angle;
	int				iso;
	int				menu_visible;
	int				shift_x;
	int				shift_y;
}	t_global;

enum e_events
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

enum e_keycodes
{
	ESC = 53,
	PLUS = 69,
	MINUS = 78,
	SPACE = 49,
	KEY_A = 0,
	KEY_E = 14,
	KEY_R = 15,
	KEY_D = 2,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123
};

/* map reading and 3D map creating */
void		read_map(char *file_map, t_global *global);
void		create_3d(char *file_map, t_global *global);
void		get_points(char *line, int y, t_fdf **values);

/* map scanning */
int			open_file_map(char *file_map);
int			get_values(char *file_map, char c);
void		get_size(char *file_map, t_global *global);
int			get_x_max(int fd);
int			get_y_max(int fd);

/* map utils */
size_t		arr_len(char **str);
float		highest(float x, float y);
int			lowest(int a, int b);
float		is_neg(float p);
int			ft_words(char const *s, char c);

/* vision drawing */
void		draw_map(t_fdf **map, t_global *global);
void		draw_line(t_fdf a, t_fdf b, t_global *global);
void		pixel_on_screen(t_data *data, int x, int y, int color);

/* vision settings */
t_global	*init_mlx(void);
void		set_default(t_global *global);
void		set_camera(t_fdf *a, t_fdf *b, t_global *global, int *color);
void		set_vision(t_global *global, t_fdf *a, t_fdf *b);

/* vision features */
void		show_menu(t_global *global);
void		isometric_projection(t_global *global, t_fdf *point);
void		zoom(int key, t_global *global);
void		rotate(int key, t_global *global);
void		shift(int key, t_global *global);

/* vision features handling (hooks) */
void		init_hooks(t_global *global);
int			keybord_hooks(int keycode, t_global *global);
int			cross_hooks(t_global *global);

/* memory stuff and checke error */
int			check_error(int argc, char *argv);
int			check_fd_error(int fd);
void		free_all(t_fdf **result);

#endif
