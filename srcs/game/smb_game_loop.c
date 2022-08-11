/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_game_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:10:29 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 23:18:29 by lgiband          ###   ########.fr       */
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

long	timestamp(long start)
{
	struct timeval	time;
	long			time_value;

	gettimeofday(&time, 0);
	time_value = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_value - start);
}

int	fps(t_game *game)
{
	long	new_frame;

	while (timestamp(game->last_time_frame) < 1000 / FPS)
		usleep(1000);
	new_frame = timestamp(0);
	game->delay = new_frame - game->last_time_frame;
	game->last_time_frame = new_frame;
	if (game->current_frame + game->delay < MAX_LONG)
		game->current_frame += game->delay;
	else
		game->current_frame = 0;
	return (0);
}

int	is_dead(t_game *game)
{
	if (game->player.state == L_DEAD || g_end == 1)
		mlx_loop_end(game->mlx.display);
	return (0);
}

int	game_loop(t_game *game)
{
	fps(game);
	update(game);
	is_dead(game);
	display(game);
	return (0);
}
