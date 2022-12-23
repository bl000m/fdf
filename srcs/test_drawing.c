/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:49:53 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/23 12:52:28 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_circle(t_data *img)
{
	int		x;
	int		xc;
	int		y;
	int		yc;
	int		d;

	x = 0;
	xc = 350;
	y = 100;
	yc = 150;
	d = 3 - 2 * y;
	while (x < y)
	{
		my_mlx_pixel_put(&img, x + xc, y +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, x + xc, -y +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, -x + xc, -y +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, -x + xc, y +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, y + xc, x +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, y + xc, -x +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, -y + xc, -x +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, -y + xc, x +yc, 0x00FF0000);
		if (d <= 0)
		{
			x++;
			d = d + 4 * x + 6;
		}
		else
		{
			x++;
			y--;
			d = d + 4 * (x - y) + 10;
		}
	}
}

void	draw_square(t_data *img)
{
	int		x;
	int		xc;
	int		y;
	int		yc;

	x = 0;
	xc = 350;
	y = 100;
	yc = 150;
	while (x < y)
	{
		my_mlx_pixel_put(&img, x + xc, y +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, x + xc, -y +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, -x + xc, -y +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, -x + xc, y +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, y + xc, x +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, y + xc, -x +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, -y + xc, -x +yc, 0x00FF0000);
		my_mlx_pixel_put(&img, -y + xc, x +yc, 0x00FF0000);
		x++;
	}
}
