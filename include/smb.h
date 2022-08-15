/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/15 23:12:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_H
# define SMB_H

# include "smb_struct.h"

# include <X11/X.h>

/*smb_init_object.c*/
t_dict			*get_dict_new(char *tag, t_object *object);
t_object		*obj_new(char *tag, float x, float y);

/*smb_parsing.c*/
t_dict 			*add_obj(char *tag, int x, int y);
t_dict			*get_all_object(int fd);
int				set_map(t_map *map, char *filename);
int				check_map_format(char *filename);
int				parsing(int argc, char **argv, t_map *map);

/*smb_event_ingame.c*/
int				key_released_ingame(KeySym keycode, t_game *game);
int				key_pressed_ingame(KeySym keycode, t_game *game);

/*smb_event.c*/
int				key_released(KeySym keycode, t_game *game);
int				key_pressed(KeySym keycode, t_game *game);
int				close_request(t_game *game);

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
int				boucle_col_down(t_collisions col, t_game *game);			
int				boucle_col_up(t_collisions col, t_game *game);
int				boucle_col_right(t_collisions col, t_game *game);
int				boucle_col_left(t_collisions col, t_game *game);

/*smb_collisions.c*/
int				check_col_player_obj_bottom(t_game *game, float x_pos,
					float y_pos, float pos);
int				check_col_player_obj(t_game *game, float x_pos,
					float y_pos, float position);
int				check_col_player_map(t_game *game, float x_pos,
					float y_pos, float position);
int				check_collisions_bottom(t_game *game, float x_pos,
					float y_pos, float position);
int				check_collisions(t_game *game, float x_pos,
					float y_pos, float position);

/*smb_move*.c*/
int				move_right(t_game *game, t_player *player);
int				move_left(t_game *game, t_player *player);
int				apply_hor_movement(t_game *game, t_player *player);
int				apply_gravity(t_game *game, t_player *player);

/*smb_update_player.c*/
int				update_player_state(t_game *game, t_player *player);
int				update_player_image(t_game *game, t_player *player);

/*smb_update.c*/
int				update_movement(t_game *game, t_player *player);
int				update_objects(t_game *game, t_dict *all_obj);
int				is_in_map(t_game *game, int x, int y);
int				i_can_move(t_game *game, t_player *player);
int				update_ingame(t_game *game);
int				update_end(t_game *game);

/*smb_game_loop.c*/
int				game_loop(t_game *game);

/*smb_init_objects*/
void			set_object(t_game *game, char *key, t_object **object);
void			init_start(t_game *game, t_object **obj);
void			init_end(t_game *game, t_object **obj);
void			init_coin(t_game *game, t_object **obj);
void			init_sign(t_game *game, t_object **obj);
void			init_btr(t_game *game, t_object **obj);
void			init_block(t_game *game, t_object **obj);
void			init_flag(t_game *game, t_object **obj);

/*smb_init_player.c*/
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
int				init_game(t_game *game);

/*smb_free_init.c*/
void			mlx_fail(t_game *game);
void			window_fail(t_game *game);
void			background_fail(t_game *game);
void			map_image_fail(t_game *game);
void			all_image_fail(t_game *game);

/*smb_free.c*/
void			free_img_array(t_game *game, t_img_data **imgs, int number);
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