/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:26:03 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/23 12:48:36 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <../mlx/mlx.h>
# include <fcntl.h>

typedef struct s_fdf
{
	int				x;
	int				y;
	int				z;
	struct s_fdf	*next;
}	t_fdf;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/* reading _ scanning map */
t_fdf	**read_map(char *file_map);
int		open_file_map(char *file_map);
int		get_values(char *file_map, char c);
int		get_x_max(int fd);
int		get_y_max(int fd);
void	get_points(char *line, int y, t_fdf **values);

/* checking */
int		check_error(int fd);

/* vision */
void	get_mlx(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* utils */
void	add_node_back(t_fdf **node, t_fdf *new);
t_fdf	*node_last(t_fdf *node);
t_fdf	*new_node(int x, int y, int z);
size_t	arr_len(char **str);

/* free things */
t_fdf	**allocate_values(int x_max, int y_max);
void	free_all(t_fdf **result);

/* testing - tb removed */
void	display_z(t_fdf *array[], int x_max, int y_max);
void	draw_circle(t_data *img);

#endif
