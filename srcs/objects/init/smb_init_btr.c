/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_btr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:28:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 17:45:12 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdlib.h>

int	btr_collisions(t_game *game, t_object *obj, int direction)
{
	if (obj->col_count == 0 && (direction == LEFT || direction == RIGHT))
	{
		generate_wincoin(game, obj);
		obj->col_count++;
	}
	return (0);
}

int	btr_del(t_game *game, t_dict *elem, t_object *obj)
{
	(void)obj;
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_btr(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->img = &game->all_images.big_tree;
	(*obj)->animation_duration = 0;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = btr_collisions;
	(*obj)->update_fonction = 0;
	(*obj)->del_fonction = btr_del;
}
