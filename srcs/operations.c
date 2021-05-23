#include "../includes/push_swap.h"

void	ft_swap(t_array *data, int param, int type)
{
	int	temp;

	if ((param == 'a' || param == 's') && data->cnt_a > 1)
	{
		temp = data->a[0];
		data->a[0] = data->a[1];
		data->a[1] = temp;
	}
	if ((param == 'b' || param == 's') && data->cnt_b > 1)
	{
		temp = data->b[0];
		data->b[0] = data->b[1];
		data->b[1] = temp;
	}
	if (type == 1)
	{
		if (param == 'a')
			write(1, "sa\n", 3);
		if (param == 'b')
			write(1, "sb\n", 3);
		if (param == 's')
			write(1, "ss\n", 3);
	}
}

void	ft_push(t_array *data, int param, int type)
{
	if (param == 'a' && data->cnt_b > 0)
	{
		if (data->cnt_a > 0)
			ft_memmove(&data->a[1], &data->a[0], sizeof(int) * (data->cnt_a));
		data->a[0] = data->b[0];
		ft_memmove(&data->b[0], &data->b[1], sizeof(int) * (data->cnt_b));
		data->cnt_a++;
		data->cnt_b--;
		if (type == 1)
			write(1, "pa\n", 3);
	}
	if (param == 'b' && data->cnt_a > 0)
	{
		if (data->cnt_b > 0)
			ft_memmove(&data->b[1], &data->b[0], sizeof(int) * (data->cnt_b));
		data->b[0] = data->a[0];
		ft_memmove(&data->a[0], &data->a[1], sizeof(int) * (data->cnt_a));
		data->cnt_b++;
		data->cnt_a--;
		if (type == 1)
			write(1, "pb\n", 3);
	}
}

void	ft_rotate(t_array *data, int param, int type)
{
	int     tmp;

    if ((param == 'a' || param == 'r') && data->cnt_a > 0)
    {
        tmp = data->a[0];
        ft_memmove(&data->a[0], &data->a[1], sizeof(int) * (data->cnt_a));
        data->a[data->cnt_a - 1] = tmp;
        
    }
	if ((param == 'b' || param == 'r') && data->cnt_b > 0)
    {
        tmp = data->b[0];
        ft_memmove(&data->b[0], &data->b[1], sizeof(int) * (data->cnt_b));
        data->b[data->cnt_b - 1] = tmp;
    }
	if (type == 1)
	{
		if (param == 'a')
			write(1, "ra\n", 3);
		if (param == 'b')
			write(1, "rb\n", 3);
		if (param == 'r')
			write(1, "rr\n", 3);
	}
}

void	ft_revrotate(t_array *data, int param, int type)
{
	int     tmp;

    if ((param == 'a' || param == 'r') && data->cnt_a > 0)
    {
        tmp = data->a[data->cnt_a - 1];
        ft_memmove(&data->a[1], &data->a[0], sizeof(int) * (data->cnt_a - 1));
        data->a[0] = tmp;
    }
	if ((param == 'b' || param == 'r') && data->cnt_b > 0)
    {
        tmp = data->b[data->cnt_b - 1];
        ft_memmove(&data->b[1], &data->b[0], sizeof(int) * (data->cnt_b - 1));
        data->b[0] = tmp;
    }
	if (type == 1)
	{
		if (param == 'a')
			write(1, "rra\n", 4);
		if (param == 'b')
			write(1, "rrb\n", 4);
		if (param == 'r')
			write(1, "rrr\n", 4);
	}
}