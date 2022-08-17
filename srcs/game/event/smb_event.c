/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:51:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:59:45 by lgiband          ###   ########.fr       */
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

int	key_pressed_default(KeySym keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

int	key_released_default(KeySym keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_request(game);
	return (0);
}

int	key_pressed(KeySym keycode, t_game *game)
{
	if (game->keypressed_fct)
		game->keypressed_fct(keycode, game);
	return (0);
}

int	key_released(KeySym keycode, t_game *game)
{
	if (game->keyreleased_fct)
		game->keyreleased_fct(keycode, game);
	return (0);
}
