/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:24:40 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/24 12:12:47 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	plot_on_screen(t_fdf a, t_fdf b, int move_x, int move_y)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	ft_printf("a.x = %i\n", a.x);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Test");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		my_mlx_pixel_put(&img, a.x, a.y, 0x00FF0000);
		a.x += move_x;
		a.y += move_y;
		if (a.x > 1000 || a.y > 1000 | a.x < 0 || a.y < 0)
			break ;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

// offset = (y * line_length + x * (bits_per_pixel / 8));
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
