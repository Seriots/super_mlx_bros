/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/22 12:54:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_H
# define SMB_H

# include "smb_struct.h"

# include <stdarg.h>

# include <X11/X.h>

/*smb_init_object.c*/
t_dict			*get_dict_new(char *tag, t_object *object);
t_object		*obj_new(char *tag, float x, float y);

/*smb_parsing.c*/
t_dict			*add_obj_parsing(char *tag, t_object obj);
t_dict			*add_obj(char *tag, int x, int y);
t_dict			*get_all_object(int fd);
int				set_map(t_map *map, char *filename);
int				check_map_format(char *filename);
int				parsing(int argc, char **argv, t_map *map);

/*smb_ingame_fct*/
int				ingame_right_pressed(t_game *game);
int				ingame_left_pressed(t_game *game);
int				ingame_top_pressed(t_game *game);
int				ingame_bottom_pressed(t_game *game);
int				ingame_right_released(t_game *game);
int				ingame_left_released(t_game *game);
int				ingame_top_released(t_game *game);
int				ingame_bottom_released(t_game *game);
int				ingame_escape_released(t_game *game);

/*smb_event_ingame.c*/
int				key_released_ingame(KeySym keycode, t_game *game);
int				key_pressed_ingame(KeySym keycode, t_game *game);

/*smb_event.c*/
int				ingame_fireball_pressed(t_game *game);
int				key_pressed_default(KeySym keycode, t_game *game);
int				key_released_default(KeySym keycode, t_game *game);
int				key_released(KeySym keycode, t_game *game);
int				key_pressed(KeySym keycode, t_game *game);
int				close_request(t_game *game);

/*smb_put_char_to_img.c*/
void			put_char_to_img(t_game *game, int x_start,
					int y_start, t_img_data *img);

/*smb_put_objects_to_img.c*/
void			put_objects_to_image(t_game *game, t_dict *objects,
					int position, t_img_data *img);

/*smb_put_player_to_img.c*/
void			put_player_to_image(t_game *game,
					t_player *player, t_img_data *img);

/*smb_put_map_to_image.c*/
void			put_map_to_image(t_game *game, char **map, int position);

/*smb_put_background_to_img.c*/
void			put_bg_to_image(t_game *game, int position, t_img_data *img);

/*smb_display.c*/
unsigned int	get_pxl_color(t_img_data img, int x, int y);
int				display_ingame(t_game *game);

/*smb_collisions_loop.c*/
int				boucle_col_down_obj(t_collisions col,
					t_game *game, t_object *obj);
int				boucle_col_up_obj(t_collisions col,
					t_game *game, t_object *obj);
int				boucle_col_right_obj(t_collisions col,
					t_game *game, t_object *obj);
int				boucle_col_left_obj(t_collisions col,
					t_game *game, t_object *obj);
int				boucle_col_down(t_collisions col, t_game *game);			
int				boucle_col_up(t_collisions col, t_game *game);
int				boucle_col_right(t_collisions col, t_game *game);
int				boucle_col_left(t_collisions col, t_game *game);

/*smb_collisions.c*/
int				check_collide_obj(t_object *obj, t_dict *all_obj,
					t_hbox *p_hbox);
int				check_col_obj_map(t_game *game, t_object *obj,
					float x_pos, float y_pos);
void			get_new_limit_wall(t_collisions value, t_hbox *p_hbox);
int				check_collisions_obj(t_game *game, t_object *obj,
					float x_pos, float y_pos);
int				check_collisions_bottom_obj(t_game *game, t_object *obj,
					float x_pos, float y_pos);
int				check_collisions_bottom_map(t_game *game, float x_pos,
					float y_pos, float pos);
int				check_col_player_obj_bottom(t_game *game, float x_pos,
					float y_pos, float pos);
int				check_col_player_obj(t_game *game, float x_pos,
					float y_pos, t_object *obj);
int				check_col_player_map(t_game *game, float x_pos,
					float y_pos, float position);
int				check_collisions_bottom(t_game *game, float x_pos,
					float y_pos, float position);
int				check_collisions(t_game *game, float x_pos,
					float y_pos, float position);

/*smb_move.c*/
int				apply_gravity_obj(t_game *game, t_object *obj, float max_speed);
int				apply_hor_movement_obj(t_game *game, t_object *obj);

int				move_right(t_game *game, t_player *player);
int				move_left(t_game *game, t_player *player);
int				apply_hor_movement(t_game *game, t_player *player);
int				apply_gravity(t_game *game, t_player *player);

