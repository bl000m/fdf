/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:15:29 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/02 12:04:58 by mpagani          ###   ########lyon.fr   */
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
		cross_hooks(global);
	else if (keycode == SPACE)
		set_default(global);
	else if (keycode == PLUS || keycode == MINUS)
		zoom(keycode, global);
	else if (keycode == KEY_D)
		global->iso = !global->iso;
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
	mlx_destroy_image(global->mlx, global->data.img);
	global->data.img = mlx_new_image(global->mlx, WIN_W, WIN_H);
	global->data.addr = mlx_get_data_addr(global->data.img, &global->data
			.bits_per_pixel, &global->data.line_length, &global->data.endian);
	draw_map(global->map, global);
	return (0);
}

int	cross_hooks(t_global *global)
{
	mlx_destroy_image(global->mlx, global->data.img);
	mlx_destroy_window(global->mlx, global->mlx_win);
	free_all(global->map);
	free(global);
	exit(0);
}
