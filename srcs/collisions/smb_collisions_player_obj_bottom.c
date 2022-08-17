/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_player_obj_bottom.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:27:14 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:28:27 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

#include <math.h>

int	check_collide_bottom(t_game *game, t_dict *all_obj, t_hbox *p_hbox)
{
	t_object	*value;

	(void)game;
	while (all_obj)
	{
		value = (t_object *)all_obj->value;
		if (((value->x > p_hbox->x_min && value->x < p_hbox->x_max)
				|| (value->x + value->width > p_hbox->x_min
					&& value->x + value->width < p_hbox->x_max)
				|| (value->x <= p_hbox->x_min
					&& value->x + value->width >= p_hbox->x_max))
			&& ((value->y > p_hbox->y_min && value->y < p_hbox->y_max)
				|| (value->y + value->height > p_hbox->y_min
					&& value->y + value->height < p_hbox->y_max)
				|| (value->y <= p_hbox->y_min
					&& value->y + value->height >= p_hbox->y_max)))
		{
			if (value->is_strong)
				return (1);
		}
		all_obj = all_obj->next;
	}
	return (0);
}

int	check_col_player_obj_bottom(t_game *game, float x_pos,
	float y_pos, float pos)
{
	t_hbox	p_hbox;

	p_hbox.x_max = max((int)floor(game->player.x_pos + game->x_position
				+ game->player.width),
			(int)floor(x_pos + game->player.width + pos));
	p_hbox.x_min = min((int)floor(game->player.x_pos + game->x_position),
			(int)floor(x_pos + pos));
	p_hbox.y_max = max((int)floor(game->player.y_pos + game->player.height),
			(int)floor(y_pos + game->player.height));
	p_hbox.y_min = min((int)floor(game->player.y_pos), (int)floor(y_pos));
	p_hbox.direction = DOWN;
	return (check_collide_bottom(game, game->map.all_object, &p_hbox));
}
