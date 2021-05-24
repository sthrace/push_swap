#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_array	data;

	ft_memset(&data, 0, sizeof(data));
	if (argc == 1)
		return (1);
	else
	{
		data.cnt_a = 0;
		validate_array(argc, argv);
		parse_argv(&data, argc, argv, 1);
		check_dups(data);
		if (data.cnt_a < 4)
			sort_3(&data);
		else if (data.cnt_a < 6)
			sort_5(&data);
		else if (data.cnt_a < 101)
			sort_100(&data, 20);
		else
			sort_500(&data, 50);
	}
	return (0);
}
