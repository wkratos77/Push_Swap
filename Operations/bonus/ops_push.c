/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:37:14 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/21 16:45:38 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push_stack(t_stack **from, t_stack **to)
{
	t_stack	*hlp;

	if (!from || !*from || !to)
		return ;
	hlp = *from;
	*from = (*from)->next;
	hlp->next = *to;
	*to = hlp;
}

void	pa(t_stack **a, t_stack **b)
{
	push_stack(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(a, b);
}