/*smb_update_player.c*/
void			change_image(t_game *game, t_player *player, int value);
int				update_running_image(t_game *game, t_player *player, int value);
int				update_growth_image(t_game *game, t_player *player, int value);
int				update_victory_image(t_game *game, t_player *player, int value);
int				update_dead_image(t_game *game, t_player *player, int value);
int				update_player_state(t_game *game, t_player *player);
int				update_player_image(t_game *game, t_player *player);

/*smb_update_end.c*/
int				update_quit_map(t_game *game);

/*smb_update_death.c*/
int				update_death(t_game *game);

/*smb_update_growth.c*/
int				growth(t_game *game);
int				shrink(t_game *game);
int				update_growth(t_game *game);
int				update_shrink(t_game *game);

/*smb_update.c*/
int				update_movement(t_game *game, t_player *player);
int				update_objects(t_game *game, t_dict *all_obj);
int				is_in_map(t_game *game, int x, int y);
int				i_can_move(t_game *game, t_player *player);
int				update_ingame(t_game *game);
int				update_end(t_game *game);

/*smb_game_loop.c*/
int				game_loop(t_game *game);

/*Obj utils*/
int				default_movement(t_game *game, t_object *obj, float max_speed);
int				generate_wincoin(t_game *game, t_object *obj);
int				check_hbox(t_game *game, t_object *obj, int x_hbox, int y_hbox);
int				update_obj_img(t_game *game, t_object *obj, int start_image);

/*Init Objects*/
void			set_object(t_game *game, char *key, t_object **object);
void			init_start(t_game *game, t_object **obj);
void			init_end(t_game *game, t_object **obj);
void			init_coin(t_game *game, t_object **obj);
void			init_sign(t_game *game, t_object **obj);
void			init_btr(t_game *game, t_object **obj);
void			init_block(t_game *game, t_object **obj);
void			init_flag(t_game *game, t_object **obj);
void			init_castle(t_game *game, t_object **obj);
void			init_wincoin(t_game *game, t_object **obj);
void			init_fire_flower(t_game *game, t_object **obj);
void			init_red_champ(t_game *game, t_object **obj);
void			init_loot_block(t_game *game, t_object **obj);
void			init_breakable_block(t_game *game, t_object **obj);
void			init_fireball(t_game *game, t_object **obj);
void			init_fireball_player(t_game *game, t_object **obj);
void			init_crate(t_game *game, t_object **obj);
void			init_flower(t_game *game, t_object **obj);
void			init_ltr(t_game *game, t_object **obj);
int				init_point_image(t_game *game, t_object *obj, int image, int score);

/*Init Ennemies*/
void			init_plant_pirahna(t_game *game, t_object **obj);
void			init_goomba(t_game *game, t_object **obj);

/*smb_init_player.c*/
int				init_all_fire_player(t_game *game);
int				init_all_big_player(t_game *game);
int				init_all_little_player(t_game *game);
int				init_player(t_game *game);

/*smb_init_tiles.c*/
int				init_all_tiles(t_game *game);

/*smb_init_image.c*/
int				init_image(t_game *game, int width,
					int height, t_img_data *img);
int				init_xpm_image(t_game *game, t_img_data *img, char *name);
int				init_images_group(t_game *game, char *path, int nb_of_images,
					t_img_data **dst_ptr);

/*smb_init_game.c*/
int				init_game_images(t_game *game);
int				init_game(t_game *game);

/*smb_get_score.c*/
int				get_time_score(long time);
int				get_end_score(t_player *player, t_object *obj);
int				get_coin_score(int coins);

/*smb_strdisplay.c*/
int				char_put(t_game *game, char c, t_coord *coord);
int				convert_put(t_game *game, char c, va_list lst, t_coord *coord);
int				strdisplay(t_game *game, const char *str, t_coord coord, ...);

/*smb_time.c*/
long			timestamp_msec(long start);
long			timestamp_sec(long start);

/*smb_free_init.c*/
void			mlx_fail(t_game *game);
void			window_fail(t_game *game);
void			background_fail(t_game *game);
void			map_image_fail(t_game *game);
void			all_image_fail(t_game *game);

/*smb_free.c*/
void			free_img_array(t_game *game, t_img_data **imgs, int number);
void			free_all_image_group(t_game *game);
void			free_all_image(t_game *game);
void			free_game(t_game *game);

/*smb_error.c*/
void			smb_print_error(int code);

/*smb_comp.c*/
int				max(int a, int b);
int				min(int a, int b);

/*smb_wall_constructor.c*/
void			convert_plateformer_map(char **map, int x, int y, int max_y);
void			convert_outdoor_map(char **map, int x, int y, int max_y);
void			convert_indoor_map(char **map, int x, int y, int max_y);
void			wall_constructor(char **map, int max_y,
					void (*convert_function)(char **, int, int, int));
#endif