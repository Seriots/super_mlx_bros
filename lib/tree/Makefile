CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MAKE		= /bin/make


NAME		= libtree.a

HEADER_NAMES= list \
			  tree
SRC_NAMES	= tree_adopt \
			  tree_clear \
			  tree_count_childs \
			  tree_count_leaves \
			  tree_depth \
			  tree_iter_if \
			  tree_iter_infix \
			  tree_iter_prefix \
			  tree_iter_suffix \
			  tree_join \
			  tree_join_two \
			  tree_new_leaf \
			  tree_size

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

.PHONY:			all clean fclean re
