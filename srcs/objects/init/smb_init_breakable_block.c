/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_breakable_block.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:09:18 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 19:15:14 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb.h"

#include <stdlib.h>

int	breakable_block_collisions(t_game *game, t_object *obj, int direction)
{
	(void)game;
	(void)obj;
	if (!check_hbox(game, obj, BB_HBOX, obj->height / 2)
		|| game->player.y_speed > 0.5 || game->player.state == CROUCH)
		return (0);
	if (direction == UP)
		obj->update_fonction = obj->del_fonction;
	return (0);
}

int	breakable_block_del(t_game *game, t_dict *elem, t_object *obj)
{
	init_break_block(game, obj, BBM_Y_SPEED1, 1);
	init_break_block(game, obj, BBM_Y_SPEED1, 2);
	init_break_block(game, obj, BBM_Y_SPEED2, 3);
	init_break_block(game, obj, BBM_Y_SPEED2, 4);
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_breakable_block(t_game *game, t_object **obj)
{
	(*obj)->all_img = game->all_images.all_breakable_block;
	(*obj)->img = &game->all_images.all_breakable_block[0];
	(*obj)->animation_duration = 0;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 1;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = breakable_block_collisions;
	(*obj)->update_fonction = 0;
	(*obj)->del_fonction = breakable_block_del;
}
