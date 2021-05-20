#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libft.h>
# include <list.h>

typedef t_list	t_stack;

enum	e_bool
{
	false,
	true
};

enum	e_fileno
{
	stdin,
	stdout,
	stderr
};

typedef	void	(*t_exception)(void);
typedef void	(*t_operation)(t_stack *, t_stack *);

/*
**	OPERATIONS
*/

void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/*
**	EXCEPTION
*/

int	exception(t_exception exception);
void	save_stacks(t_stack **a, t_stack **b);
void	clear_stacks(void);
void	bad_alloc(void);
void	invalid_arguments(void);

/*
**	PARSER
*/

int	parse_arguments(t_stack *a, unsigned int argc, char **argv);

#endif
