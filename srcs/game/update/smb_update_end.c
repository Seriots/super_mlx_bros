/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:44:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/15 22:56:53 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include "mlx.h"

int	update_end(t_game *game)
{
	update_objects(game, game->map.all_object);
	game->player.state = BAR;
	update_player_image(game, &game->player);
	if (!check_collisions_bottom(game, game->player.x_pos, game->player.y_pos + END_BAR_GRAVITY, game->x_position))
		game->player.y_pos += END_BAR_GRAVITY;
	return (0);
}
