/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:08:55 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/21 08:08:55 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "fdf.h"
#include "mlx.h"
#include "neflibx.h"
#include "rendering.h"
#include "math.h"
#include "utils.h"

static double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

static int	create_pt(t_data *data, int x, int y, t_point *pt)
{
	double	xd;
	double	yd;
	double	z;

	z = data->map3d[y * data->w + x].z * data->zspace;
	pt->color = data->map3d[y * data->w + x].color;
	xd = (cos(data->rad) * (x - data->w / 2)
			- sin(data->rad) * (y - data->h / 2)) + data->w / 2;
	yd = (sin(data->rad) * (x - data->w / 2)
			+ cos(data->rad) * (y - data->h / 2)) + data->h / 2;
	xd = xd * data->space + data->mx;
	yd = yd * data->space + data->my;
	xd = xd + yd * cos(deg_to_rad(120)) + z * cos(-deg_to_rad(120));
	yd = yd * sin(deg_to_rad(120)) + z * sin(-deg_to_rad(120));
	pt->x = (int32_t)xd;
	pt->y = (int32_t)yd;
	if (pt->x < 0 || pt->x >= data->win->x)
		return (-1);
	if (pt->y < 0 || pt->y >= data->win->y)
		return (-1);
	return (0);
}

static void	draw_neighbors(t_data *data, int x, int y)
{
	t_point	ptr;
	t_point	ptu;
	t_point	ptl;

	if (create_pt(data, x, y, &ptr) != 0)
		return ;
	if (y > 0)
	{
		if (create_pt(data, x, y - 1, &ptu) == 0)
			draw_line(ptr, ptu, data->img);
	}
	if (x > 0)
	{
		if (create_pt(data, x - 1, y, &ptl) == 0)
			draw_line(ptr, ptl, data->img);
	}
}

int	render(t_data *data)
{
	int32_t	i;
	int32_t	j;

	destroy_image(data->img);
	data->img = create_image(data->win, data->win->x, data->win->y);
	if (!data->img)
	{
		destroy_all_windows(data->display);
		destroy_display(data->display);
		exit_error("Image creation error", 0, freei(data->map3d));
	}
	i = -1;
	while (++i < data->h)
	{
		j = -1;
		while (++j < data->w)
		{
			draw_neighbors(data, j, i);
		}
	}
	mlx_put_image_to_window(data->display->mlx,
		data->win->win, data->img->img, 0, 0);
	return (0);
}
