#include "includes/push_swap.h"
#include <stdio.h>

void		ft_print_stacks(t_stack *stacks)
{
	t_array	*tmp;
	t_array	*tmp_b;

	tmp = stacks->a_head;
	tmp_b = stacks->b_head;
	printf("%9s  |%9s\n", "stack A","stack B");
	printf("_______________________\n");
	while (tmp || tmp_b)
	{
		if (tmp)
		{
			printf("%10d ", tmp->num);
			tmp = tmp->next;
		}
		else
			printf("%11c", ' ');
		printf("|");
		if (tmp_b)
		{
			printf("%10d ", tmp_b->num);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
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
	return (min);
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

int			ft_stacks_min_in_b(t_stack *stacks, int group)
{
	t_array	*tmp;
	t_array	*m;
	int		min;

	tmp = stacks->b_head;
	while (tmp->group != 0 && tmp != stacks->b_end)
		tmp = tmp->next;
	min = tmp->num;
	m = tmp;
	m->group = group;
	while (tmp != stacks->b_end)
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

void	ft_clean_stacks(t_stack *stacks)
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

void		ft_group_b(t_stack *stacks, int len, int group)
{
	int		max;

//	if (ft_find_group(stacks, 0))
//		min = ft_stacks_min_in(stacks, group);
	while (len-- > 0 && ft_find_group_b(stacks, 0))
	{
		max = ft_max_b(stacks, group);
	}
}



int			ft_avr_a(t_stack *stacks, t_ps *ps, int size)
{
	int		group;

	size /=2;
	group = 1;
	while (stacks->size_a != 0)
	{
		if (!(ft_find_group(stacks, group)))
			ft_group(stacks, size, group);
		while (ft_find_group(stacks, group)) {
			while (stacks->a_head->group != group) {
				ps->operation[5](stacks);
				printf("%s\n", ps->comand[5]);
			}
			ps->operation[4](stacks);
			printf("%s\n", ps->comand[4]);
		}
		group++;
	}
	ft_clean_stacks(stacks);
	return (size);
}

int			ft_avr_nb(t_stack *stacks, t_ps *ps, int size)
{
	int		group;
	int		group_next;
	int		ra;
	int		rra;
	t_array	*tmp;

	group = 1;
	size /= 4;
//	group_next = 2;
	while (stacks->size_b != 0) {
//		i -= i > 5 ? 1 : 0;
		if (!(ft_find_group_b(stacks, group)))
			ft_group_b(stacks, size, group);
		if (!ft_find_group_b(stacks, group + 1)) {
			group_next = group + 1;
			ft_group_b(stacks, size, group_next);
		}
		while (ft_find_group_b(stacks, group)) {
			ra = 0;
			rra = 0;
			tmp = stacks->b_head;
			while (tmp->group != group) {
				tmp = tmp->next;
				ra++;
			}
			tmp = stacks->b_end;
			while (tmp->group != group) {
				tmp = tmp->prev;
				rra++;
			}
			if (ra <= rra + 1) {
				while (ra-- > 0) {
//					if (!ft_find_group(stacks, group_next))
//						ft_group(stacks, i, group_next);
					while (stacks->b_head->group == group_next/* && stacks->size_b > 0*/) {
						ps->operation[3](stacks);
						printf("%s\n", ps->comand[3]);
//						ft_putendl_fd(ps->comand[4], 1);
//						ft_print_stacks(stacks);
						ra -= 1;
						if (group_next % 2 == 0) {
							if (ra > 0 && stacks->a_head->group != group_next) {
								ps->operation[7](stacks);
								printf("%s\n", ps->comand[7]);
//								ft_putendl_fd(ps->comand[7], 1);
//						ft_print_stacks(stacks);
								ra -= 1;
							} else {
								ps->operation[5](stacks);
								printf("%s\n", ps->comand[5]);
//								ft_putendl_fd(ps->comand[6], 1);
//						ft_print_stacks(stacks);
							}
						}
					}
					if (stacks->b_head->group != group) {
						ps->operation[6](stacks);
						printf("%s\n", ps->comand[6]);
//						ft_putendl_fd(ps->comand[5], 1);
//						ft_print_stacks(stacks);
					}

				}
			} else {
				while (rra-- >= 0) {
//					if (!ft_find_group(stacks, group_next))
//						ft_group(stacks, i, group_next);
					while (stacks->b_head->group == group_next/* && stacks->size_b > 0*/) {
						ps->operation[3](stacks);
						printf("%s\n", ps->comand[3]);
//						ft_putendl_fd(ps->comand[4], 1);
//						ft_print_stacks(stacks);
						if (group_next % 2 == 0) {
							ps->operation[5](stacks);
							printf("%s\n", ps->comand[5]);
//							ft_putendl_fd(ps->comand[6], 1);
//						ft_print_stacks(stacks);
						}
					}
					ps->operation[9](stacks);
					printf("%s\n", ps->comand[9]);
//						ft_putendl_fd(ps->comand[8], 1);
//					ft_print_stacks(stacks);
				}
			}
			ps->operation[3](stacks);
			printf("%s\n", ps->comand[3]);
//			ft_putendl_fd(ps->comand[4], 1);
//						ft_print_stacks(stacks);
			if (group % 2 == 0) {
				ps->operation[5](stacks);
				printf("%s\n", ps->comand[5]);
//				ft_putendl_fd(ps->comand[6], 1);
//			ft_print_stacks(stacks);
			}
		}
		group++;
	}
	ft_clean_stacks(stacks);
	return (size);
}

int			ft_avr_na(t_stack *stacks, t_ps *ps, int size)
{
	int		group;
	int		group_next;
	int		ra;
	int		rra;
	t_array	*tmp;

	group = 1;
	size /= 4;

	while (stacks->size_a != 0)
	{
//		i -= i > 5 ? 1 : 0;
		if (!(ft_find_group(stacks, group)))
			ft_group(stacks, size, group);
		if (!ft_find_group(stacks,group + 1))
		{
			group_next = group + 1;
			ft_group(stacks, size, group_next);
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
//					if (!ft_find_group(stacks, group_next))
//						ft_group(stacks, i, group_next);
					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
					{
						ps->operation[4](stacks);
						printf("%s\n", ps->comand[4]);
//						ft_putendl_fd(ps->comand[4], 1);
//						ft_print_stacks(stacks);
						ra -= 1;
						if (group_next % 2 == 0)
						{
							if (ra > 0 && stacks->a_head->group != group_next)
							{
								ps->operation[7](stacks);
								printf("%s\n", ps->comand[7]);
//								ft_putendl_fd(ps->comand[7], 1);
//						ft_print_stacks(stacks);
								ra -= 1;
							}
							else
							{
								ps->operation[6](stacks);
								printf("%s\n", ps->comand[6]);
//								ft_putendl_fd(ps->comand[6], 1);
//						ft_print_stacks(stacks);
							}
						}
					}
					if (stacks->a_head->group != group)
					{
						ps->operation[5](stacks);
						printf("%s\n", ps->comand[5]);
//						ft_putendl_fd(ps->comand[5], 1);
//						ft_print_stacks(stacks);
					}

				}
			}
			else
			{
				while (rra-- >= 0)
				{
//					if (!ft_find_group(stacks, group_next))
//						ft_group(stacks, i, group_next);
					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
					{
						ps->operation[4](stacks);
						printf("%s\n", ps->comand[4]);
//						ft_putendl_fd(ps->comand[4], 1);
//						ft_print_stacks(stacks);
						if (group_next % 2 == 0)
						{
							ps->operation[6](stacks);
							printf("%s\n", ps->comand[6]);
//							ft_putendl_fd(ps->comand[6], 1);
//						ft_print_stacks(stacks);
						}
					}
					ps->operation[8](stacks);
					printf("%s\n", ps->comand[8]);
//						ft_putendl_fd(ps->comand[8], 1);
//					ft_print_stacks(stacks);
				}
			}
			ps->operation[4](stacks);
			printf("%s\n", ps->comand[4]);
//			ft_putendl_fd(ps->comand[4], 1);
//						ft_print_stacks(stacks);
			if (group % 2 == 0)
			{
				ps->operation[6](stacks);
				printf("%s\n", ps->comand[6]);
//				ft_putendl_fd(ps->comand[6], 1);
//			ft_print_stacks(stacks);
			}
		}
		group++;
//
	}
	ft_clean_stacks(stacks);
	return (size);
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
//						ft_print_stacks(stacks);
					ra--;
				}
				if (stacks->b_head->group != 1)
				{
					ps->operation[6](stacks);
					printf("%s\n", ps->comand[6]);
//					ft_putendl_fd(ps->comand[6], 1);
//						ft_print_stacks(stacks);
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
//						ft_print_stacks(stacks);
				}
				ps->operation[9](stacks);
				printf("%s\n", ps->comand[9]);
//				ft_putendl_fd(ps->comand[9], 1);
//						ft_print_stacks(stacks);
			}
		}
		ps->operation[3](stacks);
		printf("%s\n", ps->comand[3]);
