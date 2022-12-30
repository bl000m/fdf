/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:02:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/30 14:18:33 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
/* issues */
// zoom + still crushing on isometric view
// starting point of isometric view different of parallel
// why point->z / 10 works in iso ? find a variable
// global_zoom. why / 8 ?
void	set_vision(t_global *global, t_fdf *a, t_fdf *b)
{
	if (global->ISO)
	{
		isometric_projection(global, a);
		isometric_projection(global, b);
	}
	a->x += global->shift_x;
	a->y += global->shift_y;
	b->x += global->shift_x;
	b->y += global->shift_y;
}

void	isometric_projection(t_global *global, t_fdf *point)
{
	point->x = (point->x - point->y) * cos(global->angle);
	point->y = (point->x + point->y) * sin(global->angle)
		- (point->z * global->zoom / (float)lowest(WIN_H / global->y_max,
			WIN_W / global->x_max) / 4);
}
