/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:08:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 19:08:09 by lgiband          ###   ########.fr       */
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
	if (game->map.map_data[y][x] != '0')
		return (0);
	else if (game->map.map_data[y][x_width] != '0')
		return (0);
	else if (game->map.map_data[y_height][x] != '0')
		return (0);
	else if (game->map.map_data[y_height][x_width] != '0')
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
	return (0);
}
