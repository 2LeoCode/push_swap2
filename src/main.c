#include <push_swap.h>

static void	push_swap(t_stack *a, t_stack *b)
{
	(void)b;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	save_stacks(&a, &b);
	if (lst_init(&a) || lst_init(&b))
		return (exception(bad_alloc));
	if (parse_arguments(a, argc, argv))
		return (-1);
	push_swap(a, b);
	clear_stacks();
	return (0);
}
