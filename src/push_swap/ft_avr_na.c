
#include "../../includes/push_swap.h"

void		ft_ra_for_na(t_stack *stacks, t_ps *ps, int group, int group_next)
{
	while (stacks->a_head->group != group)
	{
		while (stacks->a_head->group == group_next)
		{
			ft_print_operation(stacks, ps, 4);
			if (group_next % 2 == 0)
			{
				if (stacks->a_head->group != group && \
						stacks->a_head->group != group_next)
					ft_print_operation(stacks, ps, 7);
				else
					ft_print_operation(stacks, ps, 6);
			}
		}
		if (stacks->a_head->group != group)
			ft_print_operation(stacks, ps, 5);
	}
}

void		ft_rra_for_na(t_stack *stacks, t_ps *ps, int group, int group_next)
{
	while (stacks->a_head->group != group)
	{
		while (stacks->a_head->group == group_next)
		{
			ft_print_operation(stacks, ps, 4);
			if (group_next % 2 == 0)
				ft_print_operation(stacks, ps, 6);
		}
		ft_print_operation(stacks, ps, 8);
	}
}

int			ft_avr_na(t_stack *stacks, t_ps *ps, int size, int group)
{
	int		group_next;

	while (stacks->size_a != 0)
	{
		if (!(ft_find_group(stacks, group)))
			ft_group(stacks, size, group);
		if (!ft_find_group(stacks, group + 1))
		{
			group_next = group + 1;
			ft_group(stacks, size, group_next);
		}
		while (ft_find_group(stacks, group))
		{
			if (ft_which_way(stacks, group, 'a'))
				ft_ra_for_na(stacks, ps, group, group_next);
			else
				ft_rra_for_na(stacks, ps, group, group_next);
			ft_print_operation(stacks, ps, 4);
			if (group % 2 == 0)
				ft_print_operation(stacks, ps, 6);
		}
		group++;
	}
	ft_clean_stacks(stacks);
	return (size);
}

int			ft_avr_a(t_stack *stacks, t_ps *ps, int size)
{
	int		group;

	size /= 2;
	group = 1;
	ft_group(stacks, size, 1);
	ft_group(stacks, (size / 5) * 4, 2);
	while (group < 3)
	{
		while (ft_find_group(stacks, group))
		{
			while (stacks->a_head->group != group)
				ft_print_operation(stacks, ps, 5);
			ft_print_operation(stacks, ps, 4);
		}
		group++;
	}
	ft_clean_stacks(stacks);
	return (size);
}
