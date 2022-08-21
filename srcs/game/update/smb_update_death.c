/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_death.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 05:19:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 18:41:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdio.h>

static int	update_death_position(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->delay)
	{
		game->player.y_acceleration += GRAVITY_DOWN;
		if (game->player.y_speed < 0
			&& game->player.y_speed + game->player.y_acceleration > 0)
		{
			game->player.y_speed += game->player.y_acceleration;
			game->player.y_acceleration = 0;
		}
		else
			game->player.y_speed += game->player.y_acceleration;
		if (game->player.y_speed > MAX_DEAD_SPEED)
			game->player.y_speed = MAX_DEAD_SPEED;
		game->player.y_pos += game->player.y_speed;
		i++;
	}
	return (0);
}

int	update_death(t_game *game)
{
	static int	first;

	if (first == 0)
	{
		first = 1;
		game->player.state = DEAD;
		game->player.y_speed = -START_DEAD_SPEED;
		game->player.y_acceleration = 0;
	}
	update_death_position(game);
	update_player_image(game, &game->player);
	if (game->player.y_pos > SCREEN_HEIGHT)
	{
		first = 0;
		close_request(game);
	}
	return (0);
}
