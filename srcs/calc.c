#include "../includes/push_swap.h"

int	ft_mid(int *stack, int size, int value)
{
	int			arr_temp[500];
	int			temp;
	int			i;
	int			j;

	ft_memset(arr_temp, 0, 500);
	i = -1;
	while (++i < size)
		arr_temp[i] = stack[i];
	j = -1;
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
	return(arr_temp[value]);
}

int	ft_minmax(int *stack, int size, int type, int i)
{
	int	min;
	int	max;

	max = INT_MIN;
	min = INT_MAX;
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

int	ft_index(int *stack, int size, int value)
{
	int	i;

	i = -1;
	while (++i < size)
		if (stack[i] == value)
			return(i);
	return (-1);
}

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

void	sorter(int *arr, int size)
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
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}