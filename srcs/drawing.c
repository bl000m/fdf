/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:05:37 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/24 12:14:18 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_fdf a, t_fdf b)
{
	float	move_x;
	float	move_y;
	float	max;

	move_x = b.x - a.x;
	move_y = b.y - a.y;
	max = highest_move(move_x, move_y);
	move_x = move_x / max;
	move_y = move_y / max;
	ft_printf("Before plot_on_screen\n");
	plot_on_screen(a, b, move_x, move_y);
}

void	draw_map(t_fdf **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (1)
		{
			if (map[y + 1])
				draw_line(map[y][x], map[y + 1][x]);
			if (!map[y][x].last)
				draw_line(map[y][x], map[y][x + 1]);
			if (map[y][x].last)
				break ;
			x++;
		}
		y++;
	}
}
