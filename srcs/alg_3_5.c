#include "../includes/push_swap.h"

static void	ft_sort5_utils(t_array *data, int type)
{
	if (type == 1)
	{
		if (data->stack_a[data->size_a - 1] == ft_minmax(data->stack_a, data->size_a, 0, -1))
			ft_revrotate(data, 'a', 1);
		if (!ft_issorted(data->stack_a, data->size_a))
			ft_push(data, 'b', 1);
	}
	if (type == 2)
	{
		while (ft_position(data->stack_a, data->size_a, ft_minmax(data->stack_a, data->size_a, 0, -1)))
			ft_rotate(data, 'a', 1);
		if (!ft_issorted(data->stack_a, data->size_a))
			ft_push(data, 'b', 1);
	}
	if (type == 3)
	{
		while (ft_position(data->stack_a, data->size_a, ft_minmax(data->stack_a, data->size_a, 0, -1)))
			ft_revrotate(data, 'a', 1);
		if (!ft_issorted(data->stack_a, data->size_a))
			ft_push(data, 'b', 1);
	}
}

void	ft_sort_5(t_array *data)
{
	while (1)
	{
		if (ft_issorted(data->stack_a, data->size_a))
			break ;
		if ((data->stack_a[0] == ft_minmax(data->stack_a, data->size_a, 0, -1)) || (data->stack_a[data->size_a - 1] == ft_minmax(data->stack_a, data->size_a, 0, -1)))
			ft_sort5_utils(data, 1);
		if (ft_position(data->stack_a, data->size_a, ft_minmax(data->stack_a, data->size_a, 0, -1)) <= data->size_a / 2)
			ft_sort5_utils(data, 2);
		if (ft_position(data->stack_a, data->size_a, ft_minmax(data->stack_a, data->size_a, 0, -1)) > data->size_a / 2)
			ft_sort5_utils(data, 3);
	}
	while (data->size_b > 0)
		ft_push(data, 'a', 1);
}

void	ft_sort_3(t_array *data)
{
	while (1)
	{
		if (ft_issorted(data->stack_a, data->size_a))
			break ;
		if (data->stack_a[0] == ft_minmax(data->stack_a, data->size_a, 1, -1))
			ft_rotate(data, 'a', 1);
		if (data->stack_a[data->size_a - 1] == ft_minmax(data->stack_a, data->size_a, 0, -1))
			ft_revrotate(data, 'a', 1);
		if (data->stack_a[0] > data->stack_a[1])
			ft_swap(data, 'a', 1);
		if (data->stack_a[1] == ft_minmax(data->stack_a, data->size_a, 1, -1))
		{
			if (data->size_a == 3)
			{
				if (data->stack_a[0] > data->stack_a[2])
					ft_revrotate(data, 'a', 1);
				else
					ft_swap(data, 'a', 1);
			}
		}
	}
}