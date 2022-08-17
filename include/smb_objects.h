/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_objects.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:28:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/18 00:06:42 by lgiband          ###   ########.fr       */
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
# define FIRE_FLOWER "FF"
# define RED_CHAMP "REDC"
# define LOOT_BLOCK "LB"
# define LOOT_BLOCK_USE "LBU"
# define BREAKABLE_BLOCK "BB"

/*Char properties*/
# define CHAR_PATH "files/xpm/charactere/"
# define CHAR_NUMBER 95
# define CHAR_MARGE 1

/*Coin properties*/
# define COIN_PATH "files/xpm/objects/coins/coin"
# define COIN_NUMBER 6
# define COIN_HEIGHT 16

/*Must be a multiple of coin number, its better*/
# define COIN_ANIM_DURATION 672
# define WINCOIN_ANIM_DURATION 176

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
# define CASTLE_HBOX 1

/*Fire flower properties*/
# define FF_PATH "files/xpm/objects/fire_flower.xpm"
# define FF_HBOX 4
# define FF_SPAWN_SPEED 0.015f

/*Red champi properties*/
# define REDC_PATH "files/xpm/objects/red_champi.xpm"
# define REDC_HBOX 4
# define REDC_SPAWN_SPEED 0.015f

/*Loot block properties*/
# define LB_PATH "files/xpm/objects/loot_block.xpm"
# define LB_HBOX 4

/*Loot block use properties*/
# define LBU_PATH "files/xpm/objects/loot_block_use.xpm"

/*Breakable block properties*/
# define BB_PATH "files/xpm/objects/breakable_block.xpm"
# define BB_HBOX 4

#endif