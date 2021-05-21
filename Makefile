NAME = push_swap
NAME_C = checker

SRCS = srcs/push_swap.c \
		srcs/exit.c \
		srcs/validator.c \
		srcs/utils.c \
		srcs/operations.c \
		srcs/alg_3_5.c \
		srcs/alg_100.c \
		srcs/alg_500.c

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
			@$(RM) $(OBJS_C)
			@$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean FCLEAN LIBFCLEAN
			@$(RM) $(NAME)
			@$(RM) $(NAME_C)
			@$(RM) $(LIBFT)

re:			fclean all

leaks:
			valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 1 0 3 7 4 2 8

git:
			make fclean
			git add .
			git commit -m "commit"
			git push

space:
			rm -rf ~/Library/Application\ Support/Code/Cache/*
			rm -rf ~/Library/Application\ Support/Code/CachedData/*
			rm -rf ~/Library/Application Support/Spotify/PersistentCache
			rm -rf ~/Library/Application\ Support/Code/User/workspaceStoragerm -rf ~/Library/Caches/*
			rm -rf ~/Library/42_cache
			rm -rf ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage/
			rm -rf ~/Library/Application\ Support/Slack/Cache/
			rm -rf ~/Library/Application\ Support/Slack/Code\ Cache/
			rm -rf ~/Library/Caches/

.PHONY:		all clean fclean re
.SILENT:

COMP:
	echo "\n$(CYAN)COMPILING $(NAME) $(NAME_C)$(DEFAULT)"
DONE:
	echo "\n$(CYAN)COMPILED $(NAME) $(NAME_C)$(DEFAULT)"
CLEAN:
	echo "\n$(YELLOW)REMOVING $(NAME) $(NAME_C) OBJECT FILES $(DEFAULT)"
FCLEAN:
	echo "$(RED)REMOVING $(NAME) $(NAME_C) EXECUTABLE$(DEFAULT)"
LIBFCLEAN:
	echo "$(RED)REMOVING libft.a LIBRARY $(DEFAULT)"

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
DEFAULT = \033[0m