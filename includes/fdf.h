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

# include "neflibx.h"

typedef struct s_data
{
	t_display	*display;
	t_window	*win;
	t_image		*img;
}	t_data;

#endif
