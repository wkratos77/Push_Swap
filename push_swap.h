/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:03:46 by wkrati            #+#    #+#             */
/*   Updated: 2025/12/20 19:03:13 by wkrati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_chunk
{
	int				low;
	int				high;
	int				n;
}					t_chunk;

t_stack				*stack_new(int nbr);
void				stack_add_back(t_stack **stack, t_stack *new);
int					ft_lstsize(t_stack *stack);
t_stack				*stack_last(t_stack *stack);
void				free_stack(t_stack **s);

void				indexing(t_stack *a);

long				ft_atol(const char *str, int *error);
int					is_valid_integer(char *str);
int					has_duplicate(t_stack *a, int nbr);
int					parse_args(int ac, char **av, t_stack **a);

int					find_min_pos(t_stack *a);
int					find_max_pos(t_stack *a);
void				rotate_a_to_top(t_stack **a, int pos);
void				rotate_b_to_top(t_stack **b, int pos);
int					is_sorted(t_stack *a);

char				**ft_split(const char *s, char c);
void				free_split(char **arr);

void				small_sort(t_stack **a, t_stack **b);
void				chunk_sort(t_stack **a, t_stack **b);
void				push_swap(t_stack **a, t_stack **b);

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

#endif