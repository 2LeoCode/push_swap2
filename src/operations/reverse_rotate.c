#include <push_swap.h>

void	rra(t_stack *a, t_stack *b)
{
	if (lst_size(a) < 2)
		return ;
	(void)b;
	a->prev->next = a->next;
	a->next->prev = a->prev;
	a->prev = a->next;
	a->next = a->next->next;
	a->next->prev = a;
	a->prev->next = a;
}

void	rrb(t_stack *a, t_stack *b)
{
	rra(b, a);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}
