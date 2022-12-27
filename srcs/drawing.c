/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:05:37 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/27 15:34:25 by mpagani          ###   ########lyon.fr   */
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
}

// error = 2*(delta.y - delta.x)
void	draw_line(t_fdf a, t_fdf b, t_global *global)
{
	float	delta_x;
	float	delta_y;
	float	max;

	delta_x = b.x - a.x;
	delta_y = b.y - a.y;
	max = highest_delta(is_neg(delta_x), is_neg(delta_y));
	delta_x = delta_x / max;
	delta_y = delta_y / max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		my_mlx_pixel_put(&global->data, a.x, a.y, 0x00FF0000);
		a.x += delta_x;
		a.y += delta_y;
		if (a.x > WIN_W || a.y > WIN_H | a.x < 0 || a.y < 0)
			break ;
	}
}

// offset = (y * line_length + x * (bits_per_pixel / 8));
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
