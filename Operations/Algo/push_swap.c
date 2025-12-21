/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:17:08 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/18 21:17:17 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a)
		return ;
	indexing(*a);
	if (is_sorted(*a))
		return ;
	size = ft_lstsize(*a);
	if (size <= 5)
		small_sort(a, b);
	else
		chunk_sort(a, b);
}
