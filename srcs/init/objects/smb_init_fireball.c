/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_fireball.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:17:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/18 05:35:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb_settings.h"
#include "smb.h"

#include <stdlib.h>

#include <stdio.h>

int	fireball_default_collide(t_game *game, t_dict *elem, t_object *obj, int direction)
{
	(void)direction;
	(void)obj;
	(void)game;
	(void)elem;
	if (game->player.x_pos + game->x_position + game->player.width
		< (obj->x + obj->width / 2) - FB_HBOX
		|| game->player.x_pos + game->x_position
		> (obj->x + obj->width / 2) + FB_HBOX
		|| game->player.y_pos + game->player.height
		< (obj->y + obj->height / 2) - FB_HBOX
		|| game->player.y_pos > (obj->y + obj->height / 2) + FB_HBOX)
		return (0);
	if (!game->player.invincible_frame)
		shrink(game);
	return (0);
}

int	fireball_player_update(t_game *game, t_dict *elem, t_object *obj)
{
	(void)game;
	(void)elem;
	(void)obj;
	return (0);
}

int	fireball_default_update(t_game *game, t_dict *elem, t_object *obj)
{
	long int	cur_frame;
	int			image_value;

	cur_frame = (game->current_frame - obj->start_frame)
		% obj->animation_duration;
	image_value = cur_frame / (obj->animation_duration / obj->nb_image);
	if (image_value >= obj->nb_image)
		image_value = obj->nb_image - 1;
	obj->img = &obj->all_img[image_value];
	obj->y -= FB_SPEED_DEFAULT * game->delay;
	if (obj->y + obj->height < 0)
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
}
