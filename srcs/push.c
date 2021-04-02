#include "../includes/push_swap.h"

void        ft_push_a(t_array *data)
{
    if (data->size_a > 0)
        ft_memmove(&data->stack_a[1], &data->stack_a[0], sizeof(int) * (data->size_a));
    data->stack_a[0] = data->stack_b[0];
    ft_memmove(&data->stack_b[0], &data->stack_b[1], sizeof(int) * (data->size_b));
    data->size_a += 1;
    data->size_b -= 1;
    data->stack_b[data->size_b] = 0;
    write(1, "pa\n", 3);
}

void        ft_push_b(t_array *data)
{
    if (data->size_b > 0)
        ft_memmove(&data->stack_b[1], &data->stack_b[0], sizeof(int) * (data->size_b));
    data->stack_b[0] = data->stack_a[0];
    ft_memmove(&data->stack_a[0], &data->stack_a[1], sizeof(int) * (data->size_a));
    data->size_a -= 1;
    data->size_b += 1;
    data->stack_a[data->size_a] = 0;
    write(1, "pb\n", 3);
}