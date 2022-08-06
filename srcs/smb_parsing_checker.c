/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_parsing_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:59:16 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/06 15:29:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb_settings.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

static int	check_line_value(char *line, char *set)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isinset(line[i], set))
			return (0);
		i++;
	}
	return (1);
}

static void	clear_gnl_buffer(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

/*
* Check the number of lines and column of the map and character in map
*/
int	check_map_format(char *filename)
{
	int		fd;
	char	*line;
	size_t	size;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (8);
	count = 0;
	line = get_next_line(fd);
	size = ft_strlen(line);
	while (line && size == ft_strlen(line) && check_line_value(line, MAP_SET))
	{
		count ++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	clear_gnl_buffer(fd);
	close(fd);
	if (count != MAP_HEIGHT_TILES || size < MAP_WIDTH_TILES)
		return (6);
	return (0);
}
