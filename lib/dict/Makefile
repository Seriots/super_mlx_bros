CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MAKE		= /bin/make


NAME		= libdict.a

HEADER_NAMES= dict \
			  ft_printf \
			  libft
SRC_NAMES	= dict_add_back \
			  dict_add_front \
			  dict_change_val \
			  dict_clear \
			  dict_del_one \
			  dict_getelem_key \
			  dict_getelem_number \
			  dict_getelem_value \
			  dict_get_first \
			  dict_get_last \
			  dict_new \
			  dict_print \
			  dict_print_keys \
			  dict_print_values \
			  dict_copy \
			  dict_sort \
			  dict_append \
			  dict_to_array \
			  dict_size


HEADER_DIR	= include
SRC_DIR		= src
OBJ_DIR		= obj

INCLUDE		= -I$(HEADER_DIR)

HEADER		= $(HEADER_NAMES:%=$(HEADER_DIR)/%.h)
OBJ			= $(SRC_NAMES:%=$(OBJ_DIR)/%.o)


all:			$(NAME)

clean:
	rm -f $(OBJ)
	@if [ -d $(OBJ_DIR) ]; then \
		find $(OBJ_DIR) -type d | xargs rmdir -p --ignore-fail-on-non-empty; \
	fi

fclean:			clean
	rm -f $(NAME)

re:				fclean re


$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
	fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%.a:
	$(MAKE) -C $(dir $@)


.PHONY:			all clean fclean re
