#include "../includes/push_swap.h"

void	ft_sort(t_array *data)
{
	if (data->size < 4)
		ft_sort_3(data);
	else if (data->size < 6)
		ft_sort_5(data);
	else
		ft_sort_100(data);
}