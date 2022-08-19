/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_objects_fonction.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:42:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 11:30:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_OBJECTS_FONCTION_H
# define SMB_OBJECTS_FONCTION_H

# include "smb_struct.h"

/*coin*/
int	coin_collisions(t_game *game, t_dict *elem, t_object *obj, int direction);
int	coin_update(t_game *game, t_dict *elem, t_object *obj);

/*PLayer Fireball*/
int	check_collisions_fireball(t_game *game, t_object *obj, float x_pos, float y_pos);

#endif