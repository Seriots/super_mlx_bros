/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_redchamp_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:19:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 19:20:46 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb.h"
#include "smb_settings.h"

int	check_red_champ_collide(t_game *game, t_object *obj)
{
	if (game->update_fct == update_growth
		|| game->update_fct == update_shrink
		|| (game->player.state == CROUCH
			&& check_col_player_map(game, game->player.x_pos,
				game->player.y_pos - 14, game->x_position))
		|| (game->player.state != CROUCH
			&& check_col_player_map(game, game->player.x_pos,
				game->player.y_pos - 8, game->x_position))
		|| (game->player.state == CROUCH
			&& check_col_player_obj(game, game->player.x_pos
				+ game->x_position, game->player.y_pos - 14, obj))
		|| (game->player.state != CROUCH
			&& check_col_player_obj(game, game->player.x_pos
				+ game->x_position, game->player.y_pos - 8, obj)))
		return (1);
	return (0);
}
