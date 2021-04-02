#include "../includes/push_swap.h"

void        ft_revrotate_a(t_array *data)
{
    int     tmp;

    if (data->size_a > 0)
    {
        tmp = data->stack_a[data->size_a - 1];
        ft_memmove(&data->stack_a[1], &data->stack_a[0], sizeof(int) * (data->size_a - 1));
        data->stack_a[0] = tmp;
        write(1, "rra\n", 4);
    }
}

void        ft_revrotate_b(t_array *data)
{
    int     tmp;

    if (data->size_b > 0)
    {
        tmp = data->stack_b[data->size_b - 1];
        ft_memmove(&data->stack_b[1], &data->stack_b[0], sizeof(int) * (data->size_b - 1));
        data->stack_b[0] = tmp;
        write(1, "rrb\n", 4);
    }
}

void        ft_revrotate_r(t_array *data)
{
    int     tmp;

    if (data->size_a > 0)
    {
        tmp = data->stack_a[data->size_a - 1];
        ft_memmove(&data->stack_a[1], &data->stack_a[0], sizeof(int) * (data->size_a - 1));
        data->stack_a[0] = tmp;
    }
    if (data->size_b > 0)
    {
        tmp = data->stack_b[data->size_b - 1];
        ft_memmove(&data->stack_b[1], &data->stack_b[0], sizeof(int) * (data->size_b - 1));
        data->stack_b[0] = tmp;
    }
    write(1, "rrr\n", 4);
}