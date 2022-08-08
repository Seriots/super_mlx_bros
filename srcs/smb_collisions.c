/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:05:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/08 19:56:08 by lgiband          ###   ########.fr       */
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

static int	check_collisions_player_map(t_game *game, float x_pos,
		float y_pos, float position)
{
	t_collisions	col;
	int				i;
	int				j;

	col.x = (int)floor(x_pos) + (int)floor(position);
	col.y = (int)floor(y_pos);
	col.width = ((col.x + game->player.width - 1)
			/ TILES_SIZE) - (col.x / TILES_SIZE) + 1;
	col.height = ((col.y + game->player.height - 1)
			/ TILES_SIZE) - (col.y / TILES_SIZE) + 1;
	col.x /= TILES_SIZE;
	col.y /= TILES_SIZE;
	i = -1;
	while (++i < col.height)
	{
		j = -1;
		while (++j < col.width)
		{
			if (game->map.map_data[col.y + i][col.x + j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE, .height = TILES_SIZE,
						.x = (col.x + j) * TILES_SIZE, .y = (col.y + i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}

int	check_collisions_bottom(t_game *game, float x_pos, float y_pos, float pos)
{
	t_collisions	col;
	int				j;

	col.x = (int)floor(x_pos) + (int)floor(pos);
	col.y = (int)floor(y_pos + 1);
	col.width = ((col.x + game->player.width - 1) / TILES_SIZE)
		- (col.x / TILES_SIZE) + 1;
	col.height = ((col.y + game->player.height - 1) / TILES_SIZE)
		- (col.y / TILES_SIZE) + 1;
	col.x = col.x / TILES_SIZE;
	col.y = col.y / TILES_SIZE;
	j = 0;
	while (j < col.width)
	{
		if (game->map.map_data[col.y + col.height - 1][col.x + j] != '0')
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
