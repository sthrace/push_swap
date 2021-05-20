#include "../includes/push_swap.h"

int	ft_issorted(int *stack, int size, int type)
{
	int	i;

	if (type == 1)
	{
		i = -1;
		while (++i < size)
			if (i > 0 && (stack[i] < stack[i - 1]))
				return (0);
		return (1);
	}
	if (type == 2)
	{
		i = -1;
		while (++i < size)
			if (i > 0 && (stack[i] > stack[i - 1]))
				return (0);
		return (1);
	}
	return (1);
}

int	ft_find_mid(int *stack, int size, int type)
{
	int			i;
	int			j;
	int			*tmp;
	int			temp;

	i = -1;
	tmp = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		tmp[i] = stack[i];
	j = -1;
	while (++j < size - 1)
	{
		i = -1;
		while (++i < size - j - 1)
		{
			if (tmp[i] > tmp[i + 1])
			{
				temp = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = temp;
			}
		}
	}
	if (type == 1)
		i = (tmp[4]);
	if (type == 2)
		i = 4;
	tmp = NULL;
	free(tmp);
	return (i);
}

int	ft_index(int *stack, int size, int value)
{
	int	i;

	i = -1;
	while (++i < size)
		if (stack[i] == value)
			return(i);
	return (-1);
}

int	ft_minmax(int *stack, int size, int type, int i)
{
	int	min;
	int	max;
	int	index;

	max = -2147483648;
	min = 2147483647;
	if (type == 10 || type == 11)
	{
		if (size > 0)
			while (++i < size)
				if (stack[i] < min)
				{
					min = stack[i];
					index = i;
				}
		if (type == 10)
			return (min);
		if (type == 11)
			return (index);
	}
	if (type == 12 || type == 13)
	{
		if (size > 0)
			while (++i < size)
				if (stack[i] > max)
				{
					max = stack[i];
					index = i;
				}
		if (type == 20)
			return (max);
		if (type == 21)
			return (index);
	}
	return (0);
}

void	ft_sort_array(t_array *data, int *stack, int size)
{
	int			i;
	int			j;
	int			tmp;

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
	if (data->size % 2)
		data->mid_s = stack[size / 2 + 1];
	else
		data->mid_s = stack[size / 2];
}