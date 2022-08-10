/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_move_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:09:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/09 20:37:27 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

#include <stdio.h>

static void	acceleration(t_game *game, t_player *player)
{
	if (player->y_speed > 0)
		player->y_acceleration += (game->delay * -GRAVITY_UP);
	else
		player->y_acceleration += (game->delay * -GRAVITY_DOWN);
}

static void	speed(t_game *game, t_player *player)
{
	if (player->y_speed > 0 && player->y_speed
		+ (player->y_acceleration * game->delay) < 0)
	{
		player->y_speed = 0;
		player->y_acceleration = 0;
	}
	else if (player->y_speed < 0 && player->y_speed
		+ (player->y_acceleration * game->delay) < V_DOWN_MAX)
		player->y_speed = V_DOWN_MAX;
	else
		player->y_speed += (player->y_acceleration * game->delay);
}

static void	position(t_game *game, t_player *player)
{
	if (!check_collisions(game, player->x_pos,
			player->y_pos - (player->y_speed * game->delay), game->x_position))
		player->y_pos -= (player->y_speed * game->delay);
	else
	{
		if (player->y_speed < 0)
		{
			player->y_pos = game->collide_obj.y - player->height;
			player->y_acceleration = 0;
			if (player->top == true)
				player->y_speed = REJUMP_SPEED;
		}
		else
		{
			player->y_pos = game->collide_obj.y + game->collide_obj.height;
			player->y_speed = 0;
			player->y_acceleration = 0;
		}
	}
}

int	apply_gravity(t_game *game, t_player *player)
{
	if (check_collisions_bottom(game, player->x_pos, player->y_pos,
			game->x_position)
		&& player->top == false)
	{
		player->y_acceleration = 0;
		player->y_speed = 0;
	}
	else
	{
		acceleration(game, player);
		speed(game, player);
		position(game, player);
	}
	return (0);
}