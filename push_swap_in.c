#include "includes/push_swap.h"
#include <stdio.h>

int			ft_stacks_min_in(t_stack *stacks)
{
	t_array	*tmp;
	t_array	*m;
	int		min;
	int		i;

	i = 1;
	min = stacks->a_head->num;
	tmp = stacks->a_head;
	m = stacks->a_head;
	m->group = 1;
	while (i <=  stacks->size_a - 1)
	{
		if (min > tmp->next->num)
		{
			min = tmp->next->num;
			m->group = 0;
			m = tmp->next;
			m->group = 1;
		}
		tmp = tmp->next;
		i++;
	}
//	printf("min\n");
	return (min);
}

int		ft_stacks_min_next_in(t_stack *stacks, int min)
{
	t_array	*tmp;
	t_array	*m;
	int		i;
	int		min_next;

//	printf("in min_next\n");
	i = 0;
	tmp = stacks->a_head;
	while (i < 50 && tmp->num <= min)
	{
		if (tmp->num == min)
			tmp->group = 1;
		tmp = tmp->next;
		i++;
//		printf("%p\n", tmp);
	}
	if (i == 50)
		return (min);
	min_next = tmp->num;
	m = tmp;
	m->group = 1;
	while (i < stacks->size_a)
	{
		if (min_next == tmp->num)
			tmp->group = 1;
		else if (min_next > tmp->num && tmp->num > min)
		{
			min_next = tmp->num;
			m->group = 0;
			m = tmp;
			m->group = 1;
		}
		tmp = tmp->next;
		i++;
	}
//	printf("min_next exit\n");
	return (min_next);
}

void		ft_group(t_stack *stacks, int len)
{
	int		min;

	min = ft_stacks_min_in(stacks);
	while (--len > 0)
	{
		min = ft_stacks_min_next_in(stacks, min);
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
	int		i;
	int		ra;
	int		rra;
	t_array	*tmp;

	group = stacks->size_a % 50 == 0 ? stacks->size_a / 50 : stacks->size_a / 50 + 1;
	while (group-- > 0)
	{
//		printf("group %d\n", group + 1);
//		printf("%d size a  %d size b\n", stacks->size_a, stacks->size_b);
		ft_group(stacks, 50);
		i = 0;
		while (i < 50 && stacks->size_a != 0)
		{
			ra = 0;
			rra = 0;
			tmp = stacks->a_head;
			while (tmp->group != 1)
			{
				tmp = tmp->next;
				ra++;
			}
			tmp = stacks->a_end;
			while (tmp->group != 1) {
				tmp = tmp->prev;
				rra++;
			}
			if (ra <= rra + 1) {
				while (ra-- > 0) {
					ps->operation[5](stacks);
					ft_putendl_fd(ps->comand[5], 1);
				}
			} else {
				while (rra-- >= 0) {
					ps->operation[8](stacks);
					ft_putendl_fd(ps->comand[8], 1);
				}
			}
			ps->operation[4](stacks);
			ft_putendl_fd(ps->comand[4], 1);
			i++;
		}
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