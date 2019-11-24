
#include "../../includes/push_swap.h"

void		ft_push_swap_abc(t_stack *stacks, t_ps *ps)
{
	if (stacks->a_head->num > stacks->a_head->next->num)
		ft_print_operation(stacks, ps, 0);
	if (ft_a_sorted(stacks))
		return ;
	ft_print_operation(stacks, ps, 8);
	if (stacks->a_head->num > stacks->a_head->next->num)
		ft_print_operation(stacks, ps, 0);
}

void		ft_push_swap_little(t_stack *stacks, t_ps *ps)
{
	if (stacks->size_a <= 3)
	{
		ft_push_swap_abc(stacks, ps);
		return ;
	}
	if (stacks->size_a <= 5)
	{
		ft_avr_a(stacks, ps, stacks->size_a);
		if (ft_a_sorted(stacks))
		{
			ft_insert_sort_b(stacks, ps);
			return ;
		}
		ft_push_swap_abc(stacks, ps);
		ft_insert_sort_b(stacks, ps);
		return ;
	}
}
