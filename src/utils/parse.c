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

static int32_t	**realloc_tab(int32_t **tab, int32_t size)
{
	int32_t	**new;
	int32_t	i;

	new = malloc(sizeof (int32_t *) * size + 1);
	if (!new)
	{

	}
	i = -1;
	while (++i < size)
		new[i] = tab[i];
	free(tab);
	return (new);
}

static int32_t	line_size(char **line)
{
	int32_t	i;

	i = 0;
	while (line[i] != 0)
	{
		i++;
	}
	return (i);
}

static void	create_line(t_data *data, char *res)
{
	char	**split;

	split = ft_split(res, ' ');
	if (!split)
	{
		free(res);
		exit_error("Parsing error", ENOMEM);
	}

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

		free(res);
	}
}