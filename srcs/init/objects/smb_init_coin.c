/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_coin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:29:47 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 17:38:11 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"

#include <stdlib.h>

int	coin_collisions(t_game *game, t_object *obj, int direction)
{
	(void)direction;
	(void)obj;
	game->player.coins++;
	obj->update_fonction = obj->del_fonction;
	obj->is_collide = 0;
	return (0);
}

int	coin_update(t_game *game, t_dict *elem, t_object *obj)
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
	return (0);
}

int	coin_del(t_game *game, t_dict *elem, t_object *obj)
{
	(void)obj;
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_coin(t_game *game, t_object **obj)
{
	(*obj)->all_img = game->all_images.all_coins;
	(*obj)->img = &game->all_images.all_coins[0];
	(*obj)->animation_duration = COIN_ANIM_DURATION;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = COIN_NUMBER;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = coin_collisions;
	(*obj)->update_fonction = coin_update;
	(*obj)->del_fonction = coin_del;
}
