#include "../includes/push_swap.h"

void	ft_b_to_a(t_array *data)
{
	while (data->size_b > 0)
	{
		if (data->stack_b[0] == ft_minmax(data->stack_b, data->size_b, 20, -1))
			ft_push(data, 'a', 1);
		else if (ft_index(data->stack_b, data->size_b, ft_minmax(data->stack_b, data->size_b, 20, -1)) < data->size_b / 2)
		{
			while (data->stack_b[0] != ft_minmax(data->stack_b, data->size_b, 20, -1))
			{
				if (data->stack_b[1] > data->stack_b[0])
					ft_swap(data, 'b', 1);
				else
					ft_revrotate(data, 'b', 1);
			}
		}
		else
		{
			while (data->stack_b[0] != ft_minmax(data->stack_b, data->size_b, 20, -1))
				ft_rotate(data, 'b', 1);
		}
	}
}

void	ft_revsort_5(t_array *data, int *k)
{
	if (data->size_b > 1)
	{
		if (data->stack_b[0] < data->stack_b[1])
			ft_swap(data, 'b', 1);
	}
	ft_push(data, 'b', 1);
	*k += 1;
}

void	ft_sort_100(t_array *data)
{
	int	i;
	int	j;
	int	k;
	int	t;

	k = 0;
	t = ft_get_chunk(data->stack_a, data->size_a, -1, -1);
	while (k < 5)
	{
		i = 0;
		j = 0;
		while (data->stack_a[i] > t)
			i++;
		while (data->stack_a[data->size_a - j - 1] > t)
			j++;
		if (i < j)
		{
			while (i > 0)
			{
				ft_rotate(data, 'a', 1);
				i--;
			}
			ft_revsort_5(data, &k);
		}
		else if (j < i)
		{
			while (j > -1)
			{
				ft_revrotate(data, 'a', 1);
				j--;
			}
			ft_revsort_5(data, &k);
		}
		else if (j == i)
		{
			if (data->stack_a[i] < data->stack_a[data->size_a - j - 1])
			while (i > 0)
			{
				ft_rotate(data, 'a', 1);
				i--;
			}
			else
			while (j > -1)
			{
				ft_revrotate(data, 'a', 1);
				j--;
			}
			ft_revsort_5(data, &k);
		}
	}
	if (data->size_a > 0)
		ft_sort_100(data);
	else
	{
		ft_b_to_a(data);
	}
	// else
	// {
	// 	i = -1;
	// 	while (++i < data->size_b)
	// 		printf("stack_b: %d\n", data->stack_b[i]);
	// }
}