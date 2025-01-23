/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:46:49 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/10 13:46:49 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define DEFAULT_COLOR 0xFFFFFF
# define ZSPACE_INC 0.35
# define ZOOM_INC 0.008
# define ROTATE_INC 0.04
# define MOVE_INC 20

# include <inttypes.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "neflibx.h"

typedef struct s_point3
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
	int32_t	color;
}	t_point3;

typedef struct s_data
{
	t_display	*display;
	t_window	*win;
	t_image		*img;
	t_point3	*map3d;
	int32_t		w;
	int32_t		h;
	double		space;
	double		mx;
	double		my;
	double		zspace;
	double		rad;
}	t_data;

int		clean_data(t_data *data);
void	parse(t_data *data, char *filename);

#endif