//		ft_putendl_fd(ps->comand[3], 1);
//						ft_print_stacks(stacks);
		if ( stacks->size_a > 1 && stacks->a_head->num > stacks->a_head->next->num)
		{
			ps->operation[0](stacks);
			printf("%s\n", ps->comand[0]);
//			ft_putendl_fd(ps->comand[0], 1);
//						ft_print_stacks(stacks);
		}
	}
}

void		ft_push_swap_in(t_stack *stacks, t_ps *ps)
{
	int		i;

	if (stacks->size_a / 2 < 64)
		ft_avr_na(stacks, ps, 35);
	else {
		i = ft_avr_a(stacks, ps, stacks->size_a);
		while (i > 63) {
			i = ft_avr_nb(stacks, ps, i);
			i = ft_avr_na(stacks, ps, i);
		}
	}
	ft_insert_sort_b(stacks, ps);



///*	while (stacks->size_a != 0)
//	{
////		i -= i > 5 ? 1 : 0;
//		if (!(ft_find_group(stacks, group)))
//			ft_group(stacks, i, group);
//		if (!ft_find_group(stacks,group + 1))
//		{
//			group_next = group + 1;
//			ft_group(stacks, i, group_next);
//		}
//		while (ft_find_group(stacks, group))
//		{
//			ra = 0;
//			rra = 0;
//			tmp = stacks->a_head;
//			while (tmp->group != group)
//			{
//				tmp = tmp->next;
//				ra++;
//			}
//			tmp = stacks->a_end;
//			while (tmp->group != group)
//			{
//				tmp = tmp->prev;
//				rra++;
//			}
//			if (ra <= rra + 1)
//			{
//				while (ra-- > 0)
//				{
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
//					{
//						ps->operation[4](stacks);
//						printf("%s\n", ps->comand[4]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						ra -= 1;
//						if (group_next % 2 == 0)
//						{
//							if (ra > 0 && stacks->a_head->group != group_next)
//							{
//								ps->operation[7](stacks);
//								printf("%s\n", ps->comand[7]);
////								ft_putendl_fd(ps->comand[7], 1);
////						ft_print_stacks(stacks);
//								ra -= 1;
//							}
//							else
//							{
//								ps->operation[6](stacks);
//								printf("%s\n", ps->comand[6]);
////								ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//							}
//						}
//					}
//					if (stacks->a_head->group != group)
//					{
//						ps->operation[5](stacks);
//						printf("%s\n", ps->comand[5]);
////						ft_putendl_fd(ps->comand[5], 1);
////						ft_print_stacks(stacks);
//					}
//
//				}
//			}
//			else
//			{
//				while (rra-- >= 0)
//				{
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
//					{
//						ps->operation[4](stacks);
//						printf("%s\n", ps->comand[4]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						if (group_next % 2 == 0)
//						{
//							ps->operation[6](stacks);
//							printf("%s\n", ps->comand[6]);
////							ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//						}
//					}
//						ps->operation[8](stacks);
//						printf("%s\n", ps->comand[8]);
////						ft_putendl_fd(ps->comand[8], 1);
////					ft_print_stacks(stacks);
//				}
//			}
//			ps->operation[4](stacks);
//			printf("%s\n", ps->comand[4]);
////			ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//			if (group % 2 == 0)
//			{
//				ps->operation[6](stacks);
//				printf("%s\n", ps->comand[6]);
////				ft_putendl_fd(ps->comand[6], 1);
////			ft_print_stacks(stacks);
//			}
//		}
//		group++;
//
//	}*/
/*       stacks B push A*/
//	ft_clean_stacks(stacks);
///*                    fdfsdfsfd              */
//	group = 1;
//	i /= 4;
////	group_next = 2;
//	while (stacks->size_b != 0) {
////		i -= i > 5 ? 1 : 0;
//		if (!(ft_find_group_b(stacks, group)))
//			ft_group_b(stacks, i, group);
//		if (!ft_find_group_b(stacks, group + 1)) {
//			group_next = group + 1;
//			ft_group_b(stacks, i, group_next);
//		}
//		while (ft_find_group_b(stacks, group)) {
//			ra = 0;
//			rra = 0;
//			tmp = stacks->b_head;
//			while (tmp->group != group) {
//				tmp = tmp->next;
//				ra++;
//			}
//			tmp = stacks->b_end;
//			while (tmp->group != group) {
//				tmp = tmp->prev;
//				rra++;
//			}
//			if (ra <= rra + 1) {
//				while (ra-- > 0) {
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->b_head->group == group_next/* && stacks->size_b > 0*/) {
//						ps->operation[3](stacks);
//						printf("%s\n", ps->comand[3]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						ra -= 1;
//						if (group_next % 2 == 0) {
//							if (ra > 0 && stacks->a_head->group != group_next) {
//								ps->operation[7](stacks);
//								printf("%s\n", ps->comand[7]);
////								ft_putendl_fd(ps->comand[7], 1);
////						ft_print_stacks(stacks);
//								ra -= 1;
//							} else {
//								ps->operation[5](stacks);
//								printf("%s\n", ps->comand[5]);
////								ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//							}
//						}
//					}
//					if (stacks->b_head->group != group) {
//						ps->operation[6](stacks);
//						printf("%s\n", ps->comand[6]);
////						ft_putendl_fd(ps->comand[5], 1);
////						ft_print_stacks(stacks);
//					}
//
//				}
//			} else {
//				while (rra-- >= 0) {
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->b_head->group == group_next/* && stacks->size_b > 0*/) {
//						ps->operation[3](stacks);
//						printf("%s\n", ps->comand[3]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						if (group_next % 2 == 0) {
//							ps->operation[5](stacks);
//							printf("%s\n", ps->comand[5]);
////							ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//						}
//					}
//					ps->operation[9](stacks);
//					printf("%s\n", ps->comand[9]);
////						ft_putendl_fd(ps->comand[8], 1);
////					ft_print_stacks(stacks);
//				}
//			}
//			ps->operation[3](stacks);
//			printf("%s\n", ps->comand[3]);
////			ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//			if (group % 2 == 0) {
//				ps->operation[5](stacks);
//				printf("%s\n", ps->comand[5]);
////				ft_putendl_fd(ps->comand[6], 1);
////			ft_print_stacks(stacks);
//			}
//		}
//		group++;
//	}
//	ft_clean_stacks(stacks);

/*      stack a to b*/
//	group = 1;
////	group_next = 2;
//
//	i /=  4;
//	while (stacks->size_a != 0)
//	{
////		i -= i > 5 ? 1 : 0;
//		if (!(ft_find_group(stacks, group)))
//			ft_group(stacks, i, group);
//		if (!ft_find_group(stacks,group + 1))
//		{
//			group_next = group + 1;
//			ft_group(stacks, i, group_next);
//		}
//		while (ft_find_group(stacks, group))
//		{
//			ra = 0;
//			rra = 0;
//			tmp = stacks->a_head;
//			while (tmp->group != group)
//			{
//				tmp = tmp->next;
//				ra++;
//			}
//			tmp = stacks->a_end;
//			while (tmp->group != group)
//			{
//				tmp = tmp->prev;
//				rra++;
//			}
//			if (ra <= rra + 1)
//			{
//				while (ra-- > 0)
//				{
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
//					{
//						ps->operation[4](stacks);
//						printf("%s\n", ps->comand[4]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						ra -= 1;
//						if (group_next % 2 == 0)
//						{
//							if (ra > 0 && stacks->a_head->group != group_next)
//							{
//								ps->operation[7](stacks);
//								printf("%s\n", ps->comand[7]);
////								ft_putendl_fd(ps->comand[7], 1);
////						ft_print_stacks(stacks);
//								ra -= 1;
//							}
//							else
//							{
//								ps->operation[6](stacks);
//								printf("%s\n", ps->comand[6]);
////								ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//							}
//						}
//					}
//					if (stacks->a_head->group != group)
//					{
//						ps->operation[5](stacks);
//						printf("%s\n", ps->comand[5]);
////						ft_putendl_fd(ps->comand[5], 1);
////						ft_print_stacks(stacks);
//					}
//
//				}
//			}
//			else
//			{
//				while (rra-- >= 0)
//				{
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
//					{
//						ps->operation[4](stacks);
//						printf("%s\n", ps->comand[4]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						if (group_next % 2 == 0)
//						{
//							ps->operation[6](stacks);
//							printf("%s\n", ps->comand[6]);
////							ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//						}
//					}
//					ps->operation[8](stacks);
//					printf("%s\n", ps->comand[8]);
////						ft_putendl_fd(ps->comand[8], 1);
////					ft_print_stacks(stacks);
//				}
//			}
//			ps->operation[4](stacks);
//			printf("%s\n", ps->comand[4]);
////			ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//			if (group % 2 == 0)
//			{
//				ps->operation[6](stacks);
//				printf("%s\n", ps->comand[6]);
////				ft_putendl_fd(ps->comand[6], 1);
////			ft_print_stacks(stacks);
//			}
//		}
//		group++;
////
//	}
//	ft_clean_stacks(stacks);
///*                    fdfsdfsfd              */
//	group = 1;
//	i /= 2 ;
////	group_next = 2;
//	while (stacks->size_b != 0) {
////		i -= i > 5 ? 1 : 0;
//		if (!(ft_find_group_b(stacks, group)))
//			ft_group_b(stacks, i, group);
//		if (!ft_find_group_b(stacks, group + 1)) {
//			group_next = group + 1;
//			ft_group_b(stacks, i, group_next);
//		}
//		while (ft_find_group_b(stacks, group)) {
//			ra = 0;
//			rra = 0;
//			tmp = stacks->b_head;
//			while (tmp->group != group) {
//				tmp = tmp->next;
//				ra++;
//			}
//			tmp = stacks->b_end;
//			while (tmp->group != group) {
//				tmp = tmp->prev;
//				rra++;
//			}
//			if (ra <= rra + 1) {
//				while (ra-- > 0) {
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->b_head->group == group_next/* && stacks->size_b > 0*/) {
//						ps->operation[3](stacks);
//						printf("%s\n", ps->comand[3]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						ra -= 1;
//						if (group_next % 2 == 0) {
//							if (ra > 0 && stacks->a_head->group != group_next) {
//								ps->operation[7](stacks);
//								printf("%s\n", ps->comand[7]);
////								ft_putendl_fd(ps->comand[7], 1);
////						ft_print_stacks(stacks);
//								ra -= 1;
//							} else {
//								ps->operation[5](stacks);
//								printf("%s\n", ps->comand[5]);
////								ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//							}
//						}
//					}
//					if (stacks->b_head->group != group) {
//						ps->operation[6](stacks);
//						printf("%s\n", ps->comand[6]);
////						ft_putendl_fd(ps->comand[5], 1);
////						ft_print_stacks(stacks);
//					}
//
//				}
//			} else {
//				while (rra-- >= 0) {
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->b_head->group == group_next/* && stacks->size_b > 0*/) {
//						ps->operation[3](stacks);
//						printf("%s\n", ps->comand[3]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						if (group_next % 2 == 0) {
//							ps->operation[5](stacks);
//							printf("%s\n", ps->comand[5]);
////							ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//						}
//					}
//					ps->operation[9](stacks);
//					printf("%s\n", ps->comand[9]);
////						ft_putendl_fd(ps->comand[8], 1);
////					ft_print_stacks(stacks);
//				}
//			}
//			ps->operation[3](stacks);
//			printf("%s\n", ps->comand[3]);
////			ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//			if (group % 2 == 0) {
//				ps->operation[5](stacks);
//				printf("%s\n", ps->comand[5]);
////				ft_putendl_fd(ps->comand[6], 1);
////			ft_print_stacks(stacks);
//			}
//		}
//		group++;
//	}
//	ft_clean_stacks(stacks);
//
////	ft_clean_stacks(stacks);
//	group = 1;
//	i /= 2;
////	group_next = 2;
////	i = i / 2;
//	while (stacks->size_a != 0)
//	{
////		i -= i > 5 ? 1 : 0;
//		if (!(ft_find_group(stacks, group)))
//			ft_group(stacks, i, group);
//		if (!ft_find_group(stacks,group + 1))
//		{
//			group_next = group + 1;
//			ft_group(stacks, i, group_next);
//		}
//		while (ft_find_group(stacks, group))
//		{
//			ra = 0;
//			rra = 0;
//			tmp = stacks->a_head;
//			while (tmp->group != group)
//			{
//				tmp = tmp->next;
//				ra++;
//			}
//			tmp = stacks->a_end;
//			while (tmp->group != group)
//			{
//				tmp = tmp->prev;
//				rra++;
//			}
//			if (ra <= rra + 1)
//			{
//				while (ra-- > 0)
//				{
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
//					{
//						ps->operation[4](stacks);
//						printf("%s\n", ps->comand[4]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						ra -= 1;
//						if (group_next % 2 == 0)
//						{
//							if (ra > 0 && stacks->a_head->group != group_next)
//							{
//								ps->operation[7](stacks);
//								printf("%s\n", ps->comand[7]);
////								ft_putendl_fd(ps->comand[7], 1);
////						ft_print_stacks(stacks);
//								ra -= 1;
//							}
//							else
//							{
//								ps->operation[6](stacks);
//								printf("%s\n", ps->comand[6]);
////								ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//							}
//						}
//					}
//					if (stacks->a_head->group != group)
//					{
//						ps->operation[5](stacks);
//						printf("%s\n", ps->comand[5]);
////						ft_putendl_fd(ps->comand[5], 1);
////						ft_print_stacks(stacks);
//					}
//
//				}
//			}
//			else
//			{
//				while (rra-- >= 0)
//				{
////					if (!ft_find_group(stacks, group_next))
////						ft_group(stacks, i, group_next);
//					while (stacks->a_head->group == group_next/* && stacks->size_b > 0*/)
//					{
//						ps->operation[4](stacks);
//						printf("%s\n", ps->comand[4]);
////						ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//						if (group_next % 2 == 0)
//						{
//							ps->operation[6](stacks);
//							printf("%s\n", ps->comand[6]);
////							ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//						}
//					}
//					ps->operation[8](stacks);
//					printf("%s\n", ps->comand[8]);
////						ft_putendl_fd(ps->comand[8], 1);
////					ft_print_stacks(stacks);
//				}
//			}
//			ps->operation[4](stacks);
//			printf("%s\n", ps->comand[4]);
////			ft_putendl_fd(ps->comand[4], 1);
////						ft_print_stacks(stacks);
//			if (group % 2 == 0)
//			{
//				ps->operation[6](stacks);
//				printf("%s\n", ps->comand[6]);
////				ft_putendl_fd(ps->comand[6], 1);
////			ft_print_stacks(stacks);
//			}
//		}
//		group++;
//
//	}


/*    insert_sort  */
//	tmp = stacks->b_head;
//
//	while (tmp)
//	{
//		tmp->group = 0;
//		tmp = tmp->next;
//	}
//
//	while (stacks->size_b > 0)
//	{
//		if (!(ft_find_group_b(stacks, 1)))
//			ft_max_b(stacks, 1);
//		tmp = stacks->b_head;
//		ra = 0;
//		while (tmp->group != 1)
//		{
//			ra++;
//			tmp = tmp->next;
//		}
//		rra = stacks->size_b - ra;
//		if (stacks->size_b > 1)
//			ft_max_b(stacks, 1);
//		if (ra <= rra)
//		{
//			while (ra-- > 0)
//			{
//				if (stacks->b_head->group == 1)
//				{
//					ps->operation[3](stacks);
//					printf("%s\n", ps->comand[3]);
////					ft_putendl_fd(ps->comand[3], 1);
////						ft_print_stacks(stacks);
//					ra--;
//				}
//				if (stacks->b_head->group != 1)
//				{
//					ps->operation[6](stacks);
//					printf("%s\n", ps->comand[6]);
////					ft_putendl_fd(ps->comand[6], 1);
////						ft_print_stacks(stacks);
//				}
//			}
//		}
//		else{
//			while  (rra-- > 0)
//			{
//				if (stacks->b_head->group == 1)
//				{
//					ps->operation[3](stacks);
//					printf("%s\n", ps->comand[3]);
////					ft_putendl_fd(ps->comand[3], 1);
////						ft_print_stacks(stacks);
//				}
//				ps->operation[9](stacks);
//				printf("%s\n", ps->comand[9]);
////				ft_putendl_fd(ps->comand[9], 1);
////						ft_print_stacks(stacks);
//			}
//		}
//		ps->operation[3](stacks);
//		printf("%s\n", ps->comand[3]);
////		ft_putendl_fd(ps->comand[3], 1);
////						ft_print_stacks(stacks);
//		if ( stacks->size_a > 1 && stacks->a_head->num > stacks->a_head->next->num)
//		{
//			ps->operation[0](stacks);
//			printf("%s\n", ps->comand[0]);
////			ft_putendl_fd(ps->comand[0], 1);
////						ft_print_stacks(stacks);
//		}
//	}
}

