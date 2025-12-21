/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:07:56 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/20 22:08:23 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_integer(char *str)
{
	size_t	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str, int *error)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	*error = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		if (r * s < INT_MIN || r * s > INT_MAX)
			return (*error = 1, 0);
		i++;
	}
	return (r * s);
}

int	has_duplicate(t_stack *a, int nbr)
{
	t_stack	*hlp;

	hlp = a;
	while (hlp)
	{
		if (hlp->nbr == nbr)
			return (1);
		hlp = hlp->next;
	}
	return (0);
}

static int	parse_words(char **words, t_stack **a)
{
	int		error;
	long	hlp;
	int		nbr;
	int		j;
	t_stack	*node;

	j = 0;
	while (words[j])
	{
		if (!is_valid_integer(words[j]))
			return (0);
		hlp = ft_atol(words[j], &error);
		if (error == 1)
			return (0);
		nbr = (int)hlp;
		if (has_duplicate(*a, nbr))
			return (0);
		node = stack_new(nbr);
		if (!node)
			return (0);
		stack_add_back(a, node);
		j++;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_stack **a)
{
	int		i;
	char	**words;

	i = 1;
	while (i < ac)
	{
		words = ft_split(av[i], ' ');
		if (!words || !words[0])
			return (free_split(words), 0);
		if (!parse_words(words, a))
			return (free_split(words), 0);
		free_split(words);
		i++;
	}
	return (1);
}
