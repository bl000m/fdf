/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:28:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/28 17:28:12 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_global	*global;

	if (argc != 2)
		ft_printf("please specify which map to open");
	global = init_mlx();
	global->map = malloc(sizeof(global->map));
	if (!global->map)
		free_exit(global);
	global->map = read_map(argv[1], global);
	// set_default(global);
	draw_map(global->map, global);
	mlx_loop(global->mlx);
}

t_global	*init_mlx(void)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	if (!global)
		return (NULL);
	global->mlx = mlx_init();
	global->mlx_win = mlx_new_window(global->mlx, WIN_W, WIN_H, "fdf");
	init_hooks(global);
	global->data.img = mlx_new_image(global->mlx, WIN_W, WIN_H);
	global->data.addr = mlx_get_data_addr(global->data.img, &global->data
			.bits_per_pixel, &global->data.line_length, &global->data.endian);
	return (global);
}
