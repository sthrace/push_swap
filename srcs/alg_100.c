#include "../includes/push_swap.h"

void	ft_sort_100(t_array *data)
{
	while (data->size_a > data->step)
	{
		if (ft_issorted(data->stack_a, data->size_a, 1))
			break ;
		if (data->stack_a[0] > data->stack_a[1])
			ft_swap(data, 'a', 1);
		while (data->stack_a[0] != data->stack_s[data->size - data->size_a])
		{
			if (ft_position(data->stack_a, data->size_a, data->stack_s[data->size - data->size_a]) < data->size_a / 2)
				ft_rotate(data, 'a', 1);
			else
				ft_revrotate(data, 'a', 1);
		}
		ft_push(data, 'b', 1);
	}
	while (data->size_b > 0)
	{
		if (ft_issorted(data->stack_b, data->size_b, 2))
			break ;
		if (data->stack_b[0] < data->stack_b[1])
			ft_swap(data, 'b', 1);
		while (data->stack_b[0] != data->stack_s[data->size - data->size_a - 1])
		{
			if (ft_position(data->stack_b, data->size_b, data->stack_s[data->size - data->size_a - 1]) < data->size_b / 2)
				ft_rotate(data, 'b', 1);
			else
				ft_revrotate(data, 'b', 1);
		}
		ft_push(data, 'a', 1);
	}
	data->step += 2;
}