/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:05:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/07 19:25:58 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

#include <stdio.h>
/*
* Return 1: Collide
* Return 0: No-Collide
*/

static int	check_collisions_player_map(t_game *game, float x_pos, float y_pos, float position)
{
	int	x;
	int	y;
	int	height_tile;
	int	width_tile;
	int	i;
	int	j;
	
	x = (int)floor(x_pos) + (int)floor(position);
	y = (int)floor(y_pos);
	width_tile = ((x + game->player.width - 1) / TILES_SIZE) - (x / TILES_SIZE) + 1;
	height_tile = ((y + game->player.height - 1) / TILES_SIZE) - (y / TILES_SIZE) + 1;
	x = x / TILES_SIZE;
	y = y / TILES_SIZE;
	i = -1;
	while (++i < height_tile)
	{
		j = -1;
		while (++j < width_tile)
		{
			if (game->map.map_data[y + i][x + j] != '0')
				return (1);
		}
	}
	return (0);
}

int	check_collisions_bottom(t_game *game, float x_pos, float y_pos, float position)
{
	int	x;
	int	y;
	int	height_tile;
	int	width_tile;
	int	j;
	
	x = (int)floor(x_pos) + (int)floor(position);
	y = (int)floor(y_pos + 1);
	width_tile = ((x + game->player.width - 1) / TILES_SIZE) - (x / TILES_SIZE) + 1;
	height_tile = ((y + game->player.height - 1) / TILES_SIZE) - (y / TILES_SIZE) + 1;
	x = x / TILES_SIZE;
	y = y / TILES_SIZE;
	j = 0;
	while (j < width_tile)
	{
		if (game->map.map_data[y + height_tile - 1][x + j] != '0')
			return (1);
		j++;
	}
	return (0);
}

int	check_collisions(t_game *game, float x_pos, float y_pos, float position)
{
	if (check_collisions_player_map(game, x_pos, y_pos, position))
		return (1);
	return (0);
}