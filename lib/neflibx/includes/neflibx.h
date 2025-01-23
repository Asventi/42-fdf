/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neflibx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:36:06 by pjarnac           #+#    #+#             */
/*   Updated: 2024/12/20 20:36:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEFLIBX_H
# define NEFLIBX_H

# include "mlx.h"
# include <inttypes.h>

typedef struct s_display	t_display;

typedef struct s_window
{
	void		*win;
	t_display	*display;
	int			x;
	int			y;
}	t_window;

typedef struct s_display
{
	void		*mlx;
	t_window	**wins;
	int			wins_num;
	int			x;
	int			y;
}	t_display;

typedef struct s_image
{
	t_window	*win;
	void		*img;
	char		*addr;
	int			w;
	int			h;
	int			bpp;
	int			len;
	int			endian;
}	t_image;

typedef struct s_point
{
	int	x;
	int	y;
	int32_t	color;
}	t_point;

// Display management
t_display		*init_display(void);
int				destroy_display(t_display *display);

// Windows management
t_window		*init_window(t_display *display, int x, int y, char *title);
int				destroy_window(t_window *window);
int				destroy_all_windows(t_display *display);

// Colors
int32_t			get_argb(unsigned char a, unsigned char r,
					unsigned char g, unsigned char b);
unsigned char	get_a(int color);
unsigned char	get_r(int color);
unsigned char	get_g(int color);
unsigned char	get_b(int color);

// Image management
t_image			*create_image(t_window *window, int width, int height);
int				put_pixel_img(t_image *image, int x, int y, int32_t color);
int				destroy_image(t_image *image);

// Graphic operations
t_point			point(int x, int y, int32_t color);
int				draw_line(t_point pt1, t_point pt2, t_image *img);

#endif
