#include "../includes/push_swap.h"

// void	ft_b_to_a(t_array *data)
// {
// 	while (data->size_b > 0)
// 	{
// 		if (data->stack_b[0] == ft_minmax(data->stack_b, data->size_b, 20, -1))
// 			ft_push(data, 'a', 1);
// 		else if (data->stack_b[data->size_b - 1] == ft_minmax(data->stack_b, data->size_b, 20, -1))
// 			ft_revrotate(data, 'b', 1);
// 		else if (data->stack_b[1] == ft_minmax(data->stack_b, data->size_b, 20, -1))
// 			ft_swap(data, 'b', 1);
// 		else if (ft_index(data->stack_b, data->size_b, ft_minmax(data->stack_b, data->size_b, 20, -1)) < data->size_b / 2 && ft_index(data->stack_b, data->size_b, ft_minmax(data->stack_b, data->size_b, 20, -1)) > 1)
// 			ft_rotate(data, 'b', 1);
// 		else
// 			ft_revrotate(data, 'b', 1);
// 	}
// }

static void	ft_b_to_a(t_array *data)
{
	int	i;
	int	j;
	int	t;
	int	max;

	while (data->size_b > 0)
	{
		i = 0;
		j = 0;
		max = ft_minmax(data->stack_b, data->size_b, 2, -1);
		t = ft_get_chunk_100(data->stack_b, data->size_b, -1, -1);
		while (data->stack_b[i] < max)
			i++;
		while (data->stack_b[data->size_b - j - 1] < max)
			j++;
		if (j >= i)
		{
			while (i > 0)
			{
				if (i == 1 && data->stack_b[0] > t)
					ft_swap(data, 'b', 1);
				else
					ft_rotate(data, 'b', 1);
				i--;
			}
			ft_push(data, 'a', 1);
		}
		else
		{
			while (j + 1 > 0)
			{
				ft_revrotate(data, 'b', 1);
				j--;
			}
			ft_push(data, 'a', 1);
		}
	}
}

static void	ft_a_to_b(t_array *data)
{
	if (data->stack_b[0] > data->stack_a[0])
		while (data->stack_b[0] < data->stack_a[0])
		{
			if (data->stack_b[0] < data->stack_b[1])
			{
				if (data->stack_a[0] > data->stack_a[1])
					ft_swap(data, 's', 1);
				else
					ft_swap(data, 'b', 1);
			}
			else
				ft_rotate(data, 'b', 1);
		}
			
	ft_push(data, 'b', 1);
}

void	ft_sort_100(t_array *data)
{
	int	i;
	int	j;
	int	k;
	int	t;

	k = 0;
	t = ft_get_chunk_100(data->stack_a, data->size_a, -1, -1);
	if (!ft_issorted(data->stack_a, data->size_a, 1))
	{
		while (k < 20)
		{
			i = 0;
			j = 0;
			while (data->stack_a[i] > t)
				i++;
			while (data->stack_a[data->size_a - j - 1] > t)
				j++;
			if (j >= i)
			{
				while (i > 0)
				{
					if (data->size_b > 1 && (data->stack_b[0] < data->stack_b[data->size_b - 1]))
						ft_rotate(data, 'r', 1);
					else if (i == 0 && data->stack_a[1] <= t)
					{
						if (data->size_b > 1 && data->stack_b[1] > data->stack_b[0])
							ft_swap(data, 's', 1);
						else
							ft_swap(data, 'a', 1);
					}
					else
						ft_rotate(data, 'a', 1);
					i--;
				}
				ft_a_to_b(data);
				k += 1;
			}
			else if (j < i - 1)
			{
				while (j + 1 > 0)
				{
					if (data->size_b > 1 && data->stack_b[data->size_b - 1] > data->stack_b[0])
						ft_revrotate(data, 'r', 1);
					else
						ft_revrotate(data, 'a', 1);
					j--;
				}
				ft_a_to_b(data);
				k += 1;
			}
			else if (i == j + 1)
			{
				if (data->stack_a[i] < data->stack_a[j])
				{
					while (i > 0)
					{
						if (data->size_b > 1 && (data->stack_b[0] < data->stack_b[data->size_b - 1]))
							ft_rotate(data, 'r', 1);
						else if (i == 1 && data->stack_a[0] < data->stack_a[data->size_a - 1])
						{
							if (data->size_b > 1 && data->stack_b[1] > data->stack_b[0])
								ft_swap(data, 's', 1);
							else
								ft_swap(data, 'a', 1);
						}
						else
							ft_rotate(data, 'a', 1);
						i--;
					}
				}
				else
				{
					while (j + 1 > 0)
					{
						if (data->size_b > 1 && data->stack_b[data->size_b - 1] > data->stack_b[0])
							ft_revrotate(data, 'r', 1);
						else
							ft_revrotate(data, 'a', 1);
						j--;
					}
				}
				ft_a_to_b(data);
				k += 1;
			}
		}
	}
	if (data->size_a > 0 && !ft_issorted(data->stack_a, data->size_a, 1))
		ft_sort_100(data);
	else
	{
		// i = -1;
		// while (++i < data->size_b)
		// 	printf("B[%d]: %d\n", i, data->stack_b[i]);
		ft_b_to_a(data);
		// i = -1;
		// while (++i < data->size_a)
		// 	printf("A[%d]: %d\n", i, data->stack_a[i]);
	}
}