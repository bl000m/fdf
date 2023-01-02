/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_features.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:58:56 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/02 11:08:33 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric_projection(t_global *global, t_fdf *point)
{
	point->x = (point->x - point->y) * cos(global->angle);
	point->y = (point->x + point->y) * sin(global->angle)
		- (point->z * global->zoom / (float)lowest(WIN_H / global->y_max,
				WIN_W / global->x_max) / 4);
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

void	show_menu(t_global *global)
{
	char	*option;

	if (global->menu_visible == 0)
	{
		option = "SHOW / HIDE MENU => A ";
		mlx_string_put(global->mlx, global->mlx_win, 10, 5, MENU_C, option);
	}
	else if (global->menu_visible == 1)
	{
		option = "3D / 2D => D ";
		mlx_string_put(global->mlx, global->mlx_win, 10, 5, MENU_C, option);
		option = "zoom => + || -";
		mlx_string_put(global->mlx, global->mlx_win, 10, 35, MENU_C, option);
		option = "rotate => E || R";
		mlx_string_put(global->mlx, global->mlx_win, 10, 65, MENU_C, option);
		option = "default view => SPACE";
		mlx_string_put(global->mlx, global->mlx_win, 10, 95, MENU_C, option);
		option = "move UP | DOWN | LEFT | RIGHT => ARROWS";
		mlx_string_put(global->mlx, global->mlx_win, 10, 125, MENU_C, option);
		option = "quit => ESC || (x)";
		mlx_string_put(global->mlx, global->mlx_win, 10, 155, MENU_C, option);
		option = "hide menu => A";
		mlx_string_put(global->mlx, global->mlx_win, 10, 190, MENU_C, option);
	}
}
