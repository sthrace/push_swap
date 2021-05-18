#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_array
{
	int 	size;
	char	**argv;
    long	*stack;
    int     *stack_a;
    int     *stack_b;
	int		*stack_s;
    int     size_a;
    int     size_b;
	int		size_s;
	int		median;
	int		step;
}              t_array;

// exit.c //

void       ft_exit(void);

// validator.c //

void	validate_input(t_array *data);

// utils.c //

void	ft_sort_array(t_array *data, int *stack, int size);
int		ft_minmax(int *stack, int size, int type, int i);
int		ft_position(int *stack, int size, int value);
int		ft_issorted(int *stack, int size, int type);

// sort.c //

void	ft_sort(t_array *data);

// operations.c //

void	ft_swap(t_array *data, int param, int type);
void	ft_push(t_array *data, int param, int type);
void	ft_rotate(t_array *data, int param, int type);
void	ft_revrotate(t_array *data, int param, int type);

// alg_5.c //

void	ft_sort_5(t_array *data);
void	ft_sort_3(t_array *data);

// alg_100.c //

void	ft_sort_100(t_array *data);

// checker_utils.c

void	set_instructions(t_array *data, char *cmd);
void	ft_output(t_array *data);

#endif
