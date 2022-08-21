/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:21:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 18:44:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb.h"
#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"

#include "mlx.h"

#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

#include <stdio.h>

static void	set_image_to_zero(t_game *game)
{
	game->all_images.all_tiles = 0;
	game->all_images.all_coins = 0;
	game->all_images.all_lplyrs = 0;
	game->all_images.all_bplyrs = 0;
	game->all_images.all_fplyrs = 0;
	game->all_images.all_fireballs = 0;
	game->all_images.all_goombas = 0;
	game->all_images.all_piranhas = 0;
	game->all_images.all_characters = 0;
	game->all_images.all_breakable_block = 0;
	game->all_images.sign.img = 0;
	game->all_images.big_tree.img = 0;
	game->all_images.block.img = 0;
	game->all_images.end_bar.img = 0;
	game->all_images.flag.img = 0;
	game->all_images.castle.img = 0;
	game->all_images.fire_flower.img = 0;
	game->all_images.red_champi.img = 0;
	game->all_images.loot_block.img = 0;
	game->all_images.loot_block_use.img = 0;
	game->all_images.crate.img = 0;
}

static void	init_game_variable(t_game *game)
{
	struct timeval	time;
	t_object		*obj;

	game->x_position = 0;
	game->current_frame = 0;
	set_image_to_zero(game);
	game->collide_obj = (t_collisions){.x = 0, .y = 0, .width = 0, .height = 0};
	gettimeofday(&time, 0);
	game->last_time_frame = time.tv_sec * 1000 + time.tv_usec / 1000;
	game->delay = 0;
	obj = dict_getelem_key(game->map.all_object, START)->value;
	game->start.game_x = obj->x - SCREEN_WIDTH / 2;
	if (game->start.game_x < 0)
		game->start.game_x = 0;
	game->start.player_x = obj->x - game->start.game_x;
	game->start.player_y = obj->y;
	game->update_fct = update_ingame;
	game->display_fct = display_ingame;
	game->keypressed_fct = key_pressed_ingame;
	game->keyreleased_fct = key_released_ingame;
	game->map.start_time = timestamp_sec(0);
}

static int	init_objects(t_game *game)
{
	t_dict		*obj;
	t_object	*value;

	obj = game->map.all_object;
	while (obj)
	{
		value = (t_object *)obj->value;
		set_object(game, obj->key, &value);
		obj = obj->next;
	}
	return (0);
}

int	init_game(t_game *game)
{
	int	error;

	game->mlx.display = mlx_init();
	if (!game->mlx.display)
		return (mlx_fail(game), 1);
	game->mlx.window = mlx_new_window(game->mlx.display,
			SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
	if (!game->mlx.window)
		return (window_fail(game), 2);
	error = init_xpm_image(game, &game->background, BACKGROUND_NAME);
	if (error)
		return (background_fail(game), error);
	error = init_image(game, SCREEN_WIDTH, SCREEN_HEIGHT, &game->window_image);
	if (error)
		return (map_image_fail(game), error);
	init_game_variable(game);
	error = init_game_images(game);
	if (error)
		return (all_image_fail(game), error);
	init_objects(game);
	init_player(game);
	return (0);
}
