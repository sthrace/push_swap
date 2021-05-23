#include "../includes/push_swap.h"
#include <limits.h>

static void	check_dups(t_array *data)
{
	int	i;
	long	*stack;

	i = -1;
	stack = (long *)malloc(sizeof(long) * data->size);
	if (stack == NULL)
		exit(0);
	while (++i < data->size)
	{
		stack[i] = ft_atol(data->argv[i]);
		if (stack[i] > INT_MAX || stack[i] < INT_MIN)
			ft_exit();
	}
	free(stack);
	i = -1;
	while (++i < data->size)
		data->stack[i] = ft_atoi(data->argv[i]);
	ft_sort_array(data->stack, data->size);
	i = -1;
	while (++i < data->size)
		if (i > 0 && (data->stack[i] == data->stack[i - 1]))
			ft_exit();
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
	check_dups(data);
	if (data->size == 1)
        exit(0);
}