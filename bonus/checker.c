/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:22:29 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/21 17:30:48 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	error_exit(t_stack **a, t_stack **b, char *line)
{
	if (line)
		free(line);
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_args(ac, av, &a))
		return (error_exit(&a, &b, NULL));
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!apply_op(line, &a, &b))
			return (error_exit(&a, &b, line));
		free(line);
	}
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}