#include "../includes/push_swap.h"

int     ft_find_min(int *array, int size)
{
    int     min;
    int     i;

    min = 0;
    i = 0;
    while (i < size)
    {
        if (array[i] < min)
            min = array[i];
        i++;
    }
    return (min);
}

int     ft_find_max(int *array, int size)
{
    int     max;
    int     i;

    max = 0;
    i = 0;
    while (i < size)
    {
        if (array[i] > max)
            max = array[i];
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