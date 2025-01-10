/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:49:18 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/06 10:49:18 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neflibx.h"
#include <stdlib.h>

t_image	*create_image(t_window *window, int width, int height)
{
	t_image			*image;
	void			*img;

	image = malloc(sizeof (t_image));
	if (!image)
		return (NULL);
	img = mlx_new_image(window->display->mlx, width, height);
	if (!img)
		return (free(image), NULL);
	image->img = img;
	image->w = width;
	image->h = height;
	image->win = window;
	image->addr = mlx_get_data_addr(img, &image->bpp,
			&image->len, &image->endian);
	if (!image->addr)
		return (mlx_destroy_image(window->display->mlx, img),
			free(image), NULL);
	return (image);
}

int	put_pixel_img(t_image *image, int x, int y, int color)
{
	int		i;
	char	*dest;

	color = mlx_get_color_value(image->win->display->mlx, color);
	i = 0;
	dest = image->addr + y * image->len + x * (image->bpp / 8);
	while (i < image->bpp / 8)
	{
		if (image->endian == 0)
			*(dest + i) = (char)(color & 0xFF);
		else
			*(dest + image->bpp / 8 - i - 1) = (char)(color & 0xFF);
		color = color >> 8;
		i++;
	}
	return (0);
}

int	destroy_image(t_image *image)
{
	mlx_destroy_image(image->win->display->mlx, image->img);
	free(image);
	return (0);
}