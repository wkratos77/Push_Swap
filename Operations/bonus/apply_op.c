/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:59:20 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/21 23:53:22 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	trim_newline(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	if (i > 0 && s[i - 1] == '\n')
		s[i - 1] = '\0';
}

int	apply_op(char *line, t_stack **a, t_stack **b)
{
	trim_newline(line);
	if (ft_strcmp(line, "pa") == 0)
		return (pa(a, b), 1);
	if (ft_strcmp(line, "pb") == 0)
		return (pb(a, b), 1);
	if (ft_strcmp(line, "sa") == 0)
		return (sa(a), 1);
	if (ft_strcmp(line, "sb") == 0)
		return (sb(b), 1);
	if (ft_strcmp(line, "ss") == 0)
		return (ss(a, b), 1);
	if (ft_strcmp(line, "ra") == 0)
		return (ra(a), 1);
	if (ft_strcmp(line, "rb") == 0)
		return (rb(b), 1);
	if (ft_strcmp(line, "rr") == 0)
		return (rr(a, b), 1);
	if (ft_strcmp(line, "rra") == 0)
		return (rra(a), 1);
	if (ft_strcmp(line, "rrb") == 0)
		return (rrb(b), 1);
	if (ft_strcmp(line, "rrr") == 0)
		return (rrr(a, b), 1);
	return (0);
}
