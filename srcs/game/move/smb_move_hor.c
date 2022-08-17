/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_move_hor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:46:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 03:26:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdio.h>

static int	apply_speed(t_game *game, t_player *player)
{
	(void)game;
	player->x_acceleration += DECCEL_HOR;
	if (player->x_speed > 0)
	{
		player->x_speed -= player->x_acceleration;
		if (player->x_speed < 0)
			player->x_speed = 0;
	}
	else if (player->x_speed < 0)
	{
		player->x_speed += player->x_acceleration;
		if (player->x_speed > 0)
			player->x_speed = 0;
	}
	return (0);
}

int	update_speed(t_game *game, t_player *player)
{
	(void)game;
	if (player->left == 1)
	{
		player->x_acceleration += ACCEL_HOR;
		player->x_speed -= player->x_acceleration;
		if (player->x_speed < -player->x_max_speed)
			player->x_speed = -player->x_max_speed;
	}
	else if (player->right == 1)
	{
		player->x_acceleration += ACCEL_HOR;
		player->x_speed += player->x_acceleration;
		if (player->x_speed > player->x_max_speed)
			player->x_speed = player->x_max_speed;
	}
	else if (player->x_speed != 0)
		apply_speed(game, player);
	else
		player->x_acceleration = 0;
	return (0);
}

int	apply_hor_movement(t_game *game, t_player *player)
{
	int	i;

	i = 0;
	while (i < game->delay)
	{
		update_speed(game, player);
		if (player->x_speed < 0)
			move_left(game, player);
		if (player->x_speed > 0)
			move_right(game, player);
		i++;
	}
	return (0);
}
