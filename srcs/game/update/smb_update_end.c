/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:44:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:27:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

#include "mlx.h"

#include <stdio.h>

int	update_quit_map(t_game *game)
{
	update_objects(game, game->map.all_object);
	update_player_image(game, &game->player);
	update_movement(game, &game->player);
	if (check_collisions(game, game->player.x_pos + 1,
			game->player.y_pos, game->x_position)
		|| game->player.x_pos + game->player.width >= SCREEN_WIDTH)
		close_request(game);
	return (0);
}

static int	update_victory_pose(t_game *game)
{
	update_objects(game, game->map.all_object);
	update_movement(game, &game->player);
	update_player_image(game, &game->player);
	if (check_collisions_bottom(game, game->player.x_pos,
			game->player.y_pos, game->x_position))
	{
		if (game->player.state != VICTORY)
			game->player.anim_frame_start = game->current_frame;
		game->player.state = VICTORY;
		game->player.anim_duration = PLAYER_VICTORY_ANIM_DURATION;
		game->player.right = 0;
	}
	return (0);
}

static int	flag_reach_end(t_game *game)
{
	game->player.right = 1;
	game->player.left = 0;
	game->player.top = 0;
	game->player.bottom = 0;
	game->player.state = UJUMP;
	game->player.x_speed = V_ENDJUMP_MAX;
	game->player.orientation = O_RIGHT;
	game->player.y_speed = JUMP_SPEED_END;
	game->player.x_max_speed = V_ENDJUMP_MAX;
	game->update_fct = update_victory_pose;
	return (0);
}

int	update_end(t_game *game)
{
	t_dict		*search;
	t_object	*flag;
	t_object	*end_bar;

	update_objects(game, game->map.all_object);
	game->player.state = BAR;
	update_player_image(game, &game->player);
	search = dict_getelem_key(game->map.all_object, FLAG);
	if (!search)
		return (0);
	flag = (t_object *)search->value;
	search = dict_getelem_key(game->map.all_object, END);
	if (!search)
		return (0);
	end_bar = (t_object *)search->value;
	if (!check_collisions_bottom(game, game->player.x_pos, game->player.y_pos
			+ END_BAR_GRAVITY * game->delay, game->x_position))
		game->player.y_pos += END_BAR_GRAVITY * game->delay;
	else
		game->player.y_pos = end_bar->y + end_bar->height
			- game->player.height - 1;
	if (!(flag->y > end_bar->y + FLAG_MARGE || !check_collisions_bottom(game,
				game->player.x_pos, game->player.y_pos + 1, game->x_position)))
		flag_reach_end(game);
	return (0);
}
