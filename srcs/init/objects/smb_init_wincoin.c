/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_wincoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:32 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:03:58 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb.h"

#include <stdlib.h>

#include <stdio.h>

int	wincoin_update(t_game *game, t_dict *elem, t_object *obj)
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
	if (image_value <= obj->nb_image / 2)
		obj->y -= 2;
	else
		obj->y += 2;
	if (image_value == obj->nb_image - 1)
	{
		game->player.coins ++;
		dict_delone(&game->map.all_object, elem, 0, free);
	}
	return (0);
}

void	init_wincoin(t_game *game, t_object **obj)
{
	(*obj)->all_img = game->all_images.all_coins;
	(*obj)->img = &game->all_images.all_coins[0];
	(*obj)->animation_duration = WINCOIN_ANIM_DURATION;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 0;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = COIN_NUMBER;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = 0;
	(*obj)->update_fonction = wincoin_update;
}
