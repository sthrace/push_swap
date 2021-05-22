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
	return (0);
}

int	ft_get_chunk_500(int *stack, int size, int i, int j)
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
	if (arr_temp[199])
		i = (arr_temp[199]);
	else
		i = (arr_temp[sizeof(arr_temp) - 1]);
	free(arr_temp);
	arr_temp = NULL;
	return (i);
}

int	ft_get_chunk_100(int *stack, int size, int i, int j)
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
	if (arr_temp[19])
		i = (arr_temp[19]);
	else
		i = (arr_temp[sizeof(arr_temp)]);
	free(arr_temp);
	arr_temp = NULL;
	return (i);
}

int	ft_get_value(int *stack, int size, int value, int j)
{
	int			*arr_temp;
	int			temp;
	int			i;

	arr_temp = (int *)malloc(sizeof(int) * size);
	i = -1;
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
	value = arr_temp[value];
	free(arr_temp);
	return (value);
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
	int	oldmax;

	max = INT_MIN;
	min = INT_MAX;
	oldmax = max;
	if (size > 0)
	{
		while (++i < size)
		{
			if (stack[i] < min)
				min = stack[i];
			if (stack[i] > max)
				max = stack[i];
		}
	}
	if (type == 1)
		return (min);
	if (type == 2)
		return (max);
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