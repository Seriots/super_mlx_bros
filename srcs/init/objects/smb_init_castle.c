/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_castle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:27:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 16:21:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdlib.h>

int	castle_collisions(t_game *game, t_object *obj, int direction)
{
	(void)direction;
	if (check_hbox(game, obj, CASTLE_HBOX, obj->height / 2))
		return (0);
	close_request(game);
	return (0);
}

int	castle_del(t_game *game, t_dict *elem, t_object *obj)
{
	(void)obj;
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_castle(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->img = &game->all_images.castle;
	(*obj)->animation_duration = 0;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = castle_collisions;
	(*obj)->update_fonction = 0;
	(*obj)->del_fonction = castle_del;
}
