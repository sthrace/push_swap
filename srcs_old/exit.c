#include "../includes/push_swap.h"

void        ft_exit(int err)
{
    if (err == 0)
        ft_putendl_fd("Error\nNo data is provided for sorting", 2);
    if (err == 1)
        ft_putendl_fd("Error\nOnly one argument provided for sorting", 2);
    if (err == 2)
        ft_putendl_fd("Error\nHeap allocation for data array failed", 2);
    if (err == 3)
        ft_putendl_fd("Error\nArgument must be integer", 2);
    if (err == 4)
        ft_putendl_fd("Error\nOnly all positive or all negative intigers", 2);
    if (err == 5)
        ft_putendl_fd("Error\nArguments must not repeat", 2);
    if (err == 6)
        ft_putendl_fd("Error\nInteger overflow", 2);
    if (err == 7)
        ft_putendl_fd("Error\nOperation type is undefined", 2);
    exit (0);    
}