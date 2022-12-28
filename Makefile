# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 01:18:36 by absalhi           #+#    #+#              #
#    Updated: 2022/12/28 17:21:15 by absalhi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CFLAGS	=	-Wall -Wextra -Werror -O3 #-fsanitize=address
MXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
CC		=	cc
RM		=	rm -rf

NONE	=	'\033[0m'
GREEN	=	'\033[32m'
GRAY	=	'\033[2;37m'
ITALIC	=	'\033[3m'

_SRCS	=	main.c map_utils.c map_check.c so_long_utils.c so_long_errors.c				\
			ft_functions_1.c ft_player_moves.c ft_render.c ft_init_sprites.c			\
			ft_init_sprites_2.c ft_new_sprite.c ft_new_sprite_2.c ft_enemies.c			\
			ft_animate.c ft_collectibles.c ft_sounds.c ft_quick_fill.c ft_functions_2.c	\
			ft_quick_fill_2.c ft_player_attack.c ft_kill_enemy.c ft_new_sprite_3.c		\
			ft_draw_attack.c
SRCS	=	$(addprefix srcs/, $(_SRCS))
OBJS	=	$(SRCS:.c=.o)

.c.o	:
			@echo $(ITALIC)$(GRAY) "     - Making $<..." $(NONE)
			@$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@echo $(ITALIC)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
			@make -C libft/
			@$(CC) $(CFLAGS) $(MXFLAGS) -L libft/ -lft $(OBJS) -o $(NAME)
			@echo $(GREEN)"- Compiled -"$(NONE)

clean	:
			@echo $(ITALIC)$(GRAY) "     - Removing object files..." $(NONE)
			@$(RM) $(OBJS)
			@make clean -C libft/

fclean	:	clean
			@echo $(ITALIC)$(GRAY) "     - Removing $(NAME)..." $(NONE)
			@$(RM) $(NAME)
			@make fclean -C libft/

play	:	$(OBJS)
			@make -C libft/
			@$(CC) $(CFLAGS) $(MXFLAGS) -L libft/ -lft $(OBJS) -o $(NAME)
			@echo $(GREEN)"- Compiled -"$(NONE)
			@./$(NAME) maps/level1.ber
			@./$(NAME) maps/level2.ber
			@./$(NAME) maps/level3.ber
			@./$(NAME) maps/level4.ber
			@./$(NAME) maps/level5.ber

re		:	fclean all

replay	:	fclean play

.PHONY	:	all clean play fclean re replay
