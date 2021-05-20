#include "../includes/push_swap.h"

static void	check_dups(t_array *data)
{
	int			i;
	int			j;
	long		tmp;

	j = 0;
	while (j < data->size - 1)
	{
		i = 0;
		while (i < data->size - j - 1)
		{
			if (data->stack[i] > data->stack[i + 1])
			{
				tmp = data->stack[i];
				data->stack[i] = data->stack[i + 1];
				data->stack[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
	i = -1;
	while (++i < data->size)
	{
		if (i > 0 && (data->stack[i] == data->stack[i - 1]))
		{
			printf("dup: %ld at: %d\n", data->stack[i], i);
			ft_exit();
		}
	}
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
	check_dups(data);
	if (data->size == 1)
        exit(0);
}