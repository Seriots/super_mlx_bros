/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:41:28 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/09 18:32:35 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdlib.h>

#include <stdio.h>

#ifndef DEBUG
# define DEBUG 0
#endif

/*
* Map rules:
* -> 45 lines
* -> Map only composed of 0 and 1
* -> Need to be rectangular
* -> Need a 'START' and an 'END'
* -> Need the extension ".map"
*/
static int	check_map_extension(char *arg)
{
	if (!ft_strncmp(arg, MAP_EXTENSION, ft_strlen(MAP_EXTENSION) + 1))
		return (7);
	if (!ft_strncmp(&arg[ft_strlen(arg) - ft_strlen(MAP_EXTENSION_ERROR)],
			MAP_EXTENSION_ERROR, ft_strlen(MAP_EXTENSION_ERROR) + 1))
		return (7);
	if (ft_strncmp(&arg[ft_strlen(arg) - ft_strlen(MAP_EXTENSION)],
			MAP_EXTENSION, ft_strlen(MAP_EXTENSION) + 1))
		return (7);
	return (0);
}

static int	check_obj(t_map *map)
{
	if (!dict_getelem_key(map->all_object, START))
		return (11);
	if (!dict_getelem_key(map->all_object, END))
		return (12);
	return (0);
}

int	parsing(int argc, char **argv, t_map *map)
{
	int	error;

	if (argc != 2)
		return (4);
	error = check_map_extension(argv[argc - 1]);
	if (error)
		return (error);
	error = check_map_format(argv[argc - 1]);
	if (error)
		return (error);
	error = set_map(map, argv[argc - 1]);
	if (error)
		return (error);
	error = check_obj(map);
	if (error)
		return (ft_free_tab(map->map_data),
			dict_clear(map->all_object, 0, free), error);
	wall_constructor(map->map_data, MAP_HEIGHT_TILES, convert_plateformer_map);
	if (DEBUG)
		ft_printarray(map->map_data, 0);
	return (0);
}
