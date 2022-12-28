/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:20:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/28 12:44:39 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	show_menu(t_global *global)
{
	char	*option;

	option = "zoom: +/- || scroll up/down";
	mlx_string_put(global->mlx, global->mlx_win, 10, 5, 0x03fc35, option);
	option = "quit: ESC || (x)";
	mlx_string_put(global->mlx, global->mlx_win, 10, 20, 0x03fc35, option);
}
