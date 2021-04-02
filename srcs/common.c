#include "../includes/push_swap.h"

void     ft_is_sorted(t_array data)
{
    int     i;

    i = 1;
    while (i < data.size)
    {
        if (data.stack_a[i] < data.stack_a[i - 1])
            ft_exit(9);
        i++;
    }
    ft_exit(10);
}

void     ft_check_duplicates(t_array data)
{
    int         i;
    int         j;
    int         *temp;

    temp = data.stack_a;
    i = 0;
    while (i < data.size - 1)
    {
        j = i + 1;
        while (j < data.size)
        {
            if (data.stack_a[i] == temp[j])
                ft_exit(6);
            j++;
        }
        i++;
    }
}

void     ft_populate_array(t_array *data, char **argv)
{
    int     i;
    int     j;

    if (!(data->stack_a = (int *)ft_calloc((data->size), sizeof(int))))
        ft_exit(3);
    if (!(data->stack_b = (int *)ft_calloc((data->size), sizeof(int))))
        ft_exit(3);
    i = 1;
    j = 0;
    while (argv[i])
    {
        data->stack_a[j] = (int)ft_atoi(argv[i]);
        i++;
        j++;
    }
    data->stack_a[j] = 0;
    data->size_a = data->size;
    data->size_b = 0;
    if (ft_find_max(*data) >= 0 && ft_find_min(*data) < 0)
        ft_exit(5);
}

void     ft_check_ascii(char **argv)
{
    int     i;
    int     j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (!(ft_isdigit(argv[i][j])))
            {
                if (j == 0 && argv[i][j] == '-')
                    j++;
                else
                    ft_exit(4);
            }
            j++;
        }
        i++;
    }
}