/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:05:37 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/02 14:57:48 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_fdf **map, t_global *global)
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
				draw_line(map[y][x], map[y + 1][x], global);
			if (!map[y][x].last)
				draw_line(map[y][x], map[y][x + 1], global);
			if (map[y][x].last)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(global->mlx,
		global->mlx_win, global->data.img, 0, 0);
	show_menu(global);
}

void	draw_line(t_fdf a, t_fdf b, t_global *global)
{
	float	delta_x;
	float	delta_y;
	float	max;
	int		color;

	set_vision(global, &a, &b);
	set_camera(&a, &b, global, &color);
	delta_x = b.x - a.x;
	delta_y = b.y - a.y;
	max = highest(is_neg(delta_x), is_neg(delta_y));
	delta_x /= max;
	delta_y /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x > WIN_W || a.y > WIN_H || a.x < 0 || a.y < 0)
			break ;
		pixel_on_screen(&global->data, a.x, a.y, color);
		a.x += delta_x;
		a.y += delta_y;
	}
}

void	pixel_on_screen(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
