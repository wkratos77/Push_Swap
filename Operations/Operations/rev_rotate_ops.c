/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:18:44 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/09 22:58:15 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate_stack(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*beforel;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	last = stack_last(*s);
	beforel = *s;
	while (beforel->next != last)
		beforel = beforel->next;
	beforel->next = NULL;
	last->next = first;
	*s = last;
}

void	rra(t_stack **a)
{
	rev_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	write(1, "rrr\n", 4);
}
