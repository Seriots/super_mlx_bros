/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_ingame_pressed_fct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:34:04 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 10:43:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdio.h>

int	ingame_right_pressed(t_game *game)
{
	game->player.right = 1;
	if (game->player.left == 1)
	{
		game->player.left += 1;
		game->player.x_acceleration = 0;
	}
	return (0);
}

int	ingame_left_pressed(t_game *game)
{
	game->player.left = 1;
	if (game->player.right == 1)
	{
		game->player.right += 1;
		game->player.x_acceleration = 0;
	}
	return (0);
}

int	ingame_top_pressed(t_game *game)
{
	game->player.top = true;
	if (i_can_move(game, &game->player)
		&& check_collisions_bottom(game, game->player.x_pos,
			game->player.y_pos, game->x_position))
		game->player.y_speed = JUMP_SPEED;
	return (0);
}

int	ingame_bottom_pressed(t_game *game)
{
	game->player.bottom = 1;
	return (0);
}

int		ingame_fireball_pressed(t_game *game)
{
	t_dict *fireball;
	
	(void)game;
	fireball = add_obj(FIREBALL_PLAYER, game->player.x_pos + game->x_position, game->player.y_pos + game->player.height / 2);
	init_fireball_player(game, (t_object **)&fireball->value);
	dict_add_back(&game->map.all_object, fireball);
	return (0);
}