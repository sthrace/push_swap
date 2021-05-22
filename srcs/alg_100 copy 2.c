#include "../includes/push_swap.h"

static void	ft_b_to_a(t_array *data)
{
	int	mid_b;
	int	top;
	int	bottom;

	mid_b = ft_get_value(data->stack_b, data->size_b, data->size_b / 2, -1);
	while (mid_b != ft_minmax(data->stack_b, data->size_b, 2, -1))
	{
		top = 0;
		bottom = data->size_b - 1;
		mid_b = ft_get_value(data->stack_b, data->size_b, data->size_b / 2, -1);
		while (data->stack_b[top] > mid_b)
			top++;
		while (data->stack_b[bottom] > mid_b)
			bottom--;
		bottom = data->size_b - bottom;
		if (data->stack_b[0] < data->stack_b[1])
		{
			if (data->stack_a[0] > data->stack_a[1])
				ft_swap(data, 's', 1);
			else
				ft_swap(data, 'b', 1);
		}
		if (top < bottom + 1)
		{
			while (data->stack_b[0] <= mid_b)
			{
				ft_rotate(data, 'a', 1);
				if (data->stack_b[0] == ft_minmax(data->stack_b, data->size_b, 1, -1))
				{
					ft_push(data, 'a', 1);
					if (data->stack_b[0] <= mid_b && data->stack_b[0] != ft_minmax(data->stack_b, data->size_b, 1, -1))
						ft_rotate(data, 'r', 1);
					else
						ft_rotate(data, 'a', 1);
						sleep(1);
				}
			}
			ft_push(data, 'a', 1);
			if (data->stack_b[0] < data->stack_b[1])
			{
				if (data->stack_a[0] > data->stack_a[1])
					ft_swap(data, 's', 1);
				else
					ft_swap(data, 'b', 1);
			}
		}
		else if (bottom < top + 1)
		{
			while (data->stack_b[0] <= mid_b)
			{
				ft_revrotate(data, 'b', 1);
				if (data->stack_b[0] == ft_minmax(data->stack_b, data->size_b, 1, -1))
				{
					ft_push(data, 'a', 1);
					if (data->stack_b[0] <= mid_b && data->stack_b[0] != ft_minmax(data->stack_b, data->size_b, 1, -1))
						ft_rotate(data, 'r', 1);
					else
						ft_rotate(data, 'a', 1);
						sleep(1);
				}
			}
			ft_push(data, 'b', 1);
			if (data->stack_a[0] > data->stack_a[1])
			{
				if (data->stack_b[0] < data->stack_b[1])
					ft_swap(data, 's', 1);
				else
					ft_swap(data, 'a', 1);
			}
		}
		else if (top == bottom + 1)
		{
			if (data->stack_b[top] < data->stack_b[bottom])
			{
				while (data->stack_b[0] <= mid_b)
				{
					ft_rotate(data, 'a', 1);
					if (data->stack_b[0] == ft_minmax(data->stack_b, data->size_b, 1, -1))
					{
						ft_push(data, 'a', 1);
						if (data->stack_b[0] <= mid_b && data->stack_b[0] != ft_minmax(data->stack_b, data->size_b, 1, -1))
							ft_rotate(data, 'r', 1);
						else
							ft_rotate(data, 'a', 1);
							sleep(1);
					}
				}
				ft_push(data, 'a', 1);
				if (data->stack_b[0] < data->stack_b[1])
				{
					if (data->stack_a[0] > data->stack_a[1])
						ft_swap(data, 's', 1);
					else
						ft_swap(data, 'b', 1);
				}
			}
			else
			{
				while (data->stack_b[0] <= mid_b)
				{
					ft_revrotate(data, 'b', 1);
					if (data->stack_b[0] == ft_minmax(data->stack_b, data->size_b, 1, -1))
					{
						ft_push(data, 'a', 1);
						if (data->stack_b[0] <= mid_b && data->stack_b[0] != ft_minmax(data->stack_b, data->size_b, 1, -1))
							ft_rotate(data, 'r', 1);
						else
							ft_rotate(data, 'a', 1);
							sleep(1);
					}
				}
				ft_push(data, 'b', 1);
				if (data->stack_a[0] > data->stack_a[1])
				{
					if (data->stack_b[0] < data->stack_b[1])
						ft_swap(data, 's', 1);
					else
						ft_swap(data, 'a', 1);
				}
			}
		}
	}
}

