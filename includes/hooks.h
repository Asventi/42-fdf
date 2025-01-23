/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:04:29 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/23 11:04:29 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <X11/X.h>

# include "fdf.h"

int	key_hook(int keycode, t_data *data);
int	mouse_hook(int code, int x, int y, t_data *data);

#endif
