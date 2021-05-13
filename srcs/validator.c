#include "../includes/push_swap.h"

void	sort_inpot(t_array *data)
{
	int	i;

	i = 0;
	while (data->stack[++i])
	{
		;
	}
}

void	validate_input(t_array *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->stack[++i])
	{
		j = -1;
		while (data->stack[i][++j])
			if (!ft_isdigit(data->stack[i][j]))
				if (j != 0 || (j == 0 && data->stack[i][j] != '+' && data->stack[i][j] != '-'))
					ft_exit(4);
	}
	sort_input(data);
	data->size = 0;
}