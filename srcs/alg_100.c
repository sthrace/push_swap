#include "../includes/push_swap.h"

void	ft_b_to_a(t_array *data)
{
	while (data->cnt_b > 0)
		data_to_a(data);
	if (ft_index(data->a, data->cnt_a, ft_minmax(data->b, \
	data->cnt_b, 1, -1)) > data->cnt_a / 2)
		while (!ft_issorted(data->a, data->cnt_a, 1))
			ft_revrotate(data, 'a', 1);
	else
		while (!ft_issorted(data->a, data->cnt_a, 1))
			ft_rotate(data, 'a', 1);
}

void	sort_100(t_array *data, int chunk)
{
	int	pushed;

	if (ft_issorted(data->a, data->cnt_a, 1))
		return ;
	data->value = ft_value(data->a, data->cnt_a, 19);
	pushed = 0;
	while (data->cnt_b < chunk)
		data_to_b(data, &pushed);
	chunk += pushed;
	if (data->cnt_a > 0 && !ft_issorted(data->a, data->cnt_a, 1))
		sort_100(data, chunk);
	else
		ft_b_to_a(data);
}

void	sort_500(t_array *data, int chunk)
{
	int	pushed;

	data->value = ft_value(data->a, data->cnt_a, 49);
	pushed = 0;
	while (data->cnt_b < chunk)
		data_to_b(data, &pushed);
	chunk += pushed;
	if (data->cnt_a > 0 && !ft_issorted(data->a, data->cnt_a, 1))
		sort_500(data, chunk);
	else
		ft_b_to_a(data);
}
