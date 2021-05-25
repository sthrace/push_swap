#include "../includes/push_swap.h"

void	check_dups(t_array data)
{
	int	temp[500];
	int	i;

	i = -1;
	while (++i < data.cnt_a)
		temp[i] = data.a[i];
	sorter(temp, data.cnt_a);
	i = -1;
	while (++i < data.cnt_a)
		if (i > 0 && temp[i] == temp[i - 1])
			ft_exit();
}

static void	eliminate_sign(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
		{
			if (arg[i] == '-' || arg[i] == '+')
			{
				if (i != 0 || (i == 0 && !arg[i + 1]))
					ft_exit();
			}
			else
				ft_exit();
		}
	}
}

void	validate_array(int argc, char **argv)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], 32))
		{
			temp = ft_split(argv[i], 32);
			j = -1;
			while (temp[++j])
				eliminate_sign(temp[j]);
			ft_free_array(temp);
		}
		else
			eliminate_sign(argv[i]);
	}
}
