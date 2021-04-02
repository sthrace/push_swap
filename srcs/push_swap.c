#include "../includes/push_swap.h"

int     main(int argc, char **argv)
{
    t_array     *data;
    int         i;

    if (!(data = (t_array *)malloc(sizeof(t_array))))
        ft_exit(0);
    data->size = argc - 1;
    i = 1;
    if (argc == 1)
        ft_exit(0);
    else if (argc == 2)
        ft_exit(1);
    else
    {
        ft_check_ascii(argv);
        ft_populate_array(data, argv);
        ft_check_duplicates(*data);
        ft_init_alg(data);
    }
    return (0);
}