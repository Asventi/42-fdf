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

#include "rendering.h"
#include "utils.h"
#include "neflibx.h"
#include "mlx.h"
#include "hooks.h"

static int32_t	get_max_z(t_data *data)
{
	int32_t	max;
	int32_t	y;
	int32_t	x;

	max = abs(data->map3d[0].z);
	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			if (abs(data->map3d[y * data->w + x].z) > max)
				max = abs(data->map3d[y * data->w + x].z);
			x++;
		}
		y++;
	}
	if (max == 0)
		return (1);
	return (max);
}

int	clean_data(t_data *data)
{
	mlx_loop_end(data->display->mlx);
	destroy_image(data->img);
	destroy_all_windows(data->display);
	destroy_display(data->display);
	free(data->map3d);
	exit(EXIT_SUCCESS);
}

static void	init(t_data *data, int32_t x, int32_t y)
{
	data->display = init_display();
	if (!data->display)
		exit_error("Display initialisation error", 0, freei(data->map3d));
	data->win = init_window(data->display, x, y, "FdF");
	if (!data->win)
	{
		destroy_display(data->display);
		exit_error("Window creation error", 0, freei(data->map3d));
	}
	data->img = create_image(data->win, x, y);
	if (!data->img)
	{
		destroy_all_windows(data->display);
		destroy_display(data->display);
		exit_error("Image creation error", 0, freei(data->map3d));
	}
	data->zspace = 700 * (1 / (double)data->w) * (1 / (double)get_max_z(data));
	if (data->zspace < 0.1)
		data->zspace = 0.1;
	data->rad = 0.22;
	data->space = data->win->y * 0.5 / data->h;
	data->mx = (data->win->x - data->w * data->space) / 2 * 1.5;
	data->my = (data->win->y - data->h * data->space) / 2;
}

int	main(int c, char **args)
{
	t_data		data;

	if (c < 2)
		exit(EXIT_SUCCESS);
	data.h = 0;
	data.map3d = 0;
	parse(&data, args[1]);
	init(&data, 1920, 1080);
	mlx_hook(data.win->win, KeyPress, KeyPressMask, key_hook, &data);
	mlx_hook(data.win->win, DestroyNotify, StructureNotifyMask,
		clean_data, &data);
	mlx_hook(data.win->win, ButtonPress, ButtonPressMask, mouse_hook, &data);
	render(&data);
	mlx_loop(data.display->mlx);
	clean_data(&data);
}
