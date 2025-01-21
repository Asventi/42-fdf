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

#include "fdf.h"
#include "mlx.h"
#include "neflibx.h"
#include "rendering.h"
#include "math.h"

static double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

static t_point	create_pt(t_data *data, int x, int y)
{
	t_point	pt;
	double	xd;
	double	yd;
	double	rad;
	double	z;

	rad = data->rad;
	z = data->map3d[y * data->w + x].z * data->zspace;
	pt.color = data->map3d[y * data->w + x].color;
	x = x * data->space + data->mx;
	y = y * data->space + data->my;
	xd = (cos(rad) * (x - data->w / 2) - sin(rad) * (y - data->h / 2)) + data->w / 2;
	yd = (sin(rad) * (x - data->w / 2) + cos(rad) * (y - data->h / 2)) + data->h / 2;
	xd = xd * cos(0) + yd * cos(deg_to_rad(120)) + z * cos(-deg_to_rad(120));
	yd = xd * sin(0) + yd * sin(deg_to_rad(120)) + z * sin(-deg_to_rad(120));
	pt.x = (int32_t)xd;
	pt.y = (int32_t)yd;
	return (pt);
}

static void	draw_neighbors(t_data *data, int x, int y)
{
	t_point	ptr;
	t_point	ptu;
	t_point	ptl;

	ptr = create_pt(data, x, y);
	if (y > 0)
	{
		ptu = create_pt(data, x, y - 1);
		draw_line(ptr, ptu, data->img);
	}
	if (x > 0)
	{
		ptl = create_pt(data, x - 1, y);
		draw_line(ptr, ptl, data->img);
	}
}

int	render(t_data *data)
{
	int	i;
	int	j;

	data->mx = (data->win->x - data->w * data->space) / 2 * 2;
	data->my = (data->win->y - data->h * data->space) / 2;
	destroy_image(data->img);
	data->img = create_image(data->win, data->win->x, data->win->y);
	i = -1;
	while (++i < data->h)
	{
		j = -1;
		while (++j < data->w)
		{
			draw_neighbors(data, j, i);
		}
	}
	// TODO: Optimize image clear
	mlx_put_image_to_window(data->display->mlx, data->win->win, data->img->img, 0, 0);
	return (0);
}
