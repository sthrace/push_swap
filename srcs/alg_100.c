#include "../includes/push_swap.h"

static void	high_a(t_array *data)
{
	int	size;
	int remainder;
	int	goback;

	remainder = data->cnt_a - data->sorted;
	size = remainder / 2;
	data->mid_a = ft_mid(data->a, data->cnt_a - data->sorted, size);
	goback = 0;
	// printf("SizeofA: %d\nMid: %d\n", data->cnt_a - data->sorted, data->mid_a);
	while (remainder >= size)
	{
		data->mid_b = ft_mid(data->b, data->cnt_b, data->cnt_b / 2);
		if (data->a[0] == ft_minmax(data->a, data->moved, 1, -1) && data->a[0] < ft_minmax(data->b, data->cnt_b, 1, -1))
		{
			if (data->b[0] < data->b[data->cnt_b])
				ft_rotate(data, 'r', 1);
			else
				ft_rotate(data, 'a', 1);
			data->sorted++;
		}
		else if (data->a[0] > data->mid_a)
		{
			// printf("Current: %d and mid: %d\n", data->a[0], data->mid_a);
			// printf("Remainder: %d and size: %d\n", remainder, size);
			if (data->b[0] > data->mid_b && data->b[0] != ft_minmax(data->b, data->cnt_b, 1, -1))
			{
				ft_rotate(data, 'r', 1);
				goback++;
			}
			else
			{
				ft_rotate(data, 'a', 1);
				goback++;
			}
		}
		else
		{
			// printf("goback is: %d\n", goback);
			ft_push(data, 'b', 1);
			remainder--;
			while (goback-- > 0)
				ft_revrotate(data, 'a', 1);
		}
	}
	// b_to_a(data);
	// int	i;
	// i = -1;
	// while (++i < data->cnt_a)
	// 	printf("A: %d\n", data->a[i]);
	// i = -1;
	// while (++i < data->cnt_b)
	// 	printf("B: %d\n", data->b[i]);
	// printf("Min top: %d\n", ft_minmax(data->a, data->moved, 1, -1));
}

static void	a_to_b(t_array *data)
{
	while (data->moved > 0)
	{
		if (data->a[0] == ft_minmax(data->a, data->moved, 1, -1) && data->a[0] < ft_minmax(data->b, data->cnt_b, 1, -1))
		{
			if (data->b[0] < data->b[data->cnt_b])
				ft_rotate(data, 'r', 1);
			else
				ft_rotate(data, 'a', 1);
			data->sorted++;
			data->moved--;
		}
		else
		{
			if (data->a[1] == ft_minmax(data->a, data->moved, 1, -1) && data->a[0] < ft_minmax(data->b, data->cnt_b, 1, -1))
			{
				if (data->b[0] < data->b[1])
					ft_swap(data, 's', 1);
				else
					ft_swap(data, 'a', 1);
				ft_rotate(data, 'a', 1);
				data->sorted++;
				data->moved--;
			}
			ft_push(data, 'b', 1);
			data->moved--;
		}
	}
	if (data->cnt_b > 0)
		b_to_a(data);
	else
		high_a(data);
}

