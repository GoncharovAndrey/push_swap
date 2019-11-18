#include "includes/push_swap.h"
#include <stdio.h>

void		ft_print_stacks(t_stack *stacks)
{
	t_array	*tmp;

	tmp = stacks->b_head;
	while (tmp)
	{
		printf("{%d - (%d)} ", tmp->num, tmp->group);
		tmp = tmp->next;
	}
	printf("  -b\n");
	tmp = stacks->a_head;
	while (tmp)
	{
		printf("{%d - (%d)} ", tmp->num, tmp->group);
		tmp = tmp->next;
	}
	printf("  -a\n");
	printf("\n");
}

int			ft_find_group(t_stack *stacks, int group)
{
	t_array	*tmp;

	tmp = stacks->a_head;
	while (tmp != NULL)
	{
		if (tmp->group == group)
		{
//			printf("%d yes group\n", group);
			return (1);
		}
		tmp = tmp->next;
	}
//	printf("%d no group\n", group);
	return (0);
}

int			ft_stacks_min_in(t_stack *stacks, int group)
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
//	printf("min\n");
	return (min);
}

int		ft_stacks_min_next_in(t_stack *stacks, int min, int group)
{
	t_array	*tmp;
	t_array	*m;
	int		min_next;

//	printf("in min_next\n");
	tmp = stacks->a_head;
	while (tmp->group != 0 && tmp != stacks->a_end)
		tmp = tmp->next;
//		printf("%p\n", tmp);

	min_next = tmp->num;
	m = tmp;
	m->group = group;
	while (tmp != stacks->a_end->next)
	{
		if (min_next > tmp->num && tmp->num > min && tmp->num == 0)
		{
			min_next = tmp->num;
			m->group = 0;
			m = tmp;
			m->group = group;
		}
		tmp = tmp->next;
	}
//	printf("min_next exit\n");
	return (min_next);
}

void		ft_group(t_stack *stacks, int len, int group)
{
	int		min;

//	if (ft_find_group(stacks, 0))
//		min = ft_stacks_min_in(stacks, group);
	while (len-- > 0 && ft_find_group(stacks, 0))
	{
		min = ft_stacks_min_in(stacks, group);
	}
}

int			ft_max_b(t_stack *stacks)
{
	int		max_pos;
	int		max;
	int		i;
	t_array	*tmp;

	max_pos = 0;
	i = 0;
	tmp = stacks->b_head;
	max = stacks->b_head->num;
	while (tmp)
	{
		if (max < tmp->num)
		{
			max = tmp->num;
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_pos);
}

void		ft_push_swap_in(t_stack *stacks, t_ps *ps)
{
	int		group;
//	int		group_next;
	int		i;
	int		ra;
	int		rra;
	t_array	*tmp;

	group = 1;
//	group_next = 2;
	while (stacks->size_a != 0)
	{
//		printf("group %d\n", group + 1);
//		printf("%d size a  %d size b\n", stacks->size_a, stacks->size_b);
		if (!ft_find_group(stacks, group))
			ft_group(stacks, 50, group);
//		if (!ft_find_group(stacks,group_next))
//		{
//			group_next = group + 1;
//			ft_group(stacks, 20, group_next);
//		}
//		i = 0;
		while (ft_find_group(stacks, group))
		{
			ra = 0;
			rra = 0;
			tmp = stacks->a_head;
			while (tmp->group != group)
			{
				tmp = tmp->next;
				ra++;
			}
			tmp = stacks->a_end;
			while (tmp->group != group)
			{
				tmp = tmp->prev;
				rra++;
			}
			if (ra <= rra + 1)
			{
				while (ra-- > 0)
				{
//					if (stacks->a_head->group == group_next && stacks->size_b > 0)
//					{
//						ps->operation[4](stacks);
//						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						ra--;
//						if (ra == 0)
//							break;
//						ps->operation[6](stacks);
//						ft_putendl_fd(ps->comand[6], 1);
//
////						ft_print_stacks(stacks);
//					}
//					else
//					{
						ps->operation[5](stacks);
						ft_putendl_fd(ps->comand[5], 1);
//						ft_print_stacks(stacks);
//					}
				}
			}
			else
			{
				while (rra-- >= 0)
				{
//					if (stacks->a_head->group == group_next && stacks->size_b > 0)
//					{
//						ps->operation[4](stacks);
//						ft_putendl_fd(ps->comand[4], 1);
//						rra--;
//						if (rra == 0)
//							break;
////						ft_print_stacks(stacks);
//						ps->operation[6](stacks);
//						ft_putendl_fd(ps->comand[6], 1);
//
////						ft_print_stacks(stacks);
//					}
					ps->operation[8](stacks);
					ft_putendl_fd(ps->comand[8], 1);
//					ft_print_stacks(stacks);
				}
			}
			ps->operation[4](stacks);
			ft_putendl_fd(ps->comand[4], 1);
//			ft_print_stacks(stacks);
//			i++;
		}
		group++;
	}
//	printf("next fall\n");
	while (stacks->size_b > 0)
	{
		ra = ft_max_b(stacks);
		rra = stacks->size_b - ra;
		if (ra <= rra)
		{
			while (ra-- > 0)
			{
				ps->operation[6](stacks);
				ft_putendl_fd(ps->comand[6], 1);
			}
		}
		else{
			while  (rra-- > 0)
			{
				ps->operation[9](stacks);
				ft_putendl_fd(ps->comand[9], 1);
			}
		}
		ps->operation[3](stacks);
		ft_putendl_fd(ps->comand[3], 1);
	}
}