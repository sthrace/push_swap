#include "../includes/push_swap.h"

void	ft_sort_100(t_array *data)
{
	while (1)
	{
		if (ft_issorted(data->stack_a, data->size_a))
			break ;
		while (data->stack_a[0] != ft_minmax(data->stack_a, data->size_a, 0, -1))
		{
			if (data->stack_a[data->size_a - 1] == ft_minmax(data->stack_a, data->size_a, 0, -1))
				ft_revrotate(data, 'a', 1);
			else if (ft_position(data->stack_a, data->size_a, ft_minmax(data->stack_a, data->size_a, 0, -1)) < data->size_a / 2)
				ft_rotate(data, 'a', 1);
			else
				ft_revrotate(data, 'a', 1);
		}
		ft_push(data, 'b', 1);
		if (data->stack_a[0] >= data->median)
			ft_rotate(data, 'a', 1);
		else if (data->stack_a[0] < data->median)
			ft_push(data, 'b', 1);
	}
	while (data->size_b > 0)
		ft_push(data, 'a', 1);
}