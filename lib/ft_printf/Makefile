CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MAKE		= /bin/make


NAME		= libft_printf.a

HEADER_NAMES= conversion \
			  ft_printf
SRC_NAMES	= ft_printf \
			  ft_printf_utils \
			  ft_printf_utils2 \
			  ft_printf_components \
			  conversions_files/ft_putstr \
			  conversions_files/ft_putnbr \
			  conversions_files/ft_putchar \
			  conversions_files/ft_puthexa_min \
			  conversions_files/ft_putpointeur \
			  conversions_files/ft_putpointeur2 \
			  conversions_files/ft_puthexa_maj \
			  conversions_files/ft_putnbr_unsigned


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
