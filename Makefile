# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:44:01 by mpagani           #+#    #+#              #
#    Updated: 2022/12/21 14:48:08 by mpagani          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf
# src / obj files
SRCS 		= main.c
OBJS 		= $(SRCS:%.c=$(BUILD_DIR)/%.o)

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
MLX_LIB		= $(MLX)/mlx.a
MLX_INC		= -I ./miniLibX
MLX_LNK		= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

AR 			= ar
RM 			= rm -f
HEADER_FILE = push_swap.h

all: obj $(LIBFT) $(MLX_LIB) $(NAME)

obj: mkdir -p $(OBJDIR)

# $(NAME): $(OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $^ -o $@
# 	@echo "Done!"

$(OBJDIR)/%.o: $(SRCS_DIR)/%.c $(INCS_DIR)/$(HEADER_FILE) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR) $(LIBFT_INC) $(MLX_INC)

$(LIBFT):
	make -C $(LIBFT_DIR)
	# cp $(LIBFT) $(NAME)
$(MLX_LIB):
	make -C $(LIBX_DIR)
	# cp $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_LNK) $(LIBFT_LNK) -lm -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
