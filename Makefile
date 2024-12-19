# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 13:45:10 by ramedjra          #+#    #+#              #
#    Updated: 2023/04/17 13:45:31 by ramedjra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long  
LIBFT	= libft
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -I inc 
RM		= rm -f 
MLX		= $(shell tar -xf mlx.tgz && tar -xf mlx_linux.tgz)

SRCS	= so_long.c \
			src/anim.c \
			src/check.c \
			src/check_map.c \
			src/enemy.c \
			src/image.c \
			src/map.c \
			src/misc.c \
			src/move.c \
			src/player.c \
			src/utils.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c 


UNAME 	= $(shell uname)

OBJS 	= $(SRCS:.c=.o)

LIBFT_DIR  = ./libft
LIBFT = ./libft/libft.a


ifeq ($(UNAME), Linux)
$(NAME)	:  	$(MLX) $(OBJS) 
			@echo "[\033[1;32mLinux Compilation...\033[0m]" $(NAME)
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			@ ${MAKE} -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBFT) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
endif

ifeq ($(UNAME), Darwin)
$(NAME)	:	$(MLX) $(OBJS)
			@echo "[\033[1;32mMac Compilation...\033[0m]"$(NAME)
			@ $(MAKE) -C mlx all
			@ cp ./mlx/libmlx.a .
			@$(CC) $(CFLAGS) -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
endif

all:	${NAME}

clean:
	@${RM} *.o */*.o */*/*.o
	
ifeq ($(UNAME), Linux)
fclean: clean
		@echo "[\033[1;32mClean...\033[0m]"  $(NAME)
		@${RM} ${NAME}
		@${MAKE} -C mlx_linux clean
endif

ifeq ($(UNAME), Darwin)
fclean: clean
		@echo "[\033[1;32mClean...\033[0m]" $(NAME)
		@ ${RM} ${NAME}
		@ ${RM} libmlx.a
endif

re: fclean all

.PHONY: all clean fclean re
