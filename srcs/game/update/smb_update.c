/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:08:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 00:04:20 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include "mlx.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

#include <math.h>

#include <stdio.h>

extern int g_end;

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
	apply_hor_movement(game, player);
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

int	is_dead(t_game *game)
{
	if (game->player.state == DEAD || g_end == 1)
		mlx_loop_end(game->mlx.display);
	return (0);
}

int update_timer(t_game *game, long time)
{
	game->map.time = timestamp_sec(time);
	if (game->map.time >= 6000)
		game->map.time = 5999;
	return (0);
}

int	update_ingame(t_game *game)
{
	update_timer(game, game->map.start_time);
	update_objects(game, game->map.all_object);
	update_player_state(game, &game->player);
	update_player_image(game, &game->player);
	update_movement(game, &game->player);
	if (game->player.y_pos > game->map.height)
		game->player.state = DEAD;
	is_dead(game);
	return (0);
}
