/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_free_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:05:49 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/07 21:13:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "ft.h"

#include "smb_struct.h"

#include <stdlib.h>

void	window_fail(t_game *game)
{
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
	mlx_destroy_image(game->mlx.display, game->background.img);
	map_image_fail(game);
}
