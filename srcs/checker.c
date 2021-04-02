#include "../includes/push_swap.h"

static void ft_put_r(line)
{
    
}
static void ft_put_p(line)
{
    
}

static void ft_put_s(line)
{

}

static void ft_get_commands()
{
    char    *line;

    line = NULL;
    while (ft_gnl(0, &line))
	{
		if (line[0] == 's')
        {
            if (line[1] == 'a' && line[2] == '\0')
            {

            }
            else if (line[1] == 'b' && line[2] == '\0')
            {

            }
            else if (line[1] == 's' && line[2] == '\0')
            {

            }
            else
            {

            }
        }
		else if (line[0] == 'p')
        {
            if (line[1] == 'a' && line[2] == '\0')
            {

            }
            else if (line[1] == 'b' && line[2] == '\0')
            {

            }
            else
            {

            }
        }
        else if (line[0] == 'r')
        {
            if (line[1] == 'a' && line[2] == '\0')
            {

            }
            else if (line[1] == 'b' && line[2] == '\0')
            {

            }
            else if (line[1] == 'r' && line[2] == '0')
            {

            }
            else if (line[1] == 'r' && line[2] == 'a' && line[3] == '\0')
            {

            }
            else if (line[1] == 'r' && line[2] == 'b' && line[3] == '\0')
            {

            }
            else if (line[1] == 'r' && line[2] == 'r' && line[3] == '\0')
            {

            }
            else
            {
                
            }
        }
	}
}

int     main(int argc, char **argv)
{
    t_array     *data;
    int         i;

    if (!(data = (t_array *)malloc(sizeof(t_array))))
        ft_exit(0);
    data->size = argc - 1;
    i = 1;
    if (argc == 1)
        ft_exit(0);
    else if (argc == 2)
        ft_exit(1);
    else
    {
        ft_get_commands();
        ft_check_ascii(argv);
        ft_populate_array(data, argv);
        ft_check_duplicates(*data);
        ft_is_sorted(*data);
    }
    return (0);
}

