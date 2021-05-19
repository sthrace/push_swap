#include "../includes/push_swap.h"

void	ft_sort_5(t_array *data)
{
	while (1)
	{
		if (ft_issorted(data->stack_a, data->size_a, 1))
			break ;
		if (data->stack_a[0] == data->stack_s[0] || data->stack_a[0] == data->stack_s[1])
		{
			ft_push(data, 'b', 1);
			if (data->size_b > 1 && data->stack_b[0] < data->stack_b[1])
			{
				if (data->stack_a[0] > data->stack_a[1])
					ft_swap(data, 's', 1);
				else if (data->stack_a[0] == data->stack_s[data->size_s - 1])
					ft_rotate(data, 'r', 1);
				else
					ft_swap(data, 'b', 1);
			}
		}
		else if (data->stack_a[0] == data->stack_s[data->size_s - 1])
			ft_rotate(data, 'a', 1);
		else if (data->stack_a[data->size_a - 1] == data->stack_s[0])
			ft_revrotate(data, 'a', 1);
		else if (data->stack_a[0] > data->stack_a[1])
			ft_swap(data, 'a', 1);
		else
			ft_rotate(data, 'a', 1);
	}
	while (data->size_b > 0)
		ft_push(data, 'a', 1);
}

void	ft_sort_3(t_array *data)
{
	while (1)
	{
		if (ft_issorted(data->stack_a, data->size_a, 1))
			break ;
		if (data->stack_a[0] == data->stack_s[data->size_s - 1])
			ft_rotate(data, 'a', 1);
		if (data->stack_a[data->size_a - 1] == data->stack_s[0])
			ft_revrotate(data, 'a', 1);
		if (data->stack_a[0] > data->stack_a[1])
			ft_swap(data, 'a', 1);
		if (data->stack_a[1] == data->stack_s[data->size_s - 1])
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