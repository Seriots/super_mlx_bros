/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:21:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/08 21:36:46 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb.h"
#include "smb_struct.h"
#include "smb_settings.h"

#include "mlx.h"

#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

static void	init_game_variable(t_game *game)
{
	struct timeval time;

	game->x_position = 0;
	game->all_images.all_tiles = 0;
	gettimeofday(&time, 0);
	game->last_time_frame = time.tv_sec * 1000 + time.tv_usec / 1000;
	game->delay_between_frame = 0; 
}

static int	init_game_images(t_game *game)
{
	int	error;

	error = init_all_tiles(game);
	if (error)
		return (error);
	return (0);
}

static int	init_player(t_game *game)
{
	int	error;

	game->player.all_player_img = 0;
	error = init_xpm_image(game, &game->player.img_player,
			"files/xpm/objects/crate.xpm");
	if (error)
		return (error);
	game->player.height = game->player.img_player.height;
	game->player.width = game->player.img_player.width;
	game->x_position = 450 - SCREEN_WIDTH / 2;
	if (game->x_position < 0)
		game->x_position = 0;
	game->player.x_pos = 450 - game->x_position;
	game->player.y_pos = 16;
	game->player.top = false;
	game->player.bottom = false;
	game->player.right = false;
	game->player.left = false;
	game->player.y_speed = 0.0;
	game->player.y_acceleration = 0.0;
	return (0);
}

int	init_game(t_game *game)
{
	int	error;

	game->mlx.display = mlx_init();
	if (!game->mlx.display)
		return (1);
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
	init_player(game);
	return (0);
}
