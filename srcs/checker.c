#include "../includes/push_swap.h"

static void	populate_stacks(t_array *data, int argc)
{
	int	i;

	i = -1;
	while (++i < data->size)
	{
		data->stack_a[i] = ft_atoi(data->argv[i]);
		if (argc == 2)
			free(data->argv[i]);
		data->stack_b[i] = 0;
	}
	if (argc == 2)
		free(data->argv);
}

static void	init_array(t_array *data)
{
	data->stack = (long *)ft_calloc(data->size, sizeof(long));
	data->stack_a = (int *)ft_calloc(data->size, sizeof(int));
    data->stack_b = (int *)ft_calloc(data->size, sizeof(int));
	if (data->stack == NULL || data->stack_a == NULL || data->stack_b == NULL)
		ft_exit();
    data->size_a = data->size;
    data->size_b = 0;
}

static void	ft_validate_args(t_array *data, int argc, char **argv)
{
	int	i;

	if (data == NULL)
        ft_exit();
	if (argc == 1)
        exit(0);
	if (argc == 2)
		data->argv = ft_split(argv[1], 32);
	if (argc > 2)
		data->argv = argv + 1;
	data->size = 0;
	i = -1;
	while (data->argv[++i] != NULL)
		data->size++;
}

int	main(int argc, char **argv)
{
	t_array     *data;
	char		*cmd;
	char		buf[1];

	data = (t_array *)malloc(sizeof(t_array));
	ft_validate_args(data, argc, argv);
    init_array(data);
	validate_input(data);
	populate_stacks(data, argc);
	cmd = ft_strdup("");
	while (read(0, &buf, 1) > 0)
	{
		if (buf[0] == 32)
			ft_exit();
		cmd = ft_charjoin(cmd, buf[0]);
		if (buf[0] == '\n')
		{
			buf[0] = '\0';
			set_instructions(data, cmd);
			free(cmd);
			cmd = ft_strdup("");
		}
	}
	free(cmd);
	ft_output(data);
    return (0);
}