/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_fct_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:08:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 19:10:25 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

int	get_final_score(t_player *player)
{
	return (player->end_score
		+ player->coin_score
		+ player->time_score
		+ player->final_score);
}

int	update_player_position(t_game *game, t_object *obj)
{
	if (game->player.x_pos < obj->x - game->x_position)
		game->player.orientation = O_RIGHT;
	else
		game->player.orientation = O_LEFT;
	if (game->player.orientation == O_RIGHT)
		game->player.x_pos = obj->x - game->x_position + 4 - game->player.width;
	else
		game->player.x_pos = obj->x - game->x_position + 4;
	return (0);
}

int	apply_int_collisions(t_game *game, t_object *obj)
{
	t_dict		*flag;

	game->keyreleased_fct = key_released_default;
	game->keypressed_fct = key_pressed_default;
	update_player_position(game, obj);
	game->update_fct = update_end;
	game->player.x_speed = 0;
	game->player.x_acceleration = 0;
	game->player.right = 0;
	game->player.left = 0;
	game->player.end_score = get_end_score(&game->player, obj);
	game->player.time_score = get_time_score(game->map.time);
	game->player.coin_score = get_coin_score(game->player.coins);
	game->player.final_score = get_final_score(&game->player);
	flag = add_obj(FLAG, (obj->x + obj->width / 2) + END_BAR_HBOX,
			obj->y + obj->height - FALG_HEIGHT);
	init_flag(game, (t_object **)&flag->value);
	dict_add_back(&game->map.all_object, flag);
	obj->col_count++;
	return (0);
}
