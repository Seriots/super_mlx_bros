/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:51:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 01:24:56 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"

#include "mlx.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

int	close_request(t_game *game)
{
	mlx_loop_end(game->mlx.display);
	return (0);
}

int	key_pressed(KeySym keycode, t_game *game)
{
	if (keycode == XK_Right)
		game->x_position += BACKGROUND_SPEED;
	else if (keycode == XK_Left)
		game->x_position -= BACKGROUND_SPEED;
	game->refresh = true;
	return (0);
}
