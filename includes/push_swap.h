#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_array
{
	int 	size;
    int     *stack_a;
    int     *stack_b;
    int     size_a;
    int     size_b;
}              t_array;

void    ft_exit(int err);
void	validate_input(t_array *data, char **argv);

#endif
