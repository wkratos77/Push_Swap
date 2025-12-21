/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:37:50 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/21 16:45:41 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	rrb(t_stack **b)
{
	rev_rotate_stack(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
}
