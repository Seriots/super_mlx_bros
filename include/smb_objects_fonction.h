/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_objects_fonction.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:42:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 19:21:20 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_OBJECTS_FONCTION_H
# define SMB_OBJECTS_FONCTION_H

# include "smb_struct.h"

/*PLayer Fireball*/
int	check_collisions_fireball(t_game *game, t_object *obj,
		float x_pos, float y_pos);
int	fireball_player_update(t_game *game, t_dict *elem, t_object *obj);

/*Plant piranha*/
int	init_piranha_death(t_game *game, t_object *obj);
int	update_piranha_death_pos(t_game *game, t_object *obj);

/*End*/
int	apply_int_collisions(t_game *game, t_object *obj);
int	update_player_position(t_game *game, t_object *obj);
int	get_final_score(t_player *player);

/*Breakable block*/
int	init_break_block(t_game *game, t_object *obj, float y_speed, int n);

/*Red champ*/
int	check_red_champ_collide(t_game *game, t_object *obj);
#endif