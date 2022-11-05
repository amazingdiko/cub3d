# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 16:41:06 by smackere          #+#    #+#              #
#    Updated: 2022/10/24 18:00:26 by smackere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "\n"
	@-echo "\033[0;32mCompiling mlx...✅"
	@-ar -r $(NOM) $(OBJ)
	@-ranlib $(NOM)

%.o: %.c
	@-printf "\033[0;33mGenerating mlx objects 🔜 %-33.33s\r" $@
	@-gcc ${CFLAGS} -c $< -o $@ 

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
