/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_move_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:09:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/07 20:55:44 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

#include <stdio.h>

int	apply_gravity(t_game *game, t_player *player)
{
	if (check_collisions_bottom(game, player->x_pos, player->y_pos, game->x_position) && player->top == false)
	{
		player->y_acceleration = 0;
		player->y_speed = 0;
	}
	else
	{
		/*Acceleration*/
		if (player->y_speed > 0)
			player->y_acceleration += -GRAVITY_UP;
		else
			player->y_acceleration += -GRAVITY_DOWN;
		
		/*Speed*/
		if (player->y_speed > 0 && player->y_speed + player->y_acceleration < 0)
		{
			player->y_speed = 0;
			player->y_acceleration = 0;
		}
		else if (player->y_speed < 0 && player->y_speed + player->y_acceleration < V_DOWN_MAX)
			player->y_speed = V_DOWN_MAX;
		else
			player->y_speed += player->y_acceleration;
		
		/*Position*/
		if (!check_collisions(game, player->x_pos, player->y_pos - player->y_speed, game->x_position))
			player->y_pos -= player->y_speed;
		else
		{
			if (player->y_speed < 0)
			{
				if ((int)floor(player->y_pos) % TILES_SIZE != 0)
					player->y_pos += TILES_SIZE - (int)floor(player->y_pos) % TILES_SIZE;
				if (player->top == true)
				{
					player->y_speed = REJUMP_SPEED;
					player->y_acceleration = 0;
				}
			}
			else
			{
				if ((int)floor(player->y_pos) % TILES_SIZE != 0)
					player->y_pos -= (int)floor(player->y_pos) % TILES_SIZE;
				player->y_speed = 0;
				player->y_acceleration = 0;
			}
			
		}
//		printf("position: %f, speed: %f, acceleration: %f\n", player->y_pos, player->y_speed, player->y_acceleration);		
	}
	return (0);
}
