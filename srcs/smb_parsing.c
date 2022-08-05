/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:41:28 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 21:05:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG
# define DEBUG 0
#endif

#include "ft.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdlib.h>

#include <stdio.h>
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

int	parsing(int argc, char **argv, t_map *map)
{
	int error;

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
	wall_constructor(map->map_data, MAP_HEIGHT_TILES, convert_plateformer_map);
	if (DEBUG)
		ft_printarray(map->map_data, 0);
	return (0);
}