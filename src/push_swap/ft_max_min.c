
#include "../../includes/push_swap.h"

int			ft_min_a(t_stack *stacks, int group)
{
	t_array	*tmp;
	t_array	*m;
	int		min;

	tmp = stacks->a_head;
	while (tmp->group != 0 && tmp != stacks->a_end)
		tmp = tmp->next;
	min = tmp->num;
	m = tmp;
	m->group = group;
	while (tmp != stacks->a_end)
	{
		if (min > tmp->next->num && tmp->next->group == 0)
		{
			min = tmp->next->num;
			m->group = 0;
			m = tmp->next;
			m->group = group;
		}
		tmp = tmp->next;
	}
	return (min);
}

int			ft_max_b(t_stack *stacks, int group)
{
	t_array	*tmp;
	t_array	*m;
	int		max;

	tmp = stacks->b_head;
	while (tmp->group != 0 && tmp != stacks->b_end)
		tmp = tmp->next;
	max = tmp->num;
	m = tmp;
	m->group = group;
	while (tmp != stacks->b_end)
	{
		if (max < tmp->next->num && tmp->next->group == 0)
		{
			max = tmp->next->num;
			m->group = 0;
			m = tmp->next;
			m->group = group;
		}
		tmp = tmp->next;
	}
	return (max);
}
