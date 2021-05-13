#include "../includes/push_swap.h"

void	validate_input(t_array *data, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				if (j != 0 || (j == 0 && argv[i][j] != '+' && argv[i][j] != '-'))
					ft_exit(4);
	}
	data->size = 0;
}