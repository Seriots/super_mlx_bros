/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_objects.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:28:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/22 12:07:06 by lgiband          ###   ########.fr       */
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
# define GOOMBA "GBA"
# define PLANT_PIRANHA "PP"
# define FIREBALL "FB"
# define FIREBALL_PLAYER "FBP"
# define CRATE "CRATE"
# define BREAK_MOR "BBM"
# define FLOWER "FLR"
# define LTR "LTR"

/*Char properties*/
# define CHAR_PATH "files/xpm/charactere/"
# define CHAR_NUMBER 95
# define CHAR_MARGE 1

/*Coin properties*/
# define COIN_PATH "files/xpm/objects/coins/coin"
# define COIN_NUMBER 6
# define COIN_HEIGHT 16
# define COIN_WIDTH 16

/*Must be a multiple of coin number, its better*/
# define COIN_ANIM_DURATION 672
# define WINCOIN_ANIM_DURATION 176

/*Sign properties*/
# define SIGN_PATH "files/xpm/objects/sign.xpm"

/*Big TRee properties*/
# define BTR_PATH "files/xpm/objects/big_tree.xpm"

/*Block properties*/
# define BLK_PATH "files/xpm/block/block.xpm"

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
# define REDC_X_SPEED 0.05f
# define REDC_Y_MAX_SPEED 0.2f

/*Loot block properties*/
# define LB_PATH "files/xpm/block/loot_block.xpm"
# define LB_HBOX 4

/*Loot block use properties*/
# define LBU_PATH "files/xpm/block/loot_block_use.xpm"

/*Breakable block properties*/
# define BB_PATH "files/xpm/block/breakable_block/breakable_block"
# define BB_NUMBER 5
# define BB_HBOX 4
# define BBM_Y_SPEED1 0.15f
# define BBM_Y_SPEED2 0.225f
# define BBM_X_SPEED1 0.15f
# define BBM_X_SPEED2 0.225f
# define BBM_GRAVITY 0.00002f
# define BBM_Y_MAX_SPEED 0.50f

/*Goomba properties*/
# define GBA_PATH "files/xpm/ennemies/goomba/goomba"
# define GBA_NUMBER 3
# define GBA_HBOX_X 8
# define GBA_HBOX_Y 8
# define GBA_ANIM_DURATION 480
# define GBA_X_SPEED 0.065f
# define GBA_Y_MAX_SPEED 0.2f
# define GBA_HEIGHT_SHRINK 4

/*Plant piranha properties*/
# define PP_PATH "files/xpm/ennemies/plant_piranha/plant_piranha"
# define PP_NUMBER 10
# define PP_HBOX 4
# define PP_ANIM_DURATION 2000
# define PP_ANIM_DEATH_DURATION 360
# define PP_X_DEATH_SPEED 0.20f
# define PP_Y_DEATH_SPEED 0.25f
# define PP_Y_MAX_SPEED 0.50f
# define PP_GRAVITY 0.00001f

/*Fireball properties*/
# define FB_PATH "files/xpm/objects/fireball/fireball"
# define FB_NUMBER 7
# define FB_HBOX 3
# define FB_ANIM_DURATION 240
# define FB_LIVE_DURATION 1800
# define FB_EXPLOSION_DURATION 120
# define FB_SPEED_DEFAULT 0.05f
# define FB_SPEED_PLAYER 0.22f
# define FB_UP_SPEED 0.30f
# define FB_START_UP_SPEED 0.18f
# define FB_MAX_SPEED 0.3f
# define FB_GRAVITY 0.00003f

/*Crate properties*/
# define CRATE_PATH "files/xpm/block/crate.xpm"

/*Flower properties*/
# define FLOWER_PATH "files/xpm/objects/flower.xpm"

/*Little tree properties*/
# define LTR_PATH "files/xpm/objects/little_tree.xpm"

#endif