/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_point_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:40:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/22 13:02:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdlib.h>

int	point_image_update(t_game *game, t_dict *elem, t_object *obj)
{
	int	i;

	(void)elem;
	i = 0;
	while (i < game->delay)
	{
		obj->y_acceleration += PTS_GRAVITY;
		obj->y_speed += obj->y_acceleration;
		obj->y += obj->y_speed;
		if (obj->y_speed > 0)
		{
			obj->update_fonction = obj->del_fonction;
			break ;
		}
		i++;
	}
	return (0);
}

int	point_image_del(t_game *game, t_dict *elem, t_object *obj)
{
	(void)obj;
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_point(t_game *game, t_object **obj, int image)
{
	(*obj)->all_img = game->all_images.all_points;
	(*obj)->img = &(*obj)->all_img[image];
	(*obj)->width = (*obj)->img->width;
	(*obj)->height = (*obj)->img->height;
	(*obj)->is_collide = 0;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = 0;
	(*obj)->update_fonction = point_image_update;
	(*obj)->del_fonction = point_image_del;
	(*obj)->y_speed = -PTS_Y_SPEED;
	(*obj)->x_speed = 0;
}

int	init_point_image(t_game *game, t_object *obj, int image, int score)
{
	t_dict		*new;

	new = add_obj(POINT, obj->x, obj->y);
	init_point(game, (t_object **)&new->value, image);
	dict_add_back(&game->map.all_object, new);
	game->player.final_score += score;
	return (0);
}
