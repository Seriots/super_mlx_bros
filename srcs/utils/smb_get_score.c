/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_get_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:30:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:20:05 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"

int	get_time_score(long time)
{
	return ((6000 - time) * TIME_MULTIPLIER);
}

int	get_coin_score(int coins)
{
	return (coins * COIN_MULTIPLIER);
}

int	get_end_score(t_player *player, t_object *obj)
{
	if (obj->y > player->y_pos)
		return (10000);
	return ((obj->height - (player->y_pos - obj->y)) * SCORE_MULTIPLIER);
}
