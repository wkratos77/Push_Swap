/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:37:39 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/18 21:27:36 by wkrati           ###   ########.fr       */
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

static void	advance_window(int *state)
{
	if (state[0] < state[2] - 1)
		state[0]++;
	if (state[1] < state[2] - 1)
		state[1]++;
}

static void	push_to_b(t_stack **a, t_stack **b, int *state)
{
	pb(a, b);
	if ((*b)->index <= state[0])
		rb(b);
	advance_window(state);
}

static void	push_chunks(t_stack **a, t_stack **b, int n)
{
	int	state[3];

	state[0] = 0;
	state[2] = n;
	state[1] = chunk_size(n);
	if (state[1] > n - 1)
		state[1] = n - 1;
	while (*a)
	{
		if ((*a)->index <= state[1])
			push_to_b(a, b, state);
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
