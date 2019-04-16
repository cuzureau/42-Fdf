# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 14:08:28 by cuzureau          #+#    #+#              #
#    Updated: 2017/04/26 11:05:13 by cuzureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRC		=	./srcs/ft_calc.c \
			./srcs/ft_draw.c \
			./srcs/ft_events.c \
			./srcs/ft_init.c \
			./srcs/ft_parse.c \
			./srcs/main.c \

FLAGS	=	-Wall -Wextra -Werror

INC		=	./includes/fdf.h

LINC	=	./libft

MLX = -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@make -C $(LINC)
	@gcc $(FLAGS) -o $(NAME) $(LINC)/libft.a $(SRC) -I $(INC) \
	-I $(LINC)/libft.h $(MLX)
	@echo "Compilation of FdF: \033[1;32mOK\033[m"

clean:
	@make clean -C $(LINC)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LINC)

re: clean fclean all

.PHONY: all clean fclean re
