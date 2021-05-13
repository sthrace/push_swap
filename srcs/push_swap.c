#include "../includes/push_swap.h"

int     main(int argc, char **argv)
{
    t_array     *data;

    if (!(data = (t_array *)malloc(sizeof(t_array))))
        ft_exit(0);
    data->size = argc - 1;
    data->stack = argv;
    if (argc == 1)
        ft_exit(1);
    else if (argc == 2)
        ft_exit(2);
    else
    {
		validate_input(data);
    }
    return (0);
}