/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:28:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/26 18:42:31 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_z(t_fdf *array[], int x_max, int y_max)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < y_max)
	{
		while (j < x_max)
		{
			ft_printf("%i(x)", array[i][j].x);
			ft_printf("%i(y)", array[i][j].y);
			ft_printf("%i(z), ", array[i][j].z);
			j++;
		}
		j = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_global	global;

	global.map = malloc(sizeof(*global.map));
	if (!global.map)
		free_exit(&global);
	(void) *argv;
	if (argc == 2)
	{
		get_size(argv[1], &global);
		global.map = read_map(argv[1], &global);
		// init_mlx(&global);
		// draw_map(global.map, &global);
		// mlx_loop(global.mlx);
	}
	else
		ft_printf("please specify the map: ./fdf ./maps/map_name.fdf");
}

void	init_mlx(t_global *global)
{
	ft_printf("in init_mlx\n");
	ft_printf("mlx_init return = %s\n", mlx_init());
	global->mlx = mlx_init();
	if (!global->mlx)
		ft_printf("error in mlx init return\n");
	global->mlx_win = mlx_new_window(global->mlx, WIN_H, WIN_W, "fdf");
	global->data.img = mlx_new_image(global->mlx, WIN_H, WIN_W);
	global->data.addr = mlx_get_data_addr(global->data.img, &global->data
			.bits_per_pixel, &global->data.line_length, &global->data.endian);
}