//int			ft_stacks_min_in_b(t_stack *stacks, int group)
//{
//	t_array	*tmp;
//	t_array	*m;
//	int		min;
//
//	tmp = stacks->b_head;
//	while (tmp->group != 0 && tmp != stacks->b_end)
//		tmp = tmp->next;
//	min = tmp->num;
//	m = tmp;
//	m->group = group;
//	while (tmp != stacks->b_end)
//	{
//		if (min > tmp->next->num && tmp->next->group == 0)
//		{
//			min = tmp->next->num;
//			m->group = 0;
//			m = tmp->next;
//			m->group = group;
//		}
//		tmp = tmp->next;
//	}
//	return (min);
//}

//void	ft_clean_stacks(t_stack *stacks)
//{
//	t_array	*tmp;
//
//	tmp = stacks->b_head;
//	while (tmp)
//	{
//		tmp->group = 0;
//		tmp = tmp->next;
//	}
//	tmp = stacks->a_head;
//	while (tmp)
//	{
//		tmp->group = 0;
//		tmp = tmp->next;
//	}
//}
//
//void		ft_group_b(t_stack *stacks, int len, int group)
//{
//	int		max;
//
////	if (ft_find_group(stacks, 0))
////		min = ft_stacks_min_in(stacks, group);
//	while (len-- > 0 && ft_find_group_b(stacks, 0))
//	{
//		max = ft_max_b(stacks, group);
//	}
//}

