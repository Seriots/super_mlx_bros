/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:44:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/16 01:47:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

#include "mlx.h"

int	update_quit_map(t_game *game)
{
	update_objects(game, game->map.all_object);
	update_movement(game, &game->player);
	update_player_image(game, &game->player);
	if (check_collisions(game, game->player.x_pos + 1, game->player.y_pos, game->x_position)
	|| game->player.x_pos + game->player.width >= SCREEN_WIDTH)
		close_request(game);
	return (0);
}

int	update_end(t_game *game)
{
	t_dict		*search;
	t_object	*flag;
	t_object	*end_bar;

	update_objects(game, game->map.all_object);
	game->player.state = BAR;
	update_player_image(game, &game->player);
	if (!check_collisions_bottom(game, game->player.x_pos, game->player.y_pos + END_BAR_GRAVITY, game->x_position))
		game->player.y_pos += END_BAR_GRAVITY;
	search = dict_getelem_key(game->map.all_object, FLAG);
	if (search)
		flag = (t_object *)search->value;
	search = dict_getelem_key(game->map.all_object, END);
	if (search)
		end_bar = (t_object *)search->value;
	if (flag->y > end_bar->y + FLAG_MARGE)
		return (0);
	game->player.right = 1;
	game->player.left = 0;
	game->player.top = 0;
	game->player.bottom = 0;
	game->player.state = RUN;
	game->player.y_speed = JUMP_SPEED_END;
	game->update_fct = update_quit_map;
	return (0);
}
