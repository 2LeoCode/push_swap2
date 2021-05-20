#include <push_swap.h>

void	ra(t_stack *a, t_stack *b)
{
	(void)b;
	if (lst_size(a) < 2)
		return ;
	a->prev->next = a->next;
	a->next->prev = a->prev;
	a->next = a->prev;
	a->prev = a->prev->prev;
	a->prev->next = a;
	a->next->prev = a;
}

void	rb(t_stack *a, t_stack *b)
{
	ra(b, a);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}
