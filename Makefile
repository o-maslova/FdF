#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaslova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 15:57:44 by omaslova          #+#    #+#              #
#    Updated: 2018/07/09 16:08:00 by omaslova         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fdf

SRC = main.c read_map.c algorithm.c get_next_line.c key_hook.c

LIBS = -lmlx -L./libft/ -lft

GRAPHICS = -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft
	gcc -o $(NAME) $(LIBS) $(BINS) $(GRAPHICS) -g

%.o%.c :
	gcc $(FLAGS) -o $< -c &< $(LIBS)

clean:
	make clean -C libft
	rm -f $(BINS)
	rm -f *~

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all