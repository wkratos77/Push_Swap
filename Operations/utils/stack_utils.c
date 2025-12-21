/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:13:35 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/18 21:01:56 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_new(int nbr)
{
	t_stack	*n;

	n = malloc(sizeof(t_stack));
	if (!n)
		return (NULL);
	n->nbr = nbr;
	n->index = 0;
	n->next = NULL;
	return (n);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = stack_last(*stack);
	last->next = new;
}

int	ft_lstsize(t_stack *stack)
{
	int	l;

	l = 0;
	while (stack)
	{
		stack = stack->next;
		l++;
	}
	return (l);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s || !*s)
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
	*s = NULL;
}
