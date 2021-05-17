#include "../includes/push_swap.h"

void	ft_swap(t_array *data, int param, int type)
{
	int	temp;

	if ((param == 97 || param == 115) && data->size_a > 1)
	{
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
	}
	if ((param == 98 || param == 115) && data->size_b > 1)
	{
		temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
	}
	if (type == 1)
	{
		if (param == 97)
			write(1, "sa\n", 3);
		if (param == 98)
			write(1, "sb\n", 3);
		if (param == 115)
			write(1, "ss\n", 3);
	}
}

void	ft_push(t_array *data, int param, int type)
{
	if (param == 97 && data->size_b > 0)
	{
		if (data->size_a > 0)
			ft_memmove(&data->stack_a[1], &data->stack_a[0], sizeof(int) * (data->size_a));
		data->stack_a[0] = data->stack_b[0];
		ft_memmove(&data->stack_b[0], &data->stack_b[1], sizeof(int) * (data->size_b));
		data->size_a++;
		data->size_b--;
		if (type == 1)
			write(1, "pa\n", 3);
	}
	if (param == 98 && data->size_a > 0)
	{
		if (data->size_b > 0)
			ft_memmove(&data->stack_b[1], &data->stack_b[0], sizeof(int) * (data->size_b));
		data->stack_b[0] = data->stack_a[0];
		ft_memmove(&data->stack_a[0], &data->stack_a[1], sizeof(int) * (data->size_a));
		data->size_b++;
		data->size_a--;
		if (type == 1)
			write(1, "pb\n", 3);
	}
}

void	ft_rotate(t_array *data, int param, int type)
{
	int     tmp;

    if ((param == 97 || param == 114) && data->size_a > 0)
    {
        tmp = data->stack_a[0];
        ft_memmove(&data->stack_a[0], &data->stack_a[1], sizeof(int) * (data->size_a));
        data->stack_a[data->size_a - 1] = tmp;
        
    }
	if ((param == 98 || param == 114) && data->size_b > 0)
    {
        tmp = data->stack_b[0];
        ft_memmove(&data->stack_b[0], &data->stack_b[1], sizeof(int) * (data->size_b));
        data->stack_b[data->size_b - 1] = tmp;
    }
	if (type == 1)
	{
		if (param == 97)
			write(1, "ra\n", 3);
		if (param == 98)
			write(1, "rb\n", 3);
		if (param == 114)
			write(1, "rr\n", 3);
	}
}

void	ft_revrotate(t_array *data, int param, int type)
{
	int     tmp;

    if ((param == 97 || param == 114) && data->size_a > 0)
    {
        tmp = data->stack_a[data->size_a - 1];
        ft_memmove(&data->stack_a[1], &data->stack_a[0], sizeof(int) * (data->size_a - 1));
        data->stack_a[0] = tmp;
    }
	if ((param == 98 || param == 114) && data->size_b > 0)
    {
        tmp = data->stack_b[data->size_b - 1];
        ft_memmove(&data->stack_b[1], &data->stack_b[0], sizeof(int) * (data->size_b - 1));
        data->stack_b[0] = tmp;
    }
	if (type == 1)
	{
		if (param == 97)
			write(1, "rra\n", 4);
		if (param == 98)
			write(1, "rrb\n", 4);
		if (param == 114)
			write(1, "rrr\n", 4);
	}
}