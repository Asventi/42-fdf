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

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		clean_data(data);
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
