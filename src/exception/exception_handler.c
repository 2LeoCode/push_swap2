#include <push_swap.h>

static void	exception_handler(t_stack **a, t_stack **b)
{
	static t_stack	**stack_a = NULL;
	static t_stack	**stack_b = NULL;
	static _Bool	init = false;

	if (!init)
	{
		stack_a = a;
		stack_b = b;
		init = true;
	}
	else
	{
		lst_destroy(*stack_a);
		lst_destroy(*stack_b);
		*stack_a = NULL;
		*stack_b = NULL;
	}
}

void	clear_stacks(void)
{
	exception_handler(NULL, NULL);
}

void	save_stacks(t_stack **a, t_stack **b)
{
	exception_handler(a, b);
}

int	exception(t_exception exception)
{
	ft_putstr_fd("exception caught: ", stderr);
	(*exception)();
	clear_stacks();
	return (-1);
}
