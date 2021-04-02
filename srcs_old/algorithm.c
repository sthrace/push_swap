#include "../includes/push_swap.h"

void            ft_halve_a(int *array_a, int *array_b, int *size_a, int *size_b, int midpoint)
{
    int     flag;

    flag = 0;
    while (flag <= *size_a / 2 - 1)
    {
        if(*array_a < midpoint)
            ft_push_b(array_a, array_b, size_a, size_b);
        else if (*array_a > midpoint)
            ft_rotate_a(array_a, *size_a);
        flag++;
    }
    // ft_halve_a(array_a, array_b, size_a, size_b, midpoint);
}

void            ft_find_mp(int *array_a, int *array_b, int *size_a, int *size_b)
{
    int     midpoint;
    int     i;
    int     sum;
    
    if (*size_a > 2)
    {
        i = 0;
        sum = 0;
        while (i < *size_a)
        {
            sum += array_a[i];
            i++;
        }
        midpoint = (sum / *size_a);
        ft_halve_a(array_a, array_b, size_a, size_b, midpoint);
    }
    else
    {
        if (array_a[0] > array_a[1])
            ft_swap_a(array_a, *size_a);
    }
    array_b = NULL;
}

void        ft_start_sort(int *array_a, int *array_b, int size)
{
    int     *size_a;
    int     *size_b;
    int     sizea;
    int     sizeb;

    sizea = size;
    sizeb = 0;
    size_a = &sizea;
    size_b = &sizeb;
    ft_find_mp(array_a, array_b, size_a, size_b);
}