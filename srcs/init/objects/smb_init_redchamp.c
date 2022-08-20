/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_redchamp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:07:14 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/20 16:42:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb.h"
#include "smb_settings.h"

#include <stdlib.h>

#include <stdio.h>

int	red_champ_collisions(t_game *game, t_object *obj, int dir)
{
	(void)dir;
	if (check_hbox(game, obj, REDC_HBOX, REDC_HBOX))
		return (0);
	if (game->player.evolution == LITTLE)
	{
		if ((game->player.state == CROUCH
				&& check_col_player_map(game, game->player.x_pos,
					game->player.y_pos - 14, game->x_position))
			|| (game->player.state != CROUCH
				&& check_col_player_map(game, game->player.x_pos,
					game->player.y_pos - 8, game->x_position))
			|| (game->player.state == CROUCH
				&& check_col_player_obj(game, game->player.x_pos + game->x_position,
					game->player.y_pos - 14, obj))
			|| (game->player.state != CROUCH
				&& check_col_player_obj(game, game->player.x_pos + game->x_position,
					game->player.y_pos - 8, obj)))
			return (0);
		obj->is_visible = 0;
		obj->update_fonction = obj->del_fonction;
		growth(game);
	}
	else
	{
		obj->is_visible = 0;
		obj->update_fonction = obj->del_fonction;	
	}
	return (0);
}

int	red_champ_update(t_game *game, t_dict *elem, t_object *obj)
{
	(void)elem;
	apply_gravity_obj(game, obj, REDC_Y_MAX_SPEED);
	apply_hor_movement_obj(game, obj);
	if (obj->y > SCREEN_HEIGHT)
		obj->update_fonction = obj->del_fonction;
	return (0);
}

int	red_champ_spawn_update(t_game *game, t_dict *elem, t_object *obj)
{
	(void)game;
	(void)elem;
	if (obj->y > obj->animation_duration - obj->height)
		obj->y -= REDC_SPAWN_SPEED * game->delay;
	else
	{
		obj->y = obj->animation_duration - obj->height;
		obj->update_fonction = red_champ_update;
	}
	return (0);
}

int   red_champ_del(t_game *game, t_dict *elem, t_object *obj)
{
	(void)obj;
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_red_champ(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->img = &game->all_images.red_champi;
	(*obj)->animation_duration = (*obj)->y;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = red_champ_collisions;
	(*obj)->update_fonction = red_champ_spawn_update;
	(*obj)->del_fonction = red_champ_del;
	(*obj)->y_acceleration = 0.0;
	(*obj)->y_speed = 0.0;
	(*obj)->x_speed = REDC_X_SPEED;
}
