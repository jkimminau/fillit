# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 19:11:37 by jkimmina          #+#    #+#              #
#    Updated: 2018/03/21 21:40:24 by mmoros           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	driver.c	\
		fi_map.c	\
		fillit.c	\
		input.c

OBJ =	$(SRC:.c=.o)

HEADER =	fillit.h	\
			input.h

HEADERDIR = .

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "Making libft..."
	@make -C libft/
	@echo "Making..."
	@gcc $(FLAGS) -c $(SRC) $(HEADER) -I $(HEADERDIR)
	@gcc -Llibft/ -lft $(OBJ) -o $(NAME)

clean:
	@echo "Cleaning..."
	@/bin/rm -f $(OBJ) *.gch 
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
