#include "../includes/push_swap.h"

void	sort_5(t_array *data)
{
	if (!ft_issorted(data->a, data->cnt_a, 1))
	{
		while (data->cnt_a > 3)
		{
			while (data->a[0] != ft_minmax(data->a, data->cnt_a, 1, -1))
			{
				if (ft_index(data->a, data->cnt_a, \
				(ft_minmax(data->a, data->cnt_a, 1, -1))) <= data->cnt_a / 2)
					ft_rotate(data, 'a', 1);
				else
					ft_revrotate(data, 'a', 1);
			}
			ft_push(data, 'b', 1);
		}
		sort_3(data);
		while (data->cnt_b > 0)
			ft_push(data, 'a', 1);
	}
}

static void	sort_3_helper(t_array *data, int type)
{
	if (type == 1)
	{
		ft_swap(data, 'a', 1);
		ft_rotate(data, 'a', 1);
	}
	if (type == 2)
	{
		if (data->a[0] < data->a[2])
			ft_swap(data, 'a', 1);
		else
			ft_rotate(data, 'a', 1);
	}
	if (type == 3)
	{
		if (data->a[0] < data->a[1])
			ft_revrotate(data, 'a', 1);
		else
		{
			ft_swap(data, 'a', 1);
			ft_revrotate(data, 'a', 1);
		}
	}
}

void	sort_3(t_array *data)
{
	int	index;

	while (!ft_issorted(data->a, data->cnt_a, 1))
	{
		index = ft_index(data->a, data->cnt_a, \
		(ft_minmax(data->a, data->cnt_a, 1, -1)));
		if (index == 0)
			sort_3_helper(data, 1);
		else if (index == 1)
			sort_3_helper(data, 2);
		else
			sort_3_helper(data, 3);
	}
}
