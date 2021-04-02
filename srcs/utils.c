#include "../includes/push_swap.h"

int     ft_find_min(t_array data)
{
    int     min;
    int     i;

    min = 0;
    i = 0;
    while (i < data.size)
    {
        if (data.stack_a[i] < min)
            min = data.stack_a[i];
        i++;
    }
    return (min);
}

int     ft_find_max(t_array data)
{
    int     max;
    int     i;

    max = 0;
    i = 0;
    while (i < data.size)
    {
        if (data.stack_a[i] > max)
            max = data.stack_a[i];
        i++;
    }
    return (max);
}

int     ft_find_poz(int *array, int value, int size)
{
    int     i;
    int     poz;

    i = 0;
    poz = 0;
    while (i < size)
    {
        if (array[i] == value)
            poz = i;
        i++;
    }
    return (poz);
}