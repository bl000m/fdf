/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:02:59 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/02 13:17:17 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_global	*init_mlx(void)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	if (!global)
	{
		free(global);
		exit(1);
	}
	global->mlx = mlx_init();
	global->mlx_win = mlx_new_window(global->mlx, WIN_W, WIN_H, "fdf");
	global->data.img = mlx_new_image(global->mlx, WIN_W, WIN_H);
	global->data.addr = mlx_get_data_addr(global->data.img, &global->data
			.bits_per_pixel, &global->data.line_length, &global->data.endian);
	return (global);
}

void	set_default(t_global *global)
{
	global->angle = 1.047f;
	global->zoom = (float)lowest(WIN_H / global->y_max,
			WIN_W / global->x_max) / 4;
	global->iso = 1;
	global->menu_visible = 0;
	global->shift_x = global->x_max / 2;
	global->shift_y = global->y_max / 2;
}

void	set_camera(t_fdf *a, t_fdf *b, t_global *global, int *color)
{
	a->x *= global->zoom;
	b->x *= global->zoom;
	a->y *= global->zoom;
	b->y *= global->zoom;
	a->z *= global->zoom;
	b->z *= global->zoom;
	if (b->z > 0 || a->z > 0)
		*color = ALTITUDE_COLOR;
	else
		*color = FLAT_COLOR;
	if (b->z != a->z)
		*color = CLIMB_COLOR;
}

void	set_vision(t_global *global, t_fdf *a, t_fdf *b)
{
	if (global->iso)
	{
		isometric_projection(global, a);
		isometric_projection(global, b);
	}
	a->x += global->shift_x;
	a->y += global->shift_y;
	b->x += global->shift_x;
	b->y += global->shift_y;
}
