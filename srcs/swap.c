#include "../includes/push_swap.h"

void     ft_swap_a(t_array *data)
{
    int     temp;

    if (data->size_a < 2)
        return ;
    temp = data->stack_a[0];
    data->stack_a[0] = data->stack_a[1];
    data->stack_a[1] = temp;
    write(1, "sa\n", 3);
}

void     ft_swap_b(t_array *data)
{
    int     temp;

    if (data->size_b < 2)
        return ;
    temp = data->stack_b[0];
    data->stack_b[0] = data->stack_b[1];
    data->stack_b[1] = temp;
    write(1, "sb\n", 3);
}

void     ft_swap_s(t_array *data)
{
    int     temp;

    if (data->size_a < 2)
        return ;
    temp = data->stack_a[0];
    data->stack_a[0] = data->stack_a[1];
    data->stack_a[1] = temp;
    if (data->size_b < 2)
        return ;
    temp = data->stack_b[0];
    data->stack_b[0] = data->stack_b[1];
    data->stack_b[1] = temp;
    write(1, "ss\n", 3);
}