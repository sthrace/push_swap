#include "../includes/push_swap.h"

// static void	ft_b_to_a(t_array *data)
// {
// 	int	i;

// 	data->mid_b = ft_find_mid(data->stack_b, data->size_b, 1);
// 	i = ft_find_mid(data->stack_b, data->size_b, 2);
// 	while (1)
// 	{
// 		if (i >= data->size_b || data->size_b == 0)
// 			break ;
// 		if (ft_issorted(data->stack_a, data->size_a, 1) && ft_issorted(data->stack_b, data->size_b, 2))
// 		{
// 			while (data->size_b > 0)
// 			{
// 				ft_push(data, 'a', 1);
// 				i++;
// 			}
// 			break ;
// 		}
// 		else if (data->stack_b[0] == ft_minmax(data->stack_b, data->size_b, 1, -1))
// 		{
// 			ft_push(data, 'a', 1);
// 			if (data->stack_a[0] > data->stack_a[1])
// 			{
// 				if (data->stack_b[0] < data->stack_b[1])
// 					ft_swap(data, 's', 1);
// 				else
// 					ft_swap(data, 'a', 1);
// 			}
// 			i++;
// 		}
// 		else
// 			ft_revrotate(data, 'b', 1);
// 	}
// }

static void	ft_sort_2(t_array *data)
{
	data->mid_a = ft_find_mid(data->stack_a, data->size_a, 1);
	data->mid_b = ft_find_mid(data->stack_b, data->size_b, 1);
	while (1)
	{
		if (ft_issorted(data->stack_a, data->size_a, 1) || ft_issorted(data->stack_b, data->size_b, 2))
			break ;
		if (data->stack_a[data->size_a - 1] == data->stack_s[data->size_s - 1] || data->stack_b[data->size_b - 1] == data->stack_s[0])
			break ;
		if (data->stack_a[0] > data->stack_a[1] || data->stack_b[0] < data->stack_b[1])
		{
			if (data->stack_a[0] > data->stack_a[1] && data->stack_b[0] < data->stack_b[1])
				ft_swap(data, 's', 1);
			else if (data->stack_a[0] > data->stack_a[1])
				ft_swap(data, 'a', 1);
			else if (data->stack_b[0] < data->stack_b[1])
				ft_swap(data, 'b', 1);
		}
		else if (data->stack_a[0] > data->mid_a || data->stack_b[0] < data->mid_b)
		{
			if (data->stack_a[0] > data->mid_a && data->stack_b[0] < data->mid_b)
				ft_rotate(data, 'r', 1);
			else if (data->stack_a[0] > data->mid_a)
				ft_rotate(data, 'a', 1);
			else if (data->stack_b[0] < data->mid_b)
				ft_rotate(data, 'b', 1);
		}
		else
		{
			if (!ft_issorted(data->stack_a, data->size_a, 1) && !ft_issorted(data->stack_b, data->size_b, 2))
				ft_revrotate(data, 'r', 1);
			else if (!ft_issorted(data->stack_a, data->size_a, 1))
				ft_revrotate(data, 'a', 1);
			else
				ft_revrotate(data, 'b', 1);
		}
	}
}

static void	ft_a_to_b(t_array *data)
{
	int	i;

	data->mid_a = ft_find_mid(data->stack_a, data->size_a, 1);
	i = ft_find_mid(data->stack_a, data->size_a, 2);
	while (i < data->size_a)
	{
		if (data->stack_a[1] == ft_minmax(data->stack_b, data->size_b, 10, -1))
			ft_swap(data, 'a', 1);
		else if (data->stack_a[data->size_a - 1] == ft_minmax(data->stack_b, data->size_b, 10, -1))
			ft_revrotate(data, 'a', 1);
		else if (data->stack_a[0] <= data->mid_a)
		{
			if (data->size_b)
			{
				while (data->stack_b[0] != ft_minmax(data->stack_b, data->size_b, 10, -1))
				{
					if (ft_minmax(data->stack_b, data->size_b, 11, -1) < data->size_b / 2)
						ft_rotate(data, 'b', 1);
					else
						ft_revrotate(data, 'b', 1);
				}
			}
			ft_push(data, 'b', 1);
			// if (data->size_b > 1)
			// 	ft_rotate(data, 'b', 1);
			i++;
		}
		else
		{
			if (data->)
		}
			ft_rotate(data, 'a', 1);
	}
}

// static void	ft_a_to_b(t_array *data)
// {
// 	int	i;

// 	data->mid_a = ft_find_mid(data->stack_a, data->size_a, 1);
// 	i = ft_find_mid(data->stack_a, data->size_a, 2);
// 	while (i < data->size_a)
// 	{
// 		if (data->stack_a[0] > data->stack_a[1])
// 			ft_swap(data, 'a', 1);
// 		else if (data->stack_a[0] <= data->mid_a)
// 		{
// 			ft_push(data, 'b', 1);
// 			if (data->size_b > 1 && data->stack_b[0] < data->stack_b[1])
// 			{
// 				if (data->stack_a[0] > data->stack_a[1])
// 					ft_swap(data, 's', 1);
// 				else if (data->stack_a[0] == data->stack_s[data->size_s - 1])
// 					ft_rotate(data, 'r', 1);
// 				else
// 					ft_swap(data, 'b', 1);
// 				i++;
// 			}
// 		}
// 		else if (data->stack_a[0] == data->stack_s[data->size_s - 1])
// 			ft_rotate(data, 'a', 1);
// 		else if (data->stack_a[data->size_a - 1] == data->stack_s[0])
// 			ft_revrotate(data, 'a', 1);
// 		else
// 			ft_rotate(data, 'a', 1);
// 	}
// }

void	ft_sort_100(t_array *data)
{
	int	i;

	while (data->size_a > 2)
	{
		ft_a_to_b(data);
		ft_sort_2(data);
		if (ft_issorted(data->stack_a, data->size_a, 1))
			break ;
	}
	// while (data->size_b > 0)
	// {
	// 	ft_b_to_a(data);
	// 	ft_sort_2(data);
	// }
	i = -1;
	while (++i < data->size_b)
	{
		printf("stack_a[%3d]: %3d * stack_b[%3d]: %3d\n", i, data->stack_a[i], i, data->stack_b[i]);
	}
}