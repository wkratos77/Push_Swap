/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:52:09 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/18 16:05:59 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_two(t_stack **a)
{
	t_stack	*hlp;

	if (!a || !*a || !(*a)->next)
		return ;
	hlp = *a;
	if (hlp->index > hlp->next->index)
		sa(a);
}

static void	sort_three(t_stack **a)
{
	int	max_pos;

	if (!a || !*a)
		return ;
	if (ft_lstsize(*a) == 2)
		return (sort_two(a));
	if (ft_lstsize(*a) < 3)
		return ;
	max_pos = find_max_pos(*a);
	if (max_pos == 0)
		ra(a);
	else if (max_pos == 1)
		rra(a);
	sort_two(a);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	pos;

	if (!a || !*a)
		return ;
	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	if (size == 2)
		return (sort_two(a));
	if (size == 3)
		return (sort_three(a));
	while (ft_lstsize(*a) > 3)
	{
		pos = find_min_pos(*a);
		rotate_a_to_top(a, pos);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
