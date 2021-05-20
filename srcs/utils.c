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

int	ft_get_chunk(int *stack, int size, int i, int j)
{
	int			*arr_temp;
	int			temp;

	arr_temp = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		arr_temp[i] = stack[i];
	while (++j < size - 1)
	{
		i = -1;
		while (++i < size - j - 1)
		{
			if (arr_temp[i] > arr_temp[i + 1])
			{
				temp = arr_temp[i];
				arr_temp[i] = arr_temp[i + 1];
				arr_temp[i + 1] = temp;
			}
		}
	}
	i = (arr_temp[4]);
	arr_temp = NULL;
	free(arr_temp);
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

	max = INT_MIN;
	min = INT_MAX;
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
	if (type == 20 || type == 21)
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

void	ft_sort_array(int *stack, int size)
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
}