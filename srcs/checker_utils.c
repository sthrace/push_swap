#include "../includes/push_swap.h"

void	ft_output(t_array *data)
{
	if (ft_issorted(data->stack_a, data->size_a) && data->size_b == 0)
		ft_putendl_fd("\033[1;32mOK\033[0m", 1);
	else
		ft_putendl_fd("\033[1;31mKO\033[0m", 2);
}

void	set_instructions(t_array *data, char *cmd)
{
	if (!strncmp(cmd, "sa", 2) && ft_strlen(cmd) == 3)
		ft_swap(data, 'a', 0);
	else if (!strncmp(cmd, "sb", 2) && ft_strlen(cmd) == 3)
		ft_swap(data, 'b', 0);
	else if (!strncmp(cmd, "ss", 2) && ft_strlen(cmd) == 3)
		ft_swap(data, 's', 0);
	else if (!strncmp(cmd, "pa", 2) && ft_strlen(cmd) == 3)
		ft_push(data, 'a', 0);
	else if (!strncmp(cmd, "pb", 2) && ft_strlen(cmd) == 3)
		ft_push(data, 'b', 0);
	else if (!strncmp(cmd, "ra", 2) && ft_strlen(cmd) == 3)
		ft_rotate(data, 'a', 0);
	else if (!strncmp(cmd, "rb", 2) && ft_strlen(cmd) == 3)
		ft_rotate(data, 'b', 0);
	else if (!strncmp(cmd, "rr", 2) && ft_strlen(cmd) == 3)
		ft_rotate(data, 'r', 0);
	else if (!strncmp(cmd, "rra", 3) && ft_strlen(cmd) == 4)
		ft_revrotate(data, 'a', 0);
	else if (!strncmp(cmd, "rrb", 3) && ft_strlen(cmd) == 4)
		ft_revrotate(data, 'b', 0);
	else if (!strncmp(cmd, "rrr", 3) && ft_strlen(cmd) == 4)
		ft_revrotate(data, 'r', 0);
	else
		ft_exit();
}