/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:17:48 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/15 17:17:48 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdint.h>

static int	is_color(char *str)
{
	while (*str)
	{
		if (*str == 'x')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

static int32_t	get_hex(char c)
{
	int32_t	i;

	i = 0;
	while (i < 16)
	{
		if ("0123456789ABCDEF"[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int32_t	hex_to_color(char *str)
{
	int32_t	res;
	int32_t	len;

	res = 0;
	len = (int32_t)ft_strlen(str);
	if (!is_color(str))
		return (0xFFFFFF);
	while (len > 0 && str[len - 1] != 'x')
	{
		res *= 16;
		res += get_hex(str[len - 1]);
		len--;
	}
	return (res);
}
