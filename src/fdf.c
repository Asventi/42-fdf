/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:40:03 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/10 13:40:03 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <X11/X.h>

#include "utils.h"
#include "neflibx.h"
#include "mlx.h"

void	clean_data(t_data *data)
{
	mlx_loop_end(data->display->mlx);
	destroy_image(data->img);
	destroy_all_windows(data->display);
	destroy_display(data->display);
	exit(EXIT_SUCCESS);
}

void	init(t_data *data, int x, int y)
{
	data->display = init_display();
	if (!data->display)
		exit_error("Display initialisation error", 0);
	data->win = init_window(data->display, x, y, "FdF");
	if (!data->win)
	{
		destroy_display(data->display);
		exit_error("Window creation error", 0);
	}
	data->img = create_image(data->win, x, y);
	if (!data->img)
	{
		destroy_all_windows(data->display);
		destroy_display(data->display);
		exit_error("Image creation error", 0);
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		clean_data(data);
	}
	return (0);
}

int	cross_close(t_data *data)
{
	clean_data(data);
	return (0);
}

int	main(int c, char **args)
{
	t_data		data;

	data.h = 0;
	data.tab2d = 0;
	parse(&data, args[1]);
	init(&data, 1920, 1080);
	mlx_hook(data.win->win, KeyPress, KeyPressMask, key_hook, &data);
	mlx_hook(data.win->win, DestroyNotify, StructureNotifyMask, cross_close, &data);
	mlx_loop(data.display->mlx);
	clean_data(&data);
}