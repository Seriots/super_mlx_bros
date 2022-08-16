/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_game_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:10:29 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/16 02:58:53 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <sys/time.h>
#include <unistd.h>

#include <stdio.h>

extern int	g_end;

int	fps(t_game *game)
{
	long	new_frame;

	while (timestamp_msec(game->last_time_frame) < 1000 / FPS)
		usleep(1000);
	new_frame = timestamp_msec(0);
	game->delay = new_frame - game->last_time_frame;
	game->last_time_frame = new_frame;
	if (game->current_frame + game->delay < MAX_LONG)
		game->current_frame += game->delay;
	else
		game->current_frame = 0;
	return (0);
}

int	game_loop(t_game *game)
{
	fps(game);
	if (game->update_fct)
		game->update_fct(game);
	if (game->display_fct)
		game->display_fct(game);
	return (0);
}
