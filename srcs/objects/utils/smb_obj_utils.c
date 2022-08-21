/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_obj_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:50:21 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 19:05:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

int	update_obj_img(t_game *game, t_object *obj, int start_image)
{
	long int	cur_frame;
	int			image_value;

	cur_frame = (game->current_frame - obj->start_frame)
		% obj->animation_duration;
	image_value = cur_frame / (obj->animation_duration / obj->nb_image);
	if (image_value >= obj->nb_image)
		image_value = obj->nb_image - 1;
	obj->img = &obj->all_img[image_value + start_image];
	obj->width = obj->img->width;
	obj->height = obj->img->height;
	return (0);
}

int	check_hbox(t_game *game, t_object *obj, int x_hbox, int y_hbox)
{
	if (game->player.x_pos + game->x_position + game->player.width
		< (obj->x + obj->width / 2) - x_hbox
		|| game->player.x_pos + game->x_position
		> (obj->x + obj->width / 2) + x_hbox
		|| game->player.y_pos + game->player.height
		< (obj->y + obj->height / 2) - y_hbox
		|| game->player.y_pos > (obj->y + obj->height / 2) + y_hbox)
		return (1);
	return (0);
}

int	generate_wincoin(t_game *game, t_object *obj)
{
	t_dict	*wincoin;

	wincoin = add_obj(COIN, obj->x + ((obj->width - COIN_WIDTH) / 2),
			obj->y - COIN_HEIGHT);
	init_wincoin(game, (t_object **)&wincoin->value);
	dict_add_back(&game->map.all_object, wincoin);
	return (0);
}

int	default_movement(t_game *game, t_object *obj, float max_speed)
{
	int	i;

	i = 0;
	while (i < game->delay)
	{
		apply_gravity_obj(game, obj, max_speed);
		apply_hor_movement_obj(game, obj);
		i++;
	}
	return (0);
}
