#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "library.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_array
{
    int     *stack_a;
    int     *stack_b;
    int     size_a;
    int     size_b;
    int     size_half;
    int     size;
    int     midpoint;
    int     sum;
    char    **commands;
}              t_array;


void        ft_init_alg(t_array *data);
void        ft_exit(int err);
void        ft_push_a(t_array *data);
void        ft_push_b(t_array *data);
void        ft_revrotate_a(t_array *data);
void        ft_revrotate_b(t_array *data);
void        ft_revrotate_r(t_array *data);
void        ft_rotate_a(t_array *data);
void        ft_rotate_b(t_array *data);
void        ft_rotate_r(t_array *data);
void        ft_swap_a(t_array *data);
void        ft_swap_b(t_array *data);
void        ft_swap_s(t_array *data);
int         ft_find_poz(int *array, int value, int size);
int         ft_find_max(t_array data);
int         ft_find_min(t_array data);
void        ft_check_ascii(char **argv);
void        ft_populate_array(t_array *data, char **argv);
void        ft_check_duplicates(t_array data);
void        ft_is_sorted(t_array data);

#endif
