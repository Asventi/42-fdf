/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:52:46 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/07 10:52:46 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <neflibx.h>

int	get_argb(unsigned char a, unsigned char r,
						unsigned char g, unsigned char b)
{
	return ((int)a << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

unsigned char	get_a(int color)
{
	return (color >> 24 & 0xFF);
}

unsigned char	get_r(int color)
{
	return (color >> 16 & 0xFF);
}

unsigned char	get_g(int color)
{
	return (color >> 8 & 0xFF);
}

unsigned char	get_b(int color)
{
	return (color & 0xFF);
}