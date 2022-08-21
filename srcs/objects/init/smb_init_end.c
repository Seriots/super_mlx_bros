/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:40:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 19:10:28 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb.h"

#include <stdlib.h>

int	end_collisions(t_game *game, t_object *obj, int direction)
{
	(void)direction;
	if (check_hbox(game, obj, END_BAR_HBOX, obj->height / 2))
		return (0);
	if (obj->col_count == 0)
		apply_int_collisions(game, obj);
	return (0);
}

int	end_del(t_game *game, t_dict *elem, t_object *obj)
{
	(void)obj;
	dict_delone(&game->map.all_object, elem, 0, free);
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
	(*obj)->del_fonction = end_del;
	dict_add_back(&game->map.all_object,
		add_obj(BLOCK, (*obj)->x - 4, (*obj)->y + (*obj)->height));
}