void	ft_sort_100(t_array *data)
{
	int	mid_a;
	int	mid_b;
	int	top;
	int	bottom;

	mid_a = ft_get_value(data->stack_a, data->size_a, data->size_a / 2, -1);
	while (mid_a != ft_minmax(data->stack_a, data->size_a, 1, -1))
	{
		top = 0;
		bottom = data->size_a - 1;
		mid_b = ft_get_value(data->stack_b, data->size_b, data->size_b / 2, -1);
		while (data->stack_a[top] > mid_a)
			top++;
		while (data->stack_a[bottom] > mid_a)
			bottom--;
		bottom = data->size_a - bottom;
		if (ft_issorted(data->stack_a, data->size_a, 1) && data->stack_a[0] > ft_minmax(data->stack_b, data->size_b, 2, -1))
			break ;
		if (data->stack_a[0] > data->stack_a[1])
		{
			if (data->stack_b[0] < data->stack_b[1])
				ft_swap(data, 's', 1);
			else
				ft_swap(data, 'a', 1);
		}
		if (top < bottom + 1)
		{
			while (data->stack_a[0] >= mid_a)
			{
				if (data->stack_b[0] < mid_b)
					ft_rotate(data, 'r', 1);
				else
					ft_rotate(data, 'a', 1);
			}
			ft_push(data, 'b', 1);
			if (data->stack_a[0] > data->stack_a[1])
			{
				if (data->stack_b[0] < data->stack_b[1])
					ft_swap(data, 's', 1);
				else
					ft_swap(data, 'a', 1);
			}
		}
		else if (bottom < top + 1)
		{
			while (data->stack_a[0] >= mid_a)
			{
				if (data->stack_b[0] < mid_b)
					ft_revrotate(data, 'r', 1);
				else
					ft_revrotate(data, 'a', 1);
			}
			ft_push(data, 'b', 1);
			if (data->stack_a[0] > data->stack_a[1])
			{
				if (data->stack_b[0] < data->stack_b[1])
					ft_swap(data, 's', 1);
				else
					ft_swap(data, 'a', 1);
			}
		}
		else if (top == bottom + 1)
		{
			if (data->stack_a[top] > data->stack_a[bottom])
			{
				while (data->stack_a[0] >= mid_a)
				{
					if (data->stack_b[0] < mid_b)
						ft_rotate(data, 'r', 1);
					else
						ft_rotate(data, 'a', 1);
				}
				ft_push(data, 'b', 1);
				if (data->stack_a[0] > data->stack_a[1])
				{
					if (data->stack_b[0] < data->stack_b[1])
						ft_swap(data, 's', 1);
					else
						ft_swap(data, 'a', 1);
				}
			}
			else
			{
				while (data->stack_a[0] >= mid_a)
				{
					if (data->stack_b[0] < mid_b)
						ft_revrotate(data, 'r', 1);
					else
						ft_revrotate(data, 'a', 1);
				}
				ft_push(data, 'b', 1);
				if (data->stack_a[0] > data->stack_a[1])
				{
					if (data->stack_b[0] < data->stack_b[1])
						ft_swap(data, 's', 1);
					else
						ft_swap(data, 'a', 1);
				}
			}
		}
	}
	// if (data->size_b > 0)
		ft_b_to_a(data);
	// else
	// {
		int	i;
		i = -1;
		while (++i < data->size_a)
			printf("A: %d\n", data->stack_a[i]);
		i = -1;
		while (++i < data->size_b)
			printf("B: %d\n", data->stack_b[i]);
	// }
}