#include <push_swap.h>

void	pa(t_stack *a, t_stack *b)
{
	t_stack	*new_top;

	if (!lst_size(b))
		return ;
	new_top = b->prev;
	b->prev = b->prev->prev;
	b->prev->next = b;
	new_top->next = a;
	new_top->prev = a->prev;
	a->prev->next = new_top;
	a->prev = new_top;
}

void	pb(t_stack *a, t_stack *b)
{
	pa(b, a);
}
