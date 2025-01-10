/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:16:06 by pjarnac           #+#    #+#             */
/*   Updated: 2024/12/20 21:16:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "neflibx.h"
#include <stdlib.h>

int	destroy_display(t_display *display)
{
	int	i;

	if (display)
	{
		i = 0;
		while (i < display->wins_num)
		{
			if (display->wins[i])
			{
				mlx_destroy_window(display->mlx, display->wins[i]->win);
				free(display->wins[i]);
			}
			i++;
		}
		if (display->wins_num > 0)
			free(display->wins);
		mlx_destroy_display(display->mlx);
		free(display->mlx);
		free(display);
	}
	return (0);
}

t_display	*init_display(void)
{
	t_display	*display;

	display = (t_display *)malloc(sizeof (t_display));
	if (!display)
		return (0);
	display->mlx = mlx_init();
	if (!display->mlx)
	{
		free(display);
		return (0);
	}
	display->x = 0;
	display->y = 0;
	display->wins_num = 0;
	return (display);
}
