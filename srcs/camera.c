/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:58:56 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/29 15:26:54 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_default(t_global *global)
{
	global->angle = 1.047f;
	// global->zoom = 5;
	global->zoom = (float)lowest(WIN_H / global->y_max,
			WIN_W / global->x_max) / 8;
	global->ISO = 0;
	global->shift_x = WIN_W / 30;
	global->shift_y = WIN_H / 30;
}

void	set_camera(t_fdf *a, t_fdf *b, t_global *global, int *color)
{
	a->x *= global->zoom;
	b->x *= global->zoom;
	a->y *= global->zoom;
	b->y *= global->zoom;
	if (b->z > 0 || a->z > 0)
		*color = 0xfc0345;
	else
		*color = 0xBBFAFF;
	if (b->z != a->z)
		*color = 0xfc031c;
}

void	zoom(int key, t_global *global)
{
	if ((float)global->y_max * global->zoom <= WIN_H / 1.1
		&& (float)global->x_max * global->zoom <= WIN_W / 1.1)
	{
		if (key == PLUS)
			global->zoom *= 1.10;
		if (key == MINUS)
			global->zoom /= 1.10;
	}
	else
	{
		if (key == MINUS)
			global->zoom /= 1.10;
	}
}

void	rotate(int key, t_global *global)
{
	if ((float)global->y_max * global->zoom <= WIN_H / 1.1
		&& (float)global->x_max * global->zoom <= WIN_W / 1.1)
	{
		if (key == KEY_R)
			global->angle += 0.01f;
		if (key == KEY_E)
			global->angle -= 0.01f;
	}
}
