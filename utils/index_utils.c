/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 06:22:47 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/11 07:19:23 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	fill_array_from_stack(t_stack *a, int *arr, int size)
{
	t_stack	*hlp;
	int		i;

	i = 0;
	hlp = a;
	while (hlp && i < size)
	{
		arr[i] = hlp->nbr;
		i++;
		hlp = hlp->next;
	}
}

static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	hlp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				hlp = arr[i];
				arr[i] = arr[j];
				arr[j] = hlp;
			}
			j++;
		}
		i++;
	}
}

static void	give_indices(t_stack *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == a->nbr)
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	indexing(t_stack *a)
{
	int	size;
	int	*arr;

	size = ft_lstsize(a);
	if (size == 0)
		return ;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	fill_array_from_stack(a, arr, size);
	sort_int_array(arr, size);
	give_indices(a, arr, size);
	free(arr);
}
