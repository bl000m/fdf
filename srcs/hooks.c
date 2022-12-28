/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:15:29 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/28 17:26:59 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_hooks(t_global *global)
{
	mlx_hook(global->mlx_win, ON_KEYDOWN, 1L << 0, keybord_hooks, global);
	mlx_hook(global->mlx_win, ON_DESTROY, 1L << 0, cross_hooks, global);
}

int	keybord_hooks(int keycode, t_global *global)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == SPACE)
	{
		set_default(global);
	}
	else if (keycode == PLUS || keycode == MINUS)
		zoom(keycode, global);
	else if (keycode == KEY_I)
		global->ISO = 1;
	else if (keycode == KEY_Z)
		global->ISO = 0;
	mlx_clear_window(global->mlx, global->mlx_win);
	// mlx_destroy_image(global->mlx, global->mlx_win);
	// global->data.img = mlx_new_image(global->mlx, WIN_W, WIN_H);
	// global->data.addr = mlx_get_data_addr(global->data.img, &global->data
	// 		.bits_per_pixel, &global->data.line_length, &global->data.endian);
	draw_map(global->map, global);
	return (0);
}

int	cross_hooks(void)
{
	exit(0);
	return (0);
}

