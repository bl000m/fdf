# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:44:01 by mpagani           #+#    #+#              #
#    Updated: 2022/12/22 16:08:29 by mpagani          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf
# src / obj files
SRCS 		= main.c checking.c reading.c scanning_map.c utils.c \
			memory_stuff.c
OBJS 		= $(SRCS:%.c=$(OBJDIR)/%.o)

# compile
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra

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
LIBX_DIR	= ./minilibx_macos
LIBX		= $(MLX)/mlx.a
LIBX_INC	= -I ./minilibx_macos
LIBX_LNK		= -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

# others
RM 			= rm -rf

all: obj $(LIBFT) $(LIBX) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCS_DIR)/%.c Makefile $(INCS_DIR)/fdf.h
	$(CC) $(CFLAGS) $(LIBX_INC) $(LIBFT_INC) -I $(INCS_DIR) -o $@ -c $<

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

re: fclean $(NAME)

.PHONY: all clean fclean re
