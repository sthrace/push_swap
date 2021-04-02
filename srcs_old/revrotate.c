#include "../includes/push_swap.h"

void        ft_revrotate_a(int *array_a, int size_a)
{
    int     tmp;

    tmp = array_a[size_a - 1];
    ft_memmove(&array_a[1], &array_a[0], sizeof(int) * (size_a));
    array_a[0] = tmp;
    array_a[size_a] = 0;
    write(1, "rra\n", 4);
}

void        ft_revrotate_b(int *array_b, int size_b)
{
    int     tmp;

    tmp = array_b[size_b - 1];
    ft_memmove(&array_b[1], &array_b[0], sizeof(int) * (size_b));
    array_b[0] = tmp;
    array_b[size_b - 1] = 0;
    write(1, "rrb\n", 4);
}

void        ft_revrotate_r(int *array_a, int *array_b, int size_a, int size_b)
{
    ft_revrotate_a(array_a, size_a);
    ft_revrotate_b(array_b, size_b);
    write(1, "rrr\n", 4);
}