void	b_to_a(t_array *data)
{
	int	size;
	int	top;
	int	bottom;

	size = data->cnt_b / 2;
	data->mid_b = ft_mid(data->b, data->cnt_b, data->cnt_b / 2);
	while (data->cnt_b >= size)
	{
		if (data->cnt_b == 2)
		{
			if (data->b[0] < data->b[1])
			{
				if (data->a[0] > data->a[1])
				{
					ft_swap(data, 's', 1);
					ft_push(data, 'a', 1);
					ft_rotate(data, 'a', 1);
					ft_push(data, 'a', 1);
					ft_rotate(data, 'a', 1);
					data->sorted += 2;
				}
				else
				{
					ft_swap(data, 'b', 1);
					ft_push(data, 'a', 1);
					ft_rotate(data, 'a', 1);
					ft_push(data, 'a', 1);
					ft_rotate(data, 'a', 1);
					data->sorted += 2;
				}
			}
			else
			{
				ft_push(data, 'a', 1);
				ft_rotate(data, 'a', 1);
				ft_push(data, 'a', 1);
				ft_rotate(data, 'a', 1);
				data->sorted += 2;
			}
			break ;
		}
		top = 0;
		bottom = data->cnt_b - 1;
		while (data->b[top] < data->mid_b)
			top++;
		while (data->b[bottom] < data->mid_b)
			bottom--;
		bottom = data->cnt_b - bottom;
		if (data->b[0] < data->mid_b)
		{
			if (top < bottom)
			{
				if (data->b[1] == ft_minmax(data->b, data->cnt_b, 1, -1))
				{
					if (data->a[0] > data->a[1])
					{
						ft_swap(data, 's', 1);
						ft_push(data, 'a', 1);
						ft_rotate(data, 'a', 1);
						data->sorted++;
					}
					else
					{
						ft_swap(data, 'b', 1);
						ft_push(data, 'a', 1);
						ft_rotate(data, 'a', 1);
						data->sorted++;
					}
				}
				else
				{
					ft_rotate(data, 'b', 1);
					if (data->b[0] == ft_minmax(data->b, data->cnt_b, 1, -1))
					{
						ft_push(data, 'a', 1);
						ft_rotate(data, 'a', 1);
						data->sorted++;
					}
				}
			}
			else
			{
				ft_revrotate(data, 'b', 1);
				if (data->b[0] == ft_minmax(data->b, data->cnt_b, 1, -1))
				{
					ft_push(data, 'a', 1);
					ft_rotate(data, 'a', 1);
					data->sorted++;
				}
			}
		}
		else
		{
			ft_push(data, 'a', 1);
			data->moved++;
		}
	}
	if (data->cnt_b >= 2)
		b_to_a(data);
	else if (data->moved > 0)
	{
		a_to_b(data);
	// int	i;
	// i = -1;
	// while (++i < data->cnt_a)
	// 	printf("A: %d\n", data->a[i]);
	// i = -1;
	// while (++i < data->cnt_b)
	// 	printf("B: %d\n", data->b[i]);
	// printf("Min top: %d\n", ft_minmax(data->a, data->moved, 1, -1));
	}
}

void	sort_100(t_array *data)
{
	int	size;
	int	top;
	int	bottom;

	size = data->cnt_a   / 2;
	data->mid_a = ft_mid(data->a, data->cnt_a , size);
	while (data->cnt_a >= size)
	{
		top = 0;
		bottom = data->cnt_a - 1;
		data->mid_b = ft_mid(data->b, data->cnt_b, data->cnt_b / 2);
		while (data->a[top] > data->mid_a)
			top++;
		while (data->a[bottom] > data->mid_a)
			bottom--;
		bottom = data->cnt_a - bottom;
		if (data->a[0] > data->mid_a)
		{
			if (top < bottom)
			{
				if (data->b[0] > data->mid_b && data->b[0] != ft_minmax(data->b, data->cnt_b, 1, -1))
					ft_rotate(data, 'r', 1);
				else
					ft_rotate(data, 'a', 1);
			}
			else
			{
				if (data->b[data->cnt_b - 1] > data->mid_b && data->b[0] != ft_minmax(data->b, data->cnt_b, 1, -1))
					ft_revrotate(data, 'r', 1);
				else
					ft_revrotate(data, 'a', 1);
			}
		}
		else
			ft_push(data, 'b', 1);
	}
	b_to_a(data);
	// int	i;
	// i = -1;
	// while (++i < data->cnt_a)
	// 	printf("A: %d\n", data->a[i]);
	// i = -1;
	// while (++i < data->cnt_b)
	// 	printf("B: %d\n", data->b[i]);
	// printf("mid is: %d at: %d\n", data->mid_a, size);
	// printf("pushed from b: %d\n", data->moved);
	// printf("sorted: %d\n", data->sorted);
}