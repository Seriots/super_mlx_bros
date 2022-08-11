/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_free_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:05:49 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 19:47:16 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "ft.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdlib.h>

void	mlx_fail(t_game *game)
{
	ft_free_tab(game->map.map_data);
	dict_clear(game->map.all_object, 0, free);
}

void	window_fail(t_game *game)
{
	mlx_fail(game);
	mlx_destroy_display(game->mlx.display);
	free(game->mlx.display);
}

void	background_fail(t_game *game)
{
	mlx_destroy_window(game->mlx.display, game->mlx.window);
	window_fail(game);
}

void	map_image_fail(t_game *game)
{
	mlx_destroy_image(game->mlx.display, game->background.img);
	background_fail(game);
}

void	all_image_fail(t_game *game)
{
	if (game->all_images.all_tiles)
		free_img_array(game, &game->all_images.all_tiles, TILES_NUMBER);
	if (game->all_images.all_coins)
		free_img_array(game, &game->all_images.all_coins, COIN_NUMBER);
	if (game->all_images.sign.img)
		mlx_destroy_image(game->mlx.display, game->all_images.sign.img);
	mlx_destroy_image(game->mlx.display, game->window_image.img);
	map_image_fail(game);
}
