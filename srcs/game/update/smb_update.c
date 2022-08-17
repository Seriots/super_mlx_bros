/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:08:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 06:18:02 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include "mlx.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

#include <math.h>

#include <stdio.h>

extern int	g_end;

int	update_movement(t_game *game, t_player *player)
{
	if (!i_can_move(game, player))
		return (1);
	apply_gravity(game, player);
	apply_hor_movement(game, player);
	return (0);
}

int	update_objects(t_game *game, t_dict *all_obj)
{
	t_object	*value;

	while (all_obj)
	{
		value = all_obj->value;
		if (value->update_fonction)
			value->update_fonction(game, all_obj, value);
		all_obj = all_obj->next;
	}
	return (0);
}

int	is_dead(t_game *game)
{
	if (game->player.state == DEAD || g_end == 1)
		mlx_loop_end(game->mlx.display);
	return (0);
}

int	update_timer(t_game *game, long time)
{
	game->map.time = timestamp_sec(time);
	if (game->map.time >= 6000)
		game->map.time = 5999;
	return (0);
}

int	update_ingame(t_game *game)
{
	update_timer(game, game->map.start_time);
	update_objects(game, game->map.all_object);
	update_player_state(game, &game->player);
	update_player_image(game, &game->player);
	update_movement(game, &game->player);
	if (game->player.y_pos > game->map.height)
		game->player.state = DEAD;
	is_dead(game);
	return (0);
}
