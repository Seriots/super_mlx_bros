/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_objects.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:28:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/16 01:37:24 by lgiband          ###   ########.fr       */
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
# define BTR "BTR"
# define BLOCK "BLOCK"
# define FLAG "FLAG"
# define CASTLE "CATL"

/*Coin properties*/
# define COIN_PATH "files/xpm/objects/coins/coin"
# define COIN_NUMBER 6
/*Must be a multiple of coin number, its better*/
# define COIN_ANIM_DURATION 672

/*Sign properties*/
# define SIGN_PATH "files/xpm/objects/sign.xpm"

/*Big TRee properties*/
# define BTR_PATH "files/xpm/objects/big_tree.xpm"

/*Block properties*/
# define BLK_PATH "files/xpm/objects/block.xpm"

/*End properties*/
# define BAR_PATH "files/xpm/objects/end_bar.xpm"
# define END_BAR_HBOX 1

/*Flag properties*/
# define FLAG_PATH "files/xpm/objects/flag.xpm"
# define FLAG_MARGE 8
# define FALG_HEIGHT 19

/*Castle properties*/
# define CASTLE_PATH "files/xpm/objects/castle.xpm"
# define CASTLE_HBOX 4

#endif