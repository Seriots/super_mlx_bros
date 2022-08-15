/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:03:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/15 23:31:28 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"

#include <stdio.h>

int	flag_update(t_game *game, t_dict *elem, t_object *obj)
{
	t_object	*bar;
	
	(void)elem;
	bar = dict_getelem_key(game->map.all_object, END)->value;
	if (obj->y > bar->y + FLAG_MARGE)
		obj->y -= END_BAR_GRAVITY;
	return (0);
}

void	init_flag(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->img = &game->all_images.flag;
	(*obj)->animation_duration = 0;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 0;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = 0;
	(*obj)->update_fonction = flag_update;
}
