SRC =   ft_printf.c \
		print.c \
		print_hex.c

OBJS = ${SRC:.c=.o}
NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
LIBFT_PATH = ./libft
CFLAGS = -Werror -Wextra -Wall
RM = rm -f

# Define colors
DEF_COLOR = \033[0;39m
ORANGE = \033[0;33m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: ${NAME}

${NAME}: libft ${OBJS}

	@ ar rcs ${NAME} ${OBJS}

libft:
	if [ ! -d "$(LIBFT_PATH)" ]; then \
        echo "downloading libft..."; \
		git clone git@github.com:Sergio0227/Libft.git $(LIBFT_PATH); \
	fi
	${MAKE} -C ${LIBFT_PATH}
	@cp $(LIBFT_PATH)/$(LIBFTNAME) .
	@mv ${LIBFT_PATH}/$(LIBFTNAME) $(NAME)

bonus: ${NAME}

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o} 

clean:
	${MAKE} -C ${LIBFT_PATH} clean 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME};
	${RM} ${LIBFTNAME}
	${RM} -rf ${LIBFT_PATH}

re: fclean all

.PHONY: all clean fclean re libft