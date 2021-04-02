#include "../includes/push_swap.h"

static void ft_midpoint_a(t_array *data)
{
    int     i;

    i = 0;
    data->sum = 0;
    while (data->stack_a[i])
    {
        data->sum += data->stack_a[i];
        i++;
    }
    if (data->size_a % 2 == 1)
        data->midpoint = data->sum / data->size_a;
    else
        data->midpoint = data->sum / data->size_a + 1;
}

// static void ft_midpoint_b(t_array *data)
// {
//     int     i;

//     i = 0;
//     data->sum = 0;
//     while (data->stack_b[i])
//     {
//         data->sum += data->stack_b[i];
//         i++;
//     }
//     if (data->size_b % 2 == 1)
//         data->midpoint = data->sum / data->size_b;
//     else
//         data->midpoint = data->sum / data->size_b + 1;
// }

static void ft_add_a(t_array *data)
{
    ft_push_a(data);
    if (data->size_b > 1)
    {
        if (data->stack_b[0] < data->stack_b[1])
            ft_rotate_b(data);
        else
            ft_push_a(data);
        ft_push_a(data); 
    }
}

static void ft_shift_a(t_array *data)
{
    data->size = 0;
}

static void ft_shift_b(t_array *data)
{
    data->size_half = data->size_a / 2;
    while (data->size_half < data->size_a)
    {
        if (data->size_a == 2)
        {
            if (*data->stack_a > *data->stack_a + 1)
                ft_swap_a(data);
            break ;
        }
        if (*data->stack_a < data->midpoint)
            ft_push_b(data);
        else if (data->stack_a[data->size_a - 1] < data->midpoint)
        {
            ft_revrotate_a(data);
            ft_push_b(data);
        }
        else
            ft_rotate_a(data);
    }
    if (data->size_a > 2)
        ft_init_alg(data);
    else
        ft_add_a(data);
}

void        ft_init_alg(t_array *data)
{
    ft_midpoint_a(data);
    ft_shift_b(data);
    ft_shift_a(data);
    int i;
    i = 0;
    while (data->stack_a[i])
    {
        printf("A: %d\n", data->stack_a[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while (data->stack_b[i])
    {
        printf("B: %d\n", data->stack_b[i]);
        i++;
    }
}