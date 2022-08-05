/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:53:30 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 20:57:09 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb.h"
#include "smb_struct.h"
#include "smb_settings.h"

#include "mlx.h"

#include <unistd.h>
#include <stdbool.h>

#include <stdio.h>

void	call_hook(t_game *game)
{
	mlx_hook(game->mlx.window, 2, 1L << 0, key_pressed, game);
	//mlx_hook(game->vars.window, 3, 1L << 1, key_released, game);
	mlx_hook(game->mlx.window, 33, 1L << 24, close_request, game);
	mlx_loop_hook(game->mlx.display, display, game);
	mlx_do_sync(game->mlx.display);
	mlx_loop(game->mlx.display);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		error;

	error = parsing(argc, argv, &game.map);
	if (error)
		return (smb_print_error(error), 1);
	
	error = init_game(&game);
	if (error)
		return (smb_print_error(error), 1);
	call_hook(&game);
	free_game(&game);
	return (0);
}
