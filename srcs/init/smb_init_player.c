/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:10:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 14:07:14 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "mlx.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

int	init_player_next(t_game *game)
{
	game->player.y_speed = 0.0;
	game->player.y_acceleration = 0.0;
	game->player.x_speed = 0.0;
	game->player.x_acceleration = 0.0;
	game->player.x_max_speed = V_HOR_MAX;
	game->player.coins = 0;
	game->player.state = IDLE;
	game->player.orientation = O_RIGHT;
	game->player.evolution = LITTLE;
	game->player.end_score = 0;
	game->player.time_score = 0;
	game->player.coin_score = 0;
	game->player.final_score = 0;
	game->player.invincible_frame = 0;
	game->player.fireball_frame = 0;
	return (0);
}

int	init_player(t_game *game)
{
	game->player.all_player_img = game->all_images.all_lplyrs;
	game->player.anim_duration = 0;
	game->player.anim_start = 0;
	game->player.anim_length = 1;
	game->player.img_player = game->all_images.all_lplyrs[0];
	game->player.height = game->player.img_player.height;
	game->player.width = game->player.img_player.width;
	game->x_position = game->start.game_x;
	game->player.x_pos = game->start.player_x;
	game->player.y_pos = game->start.player_y;
	game->player.top = false;
	game->player.bottom = false;
	game->player.right = false;
	game->player.left = false;
	return (init_player_next(game));
}
