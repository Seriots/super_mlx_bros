/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_plant_piranha.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:12:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 14:13:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb_settings.h"
#include "smb.h"

#include <stdlib.h>

#include <stdio.h>

int	plant_pirahna_collisions(t_game *game, t_dict *elem, t_object *obj, int dir)
{
	(void)dir;
	(void)obj;
	(void)elem;
	if (game->player.x_pos + game->x_position + game->player.width
		< (obj->x + obj->width / 2) - PP_HBOX
		|| game->player.x_pos + game->x_position
		> (obj->x + obj->width / 2) + PP_HBOX
		|| game->player.y_pos + game->player.height
		< (obj->y + obj->height / 2) - PP_HBOX
		|| game->player.y_pos > (obj->y + obj->height / 2) + PP_HBOX)
		return (0);
	if (!game->player.invincible_frame)
		shrink(game);
	return (0);
}

int	plant_pirahna_update(t_game *game, t_dict *elem, t_object *obj)
{
	t_dict		*fireball;
	long int	cur_frame;
	int			image_value;

	(void)game;
	(void)elem;
	cur_frame = (game->current_frame - obj->start_frame)
		% obj->animation_duration;
	image_value = cur_frame / (obj->animation_duration / obj->nb_image);
	if (image_value >= obj->nb_image)
		image_value = obj->nb_image - 1;
	if (image_value == 1 && obj->img != &obj->all_img[image_value])
	{
		fireball = add_obj(FIREBALL, obj->x + 2, obj->y);
		init_fireball(game, (t_object **)&fireball->value);
		dict_add_back(&game->map.all_object, fireball);
	}
	obj->img = &obj->all_img[image_value];
	return (0);
}

void	init_plant_pirahna(t_game *game, t_object **obj)
{
	(*obj)->all_img = game->all_images.all_piranhas;
	(*obj)->img = &game->all_images.all_piranhas[0];
	(*obj)->animation_duration = PP_ANIM_DURATION;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 2;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = plant_pirahna_collisions;
	(*obj)->update_fonction = plant_pirahna_update;
}
