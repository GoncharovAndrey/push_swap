/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:56:36 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 18:56:39 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

int				ft_duplicate_stack(t_stack *stacks)
{
	t_array		*tmp;
	t_array		*number;

	number = stacks->a_head;
	while (number != stacks->a_end)
	{
		tmp = number->next;
		while (tmp != stacks->a_end->next)
		{
			if (number->num == tmp->num)
				return (0);
			tmp = tmp->next;
		}
		number = number->next;
	}
	return (1);
}

int				ft_atoi_max(const char *nptr, int *flag)
{
	size_t		i;
	long int	res;
	int			z;

	res = 0;
	i = 0;
	z = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	z = nptr[i] == '-' ? -1 : 1;
	i = nptr[i] == '-' || nptr[i] == '+' ? i + 1 : i + 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if ((z * res) > INT_MAX || (z * res) < INT_MIN)
		{
			*flag = 0;
			return (-1);
		}
		i++;
	}
	return (res * z);
}

void			ft_del_nav(char **nav, t_ps *ps)
{
	int			i;

	i = 0;
	if (ps->flag == 1)
	{
		while (nav[i])
		{
			free(nav[i]);
			i++;
		}
		free(nav);
	}
}

int				ft_init_flag(t_ps *ps, char ***nav, char **av, int ac)
{
	ps->flag = 0;
	*nav = !ft_strcmp(av[1], "-v") ? av + 2 : av + 1;
	ac -= !ft_strcmp(av[1], "-v") ? 2 : 1;
	ps->v = !ft_strcmp(av[1], "-v") ? 1 : 0;
	if (ac == 1)
	{
		if (!(*nav = ft_strsplit(*nav[0], 32)))
			return (0);
		ac = 0;
		ps->flag = 1;
		while (nav[0][ac])
			ac++;
	}
	return (ac);
}

int				ft_is_number(char *num)
{
	int			i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

void			ft_init_operation(t_ps *ps)
{
	ps->operation[0] = &ft_sa;
	ps->operation[1] = &ft_sb;
	ps->operation[2] = &ft_ss;
	ps->operation[3] = &ft_pa;
	ps->operation[4] = &ft_pb;
	ps->operation[5] = &ft_ra;
	ps->operation[6] = &ft_rb;
	ps->operation[7] = &ft_rr;
	ps->operation[8] = &ft_rra;
	ps->operation[9] = &ft_rrb;
	ps->operation[10] = &ft_rrr;
}

int				ft_init_stack(t_stack *stacks, int ac, char **av)
{
	t_array		*tmp;
	int			flag;

	if (!(ft_create_list(stacks, ac)))
		return (0);
	stacks->size_a = ac;
	stacks->size_b = 0;
	tmp = stacks->a_end;
	while (--ac >= 0)
	{
		if (ft_is_number(av[ac]))
		{
			if ((tmp->num = ft_atoi_max(av[ac], &flag)) == -1)
			{
				if (flag == 0)
					return (0);
			}
		}
		else
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

void			ft_init_comand(t_ps *ps)
{
	ps->comand[0] = "sa";
	ps->comand[1] = "sb";
	ps->comand[2] = "ss";
	ps->comand[3] = "pa";
	ps->comand[4] = "pb";
	ps->comand[5] = "ra";
	ps->comand[6] = "rb";
	ps->comand[7] = "rr";
	ps->comand[8] = "rra";
	ps->comand[9] = "rrb";
	ps->comand[10] = "rrr";
}

int				ft_init_all(t_stack *stacks, t_ps *ps, int ac, char **av)
{
	if (!(ft_init_stack(stacks, ac, av)))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (!(ft_duplicate_stack(stacks)))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	ft_init_comand(ps);
	ft_init_operation(ps);
	return (1);
}
