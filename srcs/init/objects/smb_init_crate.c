/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_crate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:49:12 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 20:49:39 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"

#include <stdlib.h>

int crate_del(t_game *game, t_dict *elem, t_object *obj)
{
	(void)obj;
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_crate(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->img = &game->all_images.crate;
	(*obj)->animation_duration = 0;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 0;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 1;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = 0;
	(*obj)->update_fonction = 0;
	(*obj)->del_fonction = crate_del;
}
