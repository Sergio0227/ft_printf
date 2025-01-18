SRC =   src/ft_printf.c \
		src/print.c \

SRC_BONUS =   	src_bonus/ft_printf.c \
				src_bonus/print.c \
				src_bonus/buffer.c \
				src_bonus/putstr_with_flags.c


SRC_DIR                 = src
SRC_BONUS_DIR           = src_bonus
OBJS_DIR                = ./.objs
OBJS_BONUS_DIR  		= $(OBJS_DIR)/bonus
OBJS                    = $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRC))
OBJS_BONUS              = $(patsubst $(SRC_BONUS_DIR)/%.c, $(OBJS_BONUS_DIR)/%.o, $(SRC_BONUS))
NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
LIBFT_PATH = ./libft
CFLAGS = -Werror -Wextra -Wall
RM = rm -rf


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


${NAME}: libft ${OBJS}
	@ ar rcs ${NAME} ${OBJS}
	

bonus: libft ${OBJS_BONUS}
	@ ar rcs ${NAME} ${OBJS_BONUS}

libft:
	@echo "$(CYAN)DOWNLOADING LIBFT LIBRARY...$(DEF_COLOR)";
	@{ \
		git clone -b gnl_added git@github.com:Sergio0227/Libft.git $(LIBFT_PATH) > /dev/null 2>&1 & \
		pid=$$!; \
		while kill -0 $$pid 2>/dev/null; do \
		echo -n "$(YELLOW)\r[                    ] 0%$(DEF_COLOR)"; sleep 0.25; \
		echo -n "$(YELLOW)\r[####                ] 20%$(DEF_COLOR)"; sleep 0.25; \
		echo -n "$(YELLOW)\r[########            ] 40%$(DEF_COLOR)"; sleep 0.25; \
		echo -n "$(YELLOW)\r[############        ] 60%$(DEF_COLOR)"; sleep 0.2; \
		echo -n "$(YELLOW)\r[################    ] 80%$(DEF_COLOR)"; sleep 0.2; \
		echo -n "$(YELLOW)\r[####################] 100%$(DEF_COLOR)"; sleep 0.2; \
		wait $$pid;  \
		done; \
		echo -n "$(GREEN)\r[####################] DONE$(DEF_COLOR)"; \
		echo ""; \
	}
	@echo "$(MAGENTA)COMPILING LIBFT...$(DEF_COLOR)";
	@${MAKE} -C ${LIBFT_PATH} > /dev/null 2>&1
	@cp $(LIBFT_PATH)/$(LIBFTNAME) .
	@mv ${LIBFT_PATH}/$(LIBFTNAME) $(NAME)
	@echo "$(GREEN)LIBFT LIBRARY MADE$(DEF_COLOR)";

all: ${NAME}

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@echo "$(YELLOW)Compiling $< with flags \"${CFLAGS}\"$(DEF_COLOR)"
	@${CC} ${CFLAGS} -L./ -lft -c $< -o $@
	@echo "$(GREEN)Compilation of $< success$(DEF_COLOR)"

$(OBJS_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJS_BONUS_DIR)
	@echo "$(YELLOW)Compiling $< with flags \"${CFLAGS}\"$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${INC} -c $< -o $@
	@echo "$(GREEN)Compilation of $< success$(DEF_COLOR)"

clean:
	${MAKE} -C ${LIBFT_PATH} clean 
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME};
	${RM} ${LIBFT_PATH}
	${RM} ${LIBFTNAME}

re: fclean all

.PHONY: all clean fclean re