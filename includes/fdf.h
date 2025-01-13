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

# define DEFAULT_COLOR = 0xFFFFFF

# include "neflibx.h"
# include <stdint.h>

typedef struct s_data
{
	t_display	*display;
	t_window	*win;
	t_image		*img;
	int32_t		**tab2d;
	int32_t		w;
	int32_t		h;
}	t_data;

void	parse(t_data *data, char *filename);

#endif
