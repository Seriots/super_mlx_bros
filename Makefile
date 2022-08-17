NAME := super_mlx_bros
CFLAGS := 
CC := cc
MAKE = /bin/make

define SRCS :=
	main.c
	collisions/smb_collisions_loop.c
	collisions/smb_collisions_player_map.c
	collisions/smb_collisions_player_obj_bottom.c
	collisions/smb_collisions_player_obj.c
	collisions/smb_collisions.c
	game/display/smb_display.c
	game/display/smb_put_background_to_img.c
	game/display/smb_put_char_to_img.c
	game/display/smb_put_map_to_img.c
	game/display/smb_put_objects_to_img.c
	game/display/smb_put_player_to_img.c
	game/move/smb_move_hor.c
	game/move/smb_move_left.c
	game/move/smb_move_right.c
	game/move/smb_move_up.c
	game/update/smb_growth.c
	game/update/smb_update_end.c
	game/update/smb_update_player_state.c
	game/update/smb_update_player.c
	game/update/smb_update_utils.c
	game/update/smb_update.c
	game/event/smb_event.c
	game/event/smb_ingame_event.c
	game/event/smb_ingame_pressed_fct.c
	game/event/smb_ingame_released_fct.c
	game/smb_game_loop.c
	init/smb_init_game.c
	init/smb_init_image.c
	init/smb_init_object.c
	init/smb_init_player.c
	init/smb_init_tiles.c
	init/objects/smb_add_obj.c
	init/objects/smb_init_block.c
	init/objects/smb_init_btr.c
	init/objects/smb_init_castle.c
	init/objects/smb_init_coin.c
	init/objects/smb_init_flag.c
	init/objects/smb_init_end.c
	init/objects/smb_init_sign.c
	init/objects/smb_init_start.c
	init/objects/smb_init_wincoin.c
	parsing/smb_parsing_checker.c
	parsing/smb_parsing_object.c
	parsing/smb_parsing_setter.c
	parsing/smb_parsing.c
	parsing/smb_wall_constructor.c
	utils/smb_comp.c
	utils/smb_error.c
	utils/smb_free_init.c
	utils/smb_free.c
	utils/smb_get_score.c
	utils/smb_strdisplay_utils.c
	utils/smb_strdisplay.c
	utils/smb_time.c
endef
SRCS := $(strip $(SRCS))

define HDRS :=
	ft.h
	dict.h
	ft_printf.h
	list.h
	tree.h
	mlx.h
	mlx_int.h

endef
HDRS := $(strip $(HDRS))

SRCS_DIR := srcs
OBJS_DIR := objs
INCS_DIR := include
LIB_DIR  := lib

define LIBS :=
	lib/dict/libdict.a
	lib/ft_printf/libft_printf.a
	lib/ft/libft.a
	lib/list/liblist.a
	lib/tree/libtree.a
	lib/mlx_linux/libmlx_Linux.a
endef
LIBS := $(strip $(LIBS))

define LIB_NAMES :=
	dict
	ft_printf
	ft
	list
	tree
	mlx_linux
endef
LIB_NAMES := $(strip $(LIB_NAMES))

# ============================================================================ #
#                               Intermediates                                  #
# ============================================================================ #

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))
DEP_FILES := $(OBJ_FILES:.o=.d)
HDR_FILES := $(addprefix $(INCS_DIR)/,$(HDRS))

CFLAGS := $(CFLAGS) -Wall -Wextra

ifdef DEBUG
	CFLAGS := $(CFLAGS) -g3 -fsanitize=address -D DEBUG=1
else
	CFLAGS := $(CFLAGS) -Werror -D DEBUG=0
endif

# ============================================================================ #
#                                 Functions                                    #
# ============================================================================ #

all: $(NAME)

start_compiling:
	@echo "$(_GREEN)Start Compiling $(_NO_COLOR)"
.INTERMEDIATE:	start_compiling

clean:
	@echo "$(_RED)Objs and Deps: removing$(_NO_COLOR)"
	@rm -vf $(OBJ_FILES) $(DEP_FILES)
	@if [ -d $(OBJS_DIR) ]; then \
		find $(OBJS_DIR) -type d | xargs rmdir -p --ignore-fail-on-non-empty; \
	fi
.PHONY: clean

fclean: clean
	@echo "\n$(_RED)$(NAME): removing$(_NO_COLOR)"
	rm -f $(NAME)
	@for lib in $(LIB_NAMES); do \
		echo "\n$(_RED)$${lib}: cleaning$(_NO_COLOR)"; \
		$(MAKE) --no-print-directory -C $(LIB_DIR)/$${lib}/ fclean 2> /dev/null \
		|| $(MAKE) --no-print-directory -C $(LIB_DIR)/$${lib}/ clean 2> /dev/null \
		|| echo "Cannot be clean"; \
	done
.PHONY: fclean

re:	fclean
	$(MAKE) all
.PHONY: re

# ============================================================================ #
#                                   Colors                                     #
# ============================================================================ #

_GREY		= \033[30m
_RED		= \033[31m
_GREEN		= \033[32m
_YELLOW		= \033[33m
_BLUE		= \033[34m
_PURPLE		= \033[35m
_CYAN		= \033[36m
_WHITE		= \033[37m
_NO_COLOR	= \033[0m

# ============================================================================ #
#                                   Rules                                      #
# ============================================================================ #

$(NAME): $(LIBS) $(OBJ_FILES) 
	@echo "\n$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS) -lXext -lX11 -lm

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c  start_compiling
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo "\n$(_BLUE)$(dir $@): Create$(_NO_COLOR)"; \
	fi
	$(CC) $(CFLAGS) -MMD -I $(INCS_DIR) -o $@ -c $<

-include $(DEP_FILES)

%.a:
	@echo "$(_GREEN)$(dir $@): make$(_NO_COLOR)"
	@$(MAKE) --no-print-directory -C $(dir $@)
	@echo ""