void	ft_push_swap_av(t_stack *stacks, t_ps *ps)
{
	int size_ga;
	int size_gb;
	int group_a;
	int group_b;
	t_array *tmp;
	int		i;
	int		ra;
	int		rra;

	size_ga = stacks->size_a / 2;
	size_gb = stacks->size_a - size_ga;
	group_b = 1;


	ft_group(stacks, size_ga, 1);
	ft_group(stacks,size_gb, 2);
	i = 1;
	while (ft_find_group(stacks, i)) {
		while (ft_find_group(stacks, i)) {
			while (stacks->a_head->group != i) {
				ps->operation[5](stacks);
				printf("%s\n", ps->comand[5]);
			}
			ps->operation[4](stacks);
			printf("%s\n", ps->comand[4]);
		}
		i++;
	}
	ft_clean_stacks(stacks);

	ft_group_b(stacks, size_gb / 2, 1);
	ft_group_b(stacks, size_gb / 2, 2);
	size_gb /=  2;
	ft_group_b(stacks, size_ga/2 , 3);
	ft_group_b(stacks, size_ga/2 , 4);
	size_ga /=2;
	i = 1;
	while (stacks->size_b != 0) {
		if (!ft_find_group_b(stacks, i))
			ft_group_b(stacks, 8, i);
		while (ft_find_group_b(stacks, i)) {
			ra = 0;
			rra = 0;
			tmp = stacks->b_head;
			while (tmp->group != i) {
				tmp = tmp->next;
				ra++;
			}
			tmp = stacks->b_end;
			while (tmp->group != i) {
				tmp = tmp->prev;
				rra++;
			}
			if (ra <= rra + 1) {
				while (stacks->b_head->group != i) {
					ps->operation[6](stacks);
					printf("%s\n", ps->comand[6]);
				}
				ps->operation[3](stacks);
				printf("%s\n", ps->comand[3]);
			} else {
				while (stacks->b_head->group != i) {
					ps->operation[9](stacks);
					printf("%s\n", ps->comand[9]);
				}
				ps->operation[3](stacks);
				printf("%s\n", ps->comand[3]);
			}
		}
		i += 1;
	}
	ft_clean_stacks(stacks);
/*
	ft_clean_stacks(stacks);
		ft_group(stacks, stacks->size_a - 250 , i);
	while (ft_find_group(stacks, i) != 0) {

		while (ft_find_group(stacks, i)) {
			ra = 0;
			rra = 0;
			tmp = stacks->a_head;
			while (tmp->group != i) {
				tmp = tmp->next;
				ra++;
			}
			tmp = stacks->a_end;
			while (tmp->group != i) {
				tmp = tmp->prev;
				rra++;
			}
			if (ra <= rra + 1 ) {
				while (stacks->a_head->group != i) {
					ps->operation[5](stacks);
					printf("%s\n", ps->comand[5]);
				}
				ps->operation[4](stacks);
				printf("%s\n", ps->comand[4]);
			} else {
				while (stacks->a_head->group != i) {
					ps->operation[8](stacks);
					printf("%s\n", ps->comand[8]);
				}
				ps->operation[4](stacks);
				printf("%s\n", ps->comand[4]);
			}
		}
		i++;
	}


	ft_clean_stacks(stacks);
	ft_group(stacks,size_gb / 2, 1);
	size_gb /= 2;
	ft_group(stacks,size_gb / 2, 2);
	size_gb /= 2;
	ft_group(stacks,size_gb / 2, 3);
	size_gb /= 2;
	ft_group(stacks,size_gb * 2, 4);

	i = 1;
	while (ft_find_group(stacks, i)) {
		while (ft_find_group(stacks, i)) {
			while (stacks->a_head->group != i) {
				ps->operation[5](stacks);
				printf("%s\n", ps->comand[5]);
			}
			ps->operation[4](stacks);
			printf("%s\n", ps->comand[4]);
		}
		i++;
	}
	ft_clean_stacks(stacks);
	i = 1;
	while (stacks->size_b != 0) {
		if (!ft_find_group_b(stacks, i))
			ft_group_b(stacks, 8, i);
		while (ft_find_group_b(stacks, i)) {
			ra = 0;
			rra = 0;
			tmp = stacks->b_head;
			while (tmp->group != i) {
				tmp = tmp->next;
				ra++;
			}
			tmp = stacks->b_end;
			while (tmp->group != i) {
				tmp = tmp->prev;
				rra++;
			}
			if (ra <= rra + 1) {
				while (stacks->b_head->group != i) {
					ps->operation[6](stacks);
					printf("%s\n", ps->comand[6]);
				}
				ps->operation[3](stacks);
				printf("%s\n", ps->comand[3]);
			} else {
				while (stacks->b_head->group != i) {
					ps->operation[9](stacks);
					printf("%s\n", ps->comand[9]);
				}
				ps->operation[3](stacks);
				printf("%s\n", ps->comand[3]);
			}
		}
		i += 1;
	}
	ft_clean_stacks(stacks);
	i = 1;
	while (stacks->size_a != 0) {
		if (!ft_find_group(stacks, i))
			ft_group(stacks, 15, i);
		while (ft_find_group(stacks, i)) {
			ra = 0;
			rra = 0;
			tmp = stacks->a_head;
			while (tmp->group != i) {
				tmp = tmp->next;
				ra++;
			}
			tmp = stacks->a_end;
			while (tmp->group != i) {
				tmp = tmp->prev;
				rra++;
			}
			if (ra <= rra + 1 ) {
				while (stacks->a_head->group != i) {
					ps->operation[5](stacks);
					printf("%s\n", ps->comand[5]);
				}
				ps->operation[4](stacks);
				printf("%s\n", ps->comand[4]);
			} else {
				while (stacks->a_head->group != i) {
					ps->operation[8](stacks);
					printf("%s\n", ps->comand[8]);
				}
				ps->operation[4](stacks);
				printf("%s\n", ps->comand[4]);
			}
		}
		i++;
	}*/
/*
	ft_group_b(stacks, size_gb / 2, 1);
	ft_group_b(stacks, size_gb / 2, 2);
	ft_group_b(stacks, size_gb , 3);
	ft_group_b(stacks, size_gb , 4);
	ft_group_b(stacks, size_gb * 2, 5);
	ft_group_b(stacks, size_gb * 2, 6);
	size_gb /= 2;
	i = 1;
	while (ft_find_group_b(stacks, i)) {

		while (ft_find_group_b(stacks, i)) {
			ra = 0;
			rra = 0;
			tmp = stacks->b_head;
			while (tmp->group != i) {
				tmp = tmp->next;
				ra++;
			}
			tmp = stacks->b_end;
			while (tmp->group != i) {
				tmp = tmp->prev;
				rra++;
			}
			if (ra <= rra + 1) {
				while (stacks->b_head->group != i) {
					ps->operation[6](stacks);
					printf("%s\n", ps->comand[6]);
				}
				ps->operation[3](stacks);
				printf("%s\n", ps->comand[3]);
			} else {
				while (stacks->b_head->group != i) {
					ps->operation[9](stacks);
					printf("%s\n", ps->comand[9]);
				}
				ps->operation[3](stacks);
				printf("%s\n", ps->comand[3]);
			}
		}
		i += 1;
	}*/
/*
	ft_clean_stacks(stacks);
	ft_group_b(stacks,size_ga / 2, 1);
	size_ga /= 2;
	ft_group_b(stacks,size_ga / 2, 2);
	size_ga /= 2;
	ft_group_b(stacks,size_ga / 2, 3);
	size_ga /= 2;
	i = 1;
	while (ft_find_group_b(stacks, i)) {
		while (ft_find_group_b(stacks, i)) {
			while (stacks->b_head->group != i) {
				ps->operation[6](stacks);
				printf("%s\n", ps->comand[6]);
			}
			ps->operation[3](stacks);
			printf("%s\n", ps->comand[3]);
		}
		i++;
	}
	ft_clean_stacks(stacks);
	ft_group(stacks, size_ga / 2, 1);
	ft_group(stacks, size_ga / 2, 2);
	ft_group(stacks, size_ga , 3);
	ft_group(stacks, size_ga , 4);
	ft_group(stacks, size_ga * 2 , 5);
	ft_group(stacks, size_ga * 2, 6);
	ft_group(stacks, size_gb * 2, 7);
	ft_group(stacks, size_gb * 2, 8);
	ft_group(stacks, size_gb * 2, 9);
	ft_group(stacks, size_gb * 2, 10);
	ft_group(stacks, size_gb , 11);
	ft_group(stacks, size_gb , 12);
	ft_group(stacks, size_gb , 13);
	ft_group(stacks, size_gb , 14);
	ft_group(stacks, size_gb / 2, 15);
	ft_group(stacks, size_gb / 2, 16);
	ft_group(stacks, size_gb / 2, 17);
	ft_group(stacks, size_gb / 2, 18);
	ft_group(stacks, size_gb * 2, 19);
	ft_group(stacks, size_gb * 2, 20);
	i = 1;
	while (ft_find_group(stacks, i) != 0) {

		while (ft_find_group(stacks, i)) {
			ra = 0;
			rra = 0;
			tmp = stacks->a_head;
			while (tmp->group != i) {
				tmp = tmp->next;
				ra++;
			}
			tmp = stacks->a_end;
			while (tmp->group != i) {
				tmp = tmp->prev;
				rra++;
			}
			if (ra <= rra + 1 ) {
				while (stacks->a_head->group != i) {
					ps->operation[5](stacks);
					printf("%s\n", ps->comand[5]);
				}
				ps->operation[4](stacks);
				printf("%s\n", ps->comand[4]);
			} else {
				while (stacks->a_head->group != i) {
					ps->operation[8](stacks);
					printf("%s\n", ps->comand[8]);
				}
				ps->operation[4](stacks);
				printf("%s\n", ps->comand[4]);
			}
		}
		i++;
	}
	ft_clean_stacks(stacks);
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
//						ft_print_stacks(stacks);
					ra--;
				}
				if (stacks->b_head->group != 1)
				{
					ps->operation[6](stacks);
					printf("%s\n", ps->comand[6]);
//					ft_putendl_fd(ps->comand[6], 1);
//						ft_print_stacks(stacks);
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
//						ft_print_stacks(stacks);
				}
				ps->operation[9](stacks);
				printf("%s\n", ps->comand[9]);
//				ft_putendl_fd(ps->comand[9], 1);
//						ft_print_stacks(stacks);
			}
		}
		ps->operation[3](stacks);
		printf("%s\n", ps->comand[3]);
//		ft_putendl_fd(ps->comand[3], 1);
//						ft_print_stacks(stacks);
		if ( stacks->size_a > 1 && stacks->a_head->num > stacks->a_head->next->num)
		{
			ps->operation[0](stacks);
			printf("%s\n", ps->comand[0]);
//			ft_putendl_fd(ps->comand[0], 1);
//						ft_print_stacks(stacks);
		}
	}*/

	/*
	ft_group(stacks,size_gb / 2, 2);
	size_gb /= 2;
	ft_group(stacks,size_gb, 3);

	while (ft_find_group(stacks))



		while (stacks->size_b != 0)
	{
		if (!ft_find_group_b(stacks, 1))
			ft_group_b(stacks, size_ga / 2, 1);
		while (ft_find_group_b(stacks, 1))
		{
				while (stacks->b_head->group != 1)
				{
					ps->operation[6](stacks);
					printf("%s\n", ps->comand[6]);
				}
				ps->operation[3](stacks);
				printf("%s\n", ps->comand[3]);
		}
	}
	ft_clean_stacks(stacks);
	size_ga = size_ga / 2;
	group_a = 2;
//	while (!(stacks->size_b > 0 && size_gb < 30))
//	{
		size_ga = size_ga / 2;
		size_gb = size_gb / 2;
		group_a *= 2;
		group_b *= 2;
		if (stacks->size_b == 0)
		{

			i = 0;
			while (i++ < group_a)
				ft_group(stacks, size_ga, i);
			while (ft_find_group(stacks, 0))
				ft_group(stacks, size_gb, i++);

			i = 1;
			while (stacks->size_a != 0) {

				while (ft_find_group(stacks, i)) {
					ra = 0;
					rra = 0;
					tmp = stacks->a_head;
					while (tmp->group != i) {
						tmp = tmp->next;
						ra++;
					}
					tmp = stacks->a_end;
					while (tmp->group != i) {
						tmp = tmp->prev;
						rra++;
					}
					if (ra <= rra + 1 ) {
						while (stacks->a_head->group != i) {
							ps->operation[5](stacks);
							printf("%s\n", ps->comand[5]);
						}
						ps->operation[4](stacks);
						printf("%s\n", ps->comand[4]);
					} else {
						while (stacks->a_head->group != i) {
							ps->operation[8](stacks);
							printf("%s\n", ps->comand[8]);
						}
						ps->operation[4](stacks);
						printf("%s\n", ps->comand[4]);
					}
				}
				i++;
			}
		}
			ft_clean_stacks(stacks);
			size_ga = size_ga / 2;
			size_gb = size_gb / 2;
			group_a *= 2;
			group_b *= 2;
			if (stacks->size_a == 0)
			{

				i = 0;

				while (i++ < group_b)
					ft_group_b(stacks, size_gb, i);
				while (ft_find_group_b(stacks, 0))
					ft_group_b(stacks, size_ga, i++);

				i = 1;
				while (stacks->size_b != 0) {

					while (ft_find_group_b(stacks, i)) {
						ra = 0;
						rra = 0;
						tmp = stacks->b_head;
						while (tmp->group != i) {
							tmp = tmp->next;
							ra++;
						}
						tmp = stacks->b_end;
						while (tmp->group != i) {
							tmp = tmp->prev;
							rra++;
						}
						if (ra <= rra + 1) {
							while (stacks->b_head->group != i) {
								ps->operation[6](stacks);
								printf("%s\n", ps->comand[6]);
							}
							ps->operation[3](stacks);
							printf("%s\n", ps->comand[3]);
						} else {
							while (stacks->b_head->group != i) {
								ps->operation[9](stacks);
								printf("%s\n", ps->comand[9]);
							}
							ps->operation[3](stacks);
							printf("%s\n", ps->comand[3]);
						}
					}
					i++;
				}
			}
			ft_clean_stacks(stacks);
	size_ga = size_ga / 2;
	size_gb = size_gb / 2;
	group_a *= 2;
	group_b *= 2;
	if (stacks->size_b == 0)
	{

		i = 0;
		while (i++ < group_a)
			ft_group(stacks, size_ga, i);
		while (ft_find_group(stacks, 0))
			ft_group(stacks, size_gb, i++);

		i = 1;
		while (stacks->size_a != 0) {

			while (ft_find_group(stacks, i)) {
				ra = 0;
				rra = 0;
				tmp = stacks->a_head;
				while (tmp->group != i) {
					tmp = tmp->next;
					ra++;
				}
				tmp = stacks->a_end;
				while (tmp->group != i) {
					tmp = tmp->prev;
					rra++;
				}
				if (ra <= rra + 1 ) {
					while (stacks->a_head->group != i) {
						ps->operation[5](stacks);
						printf("%s\n", ps->comand[5]);
					}
					ps->operation[4](stacks);
					printf("%s\n", ps->comand[4]);
				} else {
					while (stacks->a_head->group != i) {
						ps->operation[8](stacks);
						printf("%s\n", ps->comand[8]);
					}
					ps->operation[4](stacks);
					printf("%s\n", ps->comand[4]);
				}
			}
			i++;
		}
	}*/
/*	ft_clean_stacks(stacks);
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
//						ft_print_stacks(stacks);
					ra--;
				}
				if (stacks->b_head->group != 1)
				{
					ps->operation[6](stacks);
					printf("%s\n", ps->comand[6]);
//					ft_putendl_fd(ps->comand[6], 1);
//						ft_print_stacks(stacks);
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
//						ft_print_stacks(stacks);
				}
				ps->operation[9](stacks);
				printf("%s\n", ps->comand[9]);
//				ft_putendl_fd(ps->comand[9], 1);
//						ft_print_stacks(stacks);
			}
		}
		ps->operation[3](stacks);
		printf("%s\n", ps->comand[3]);
//		ft_putendl_fd(ps->comand[3], 1);
//						ft_print_stacks(stacks);
		if ( stacks->size_a > 1 && stacks->a_head->num > stacks->a_head->next->num)
		{
			ps->operation[0](stacks);
			printf("%s\n", ps->comand[0]);
//			ft_putendl_fd(ps->comand[0], 1);
//						ft_print_stacks(stacks);
		}
	}*/
}