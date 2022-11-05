# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 10:55:24 by smackere          #+#    #+#              #
#    Updated: 2022/10/25 19:48:39 by smackere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

CUB =	srcs/cub/render.c\
		srcs/cub/init.c\
		srcs/cub/key_hook.c\
		srcs/cub/render_help.c\
		srcs/cub/key_hook_help.c\
		srcs/cub/mouse_hook.c\
		srcs/cub/minimap.c\
		srcs/cub/minimap_all.c\

GNL =	srcs/gnl/get_next_line_utils.c\
		srcs/gnl/get_next_line.c\

PARS =  srcs/parser/check_map.c\
		srcs/parser/parse_params.c\
		srcs/parser/parse_rgb.c\
		srcs/parser/texture_form.c\

UTILS = srcs/utils/utils.c\
		srcs/utils/free.c\
		srcs/utils/str_arr_utils.c\
		srcs/utils/str_arr_utils2.c\
		srcs/utils/pixel.c\

SRC =	${GNL} ${PARS} ${UTILS} ${CUB}\
		srcs/main.c\

PATH_LIB = srcs/libft/

NAME_LIB = libft.a

LIB =	srcs/libft/libft.a

HDRS =	srcs/cub.h srcs/types.h srcs/parser/parser.h\
		srcs/libft/libft.h srcs/gnl/get_next_line.h srcs/cub/cub_cast.h\
		mlx/mlx_int.h mlx/mlx_new_window.h mlx/mlx_opengl.h mlx/mlx_png.h\
		mlx/mlx.h

OBJ =	$(SRC:c=o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
	@echo "\n"
	@make -C mlx 2>/dev/null
	@make -C $(PATH_LIB)
	@echo "\033[0;32mCompiling cub3d...✅"
	@$(CC) $(FLAGS) $(MLX_FLAGS) -I mlx $(OBJ) $(LIB) -I. -o $(NAME)
	@echo "\n\033[0;33m🥂Done and ready!🥂"

%.o: %.c
	@printf "\033[0;33mGenerating cub3d objects 🔜 %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C $(PATH_LIB)
	@echo "\033[0;31mCleaning mlx..."
	@make clean -C mlx/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\n\033[0;32mCleaning process is competed!"

fclean: clean
	@echo "\033[0;31m🧹Cleaning libft🧹..."
	@make fclean -C $(PATH_LIB)
	@echo "\n✂️Deleting executable..."
	@rm -f $(NAME)
	@echo "\n\033[0;32mF_cleaning process is competed!"

re:		fclean all

reclean: re
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C $(PATH_LIB)
	@echo "\033[0;31mCleaning mlx..."
	@make clean -C mlx/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\n\033[0;32mCleaning process is competed!"

.PHONY: all clean fclean re reclean
