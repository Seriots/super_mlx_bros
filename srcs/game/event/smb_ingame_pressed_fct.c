/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_ingame_pressed_fct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:34:04 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:41:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

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
