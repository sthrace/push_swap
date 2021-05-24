#include "../includes/push_swap.h"

void	ft_exit(void)
{
	ft_putendl_fd("\033[1;31mError\033[0m", 2);
	exit (1);
}

void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	parse_argv(t_array *data, int argc, char **argv, int i)
{
	int		j;
	int		k;
	char	**temp;

	j = -1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], 32))
		{
			temp = ft_split(argv[i], 32);
			k = -1;
			while (temp[++k])
				data->a[++j] = ft_atol(temp[k]);
			data->cnt_a += k;
			ft_free_array(temp);
			i++;
		}
		else
		{
			data->a[++j] = ft_atol(argv[i]);
			data->cnt_a++;
			i++;
		}
	}
}
