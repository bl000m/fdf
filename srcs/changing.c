/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:02:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/28 17:41:25 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_vision(t_global *global, t_fdf *a, t_fdf *b)
{
	// a->x -= global->x_max / 2;
	// a->y -= global->y_max / 2;
	// a->x *= global->zoom;
	// a->y *= global->zoom;
	// b->x -= global->x_max / 2;
	// b->y -= global->y_max / 2;
	// b->x *= global->zoom;
	// b->y *= global->zoom;
	// rotate_z(a, b, global->angle);
	if (global->ISO)
	{
		isometric_projection(global, a);
		isometric_projection(global, b);
	}
	// a->x += global->shift_x;
	// a->y += global->shift_y;
	// b->x += global->shift_x;
	// b->y += global->shift_y;
}

void	isometric_projection(t_global *global, t_fdf *point)
{
	// ft_printf("point->z = %i\n", point->z);
	// point->x += 10;
	// point->y += 10;
	point->x = (point->x - point->y) * cos(global->angle);
	point->y = (point->x + point->y) * sin(global->angle) - point->z;
	// ft_printf("point->x = %i\n", point->x);
	ft_printf("point->y = %i\n", point->y);
}

void	rotate_z(t_fdf *a, t_fdf *b, float angle)
{
	a->x = (a->x * cos(angle)) - (a->y * sin(angle));
	a->y = (a->x * sin(angle)) + (a->y * cos(angle));
	b->x = (b->x * cos(angle)) - (b->y * sin(angle));
	b->y = (b->x * sin(angle)) + (b->y * cos(angle));
}
