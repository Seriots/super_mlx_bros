/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_objects.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:28:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 00:08:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_OBJECTS_H
# define SMB_OBJECTS_H

/*Extensions of images use*/
# define IMAGE_EXTENSION ".xpm"
# define NAME_BUFFER_SIZE 256
# define NUMBER_BUFFER_SIZE 11

/*Objects*/
# define START "START"
# define END "END"
# define COIN "COIN"
# define SIGN "SIGN"

/*Coin properties*/
# define COIN_PATH "files/xpm/objects/coins/coin"
# define COIN_NUMBER 6
# define COIN_ANIM_DURATION 100

/*Sign properties*/
# define SIGN_PATH "files/xpm/objects/sign.xpm"

#endif