/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_player_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:21:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/09 18:56:43 by lgiband          ###   ########.fr       */
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

int	check_col_left(t_game *game, float x_pos, float pos)
{
	t_collisions	col;

	col.x = (int)ceil(game->player.x_pos + game->x_position);
	col.y = (int)floor(game->player.y_pos);
	col.height = ((col.y + game->player.height - 1) / TILES_SIZE)
		- (col.y / TILES_SIZE) + 1;
	col.width = (((col.x) / TILES_SIZE)
			- (int)floor(x_pos + pos) / TILES_SIZE) + 1;
	col.x = col.x / TILES_SIZE;
	col.y /= TILES_SIZE;
	return (boucle_col_left(col, game));
}

int	check_col_right(t_game *game, float x_pos, float pos)
{
	t_collisions	col;

	col.x = (int)floor(game->player.x_pos + game->x_position);
	col.y = (int)floor(game->player.y_pos);
	col.height = ((col.y + game->player.height - 1) / TILES_SIZE)
		- (col.y / TILES_SIZE) + 1;
	col.width = (((int)ceil(x_pos + pos + game->player.width) / TILES_SIZE
				- col.x / TILES_SIZE)) + 1;
	col.x /= TILES_SIZE;
	col.y /= TILES_SIZE;
	return (boucle_col_right(col, game));
}

int	check_col_up(t_game *game, float y_pos)
{
	t_collisions	col;

	col.x = (int)floor(game->player.x_pos + game->x_position);
	col.y = (int)ceil(game->player.y_pos);
	col.height = (((col.y) / TILES_SIZE)
			- ((int)floor(y_pos) / TILES_SIZE)) + 1;
	col.width = ((col.x + game->player.width - 1) / TILES_SIZE)
		- (col.x / TILES_SIZE) + 1;
	col.x /= TILES_SIZE;
	col.y = col.y / TILES_SIZE;
	return (boucle_col_up(col, game));
}

int	check_col_down(t_game *game, float y_pos)
{
	t_collisions	col;

	col.x = (int)floor(game->player.x_pos) + (int)floor(game->x_position);
	col.y = (int)floor(game->player.y_pos);
	col.height = (((int)ceil(y_pos) + game->player.height)
			/ TILES_SIZE - (col.y) / TILES_SIZE) + 1;
	col.width = ((col.x + game->player.width - 1)
			/ TILES_SIZE) - (col.x / TILES_SIZE) + 1;
	col.x /= TILES_SIZE;
	col.y = (col.y) / TILES_SIZE;
	return (boucle_col_down(col, game));
}

int	check_col_player_map(t_game *game, float x_pos, float y_pos, float pos)
{
	if (game->player.x_pos > x_pos || game->x_position > pos)
		return (check_col_left(game, x_pos, pos));
	else if (game->player.x_pos < x_pos || game->x_position < pos)
		return (check_col_right(game, x_pos, pos));
	else if (game->player.y_pos > y_pos)
		return (check_col_up(game, y_pos));
	else if (game->player.y_pos < y_pos)
		return (check_col_down(game, y_pos));
	else
		return (0);
}
