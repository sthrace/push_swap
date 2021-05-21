#include "../includes/push_swap.h"

static void	ft_chose_alg(t_array *data)
{
	if (data->size < 4)
		ft_sort_3(data);
	else if (data->size < 6)
		ft_sort_5(data);
	else if (data->size < 101)
		ft_sort_100(data);
	else
		ft_sort_500(data);
}


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
	data->stack = (int *)malloc(sizeof(int) * data->size);
	data->stack_a = (int *)malloc(sizeof(int) * data->size);
    data->stack_b = (int *)malloc(sizeof(int) * data->size);
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
	free(data->stack);
	free(data->stack_a);
	free(data->stack_b);
	free(data);
    return (0);
}