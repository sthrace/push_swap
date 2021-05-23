#include "../includes/push_swap.h"

static void	ft_output(t_array *data)
{
	if (ft_issorted(data->a, data->cnt_a, 1) && data->cnt_b == 0)
		ft_putendl_fd("\033[1;32mOK\033[0m", 1);
	else
		ft_putendl_fd("\033[1;31mKO\033[0m", 2);
}

static void	set_instructions(t_array *data, char *cmd)
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

int	main(int argc, char **argv)
{
	t_array data;
	char		*cmd;
	char		buf[1];

	ft_memset(&data, 0, sizeof(data));
	ft_memset(&cmd, 0, 5);
	if (argc == 1)
		return(1);
	else
	{
		data.cnt_a = 0;
		validate_array(argc, argv);
		parse_argv(&data, argc, argv, 1);
		check_dups(data);
		cmd = ft_strdup("");
		while (read(0, &buf, 1) > 0)
		{
			if (buf[0] == 32)
				ft_exit();
			cmd = ft_charjoin(cmd, buf[0]);
			if (buf[0] == '\n')
			{
				buf[0] = '\0';
				set_instructions(&data, cmd);
				free(cmd);
				cmd = ft_strdup("");
			}
		}
		free(cmd);
		ft_output(&data);
	}
	return (0);
}