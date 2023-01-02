/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:28:59 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/02 14:29:36 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_global	*global;

	check_error(argc, argv[1]);
	global = init_mlx();
	read_map(argv[1], global);
	set_default(global);
	draw_map(global->map, global);
	init_hooks(global);
	mlx_loop(global->mlx);
}
