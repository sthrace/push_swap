#include "../includes/push_swap.h"

void        ft_rotate_a(int *array_a, int size_a)
{
    int     tmp;

    tmp = array_a[0];
    ft_memmove(&array_a[0], &array_a[1], sizeof(int) * (size_a));
    array_a[size_a - 1] = tmp;
    write(1, "ra\n", 3);
}

void        ft_rotate_b(int *array_b, int size_b)
{
    int     tmp;

    tmp = array_b[0];
    ft_memmove(&array_b[0], &array_b[1], sizeof(int) * (size_b));
    array_b[size_b - 1] = tmp;
    write(1, "rb\n", 3);
}

void        ft_rotate_r(int *array_a, int *array_b, int size_a, int size_b)
{
    ft_rotate_a(array_a, size_a);
    ft_rotate_b(array_b, size_b);
    write(1, "rr\n", 3);
}