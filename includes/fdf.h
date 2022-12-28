/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:26:03 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/28 17:06:02 by mpagani          ###   ########lyon.fr   */
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

typedef struct s_fdf
{
	int				x;
	int				y;
	int				z;
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
	int				ISO;
	int				shift_x;
	int				shift_y;
}	t_global;


enum e_events
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

// also : plus 24 minus 27
enum e_keycodes
{
	ESC = 53,
	PLUS = 69,
	MINUS = 78,
	SPACE = 49,
	KEY_I = 34,
	KEY_Z = 90
};

/* reading _ scanning map */
t_fdf		**read_map(char *file_map, t_global *global);
int			open_file_map(char *file_map);
void		create_list(char *file_map, t_global *global, t_fdf **values);
int			get_values(char *file_map, char c);
void		get_size(char *file_map, t_global *global);
int			get_x_max(int fd);
int			get_y_max(int fd);
void		get_points(char *line, int y, t_fdf **values);

/* checking */
int			check_error(int fd);

/* vision */
t_global	*init_mlx(void);
void		set_default(t_global *global);
void		set_camera(t_fdf *a, t_fdf *b, t_global *global, int *color);
void		set_vision(t_global *global, t_fdf *a, t_fdf *b);
void		show_menu(t_global *global);
void		draw_map(t_fdf **map, t_global *global);
void		draw_line(t_fdf a, t_fdf b, t_global *global);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		zoom(int key, t_global *global);
void		isometric_projection(t_global *global, t_fdf *point);
void		rotate_z(t_fdf *a, t_fdf *b, float angle);
/* hooks */
void		init_hooks(t_global *global);
int			keybord_hooks(int keycode, t_global *global);
int			cross_hooks(void);

/* utils */
size_t		arr_len(char **str);
float		highest(float x, float y);
int			lowest(int a, int b);
float		is_neg(float p);
int			ft_words(char const *s, char c);

/* free things */
void		allocate_values(t_fdf **values, t_global *global);
void		free_all(t_fdf **result);
void		free_array(char **array);
void		free_exit(t_global *global);

/* testing - tb removed */
void		display_z(t_fdf *array[], int x_max, int y_max);
void		draw_circle(t_data *img);

#endif
