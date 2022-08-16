/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_ingame_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:12:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/16 22:30:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

#include "mlx.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

#include <stdio.h>

int	key_pressed_ingame(KeySym keycode, t_game *game)
{
	if (keycode == XK_Right)
	{
		game->player.right = 1;
		if (game->player.left == 1)
		{
			game->player.left += 1;
			game->player.x_acceleration = 0;
		}
	}
	else if (keycode == XK_Left)
	{
		game->player.left = 1;
		if (game->player.right == 1)
		{
			game->player.right += 1;
			game->player.x_acceleration = 0;
		}
	}
	else if (keycode == XK_Down)
		game->player.bottom = 1;
	else if (keycode == XK_Up || keycode == XK_space)
		game->player.top = true;
	else if ((keycode == XK_Up || keycode == XK_space)
		&& game->player.top == false
		&& i_can_move(game, &game->player)
		&& check_collisions_bottom(game, game->player.x_pos,
			game->player.y_pos, game->x_position))
		game->player.y_speed = JUMP_SPEED;
	return (0);
}

int	key_released_ingame(KeySym keycode, t_game *game)
{
	if (keycode == XK_Right)
	{
		if (game->player.left > game->player.right)
			game->player.left -= 1;
		if (game->player.right == 1)
			game->player.x_acceleration = 0;
		game->player.right = 0;
	}
	else if (keycode == XK_Left)
	{
		if (game->player.right > game->player.left)
			game->player.right -= 1;
		if (game->player.left == 1)
			game->player.x_acceleration = 0;
		game->player.left = 0;
	}
	else if (keycode == XK_Down)
		game->player.bottom = 0;
	else if (keycode == XK_Up || keycode == XK_space)
		game->player.top = false;
	else if (keycode == 0x0061)
	{
		game->player.all_player_img = game->all_images.all_big_players;
		game->player.evolution = BIG;
	}
	else if (keycode == 0x007a)
	{
		game->player.all_player_img = game->all_images.all_little_players;
		game->player.evolution = LITTLE;
	}
	if (game->player.right == 0 && game->player.left == 0
		&& game->player.top == 0 && game->player.bottom == 0)
	{
		if (keycode == XK_Escape)
			close_request(game);
	}
	return (0);
}