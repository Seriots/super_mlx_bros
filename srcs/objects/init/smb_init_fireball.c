/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_fireball.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:17:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 15:57:07 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb_settings.h"
#include "smb.h"

#include <stdlib.h>

int	fireball_default_collide(t_game *game, t_object *obj, int direction)
{
	(void)direction;
	if (!check_hbox(game, obj, FB_HBOX, FB_HBOX))
		return (0);
	if (!game->player.invincible_frame)
		shrink(game);
	return (0);
}

int	fireball_default_update(t_game *game, t_dict *elem, t_object *obj)
{
	(void)elem;
	update_obj_img(game, obj, 0);
	if (obj->y - FB_SPEED_DEFAULT * game->delay + obj->height < 0
		|| check_collisions_obj(game, obj, obj->x, obj->y
			- FB_SPEED_DEFAULT * game->delay))
		obj->update_fonction = obj->del_fonction;
	else
		obj->y -= FB_SPEED_DEFAULT * game->delay;
	return (0);
}

int	fireball_default_del(t_game *game, t_dict *elem, t_object *obj)
{
	if (obj->col_count != 0)
	{
		obj->start_frame = game->current_frame;
		obj->animation_duration = FB_EXPLOSION_DURATION;
		obj->nb_image = 3;
		obj->is_collide = 0;
		obj->col_count ++;
	}
	update_obj_img(game, obj, 3);
	if (obj->start_frame + FB_EXPLOSION_DURATION < game->current_frame)
		dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_fireball(t_game *game, t_object **obj)
{
	(*obj)->all_img = game->all_images.all_fireballs;
	(*obj)->img = &game->all_images.all_fireballs[0];
	(*obj)->animation_duration = FB_ANIM_DURATION;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 4;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = fireball_default_collide;
	(*obj)->update_fonction = fireball_default_update;
	(*obj)->del_fonction = fireball_default_del;
}
