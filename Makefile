# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:44:01 by mpagani           #+#    #+#              #
#    Updated: 2023/01/02 13:26:26 by mpagani          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf
# src / obj files
SRCS 		= main.c map_reading.c map_scanning.c map_utils.c \
			vision_drawing.c vision_settings.c \
			vision_hooks.c vision_features.c \
			memory_stuff.c
OBJS 		= $(SRCS:%.c=$(OBJDIR)/%.o)

# compile
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra -ggdb3 -g3

# directories
SRCS_DIR	= ./srcs
INCS_DIR	= ./includes
OBJDIR 		= ./obj

# library ft_
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_INC	= -I ./libft
LIBFT_LNK	= -L ./libft -l ft

# library minilibx
LIBX_DIR	= ./mlx
LIBX		= $(LIBX_DIR)/libmlx.a
LIBX_INC	= -Imlx
LIBX_LNK		= -Lmlx -lmlx -framework OpenGL -framework AppKit

# others
RM 			= rm -rf

all: obj $(LIBFT) $(LIBX) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCS_DIR)/%.c Makefile $(INCS_DIR)/fdf.h
	$(CC) $(CFLAGS) $(LIBX_INC) $(LIBFT_INC) -I $(INCS_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBX):
	make -C $(LIBX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBX_LNK) $(LIBFT_LNK) -lm -o $(NAME)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBX_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
