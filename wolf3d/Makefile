# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagirard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 15:53:24 by lagirard          #+#    #+#              #
#    Updated: 2017/10/31 15:02:45 by lagirard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = srcs/

SRCS = main.c init.c tab.c map.c\
raycasting_dda.c raycasting_init.c raycasting_wall.c\
vertical.c events.c\
errors_tab.c errors_minilib.c errors_ray.c\

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

INC = -I ./includes/ -I./libft/includes

LIB = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	    	@make -C libft/
			@make -C minilibx_macos
		  	@gcc $(OBJ) $(INC) $(LIB) -o $(NAME)

%.o: $(SRC_PATH)%.c
	       	@gcc -c $(FLAGS) $< -o $@ $(INC)


.PHONY = clean
clean :
	        @rm -rf $(OBJ)

fclean : clean
	        @rm -rf $(NAME)
			    @make -C libft fclean
				@make -C minilibx_macos clean

re : fclean all

.PHONY: all clean fclean re
