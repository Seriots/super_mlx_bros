/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:40:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/18 07:14:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdio.h>

static int	get_final_score(t_player *player)
{
	return (player->end_score + player->coin_score + player->time_score);
}

static int	update_player_position(t_game *game, t_object *obj)
{
	if (game->player.x_pos + game->player.width < obj->x - game->x_position + 4)
		game->player.orientation = O_RIGHT;
	else
		game->player.orientation = O_LEFT;
	if (game->player.orientation == O_RIGHT)
		game->player.x_pos = obj->x - game->x_position + 4 - game->player.width;
	else
		game->player.x_pos = obj->x - game->x_position + 4;
	return (0);
}

static int	apply_int_collisions(t_game *game, t_object *obj)
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

int	end_collisions(t_game *game, t_dict *elem, t_object *obj, int direction)
{
	(void)elem;
	(void)direction;
	if (game->player.x_pos + game->x_position + game->player.width
		< (obj->x + obj->width / 2) - END_BAR_HBOX
		|| game->player.x_pos + game->x_position
		> (obj->x + obj->width / 2) + END_BAR_HBOX)
		return (0);
	if (obj->col_count == 0)
		apply_int_collisions(game, obj);
	return (0);
}

void	init_end(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->img = &game->all_images.end_bar;
	(*obj)->animation_duration = 0;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = end_collisions;
	(*obj)->update_fonction = 0;
	dict_add_back(&game->map.all_object,
		add_obj(BLOCK, (*obj)->x - 4, (*obj)->y + (*obj)->height));
}
