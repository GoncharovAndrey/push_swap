///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_push_swap_rec.c                                 :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2019/11/16 17:23:50 by cjosue            #+#    #+#             */
///*   Updated: 2019/11/16 17:23:52 by cjosue           ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "includes/push_swap.h"
//#include <stdio.h>
//
//int				ft_sa_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_a < 2)
//		return (0);
//	if (rec->i > 0)
//	{
//		if (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2)
//			return (0);
//		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7 || \
//			rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 10))
//			return (0);
//	}
//	ft_sa(stacks);
////	printf("yes\n");
//	return (1);
//}
//
//int		ft_sb_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_b < 2)
//		return (0);
//	if (rec->i > 0)
//	{
//		if (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2)
//			return (0);
//		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7 || \
//			rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10))
//			return (0);
//	}
//	ft_sb(stacks);
//	return (1);
//}
//
//int		ft_ss_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_b < 2 || stacks->size_a < 2)
//		return (0);
//	if (rec->i > 1)
//	{
//		if (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 0)
//			return (0);
//		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7 || \
//			rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10))
//			return (0);
//		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7 || \
//			rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 10))
//			return (0);
//	}
//	ft_ss(stacks);
//	return (1);
//}
//
//int		ft_pa_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_b == 0)
//		return (0);
//	if (rec->i > 0 && rec->arr_com[i - 1] == 4)
//		return (0);
//	ft_pa(stacks);
//	return (1);
//}
//
//int		ft_pb_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_a == 0)
//		return (0);
//	if (rec->i > 0 && rec->arr_com[i - 1] == 3)
//		return (0);
//	ft_pb(stacks);
//	return (1);
//}
//
//int		ft_ra_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_a < 2)
//		return (0);
//	if (rec->i > 0)
//	{
//		if (rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 10)
//			return (0);
//		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7))
//			return (0);
//	}
//	ft_ra(stacks);
//	return (1);
//}
//
//int		ft_rb_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_b < 2)
//		return (0);
//	if (rec->i > 0)
//	{
//		if (rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10)
//			return (0);
//		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7))
//			return (0);
//	}
//	ft_rb(stacks);
//	return (1);
//}
//
//int		ft_rr_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_a < 2 || stacks->size_b < 2)
//		return (0);
//	if (rec->i > 0)
//	{
//		if (rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10)
//			return (0);
//		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7))
//			return (0);
//		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7))
//			return (0);
//	}
//	ft_rr(stacks);
//	return (1);
//}
//
//int		ft_rra_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_a < 2)
//		return (0);
//	if (rec->i > 0)
//	{
//		if (rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 7)
//			return (0);
//		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 10))
//			return (0);
//	}
//	ft_ra(stacks);
//	return (1);
//}
//
//int		ft_rrb_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_b < 2)
//		return (0);
//	if (rec->i > 0)
//	{
//		if (rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7)
//			return (0);
//		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10))
//			return (0);
//	}
//	ft_rb(stacks);
//	return (1);
//}
//
//int		ft_rrr_rec(t_stack *stacks, t_rec *rec)
//{
//	int	i;
//
//	i = rec->i;
//	if (stacks->size_a < 2 || stacks->size_b < 2)
//		return (0);
//	if (rec->i > 0)
//	{
//		if (rec->arr_com[i - 1] == 5 || rec->arr_com[i - 1] == 6 || rec->arr_com[i - 1] == 7)
//			return (0);
//		if (stacks->size_b == 2 && (rec->arr_com[i - 1] == 1 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 9 || rec->arr_com[i - 1] == 10))
//			return (0);
//		if (stacks->size_a == 2 && (rec->arr_com[i - 1] == 0 || rec->arr_com[i - 1] == 2 || rec->arr_com[i - 1] == 8 || rec->arr_com[i - 1] == 10))
//			return (0);
//	}
//	ft_rrr(stacks);
//	return (1);
//}
//
//void			ft_init_rec(t_rec *rec, t_ps *ps, int len)
//{
//	rec->lenght = len;
//	rec->i = 0;
//	rec->arr_com = (int *)malloc(sizeof(int) * len);
//	rec->arr_res = (int *)malloc(sizeof(int) * len);
//	ft_memset(rec->arr_com, 42, sizeof(int) * len);
//	ft_memset(rec->arr_res, 42, sizeof(int) * len);
//	ps->oper[0] = &ft_sa_rec;
//	ps->oper[1] = &ft_sb_rec;
//	ps->oper[2] = &ft_ss_rec;
//	ps->oper[3] = &ft_pa_rec;
//	ps->oper[4] = &ft_pb_rec;
//	ps->oper[5] = &ft_ra_rec;
//	ps->oper[6] = &ft_rb_rec;
//	ps->oper[7] = &ft_rr_rec;
//	ps->oper[8] = &ft_rra_rec;
//	ps->oper[9] = &ft_rrb_rec;
//	ps->oper[10] = &ft_rrr_rec;
//}
//
//void		ft_back_rec(t_stack *stacks, t_rec *rec)
//{
//	int		i;
//
//	i = rec->i;
//	if (rec->arr_com[i] == 0)
//		ft_sa(stacks);
//	if (rec->arr_com[i] == 1)
//		ft_sb(stacks);
//	if (rec->arr_com[i] == 2)
//		ft_ss(stacks);
//	if (rec->arr_com[i] == 3)
//		ft_pb(stacks);
//	if (rec->arr_com[i] == 4)
//		ft_pa(stacks);
//	if (rec->arr_com[i] == 5)
//		ft_rra(stacks);
//	if (rec->arr_com[i] == 6)
//		ft_rrb(stacks);
//	if (rec->arr_com[i] == 7)
//		ft_rrr(stacks);
//	if (rec->arr_com[i] == 8)
//		ft_ra(stacks);
//	if (rec->arr_com[i] == 9)
//		ft_rb(stacks);
//	if (rec->arr_com[i] == 10)
//		ft_rr(stacks);
//}
//
//int		ft_a_sorted_ac(t_stack *stacks)
//{
//	t_array	*tmp;
//	int		size;
//
//	if (stacks->size_b != 0)
//		return (-1);
//	tmp = stacks->a_head;
//	size = stacks->size_a;
//	while (size-- > 1)
//	{
//		if (tmp->num > tmp->next->num)
//			return (-1);
//		tmp = tmp->next;
//	}
//	return (1);
//}
//
//void	ft_push_swap_rec(t_stack *stacks, t_rec *rec, t_ps *ps)
//{
//	int		tmp;
//
//	while (rec->arr_com[0] < 11)
//	{
//		if (rec->i == rec->lenght)
//			rec->i--;
//		if (rec->arr_com[rec->i] == 11)
//			rec->i--;
//		if (rec->arr_com[rec->i] < 11)
//		{
//			ft_back_rec(stacks, rec);
//			rec->arr_com[rec->i]++;
//		}
//		else
//			rec->arr_com[rec->i] = 0;
//		tmp = rec->arr_com[rec->i];
//		while (tmp < 11)
//		{
//			if (ps->oper[tmp](stacks,rec))
//			{
//				rec->arr_com[rec->i] = tmp;
//				break;
//			}
//			tmp++;
//		}
//		if (tmp == 11)
//		{
//			ft_back_rec(stacks, rec);
//			rec->arr_com[rec->i] = tmp;
//			continue;
//		}
//		rec->i++;
////		printf("%d  size  %d  ac\n", stacks->size_a, ac);
//		if (ft_a_sorted_ac(stacks) == 1 && (rec->i) < rec->lenght)
//		{
//			rec->lenght = rec->i;
////			rec->arr_res[0] = rec->arr_com[0];
//			ft_memcpy(rec->arr_res, rec->arr_com, rec->lenght * 4);
//		}
//	}
//}
