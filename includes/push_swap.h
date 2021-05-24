#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_array
{
    int     a[500];
    int     b[500];
    int     cnt_a;
    int     cnt_b;
	int		mid_a;
	int		mid_b;
	int		value;
}              t_array;

// utils.c //

void	parse_argv(t_array *data, int argc, char **argv, int i);
void	ft_free_array(char **array);
void	ft_exit(void);

// validator.c //

void	validate_array(int argc, char **argv);
void	check_dups(t_array data);

// calc.c //

void	sorter(int *arr, int size);
int		ft_issorted(int *stack, int size, int type);
int		ft_index(int *stack, int size, int value);
int		ft_minmax(int *stack, int size, int type, int i);
int		ft_value(int *stack, int size, int index);
int		ft_top_5(int *stack, int size);

// operations.c //

void	ft_swap(t_array *data, int param, int type);
void	ft_push(t_array *data, int param, int type);
void	ft_rotate(t_array *data, int param, int type);
void	ft_revrotate(t_array *data, int param, int type);

// alg_3_5.c //

void	sort_3(t_array *data);
void	sort_5(t_array *data);
void	revsort_3(t_array *data);
void	revsort_5(t_array *data);

// alg_100.c //

void	sort_100(t_array *data, int chunk);
void	sort_500(t_array *data, int chunk);
void	ft_b_to_a(t_array *data);

// alg_100_utils.c //

void	data_to_b(t_array *data, int *pushed);
void	data_to_a(t_array *data);

#endif
