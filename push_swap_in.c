/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:28:56 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/24 19:28:59 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

void		ft_print_operation(t_stack *stacks, t_ps *ps, int num)
{
	ps->operation[num](stacks);
	ft_putendl_fd(ps->comand[num], 1);
}

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

void		ft_group(t_stack *stacks, int len, int group)
{
	int		min;

	while (len-- > 0 && ft_find_group(stacks, 0))
	{
		min = ft_min_a(stacks, group);
	}
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

void		ft_group_b(t_stack *stacks, int len, int group)
{
	int		max;

	while (len-- > 0 && ft_find_group_b(stacks, 0))
	{
		max = ft_max_b(stacks, group);
	}
}

void		ft_clean_stacks(t_stack *stacks)
{
	t_array	*tmp;

	tmp = stacks->b_head;
	while (tmp)
	{
		tmp->group = 0;
		tmp = tmp->next;
	}
	tmp = stacks->a_head;
	while (tmp)
	{
		tmp->group = 0;
		tmp = tmp->next;
	}
}

int			ft_which_way(t_stack *stacks, int group, char st)
{
	int		ra;
	int		rra;
	t_array	*tmp;

	ra = 0;
	rra = 0;
	tmp = (st == 'a') ? stacks->a_head : stacks->b_head;
	while (tmp->group != group)
	{
		tmp = tmp->next;
		ra++;
	}
	tmp = (st == 'a') ? stacks->a_end : stacks->b_end;
	while (tmp->group != group)
	{
		tmp = tmp->prev;
		rra++;
	}
	if (ra <= rra + 1)
		return (1);
	return (0);
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

void		ft_ra_for_nb(t_stack *stacks, t_ps *ps, int group, int group_next)
{
	while (stacks->b_head->group != group)
	{
		while (stacks->b_head->group == group_next)
		{
			ft_print_operation(stacks, ps, 3);
			if (group_next % 2 == 0)
			{
				if (stacks->a_head->group != group_next && \
						stacks->a_head->group != group)
					ft_print_operation(stacks, ps, 7);
				else
					ft_print_operation(stacks, ps, 5);
			}
		}
		if (stacks->b_head->group != group)
			ft_print_operation(stacks, ps, 6);
	}
}

void		ft_rra_for_nb(t_stack *stacks, t_ps *ps, int group, int group_next)
{
	while (stacks->b_head->group != group)
	{
		while (stacks->b_head->group == group_next)
		{
			ft_print_operation(stacks, ps, 3);
			if (group_next % 2 == 0)
				ft_print_operation(stacks, ps, 5);
		}
		ft_print_operation(stacks, ps, 9);
	}
}

int			ft_avr_nb(t_stack *stacks, t_ps *ps, int size, int group)
{
	int		group_next;

	while (stacks->size_b != 0)
	{
		if (!(ft_find_group_b(stacks, group)))
			ft_group_b(stacks, size, group);
		if (!ft_find_group_b(stacks, group + 1))
		{
			group_next = group + 1;
			ft_group_b(stacks, size, group_next);
		}
		while (ft_find_group_b(stacks, group))
		{
			if (ft_which_way(stacks, group, 'b'))
				ft_ra_for_nb(stacks, ps, group, group_next);
			else
				ft_rra_for_nb(stacks, ps, group, group_next);
			ft_print_operation(stacks, ps, 3);
			if (group % 2 == 0)
				ft_print_operation(stacks, ps, 5);
		}
		group++;
	}
	ft_clean_stacks(stacks);
	return (size);
}

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

void		ft_ra_rra_for_sort_b(t_stack *stacks, t_ps *ps, int ra, int rra)
{
	if (ra <= rra)
	{
		while (ra-- > 0)
		{
			if (stacks->b_head->group == 1)
			{
				ft_print_operation(stacks, ps, 3);
				ra--;
			}
			if (stacks->b_head->group != 1)
				ft_print_operation(stacks, ps, 6);
		}
	}
	else
	{
		while (rra-- > 0)
		{
			if (stacks->b_head->group == 1)
				ft_print_operation(stacks, ps, 3);
			ft_print_operation(stacks, ps, 9);
		}
	}
}

void		ft_insert_sort_b(t_stack *stacks, t_ps *ps)
{
	int		ra;
	int		rra;
	t_array	*tmp;

	while (stacks->size_b > 0)
	{
		if (!(ft_find_group_b(stacks, 1)))
			ft_max_b(stacks, 1);
		tmp = stacks->b_head;
		ra = 0;
		while (tmp && tmp->group != 1)
		{
			ra++;
			tmp = tmp->next;
		}
		rra = stacks->size_b - ra;
		if (stacks->size_b > 1)
			ft_max_b(stacks, 1);
		ft_ra_rra_for_sort_b(stacks, ps, ra, rra);
		ft_print_operation(stacks, ps, 3);
		if (stacks->size_a > 1 && \
				stacks->a_head->num > stacks->a_head->next->num)
			ft_print_operation(stacks, ps, 0);
	}
}

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

void		ft_push_swap_in(t_stack *stacks, t_ps *ps)
{
	int		i;

	if (ft_a_sorted(stacks))
		return ;
	if (stacks->size_a <= 5)
	{
		ft_push_swap_little(stacks, ps);
		return ;
	}
	if (stacks->size_a / 2 < 124)
		ft_avr_na(stacks, ps, 15, 1);
	else
	{
		i = ft_avr_a(stacks, ps, stacks->size_a);
		while (i > 50)
		{
			i = ft_avr_nb(stacks, ps, i / 5, 1);
			i = ft_avr_na(stacks, ps, i / 5, 1);
		}
	}
	ft_insert_sort_b(stacks, ps);
}
