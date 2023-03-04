NAME	= ../printfd.a

SRCS	=	ft_printfd.c utils/ft_printfd_char.c utils/ft_printfd_hexa.c utils/ft_printfd_int.c utils/ft_printfd_str.c utils/ft_printfd_uint.c utils/ft_printfd_hexa_pointer.c utils/ft_strlen.c

OBJS	= ${SRCS:.c=.o}

CC				= cc

CFLAGS 			= -Wall -Werror -Wextra

%.o:			%.c Makefile ft_printfd.h
						${CC} ${CFLAGS} -I . -c -g $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

all:			${NAME}

clean:
						rm -f ${OBJS}

fclean:			clean
						rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
