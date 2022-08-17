# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 17:12:22 by ekeen-wy          #+#    #+#              #
#    Updated: 2022/08/09 11:15:17 by ekeen-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address

DEPS := fdf.h

SRC := main.c parse_map.c error_utils.c memory_utils.c bresenhams.c build_map.c \
	   map_utils.c matrix_init.c matrix_transformation.c matrix_utils.c \
	   drawing_utils.c general_utils.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "compiled fdf!"

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@echo "removed fdf!"

clean:
	@$(MAKE) --no-print-directory fclean -C libft
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re