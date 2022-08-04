/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:21:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 01:26:28 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb.h"
#include "smb_struct.h"
#include "smb_settings.h"

#include "mlx.h"

#include <stdlib.h>

static void	init_game_variable(t_game *game)
{
	game->refresh = true;
	game->x_position = 0;
}

int	init_game(t_game *game)
{
	int	error;

	game->mlx.display = mlx_init();
	if (!game->mlx.display)
		return (1);
	game->mlx.window = mlx_new_window(game->mlx.display,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Super Mlx Bros");
	if (!game->mlx.window)
		return (mlx_destroy_display(game->mlx.display),
			free(game->mlx.display), 2);
	error = init_xpm_image(game, &game->background,
			"files/xpm/Infinite_sky_background.xpm");
	if (error)
		return (mlx_destroy_window(game->mlx.display, game->mlx.window),
			mlx_destroy_display(game->mlx.display),
			free(game->mlx.display), error);
	error = init_image(game, SCREEN_WIDTH, SCREEN_HEIGHT, &game->window_image);
	if (error)
		return (mlx_destroy_image(game->mlx.display, game->background.img),
			mlx_destroy_window(game->mlx.display, game->mlx.window),
			mlx_destroy_display(game->mlx.display),
			free(game->mlx.display), error);
	init_game_variable(game);
	return (0);
}
