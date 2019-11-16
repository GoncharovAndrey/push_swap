/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_rec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:23:50 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/16 17:23:52 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"


int				ft_sa_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_a < 2)
		return (0);
	if (rec->i > 0)
	{
		if (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2)
			return (0);
		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7 || \
			rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] = 10))
			return (0);
	}
	ft_sa(stacks);
	return (1);
}

int		ft_sb_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_b < 2)
		return (0);
	if (rec->i > 0)
	{
		if (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2)
			return (0);
		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7 || \
			rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] = 10))
			return (0);
	}
	ft_sb(stacks);
	return (1);
}

int		ft_ss_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_b < 2 || stacks->size_a < 2)
		return (0);
	if (rec->i > 1)
	{
		if (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 0)
			return (0);
		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7 || \
			rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] = 10))
			return (0);
		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7 || \
			rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] = 10))
			return (0);
	}
	ft_ss(stacks);
	return (1);
}

int		ft_pa_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_b == 0)
		return (0);
	if (rec->i > 0 && rec->arr_com[i - 1] == 4)
		return (0);
	ft_pa(stacks);
	return (1);
}

int		ft_pb_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_a == 0)
		return (0);
	if (rec->i > 0 && rec->arr_com[i - 1] == 3)
		return (0);
	ft_pb(stacks);
	return (1);
}

int		ft_ra_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_a < 2)
		return (0);
	if (rec->i > 0)
	{
		if (rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 10)
			return (0);
		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7))
			return (0);
	}
	ft_ra(stacks);
	return (1);
}

int		ft_rb_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_b < 2)
		return (0);
	if (rec->i > 0)
	{
		if (rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10)
			return (0);
		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7))
			return (0);
	}
	ft_rb(stacks);
	return (1);
}

int		ft_rr_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_a < 2 || stacks->size_b < 2)
		return (0);
	if (rec->i > 0)
	{
		if (rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10)
			return (0);
		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7))
			return (0);
		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7))
			return (0);
	}
	ft_rr(stacks);
	return (1);
}

int		ft_rra_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_a < 2)
		return (0);
	if (rec->i > 0)
	{
		if (rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7)
			return (0);
		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 10))
			return (0);
	}
	ft_ra(stacks);
	return (1);
}

int		ft_rrb_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_b < 2)
		return (0);
	if (rec->i > 0)
	{
		if (rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7)
			return (0);
		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10))
			return (0);
	}
	ft_rb(stacks);
	return (1);
}

int		ft_rrr_rec(t_stack *stacks, t_rec *rec)
{
	if (stacks->size_a < 2 || stacks->size_b < 2)
		return (0);
	if (rec->i > 0)
	{
		if (rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7)
			return (0);
		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10))
			return (0);
		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 10))
			return (0);
	}
	ft_rrr(stacks);
	return (1);
}

void			ft_init_rec(t_rec *rec, int len)
{
	ft_init_rec(rec);
	rec->lenght = len;
	rec->i = 0;
	rec->arr_com = (int *)malloc(sizeof(int) * len);
	rec->arr_res = (int *)malloc(sizeof(int) * len);
	ft_memset(rec->arr_com, 0, sizeof(int) * len);
	ft_memset(rec->arr_res, 0, sizeof(int) * len);
	rec->operation[0] = &ft_sa_rec;
	rec->operation[1] = &ft_sb_rec;
	rec->operation[2] = &ft_ss_rec;
	rec->operation[3] = &ft_pa_rec;
	rec->operation[4] = &ft_pb_rec;
	rec->operation[5] = &ft_ra_rec;
	rec->operation[6] = &ft_rb_rec;
	rec->operation[7] = &ft_rr_rec;
	rec->operation[8] = &ft_rra_rec;
	rec->operation[9] = &ft_rrb_rec;
	rec->operation[10] = &ft_rrr_rec;
}
