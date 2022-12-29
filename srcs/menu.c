/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:20:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/29 15:14:00 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	show_menu(t_global *global)
{
	char	*option;

	option = "zoom: +/-";
	mlx_string_put(global->mlx, global->mlx_win, 10, 5, 0x03fc35, option);
	option = "default view: SPACE";
	mlx_string_put(global->mlx, global->mlx_win, 10, 35, 0x03fc35, option);
	option = "quit: ESC || (x)";
	mlx_string_put(global->mlx, global->mlx_win, 10, 65, 0x03fc35, option);
	option = "isometric: >> I << || back: >> Q <<";
	mlx_string_put(global->mlx, global->mlx_win, 10, 95, 0x03fc35, option);
}
