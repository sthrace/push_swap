#include "../includes/push_swap.h"

void	ft_sort_5(t_array *data)
{
	while (data->size_a > 3)
	{
		while (data->stack_a[0] != ft_minmax(data->stack_a, data->size_a, 10, -1))
		{
			if (ft_index(data->stack_a, data->size_a, (ft_minmax(data->stack_a, data->size_a, 10, -1))) <= data->size_a / 2)
				ft_rotate(data, 'a', 1);
			else
				ft_revrotate(data, 'a', 1);
		}
		ft_push(data, 'b', 1);
	}
	ft_sort_3(data);
	while (data->size_b > 0)
		ft_push(data, 'a', 1);
}

void	ft_sort_3(t_array *data)
{
	while (!ft_issorted(data->stack_a, data->size_a, 1))
	{
		if (ft_index(data->stack_a, data->size_a, (ft_minmax(data->stack_a, data->size_a, 10, -1))) == 0)
		{
			ft_swap(data, 'a', 1);
			ft_rotate(data, 'a', 1);
		}
		else if (ft_index(data->stack_a, data->size_a, (ft_minmax(data->stack_a, data->size_a, 10, -1))) == 1)
		{
			if (data->stack_a[0] < data->stack_a[2])
				ft_swap(data, 'a', 1);
			else
				ft_rotate(data, 'a', 1);;
		}
		else
		{
			if (data->stack_a[0] < data->stack_a[1])
				ft_revrotate(data, 'a', 1);
			else
			{
				ft_swap(data, 'a', 1);
				ft_revrotate(data, 'a', 1);
			}
		}
	}
}