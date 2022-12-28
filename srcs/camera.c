/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:58:56 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/28 17:21:18 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_default(t_global *global)
{
	global->angle = 0.523599;
	global->zoom = 40;
	global->zoom = lowest(WIN_H / global->y_max, WIN_W / global->x_max);
	global->ISO = 0;
	global->shift_x = WIN_W / 3;
	global->shift_y = WIN_H / 3;
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
	if (key == PLUS)
		global->zoom *= 1.10;
	if (key == MINUS)
		global->zoom *= 0.90;
	draw_map(global->map, global);
}
