#include <push_swap.h>
#include <stdio.h>

int	parse_arguments(t_stack *a, unsigned int argc, char **argv)
{
	unsigned int	i;
	unsigned int	j;
	long long		val;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (ft_isspace(argv[i][j]))
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+'
						|| ft_isdigit(argv[i][j]))
			{
				val = ft_atoll(&argv[i][j]);
				if (lst_push_back(a, &val, sizeof(long long)))
					return (exception(bad_alloc));
				if (argv[i][j] == '+')
					j++;
				if (argv[i][j] == '-')
					j++;
				while (ft_isdigit(argv[i][j]))
					j++;
			}
			else if (argv[i][j])
				return (exception(invalid_arguments));
		}
	}
	return (0);
}
