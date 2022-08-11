/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:51:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 22:54:20 by lgiband          ###   ########.fr       */
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

int	close_request(t_game *game)
{
	mlx_loop_end(game->mlx.display);
	return (0);
}

int	key_pressed(KeySym keycode, t_game *game)
{
	if (keycode == XK_Right)
	{
		game->player.right = 1;
		if (game->player.left == 1)
			game->player.left += 1;
	}
	else if (keycode == XK_Left)
	{
		game->player.left = 1;
		if (game->player.right == 1)
			game->player.right += 1;
	}
	else if ((keycode == XK_Up || keycode == XK_space)
		&& game->player.top == false
		&& i_can_move(game, &game->player)
		&& check_collisions_bottom(game, game->player.x_pos,
			game->player.y_pos + 1, game->x_position))
	{
		game->player.top = true;
		game->player.y_speed = JUMP_SPEED;
	}
	return (0);
}

int	key_released(KeySym keycode, t_game *game)
{
	if (keycode == XK_Right)
	{
		if (game->player.left > game->player.right)
			game->player.left -= 1;
		game->player.right = 0;
	}
	else if (keycode == XK_Left)
	{
		if (game->player.right > game->player.left)
			game->player.right -= 1;
		game->player.left = 0;
	}
	else if (keycode == XK_Up || keycode == XK_space)
		game->player.top = false;
	if (game->player.right == 0 && game->player.left == 0
		&& game->player.top == 0 && game->player.bottom == 0)
	{
		if (keycode == XK_Escape)
			close_request(game);
	}
	return (0);
}
