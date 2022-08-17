/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_ingame_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:12:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:58:27 by lgiband          ###   ########.fr       */
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
		ingame_right_pressed(game);
	else if (keycode == XK_Left)
		ingame_left_pressed(game);
	else if (keycode == XK_Down)
		ingame_bottom_pressed(game);
	else if (keycode == XK_Up || keycode == XK_space)
		ingame_top_pressed(game);
	return (0);
}

int	key_released_ingame(KeySym keycode, t_game *game)
{
	if (keycode == XK_Right)
		ingame_right_released(game);
	else if (keycode == XK_Left)
		ingame_left_released(game);
	else if (keycode == XK_Down)
		ingame_bottom_released(game);
	else if (keycode == XK_Up || keycode == XK_space)
		ingame_top_released(game);
	else if (keycode == XK_Escape)
		ingame_escape_released(game);
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
	return (0);
}
