/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:26:03 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/27 16:26:03 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <../mlx/mlx.h>
# include <fcntl.h>

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
}	t_global;

typedef struct s_camera
{
	float	zoom;
}	t_camera;

/* reading _ scanning map */
t_fdf	**read_map(char *file_map, t_global *global);
int		open_file_map(char *file_map);
void	create_list(char *file_map, t_global *global, t_fdf **values);
int		get_values(char *file_map, char c);
void	get_size(char *file_map, t_global *global);
int		get_x_max(int fd);
int		get_y_max(int fd);
void	get_points(char *line, int y, t_fdf **values);

/* checking */
int		check_error(int fd);

/* vision */
t_global	*init_mlx(void);
void	draw_map(t_fdf **map, t_global *global);
void	draw_line(t_fdf a, t_fdf b, t_global *global);
// void	plot_on_screen(t_fdf a, t_fdf b, int delta_x, int delta_y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* utils */
size_t	arr_len(char **str);
float	highest_delta(float x, float y);
float	is_neg(float p);
int		ft_words(char const *s, char c);

/* free things */
void	allocate_values(t_fdf **values, t_global *global);
void	free_all(t_fdf **result);
void	free_array(char **array);
void	free_exit(t_global *global);

/* testing - tb removed */
void	display_z(t_fdf *array[], int x_max, int y_max);
void	draw_circle(t_data *img);

#endif
