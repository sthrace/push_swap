#include "../includes/push_swap.h"

static void	check_dups(t_array *data)
{
	int	i;

	i = -1;
	while (++i < data->size)
		if (i > 0 && (data->stack[i] == data->stack[i - 1]))
			ft_exit();
}

static void	stack_input(t_array *data)
{
	int	i;

	i = -1;
	while (++i < data->size)
	{
		data->stack[i] = ft_atol(data->argv[i]);
		if (data->stack[i] > INT_MAX)
			ft_exit();
	}
}

void	validate_input(t_array *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->size)
	{
		if (ft_strlen(data->argv[i]) > 10)
			ft_exit();
		j = -1;
		while (data->argv[i][++j])
		{
			if (!ft_isdigit(data->argv[i][j]))
			{
				if (j != 0 || (j == 0 && (data->argv[i][j] != '+' && data->argv[i][j] != '-')))
					ft_exit();
				else if (j == 0 && (data->argv[i][j] == '-' || data->argv[i][j] == '+') && !data->argv[i][j + 1])
					ft_exit();
			}
		}
	}
	stack_input(data);
	sort_input(data, data->stack, data->size);
	check_dups(data);
	if (data->size == 1)
        exit(0);
}