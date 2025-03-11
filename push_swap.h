/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:44:40 by azorlutu          #+#    #+#             */
/*   Updated: 2025/01/08 22:44:40 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

t_stack_node	*find_highest_node(t_stack_node *stack);
t_stack_node	*find_smallest_node(t_stack_node *stack);
t_stack_node	*find_cheapest_node(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *head);

char			**ft_split(char *str, char seperator);

long			ft_atol(const char *str);

int				get_stack_len(t_stack_node *stack);
int				error_repetition(t_stack_node *a, int number);
int				error_syntax(char *str_n);
int				ft_strcmp(char *str_1, char *str_2);

void			tiny_sort(t_stack_node **stack_a);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			init_stack(t_stack_node **a, char **argv, bool argc_count_2);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **a, char **argv, bool argc_count_2);
void			free_matrix(char **argv);
void			finish_rotation(t_stack_node **stack,
					t_stack_node *cheapest_top_node,
					char stack_name);
void			free_stack_both(t_stack_node **stack_a, t_stack_node **stack_b);

void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
#endif
