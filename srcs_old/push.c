#include "../includes/push_swap.h"

void        ft_push_a(int *array_a, int *array_b, int *size_a, int *size_b)
{
    if (*size_a > 0)
        ft_memmove(&array_a[1], &array_a[0], sizeof(int) * *(size_a));
    array_a[0] = array_b[0];
    ft_memmove(&array_b[0], &array_b[1], sizeof(int) * *(size_b));
    *size_a += 1;
    *size_b -= 1;
    array_b[*size_b] = 0;
    write(1, "pb\n", 3);
}

void        ft_push_b(int *array_a, int *array_b, int *size_a, int *size_b)
{
    if (*size_b > 0)
        ft_memmove(&array_b[1], &array_b[0], sizeof(int) * *(size_b));
    array_b[0] = array_a[0];
    ft_memmove(&array_a[0], &array_a[1], sizeof(int) * *(size_a));
    *size_a -= 1;
    array_a[*size_a] = 0;
    *size_b += 1;
    write(1, "pb\n", 3);
}