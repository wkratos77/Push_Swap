/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:41:32 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/12 03:37:23 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*current;
	t_stack	*next;

	if (!a || !a->next)
		return (1);
	current = a;
	next = current->next;
	while (next)
	{
		if (current->nbr > next->nbr)
			return (0);
		current = current->next;
		next = next->next;
	}
	return (1);
}

int	find_min_pos(t_stack *a)
{
	int		i;
	int		pos;
	int		min;
	t_stack	*hlp;

	if (!a)
		return (-1);
	pos = 0;
	hlp = a;
	min = hlp->index;
	i = 0;
	while (hlp)
	{
		if (hlp->index < min)
		{
			min = hlp->index;
			pos = i;
		}
		hlp = hlp->next;
		i++;
	}
	return (pos);
}

int	find_max_pos(t_stack *a)
{
	int		i;
	int		pos;
	int		max;
	t_stack	*hlp;

	if (!a)
		return (-1);
	pos = 0;
	hlp = a;
	max = hlp->index;
	i = 0;
	while (hlp)
	{
		if (hlp->index > max)
		{
			max = hlp->index;
			pos = i;
		}
		hlp = hlp->next;
		i++;
	}
	return (pos);
}

void	rotate_a_to_top(t_stack **a, int pos)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		while (i++ < pos)
			ra(a);
	}
	else
	{
		while (i++ < size - pos)
			rra(a);
	}
}

void	rotate_b_to_top(t_stack **b, int pos)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*b);
	if (pos <= size / 2)
	{
		while (i++ < pos)
			rb(b);
	}
	else
	{
		while (i++ < size - pos)
			rrb(b);
	}
}
