/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_player_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:21:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:23:35 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

void	change_image(t_game *game, t_player *player, int value)
{
	int			pre_h;
	int			new_h;

	(void)game;
	pre_h = player->height;
	player->img_player = player->all_player_img[value];
	player->width = player->img_player.width;
	player->height = player->img_player.height;
	new_h = player->height;
	if (pre_h != new_h)
		player->y_pos += (pre_h - new_h);
}

int	update_running_image(t_game *game, t_player *player, int value)
{
	int	cur_frame;
	int	image_value;

	cur_frame = (game->current_frame - player->anim_frame_start)
		% player->anim_duration;
	image_value = 0;
	image_value = cur_frame / (player->anim_duration / player->anim_length);
	if (image_value >= player->anim_length)
		image_value = player->anim_length - 1;
	change_image(game, player, value + image_value);
	return (0);
}

int	update_growth_image(t_game *game, t_player *player, int value)
{
	int	cur_frame;
	int	image_value;

	cur_frame = (game->current_frame - player->anim_frame_start)
		% player->anim_duration;
	image_value = cur_frame / (player->anim_duration / player->anim_length);
	if (image_value >= player->anim_length)
		image_value = player->anim_length - 1;
	if ((game->current_frame - player->anim_frame_start)
		> player->anim_duration)
		game->update_fct = update_ingame;
	else
		change_image(game, player, value + image_value);
	return (0);
}

int	update_victory_image(t_game *game, t_player *player, int value)
{
	if (game->current_frame - player->anim_frame_start > player->anim_duration)
	{
		game->player.x_max_speed = V_END_MAX;
		if (player->state != RUN)
			player->anim_frame_start = game->current_frame;
		player->state = RUN;
		player->anim_duration = PLAYER_RUN_ANIM_SPEED;
		if (player->evolution == LITTLE)
			player->anim_length = 2;
		else
			player->anim_length = 3;
		game->player.right = 1;
		game->player.state = RUN;
		game->update_fct = update_quit_map;
	}
	else
		change_image(game, player, value);
	return (0);
}

int	update_dead_image(t_game *game, t_player *player, int value)
{
	int	cur_frame;
	int	image_value;

	cur_frame = (game->current_frame - player->anim_frame_start)
		% player->anim_duration;
	image_value = cur_frame / (player->anim_duration / player->anim_length);
	change_image(game, player, value + image_value);
	return (0);
}
