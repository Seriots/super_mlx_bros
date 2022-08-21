/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_goomba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:05:37 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 19:24:08 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb_settings.h"
#include "smb.h"

#include <stdlib.h>

#include <stdio.h>

int	goomba_del(t_game *game, t_dict *elem, t_object *obj)
{
	if (obj->img != &obj->all_img[2])
	{
		generate_wincoin(game, obj);
		game->player.final_score += 100;
		obj->is_collide = 0;
		obj->start_frame = game->current_frame;
		obj->y += 8;
		obj->height = 8;
		obj->img = &obj->all_img[2];
	}
	if (obj->start_frame + 500 < game->current_frame)
		dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

int	goomba_collisions(t_game *game, t_object *obj, int direction)
{
	(void)direction;
	if (check_hbox(game, obj, GBA_HBOX_X, GBA_HBOX_Y))
		return (0);
	if (game->player.y_pos + game->player.height < obj->y + GBA_HEIGHT_SHRINK)
	{
		obj->update_fonction = obj->del_fonction;
		game->player.y_speed = REJUMP_SPEED;
		game->player.y_acceleration = 0;
	}
	else if (!game->player.invincible_frame
		&& !check_hbox(game, obj, GBA_HBOX_X / 2, GBA_HBOX_Y / 2))
		shrink(game);
	return (0);
}

int	goomba_update(t_game *game, t_dict *elem, t_object *obj)
{
	long int	cur_frame;
	int			image_value;

	(void)game;
	(void)elem;
	cur_frame = (game->current_frame - obj->start_frame)
		% obj->animation_duration;
	image_value = cur_frame / (obj->animation_duration / obj->nb_image);
	if (image_value >= obj->nb_image)
		image_value = obj->nb_image - 1;
	obj->img = &obj->all_img[image_value];
	default_movement(game, obj, GBA_Y_MAX_SPEED);
	if (obj->y > SCREEN_HEIGHT)
		dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_goomba(t_game *game, t_object **obj)
{
	(*obj)->all_img = game->all_images.all_goombas;
	(*obj)->img = &game->all_images.all_goombas[0];
	(*obj)->animation_duration = GBA_ANIM_DURATION;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 2;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = goomba_collisions;
	(*obj)->update_fonction = goomba_update;
	(*obj)->del_fonction = goomba_del;
	(*obj)->y_acceleration = 0.0;
	(*obj)->y_speed = 0.0;
	(*obj)->x_speed = -GBA_X_SPEED;
}
