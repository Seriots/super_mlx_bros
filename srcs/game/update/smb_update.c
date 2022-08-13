/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:08:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/13 17:04:09 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

#include <math.h>

#include <stdio.h>

int	is_in_map(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width / TILES_SIZE
		|| y < 0 || y >= game->map.height / TILES_SIZE)
		return (0);
	return (1);
}

int	i_can_move(t_game *game, t_player *player)
{
	int	y;
	int	x;
	int	y_height;
	int	x_width;

	y = (int)floor(player->y_pos) / TILES_SIZE;
	x = (int)floor(player->x_pos + game->x_position) / TILES_SIZE;
	y_height = (int)floor(player->y_pos + player->height) / TILES_SIZE;
	x_width = (int)floor(player->x_pos + game->x_position + player->width)
		/ TILES_SIZE;
	if ((int)floor(player->x_pos + game->x_position + player->width)
		% TILES_SIZE == 0)
		x_width -= 1;
	if ((int)floor(player->y_pos + player->height) % TILES_SIZE == 0)
		y_height -= 1;
	if (is_in_map(game, x, y) && game->map.map_data[y][x] != '0')
		return (0);
	if (is_in_map(game, x_width, y) && game->map.map_data[y][x_width] != '0')
		return (0);
	if (is_in_map(game, x, y_height) && game->map.map_data[y_height][x] != '0')
		return (0);
	if (is_in_map(game, x_width, y_height)
		&& game->map.map_data[y_height][x_width] != '0')
		return (0);
	return (1);
}

int	update_movement(t_game *game, t_player *player)
{
	if (!i_can_move(game, player))
		return (1);
	apply_gravity(game, player);
	if (player->left == 1)
		move_left(game, player);
	if (player->right == 1)
		move_right(game, player);
	return (0);
}

int	update_objects(t_game *game, t_dict *all_obj)
{
	t_object	*value;

	while (all_obj)
	{
		value = all_obj->value;
		if (value->update_fonction)
			value->update_fonction(game, all_obj, value);
		all_obj = all_obj->next;
	}
	return (0);
}

int	update(t_game *game)
{
	update_objects(game, game->map.all_object);
	update_movement(game, &game->player);
	if (game->player.y_pos > game->map.height)
		game->player.state = DEAD;
	return (0);
}
