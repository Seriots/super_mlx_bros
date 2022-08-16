/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_castle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:27:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/16 01:38:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdio.h>

int	castle_collisions(t_game *game, t_dict *elem, t_object *obj, int direction)
{
	(void)direction;
	(void)elem;
	if (game->player.x_pos + game->x_position + game->player.width < (obj->x + obj->width / 2) - CASTLE_HBOX
	|| game->player.x_pos + game->x_position > (obj->x + obj->width / 2) + CASTLE_HBOX)
		return (0);
	close_request(game);
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
}