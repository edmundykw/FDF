# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 17:12:22 by ekeen-wy          #+#    #+#              #
#    Updated: 2022/08/18 18:53:24 by ekeen-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address

MLX := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

DEPS := Includes/fdf.h

LIBFT_PATH	= Sources/libft
LIBFT   	= $(LIBFT_PATH)/libft.a
BRE_DIR 	= Sources/Bresenhams/
MAIN		= Sources/Main/
MAT_DIR	 	= Sources/Matrix/
MAP_DIR 	= Sources/Maps/
UTL_DIR 	= Sources/Utils/

SRC := $(addprefix $(MAIN), main.c) \
	   $(addprefix $(BRE_DIR), bresenhams.c drawing_utils.c) \
	   $(addprefix $(MAT_DIR), matrix_init.c matrix_transformation.c) \
	   $(addprefix $(MAP_DIR), build_map.c parse_map.c) \
	   $(addprefix $(UTL_DIR), error_utils.c event_handler.c general_utils.c) \
	   $(addprefix $(UTL_DIR), memory_utils.c map_utils.c  matrix_utils.c)	    

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
	@echo "compiled fdf!"

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@echo "removed fdf!"

clean:
	@$(MAKE) --no-print-directory fclean -C $(LIBFT_PATH)
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re