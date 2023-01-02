/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:47:12 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/02 12:32:38 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_all(t_fdf **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return ;
}

int	check_error(int argc, char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (argc != 2)
	{
		if (argc < 2)
			ft_printf("Hey, please specify which map to open ! > ./maps/...");
		if (argc > 2)
			ft_printf("Hey, you wrote too many arguments !");
		exit(1);
	}
	else if (fd == -1 || read(fd, 0, 0) < 0)
	{
		ft_printf("Hey, this is not a valid map. I can't open it !");
		exit (1);
	}
	close(fd);
	return (1);
}

int	check_fd_error(int fd)
{
	if (fd == -1 || read(fd, 0, 0) < 0)
		exit (1);
	return (1);
}
