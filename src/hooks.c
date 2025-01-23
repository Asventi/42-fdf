/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:04:14 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/23 11:04:14 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "rendering.h"

static void	move_hook(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->my -= MOVE_INC;
	else if (keycode == XK_s)
		data->my += MOVE_INC;
	else if (keycode == XK_a)
		data->mx -= MOVE_INC;
	else
		data->mx += MOVE_INC;
	render(data);
}

static void	rotate_hook(int keycode, t_data *data)
{
	if (keycode == XK_Right)
		data->rad += ROTATE_INC;
	else
		data->rad -= ROTATE_INC;
	render(data);
}

static void	zoom_hook(int keycode, t_data *data)
{
	if (keycode == XK_r)
		data->space *= 1 + ZOOM_INC;
	else
		data->space *= 1 - ZOOM_INC;
	render(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		clean_data(data);
	if (keycode == XK_w || keycode == XK_d
		|| keycode == XK_s || keycode == XK_a)
		move_hook(keycode, data);
	else if (keycode == XK_Right || keycode == XK_Left)
		rotate_hook(keycode, data);
	else if (keycode == XK_r || keycode == XK_f)
		zoom_hook(keycode, data);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (code == 4)
	{
		data->zspace += ZSPACE_INC;
		render(data);
	}
	else if (code == 5)
	{
		data->zspace -= ZSPACE_INC;
		render(data);
	}
	return (0);
}
