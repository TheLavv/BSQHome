# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mteressa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/31 14:05:02 by mteressa          #+#    #+#              #
#    Updated: 2020/08/31 14:05:13 by mteressa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSQ

SRCS = *.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(SRCS) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
