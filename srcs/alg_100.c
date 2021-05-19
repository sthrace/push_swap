#include "../includes/push_swap.h"

void	ft_sort_100(t_array *data)
{
	int	i;

	data->mid_a = ft_find_mid(data->stack_a, data->size_a);
	i = ft_index(data->stack_a, data->size_a, data->mid_a);
	printf("Mid is: %d\n", data->mid_a);
	printf("Position of mid is: %d\n", i);
	// while (1)
	// {
	// 	if (ft_issorted(data->stack_a, data->size_a, 1) && data->size_b == 0)
	// 		break ;
		
	// }
}