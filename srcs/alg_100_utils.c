#include "../includes/push_swap.h"

static void	push_rotate(t_array *data, int type)
{
	if (type == 1)
	{
		ft_push(data, 'a', 1);
		ft_rotate(data, 'a', 1);
	}
	if (type == 2)
	{
		if (data->b[0] < data->b[data->cnt_b - 1])
			ft_rotate(data, 'r', 1);
		else
			ft_rotate(data, 'a', 1);
	}
	if (type == 3)
	{
		if (data->b[0] < data->b[data->cnt_b - 1])
			ft_revrotate(data, 'r', 1);
		else
			ft_revrotate(data, 'a', 1);
	}
}

static void	set_values_b(t_array *data, int *top, int *bottom)
{
	*top = 0;
	*bottom = data->cnt_b - 1;
	while (data->b[*top] != ft_minmax(data->b, data->cnt_b, 1, -1) \
	&& data->b[*top] != ft_minmax(data->b, data->cnt_b, 2, -1))
		*top += 1;
	while (data->b[*bottom] != ft_minmax(data->b, data->cnt_b, 1, -1) \
	&& data->b[*bottom] != ft_minmax(data->b, data->cnt_b, 2, -1))
		*bottom -= 1;
	if (data->b[*top] == ft_minmax(data->a, data->cnt_a, 2, -1))
		*top -= 1;
	else if (data->b[*bottom] == ft_minmax(data->a, data->cnt_a, 2, -1))
		*bottom -= 1;
	*bottom = data->cnt_b - *bottom;
}

static void	set_values_a(t_array *data, int *top, int *bottom)
{
	*top = 0;
	*bottom = data->cnt_a - 1;
	while (data->a[*top] > data->value)
		*top += 1;
	while (data->a[*bottom] > data->value)
		*bottom -= 1;
	*bottom = data->cnt_a - *bottom;
}

void	data_to_a(t_array *data)
{
	int	top;
	int	bottom;

	set_values_b(data, &top, &bottom);
	if (top < bottom)
	{
		while (top--)
			ft_rotate(data, 'b', 1);
		if (data->b[0] == ft_minmax(data->b, data->cnt_b, 1, -1))
			push_rotate(data, 1);
		else
			ft_push(data, 'a', 1);
	}
	else
	{
		while (bottom--)
			ft_revrotate(data, 'b', 1);
		if (data->b[0] == ft_minmax(data->b, data->cnt_b, 1, -1))
			push_rotate(data, 1);
		else
			ft_push(data, 'a', 1);
	}
}

void	data_to_b(t_array *data, int *pushed)
{
	int	top;
	int	bottom;

	set_values_a(data, &top, &bottom);
	if (top < bottom)
	{
		while (top--)
			push_rotate(data, 2);
		ft_push(data, 'b', 1);
		*pushed += 1;
	}
	else
	{
		while (bottom--)
			push_rotate(data, 3);
		ft_push(data, 'b', 1);
		*pushed += 1;
	}
}
