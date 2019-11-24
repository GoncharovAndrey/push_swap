/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:23:58 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/06 12:24:00 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_array			*ft_create_elem(void)
{
	t_array		*tmp;

	if (!(tmp = (t_array*)malloc(sizeof(t_array))))
		return (NULL);
	tmp->num = 0;
	tmp->group = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void			ft_del_list(t_stack *stacks)
{
	t_array		*tmp;

	while (stacks->a_head)
	{
		tmp = stacks->a_head;
		stacks->a_head = stacks->a_head->next;
		free(tmp);
	}
	while (stacks->b_head)
	{
		tmp = stacks->b_head;
		stacks->b_head = stacks->b_head->next;
		free(tmp);
	}
}

int				ft_create_list(t_stack *stacks, int ac)
{
	t_array		*tmp;
	t_array		*lst;

	if (!(stacks->a_head = ft_create_elem()))
		return (0);
	stacks->b_head = NULL;
	stacks->b_end = NULL;
	lst = stacks->a_head;
	stacks->a_end = stacks->a_head;
	while (--ac > 0)
	{
		if (!(tmp = ft_create_elem()))
		{
			ft_del_list(stacks);
			return (0);
		}
		lst->next = tmp;
		tmp->prev = lst;
		stacks->a_end = tmp;
		lst = tmp;
	}
	return (1);
}
