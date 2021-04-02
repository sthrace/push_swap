NAME_P = push_swap
NAME_C = checker

SRCS = srcs/algorithm.c \
		srcs/common.c \
		srcs/exit.c \
		srcs/push.c \
		srcs/revrotate.c \
		srcs/rotate.c \
		srcs/swap.c \
		srcs/utils.c

SRCS_L = library/ft_atoi.c \
		library/ft_calloc.c \
		library/ft_isdigit.c \
		library/ft_memmove.c \
		library/ft_putendl_fd.c \
		library/ft_memset.c \
		library/ft_putstr_fd.c

SRCS_P = srcs/push_swap.c \
		$(SRCS) \
		$(SRCS_L)

SRCS_C = srcs/checker.c \
		$(SRCS) \
		$(SRCS_L)

OBJS_P = $(SRCS_P:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

CC = clang

RM = rm -rf

CFLAGS = -g -Wall -Werror -Wextra

all:		$(NAME_P) $(NAME_C)

%.o: %.c
	# @$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME_P):	$(OBJS_P)
		# @make -C libft
		# @$(CC) $(CFLAGS) -o $(NAME_P) $(OBJS_P) ./libft/libft.a
		@$(CC) $(CFLAGS) -o $(NAME_P) $(OBJS_P)
		@echo Push_swap compiled

$(NAME_C):	$(OBJS_C)
		# @make -C libft
		# @$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) ./libft/libft.a
		@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C)
		@echo Checker compiled

clean:		
		@$(RM) $(OBJS_P) $(OBJS_C)
		# @make clean -C libft
		@echo object files removed

fclean:		clean
		@$(RM) $(NAME_P) $(NAME_C)
		# @make fclean -C libft
		@echo Programs removed

re:		fclean all

.PHONY:		all clean fclean re