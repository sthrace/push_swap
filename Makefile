NAME = push_swap
NAME_C = checker

SRCS = srcs/push_swap.c \
		srcs/exit.c \
		srcs/validator.c \
		srcs/utils.c \
		srcs/sort.c \
		srcs/operations.c \
		srcs/alg_3_5.c \
		srcs/alg_100.c

SRCS_C = srcs/checker.c \
		srcs/validator.c \
		srcs/exit.c \
		srcs/utils.c \
		srcs/operations.c \
		srcs/checker_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
LIBFT_DIR	= libft/
LIBFT		= $(LIBFT_DIR)libft.a

CC = clang
CFLAGS = -g3 -Wall -Werror -Wextra

RM = rm -rf

all:		$(NAME)

$(NAME):	library COMP $(OBJS) $(NAME_C) DONE
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(NAME_C):	COMP $(OBJS_C) DONE
			@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) $(LIBFT)

%.o: %.c
			$(CC) -c $(CFLAGS) -o $@ $<
			printf "$(CYAN)██"		

library:		
			@$(MAKE) -C $(LIBFT_DIR)

clean:		CLEAN
			@$(RM) $(OBJS)
			@$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean FCLEAN LIBFCLEAN
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)

re:			fclean all

leaks:
			valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

git:
			make fclean
			git add .
			git commit -m "commit"
			git push

.PHONY:		all clean fclean re
.SILENT:

COMP:
	echo "\n$(CYAN)COMPILING $(NAME)$(DEFAULT)"
DONE:
	echo "\n$(CYAN)COMPILED $(NAME)$(DEFAULT)"
CLEAN:
	echo "\n$(YELLOW)REMOVING $(NAME) OBJECT FILES $(DEFAULT)"
FCLEAN:
	echo "$(RED)REMOVING $(NAME) EXECUTABLE$(DEFAULT)"
LIBFCLEAN:
	echo "$(RED)REMOVING libft.a LIBRARY $(DEFAULT)"

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
DEFAULT = \033[0m