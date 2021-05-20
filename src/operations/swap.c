#include <push_swap.h>

void	sa(t_stack *a, t_stack *b)
{
	t_stack	*new_top;

	(void)b;
	if (lst_size(a) < 2)
		return ;
	new_top = a->prev->prev;
	a->prev->prev = new_top->prev;
	a->prev->next = new_top;
	new_top->prev = a->prev;
	new_top->next = a;
	a->prev = new_top;
}

void	sb(t_stack *a, t_stack *b)
{
	sa(b, a);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}
