/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_objects_fonction.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:42:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 20:30:56 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_OBJECTS_FONCTION_H
# define SMB_OBJECTS_FONCTION_H

# include "smb_struct.h"

/*coin*/
int	coin_collisions(t_game *game, t_dict *elem, t_object *obj, int direction);
int	coin_update(t_game *game, t_dict *elem, t_object *obj);

#endif