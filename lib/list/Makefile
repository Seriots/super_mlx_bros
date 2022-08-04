CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MAKE		= /bin/make


NAME		= liblist.a

HEADER_NAMES= list
SRC_NAMES	= list_add_back \
			  list_add_front \
			  list_append \
			  list_append_back \
			  list_clear \
			  list_delone \
			  list_iter \
			  list_last \
			  list_map \
			  list_new \
			  list_rev \
			  list_size


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
