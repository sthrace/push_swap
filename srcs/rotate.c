#include "../includes/push_swap.h"

void        ft_rotate_a(t_array *data)
{
    int     tmp;

    if (data->size_a > 0)
    {
        tmp = data->stack_a[0];
        ft_memmove(&data->stack_a[0], &data->stack_a[1], sizeof(int) * (data->size_a));
        data->stack_a[data->size_a - 1] = tmp;
        write(1, "ra\n", 3);
    }
}

void        ft_rotate_b(t_array *data)
{
    int     tmp;

    if (data->size_b > 0)
    {
        tmp = data->stack_b[0];
        ft_memmove(&data->stack_b[0], &data->stack_b[1], sizeof(int) * (data->size_b));
        data->stack_b[data->size_b - 1] = tmp;
        write(1, "ra\n", 3);
    }
}

void        ft_rotate_r(t_array *data)
{
    int     tmp;

    if (data->size_a > 0)
    {
        tmp = data->stack_a[0];
        ft_memmove(&data->stack_a[0], &data->stack_a[1], sizeof(int) * (data->size_a));
        data->stack_a[data->size_a - 1] = tmp;
    }
    if (data->size_b > 0)
    {
        tmp = data->stack_b[0];
        ft_memmove(&data->stack_b[0], &data->stack_b[1], sizeof(int) * (data->size_b));
        data->stack_b[data->size_b - 1] = tmp;
    }
    write(1, "rr\n", 3);
}