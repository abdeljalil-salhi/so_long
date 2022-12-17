# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 01:18:36 by absalhi           #+#    #+#              #
#    Updated: 2022/12/17 05:59:49 by absalhi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CFLAGS	=	-Wall -Wextra -Werror
CC		=	cc
RM		=	rm -rf

NONE	=	'\033[0m'
GREEN	=	'\033[32m'
GRAY	=	'\033[2;37m'
ITALIC	=	'\033[3m'

_SRCS	=	main.c map_utils.c map_check.c so_long_utils.c so_long_errors.c \
			ft_functions_1.c
SRCS	=	$(addprefix srcs/, $(_SRCS))
OBJS	=	$(SRCS:.c=.o)

.c.o	:
			@echo $(ITALIC)$(GRAY) "     - Making $<..." $(NONE)
			@$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@echo $(ITALIC)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
			@make -C libft/
			@$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L libft/ -lft $(OBJS) -o $(NAME)
			@echo $(GREEN)"- Compiled -"$(NONE)

clean	:
			@echo $(ITALIC)$(GRAY) "     - Removing object files..." $(NONE)
			@$(RM) $(OBJS)
			@make clean -C libft/

fclean	:	clean
			@echo $(ITALIC)$(GRAY) "     - Removing $(NAME)..." $(NONE)
			@$(RM) $(NAME)
			@make fclean -C libft/

re		:	fclean all

.PHONY	:	all clean fclean re
