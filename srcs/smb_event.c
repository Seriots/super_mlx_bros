/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:51:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/06 19:33:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"

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
		game->player.right = true;
	else if (keycode == XK_Left)
		game->player.left = true;
	return (0);
}

int	key_released(KeySym keycode, t_game *game)
{
	if (keycode == XK_Right)
		game->player.right = false;
	else if (keycode == XK_Left)
		game->player.left = false;
	if (game->player.right == false && game->player.left == false
		&& game->player.top == false && game->player.bottom == false)
	{
		if (keycode == XK_Escape)
			close_request(game);
	}
	return (0);
}
