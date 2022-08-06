/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:08:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/06 19:42:27 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

int	update_movement(t_game *game, t_player *player)
{
	if (player->left == true)
		move_left(game, player);
	if (player->right == true)
		move_right(game, player);
	return (0);
}

int	update(t_game *game)
{
	update_movement(game, &game->player);
	return (0);
}
