/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_redchamp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:07:14 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 14:36:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb.h"
#include "smb_settings.h"

#include <stdlib.h>

int	red_champ_collisions(t_game *game, t_dict *elem, t_object *obj, int dir)
{
	(void)dir;
	if (game->player.x_pos + game->x_position + game->player.width
		< (obj->x + obj->width / 2) - REDC_HBOX
		|| game->player.x_pos + game->x_position
		> (obj->x + obj->width / 2) + REDC_HBOX
		|| game->player.y_pos + game->player.height
		< (obj->y + obj->height / 2) - REDC_HBOX
		|| game->player.y_pos > (obj->y + obj->height / 2) + REDC_HBOX)
		return (0);
	if (game->player.evolution == LITTLE)
		growth(game);
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

int	red_champ_update(t_game *game, t_dict *elem, t_object *obj)
{
	apply_gravity_obj(game, obj, REDC_Y_MAX_SPEED);
	apply_hor_movement_obj(game, obj);
	if (obj->y > SCREEN_HEIGHT)
		dict_delone(&game->map.all_object, elem, 0, free);
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
	(*obj)->del_fonction = 0;
	(*obj)->y_acceleration = 0.0;
	(*obj)->y_speed = 0.0;
	(*obj)->x_speed = REDC_X_SPEED;
}
