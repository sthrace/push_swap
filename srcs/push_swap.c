#include "../includes/push_swap.h"

static void	ft_chose_alg(t_array *data)
{
	if (data->size < 4)
		ft_sort_3(data);
	else if (data->size < 6)
		ft_sort_5(data);
	else
		ft_sort_100(data);
}


static void	populate_stacks(t_array *data, int argc)
{
	int	i;

	i = -1;
	while (++i < data->size)
	{
		data->stack_a[i] = ft_atoi(data->argv[i]);
		data->stack_s[i] = ft_atoi(data->argv[i]);
		if (argc == 2)
			free(data->argv[i]);
		data->stack_b[i] = 0;
	}
	if (argc == 2)
		free(data->argv);
	ft_sort_array(data, data->stack_s, data->size_s);
}

static void	init_array(t_array *data)
{
	data->stack = (long *)malloc(sizeof(long) * data->size);
	data->stack_a = (int *)ft_calloc(data->size, sizeof(int));
    data->stack_b = (int *)ft_calloc(data->size, sizeof(int));
	data->stack_s = (int *)ft_calloc(data->size, sizeof(int));
	if (data->stack == NULL || data->stack_a == NULL || data->stack_b == NULL)
		ft_exit();
    data->size_a = data->size;
    data->size_b = 0;
	data->size_s = data->size;
}

static void	ft_validate_args(t_array *data, int argc, char **argv)
{
	int	i;

	if (data == NULL)
        ft_exit();
	if (argc == 1)
        ft_exit();
	if (argc == 2)
		data->argv = ft_split(argv[1], 32);
	if (argc > 2)
		data->argv = argv + 1;
	data->size = 0;
	i = -1;
	while (data->argv[++i] != NULL)
		data->size++;
}

int     main(int argc, char **argv)
{
    t_array     *data;

	data = (t_array *)malloc(sizeof(t_array));
	ft_validate_args(data, argc, argv);
    init_array(data);
	validate_input(data);
	populate_stacks(data, argc);
	ft_chose_alg(data);
    return (0);
}