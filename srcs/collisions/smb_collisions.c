/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:05:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:51:01 by lgiband          ###   ########.fr       */
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
		if (is_in_map(game, col.x + j, col.y + col.height - 1))
		{
			if (check_col_player_obj_bottom(game, x_pos, y_pos + 1, pos)
				|| game->map.map_data[col.y + col.height - 1][col.x + j] != '0')
				return (1);
		}
		j++;
	}
	return (0);
}

int	check_collisions_bottom_map(t_game *game, float x_pos,
	float y_pos, float pos)
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
		if (is_in_map(game, col.x + j, col.y + col.height - 1))
		{
			if (game->map.map_data[col.y + col.height - 1][col.x + j] != '0')
				return (1);
		}
		j++;
	}
	return (0);
}

int	check_collisions(t_game *game, float x_pos, float y_pos, float position)
{
	int	collide;

	game->collide_obj = (t_collisions){.x = 0, .y = 0, .width = 0, .height = 0};
	collide = check_col_player_map(game, x_pos, y_pos, position);
	if (!collide)
		collide = check_col_player_obj(game, x_pos, y_pos, position);
	else
		check_col_player_obj(game, x_pos, y_pos, position);
	return (collide);
}
