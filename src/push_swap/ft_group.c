
#include "../../includes/push_swap.h"

int			ft_find_group(t_stack *stacks, int group)
{
	t_array	*tmp;

	tmp = stacks->a_head;
	while (tmp != NULL)
	{
		if (tmp->group == group)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_find_group_b(t_stack *stacks, int group)
{
	t_array	*tmp;

	tmp = stacks->b_head;
	while (tmp != NULL)
	{
		if (tmp->group == group)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		ft_group(t_stack *stacks, int len, int group)
{
	while (len-- > 0 && ft_find_group(stacks, 0))
	{
		ft_min_a(stacks, group);
	}
}

void		ft_group_b(t_stack *stacks, int len, int group)
{
	while (len-- > 0 && ft_find_group_b(stacks, 0))
	{
		ft_max_b(stacks, group);
	}
}

