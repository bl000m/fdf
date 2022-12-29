/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:02:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/29 15:21:52 by mpagani          ###   ########lyon.fr   */
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

	// rotate_z(a, b, global->angle);
	a->x += global->shift_x;
	a->y += global->shift_y;
	b->x += global->shift_x;
	b->y += global->shift_y;
	if (global->ISO)
	{
		isometric_projection(global, a);
		isometric_projection(global, b);
	}
}

void	isometric_projection(t_global *global, t_fdf *point)
{
	point->x = (point->x - point->y) * cos(global->angle);
	point->y = (point->x + point->y) * sin(global->angle) - (point->z / 10);
}

// void	rotate_z(t_fdf *a, t_fdf *b, float angle)
// {
// 	a->x = (a->x * cos(angle)) - (a->y * sin(angle));
// 	a->y = (a->x * sin(angle)) + (a->y * cos(angle));
// 	b->x = (b->x * cos(angle)) - (b->y * sin(angle));
// 	b->y = (b->x * sin(angle)) + (b->y * cos(angle));
// }
