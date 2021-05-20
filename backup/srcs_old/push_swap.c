#include "../includes/push_swap.h"

static void     ft_check_duplicates(int *array_a, int size)
{
    int         i;
    int         j;
    int         *temp;

    temp = array_a;
    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (array_a[i] == temp[j])
                ft_exit(5);
            if (array_a[i] > 2147483647 || array_a[i] < -2147483648)
                ft_exit(6);
            j++;
        }
        i++;
    }
}

static void     ft_populate_array(int size, char **argv)
{
    int     *array_a;
    int     *array_b;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (!(array_a = (int *)malloc(sizeof(int) * (size))))
        ft_exit(2);
    if (!(array_b = (int *)ft_calloc(size, sizeof(int))))
        ft_exit(2);
    while (argv[++i])
    {
        array_a[j] = (int)ft_atoi(argv[i]);
        j++;
    }
    if (ft_find_max(array_a, size) >= 0 && ft_find_min(array_a, size) < 0)
        ft_exit(4);
    ft_check_duplicates(array_a, size);
    ft_start_sort(array_a, array_b, size);
}

static void     ft_check_argv(char **argv)
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
                    ft_exit(3);
            }
            j++;
        }
        i++;
    }
}

int     main(int argc, char **argv)
{
    int     size;

    size = argc - 1;
    if (argc == 1)
        ft_exit(0);
    else if (argc == 2)
        ft_exit(1);
    else
    {
        ft_check_argv(argv);
        ft_populate_array(size, argv);
    }
    return (0);
}