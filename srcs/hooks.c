/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:15:29 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/30 12:56:37 by mpagani          ###   ########lyon.fr   */
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
	else if (keycode == KEY_D)
		global->ISO = !global->ISO;
	else if (keycode == KEY_R || keycode == KEY_E)
		rotate(keycode, global);
	else if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
		shift(keycode, global);
	else if (keycode == KEY_A)
	{
		global->menu_visible = !global->menu_visible;
		show_menu(global);
	}
	mlx_clear_window(global->mlx, global->mlx_win);
	global->data.img = mlx_new_image(global->mlx, WIN_W, WIN_H);
	global->data.addr = mlx_get_data_addr(global->data.img, &global->data
			.bits_per_pixel, &global->data.line_length, &global->data.endian);
	draw_map(global->map, global);
	return (0);
}

int	cross_hooks(void)
{
	exit(0);
	return (0);
}

