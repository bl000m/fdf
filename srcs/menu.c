/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:20:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/30 13:29:17 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
