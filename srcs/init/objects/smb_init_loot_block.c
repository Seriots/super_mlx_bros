/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_loot_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:08:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 14:10:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_settings.h"
#include "smb_objects_fonction.h"
#include "smb.h"

#include <stdlib.h>

int	apply_loot_block_collide(t_game *game, t_object *obj)
{
	t_dict	*loot;

	if (game->player.evolution == LITTLE)
	{
		loot = add_obj(RED_CHAMP, obj->x, obj->y);
		init_red_champ(game, (t_object **)&loot->value);
	}
	else
	{
		loot = add_obj(FIRE_FLOWER, obj->x, obj->y);
		init_fire_flower(game, (t_object **)&loot->value);
	}
	dict_add_front(&game->map.all_object, loot);
	obj->img = &game->all_images.loot_block_use;
	obj->col_count = 1;
	return (0);
}

int	loot_block_collisions(t_game *game, t_dict *elem,
	t_object *obj, int direction)
{
	(void)elem;
	if (game->player.x_pos + game->x_position + game->player.width
		< (obj->x + obj->width / 2) - LB_HBOX
		|| game->player.x_pos + game->x_position
		> (obj->x + obj->width / 2) + LB_HBOX)
		return (0);
	if (direction == UP && obj->col_count == 0)
		apply_loot_block_collide(game, obj);
	return (0);
}

void	init_loot_block(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->img = &game->all_images.loot_block;
	(*obj)->animation_duration = 0;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 1;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = loot_block_collisions;
	(*obj)->update_fonction = 0;
}
