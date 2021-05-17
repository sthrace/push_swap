#include "../includes/push_swap.h"

int	ft_issorted(int *stack, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (i > 0 && (stack[i] < stack[i - 1]))
			return (0);
	return (1);
}

int	ft_position(int *stack, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == value)
			break;
		i++;
	}
	return (i);
}

int	ft_minmax(int *stack, int size, int type, int i)
{
	int	min;
	int	max;

	max = -2147483648;
	min = 2147483647;
	if (type == 0)
	{
		if (size > 0)
			while (++i < size)
				if (stack[i] < min)
					min = stack[i];
		return (min);
	}
	if (type == 1)
	{
		if (size > 0)
			while (++i < size)
				if (stack[i] > max)
					max = stack[i];
		return (max);
	}
	return (0);
}

void	sort_input(t_array *data, unsigned long long *stack, int size)
{
	int			i;
	int			j;
	long		tmp;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - j - 1)
		{
			if (stack[i] > stack[i + 1])
			{
				tmp = stack[i];
				stack[i] = stack[i + 1];
				stack[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
	data->median = stack[size / 2];
}