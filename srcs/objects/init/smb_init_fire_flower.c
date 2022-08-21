/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_fire_flower.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:04:32 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 15:03:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb_settings.h"
#include "smb.h"

#include <stdlib.h>

int	fire_flower_collisions(t_game *game, t_object *obj, int dir)
{
	(void)dir;
	(void)obj;
	if (check_hbox(game, obj, FF_HBOX, FF_HBOX))
		return (0);
	if (game->player.evolution < FIRE)
		growth(game);
	obj->is_visible = 0;
	obj->update_fonction = obj->del_fonction;
	return (0);
}

int	fire_flower_update(t_game *game, t_dict *elem, t_object *obj)
{
	(void)game;
	(void)elem;
	if (obj->y > obj->animation_duration - obj->height)
		obj->y -= FF_SPAWN_SPEED * game->delay;
	else
	{
		obj->y = obj->animation_duration - obj->height;
		obj->update_fonction = 0;
	}
	return (0);
}

int	fire_flower_del(t_game *game, t_dict *elem, t_object *obj)
{
	(void)obj;
	game->player.final_score += 500;
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_fire_flower(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->img = &game->all_images.fire_flower;
	(*obj)->animation_duration = (*obj)->y;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = fire_flower_collisions;
	(*obj)->update_fonction = fire_flower_update;
	(*obj)->del_fonction = fire_flower_del;
}
