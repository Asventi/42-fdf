/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:37:07 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/10 14:37:07 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "errno.h"
#include "libft.h"

void	exit_error(char *err, int code)
{
	if (code == 0)
	{
		write(2, err, ft_strlen(err));
	}
	else
	{
		if (code != -1)
			errno = code;
		perror(err);
	}
	exit(EXIT_FAILURE);
}