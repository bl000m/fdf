/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:58:56 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/30 14:07:49 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_default(t_global *global)
{
	global->angle = 1.047f;
	global->zoom = (float)lowest(WIN_H / global->y_max,
			WIN_W / global->x_max) / 4;
	global->ISO = 1;
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

void	zoom(int key, t_global *global)
{
	if (key == PLUS)
		global->zoom *= 1.10;
	if (key == MINUS)
		global->zoom /= 1.10;
}

void	rotate(int key, t_global *global)
{
	if (key == KEY_R)
		global->angle += 0.01f;
	if (key == KEY_E)
		global->angle -= 0.01f;
}

void	shift(int key, t_global *global)
{
	if (key == UP)
		global->shift_y -= global->x_max / 2;
	if (key == DOWN)
		global->shift_y += global->x_max / 2;
	if (key == LEFT)
		global->shift_x -= global->x_max / 2;
	if (key == RIGHT)
		global->shift_x += global->x_max / 2;
}
