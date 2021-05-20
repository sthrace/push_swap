#include "../includes/push_swap.h"

void     ft_swap_a(int *array_a, int size_a)
{
    int     temp;

    if (size_a < 2)
        return ;
    temp = array_a[0];
    array_a[0] = array_a[1];
    array_a[1] = temp;
    write(1, "sa\n", 3);
}

void     ft_swap_b(int *array_b, int size_b)
{
    int     temp;

    if (size_b < 1)
        return ;
    temp = array_b[0];
    array_b[0] = array_b[1];
    array_b[1] = temp;
    write(1, "sa\n", 3);
}

void     ft_swap_s(int *array_a, int *array_b, int size_a, int size_b)
{
    ft_swap_a(array_a, size_a);
    ft_swap_b(array_b, size_b);
    write(1, "ss\n", 3);
}