/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:37:39 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/20 22:21:26 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	chunk_size(int n)
{
	if (n <= 100)
		return (n / 5);
	if (n <= 500)
		return (n / 12);
	return (n / 20);
}

static void	advance_chunk(t_chunk *w)
{
	if (w->low < w->n - 1)
		w->low++;
	if (w->high < w->n - 1)
		w->high++;
}

static void	push_to_b(t_stack **a, t_stack **b, t_chunk *w)
{
	pb(a, b);
	if ((*b)->index <= w->low)
		rb(b);
	advance_chunk(w);
}

static void	push_chunks(t_stack **a, t_stack **b, int n)
{
	t_chunk	w;

	w.low = 0;
	w.n = n;
	w.high = chunk_size(n);
	if (w.high >= n)
		w.high = n - 1;
	while (*a)
	{
		if ((*a)->index <= w.high)
			push_to_b(a, b, &w);
		else
			ra(a);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	pos;

	if (!a || !*a)
		return ;
	push_chunks(a, b, ft_lstsize(*a));
	while (*b)
	{
		pos = find_max_pos(*b);
		rotate_b_to_top(b, pos);
		pa(a, b);
	}
}
