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

int		ft_max_b(t_stack *stacks, int group)
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


void		ft_push_swap_in(t_stack *stacks, t_ps *ps)
{
	int		group;
	int		group_next;
	int		ra;
	int		rra;
	t_array	*tmp;
	int		i;

	group = 1;
//	group_next = 2;
	while (stacks->size_a != 0)
	{
		i = 0;
		if (!ft_find_group(stacks, group))
			ft_group(stacks, 25, group);
		if (!ft_find_group(stacks,group + 1))
		{
			group_next = group + 1;
			ft_group(stacks, 25, group_next);
		}
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
					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
					{
						ps->operation[4](stacks);
						printf("%s\n", ps->comand[4]);
//						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
						ra -= 1;
						if (group_next % 2 == 0)
						{
							if (ra > 0 && stacks->a_head->group != group_next)
							{
								ps->operation[7](stacks);
								printf("%s\n", ps->comand[7]);
//								ft_putendl_fd(ps->comand[7], 1);
								ra -= 1;
							}
							else
							{
								ps->operation[6](stacks);
								printf("%s\n", ps->comand[6]);
//								ft_putendl_fd(ps->comand[6], 1);
							}
						}
						i++;
//////						ft_print_stacks(stacks);
					}
					if (stacks->a_head->group != group)
					{
						ps->operation[5](stacks);
						printf("%s\n", ps->comand[5]);
//						ft_putendl_fd(ps->comand[5], 1);
					}
////						ft_print_stacks(stacks);
				}
			}
			else
			{
				while (rra-- >= 0)
				{
					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
					{
						ps->operation[4](stacks);
						printf("%s\n", ps->comand[4]);
//						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
						if (group_next % 2 == 0)
						{
							ps->operation[6](stacks);
							printf("%s\n", ps->comand[6]);
//							ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
						}
						i++;
////						ft_print_stacks(stacks);
					}
						ps->operation[8](stacks);
						printf("%s\n", ps->comand[8]);
//						ft_putendl_fd(ps->comand[8], 1);
////					ft_print_stacks(stacks);
				}
			}
			ps->operation[4](stacks);
			printf("%s\n", ps->comand[4]);
//			ft_putendl_fd(ps->comand[4], 1);
			if (group % 2 == 0)
			{
				ps->operation[6](stacks);
				printf("%s\n", ps->comand[6]);
//				ft_putendl_fd(ps->comand[6], 1);
////			ft_print_stacks(stacks);
			}
		}
		group++;

//		while (i-- > 0)
//		{
//			ps->operation[9](stacks);
//			ft_putendl_fd(ps->comand[9], 1);
//		}
	}
	tmp = stacks->b_head;

	while (tmp)
	{
		tmp->group = 0;
		tmp = tmp->next;
	}

	while (stacks->size_b > 0)
	{
		if (!(ft_find_group_b(stacks, 1)))
			ft_max_b(stacks, 1);
		tmp = stacks->b_head;
		ra = 0;
		while (tmp->group != 1)
		{
			ra++;
			tmp = tmp->next;
		}
		rra = stacks->size_b - ra;
		if (stacks->size_b > 1)
			ft_max_b(stacks, 1);
		if (ra <= rra)
		{
			while (ra-- > 0)
			{
				if (stacks->b_head->group == 1)
				{
					ps->operation[3](stacks);
					printf("%s\n", ps->comand[3]);
//					ft_putendl_fd(ps->comand[3], 1);
					ra--;
				}
				if (stacks->b_head->group != 1)
				{
					ps->operation[6](stacks);
					printf("%s\n", ps->comand[6]);
//					ft_putendl_fd(ps->comand[6], 1);
				}
			}
		}
		else{
			while  (rra-- > 0)
			{
				if (stacks->b_head->group == 1)
				{
					ps->operation[3](stacks);
					printf("%s\n", ps->comand[3]);
//					ft_putendl_fd(ps->comand[3], 1);
				}
				ps->operation[9](stacks);
				printf("%s\n", ps->comand[9]);
//				ft_putendl_fd(ps->comand[9], 1);
			}
		}
		ps->operation[3](stacks);
		printf("%s\n", ps->comand[3]);
//		ft_putendl_fd(ps->comand[3], 1);
		if ( stacks->size_a > 1 && stacks->a_head->num > stacks->a_head->next->num)
		{
			ps->operation[0](stacks);
			printf("%s\n", ps->comand[0]);
//			ft_putendl_fd(ps->comand[0], 1);
		}
	}
}