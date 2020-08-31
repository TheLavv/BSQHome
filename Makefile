NAME	= BSQ

SRCS	= srcs/*.c

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
		${CC} ${SRCS} -o ${NAME}

clean:
		/bin/rm -f *.o

fclean:	clean
		/bin/rm -f ${NAME}

re:	fclean all
