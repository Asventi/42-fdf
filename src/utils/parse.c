/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:40:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/10 13:40:16 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fdf.h"
#include "utils.h"
#include "libft.h"

static t_point3	point3(int32_t x, int32_t y, int32_t z, int32_t color)
{
	t_point3	pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	pt.color = color;
	return (pt);
}

static void	realloc_tab(t_data *data)
{
	t_point3	*new;
	int32_t		i;

	new = malloc(sizeof (t_point3) * data->w * (data->h + 1));
	if (!new)
	{
		errno = ENOMEM;
		return ;
	}
	i = -1;
	while (++i < data->w * data->h)
		new[i] = data->map3d[i];
	free(data->map3d);
	data->map3d = new;
}

static int32_t	line_size(char **line)
{
	int32_t	i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}

static void	create_line(t_data *data, char *res)
{
	char	**split;
	int32_t	i;

	split = ft_split(res, ' ');
	if (!split)
		exit_error("Parsing error", ENOMEM, freei(res), freei(data->map3d));
	data->w = line_size(split);
	realloc_tab(data);
	if (errno == ENOMEM)
		exit_error("Parsing error", -1, freei(res),
			free_split(split), freei(data->map3d));
	i = 0;
	while (split[i] != 0)
	{
		data->map3d[data->w * data->h + i] = point3(i, data->h,
				ft_atoi(split[i]), hex_to_color(split[i]));
		i++;
	}
	data->h++;
	free_split(split);
}

void	parse(t_data *data, char *filename)
{
	int32_t	fd;
	char	*res;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(filename, -1);
	res = (char *)1;
	while (res)
	{
		res = get_next_line(fd);
		if (!res && errno == EISDIR)
			exit_error(filename, -1);
		if (res && res[ft_strlen(res) - 1] == '\n')
			res[ft_strlen(res) - 1] = ' ';
		if (!res)
			return ;
		create_line(data, res);
		free(res);
	}
}
