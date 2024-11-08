SRC			= src/ft_printf.c \
			  src/string_utils.c	

SRC_BONUS	= src/bonus/ft_printf.c

OBJS		= ${SRC:.c=.o}
OBJS_BONUS	= ${SRC_BONUS:.c=.o}
NAME		= libftprintf.a
CC 			= cc
RM			= rm -f
CFLAGS 		= -Wall -Wextra -Werror

#ar is a  archive command in Unix/Linux
#r: Replace or add the specified files to the archive.
#c: Create the archive if it doesn’t already exist.
#s: Add an index to the archive, making it faster to link to.
${NAME}: ${OBJS}
	@ ar rcs ${NAME} ${OBJS}

all: ${NAME} bonus

bonus: ${OBJS_BONUS}
	@ ar rcs ${NAME} ${OBJS_BONUS}

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY:
	all clean fclean re