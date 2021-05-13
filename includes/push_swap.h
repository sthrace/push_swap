#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_array
{
	int 	size;
    char    **stack;
    int     *stack_a;
    int     *stack_b;
    int     *stack_s;
    int     median;
    int     size_a;
    int     size_b;
}              t_array;

void    ft_exit(int err);
void	validate_input(t_array *data);

#endif
