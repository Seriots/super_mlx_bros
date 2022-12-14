/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_ingame_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:12:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:19:58 by lgiband          ###   ########.fr       */
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
	else if (keycode == XK_e
		&& game->player.evolution == FIRE
		&& game->player.state != CROUCH)
		ingame_fireball_pressed(game);
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
	else if (keycode == XK_j && game->player.evolution < FIRE)
		growth(game);
	else if (keycode == XK_k && game->player.evolution != LITTLE)
		shrink(game);
	return (0);
}
