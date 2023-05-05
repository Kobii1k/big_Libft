NAME	= libft.a

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strnstr.c ft_memset.c ft_bzero.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_calloc.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_striteri.c ft_strmapi.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_itoa.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c get_next_line.c get_next_line_utils.c ft_printf.c ft_print_char.c ft_print_hexa.c ft_print_int.c ft_print_str.c ft_print_uint.c ft_print_hexa_pointer.c ft_printfd.c ft_printfd_char.c ft_printfd_hexa.c ft_printfd_int.c ft_printfd_str.c ft_printfd_uint.c ft_printfd_hexa_pointer.c

SRCSDIR	= ./srcs/

SRCSPATH = $(addprefix $(SRCSDIR),$(SRCS))

OBJSDIR	= ./objs/

OBJS	= $(SRCSPATH:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

$(OBJSDIR)%.o:	${SRCSDIR}%.c Makefile libft.h
			@mkdir -p objs
			${CC} ${CFLAGS} -I . -c -g $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			rm -rf ${OBJSDIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
