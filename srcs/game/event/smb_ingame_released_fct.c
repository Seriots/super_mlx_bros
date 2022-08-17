/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_ingame_released_fct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:42:45 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:59:33 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb.h"

int	ingame_right_released(t_game *game)
{
	if (game->player.left > game->player.right)
		game->player.left -= 1;
	if (game->player.right == 1)
		game->player.x_acceleration = 0;
	game->player.right = 0;
	return (0);
}

int	ingame_left_released(t_game *game)
{
	if (game->player.right > game->player.left)
		game->player.right -= 1;
	if (game->player.left == 1)
		game->player.x_acceleration = 0;
	game->player.left = 0;
	return (0);
}

int	ingame_top_released(t_game *game)
{
	game->player.top = false;
	return (0);
}

int	ingame_bottom_released(t_game *game)
{
	game->player.bottom = 0;
	return (0);
}

int	ingame_escape_released(t_game *game)
{
	if (game->player.right == 0 && game->player.left == 0
		&& game->player.top == 0 && game->player.bottom == 0)
		close_request(game);
	return (0);
}
