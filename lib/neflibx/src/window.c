/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:33:06 by pjarnac           #+#    #+#             */
/*   Updated: 2024/12/20 21:33:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "neflibx.h"

static t_window	**extend_windows(t_display *display)
{
	int			i;
	t_window	**windows;

	windows = malloc(sizeof (t_window *) * (display->wins_num + 1));
	if (!windows)
		return (NULL);
	i = -1;
	while (++i < display->wins_num)
		windows[i] = display->wins[i];
	if (display->wins_num > 0)
		free(display->wins);
	display->wins_num++;
	return (windows);
}

t_window	*init_window(t_display *display, int x, int y, char *title)
{
	t_window	*window;
	t_window	**windows;

	if (!display)
		return (NULL);
	window = (t_window *)malloc(sizeof (t_window));
	if (!window)
		return (NULL);
	windows = extend_windows(display);
	if (!windows)
		return (free(window), NULL);
	window->win = mlx_new_window(display->mlx, x, y, title);
	if (!window->win)
		return (free(window), free(windows), NULL);
	window->x = x;
	window->y = y;
	window->display = display;
	display->wins = windows;
	display->wins[display->wins_num - 1] = window;
	return (window);
}

int	destroy_window(t_window *window)
{
	int			i;
	int			j;
	t_window	**windows;

	if (window->display->wins_num > 1)
	{
		windows = malloc(sizeof (t_window *) * (window->display->wins_num - 1));
		if (!windows)
			return (-1);
		i = -1;
		j = -1;
		while (++i < window->display->wins_num)
			if (window->display->wins[i] != window)
				windows[++j] = window->display->wins[i];
		free(window->display->wins);
		window->display->wins = windows;
	}
	else
		free(window->display->wins);
	window->display->wins_num--;
	mlx_destroy_window(window->display->mlx, window->win);
	free(window);
	return (0);
}

int	destroy_all_windows(t_display *display)
{
	int		i;

	i = -1;
	while (++i < display->wins_num)
	{
		mlx_destroy_window(display->mlx, display->wins[i]->win);
		free(display->wins[i]);
	}
	free(display->wins);
	display->wins_num = 0;
	display->wins = NULL;
	return (0);
}
