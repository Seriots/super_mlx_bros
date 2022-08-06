/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_parsing_setter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:27:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/06 15:08:37 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb_struct.h"
#include "smb_settings.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
/*
* Set map struct and return an error code on error
*/
int	set_map(t_map *map, char *filename)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (8);
	map->map_data = ft_calloc(sizeof(char *), MAP_HEIGHT_TILES + 1);
	if (!map->map_data)
		return (close(fd), 9);
	map->height = MAP_HEIGHT_TILES * TILES_SIZE;
	i = 0;
	while (i < MAP_HEIGHT_TILES)
	{
		map->map_data[i] = get_next_line(fd);
		if (!map->map_data[i])
			return (ft_free_tab(map->map_data), close(fd), 9);
		i++;
	}
	map->width = ft_strlen(map->map_data[0]) * TILES_SIZE;
	map->object_data = 0;
	map->map_img = 0;
	return (0);
}
