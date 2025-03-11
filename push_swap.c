/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:49:44 by azorlutu          #+#    #+#             */
/*   Updated: 2025/01/14 23:49:50 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate_both(t_stack_node **a,
							t_stack_node **b,
							t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static	void	reverse_rotate_both(t_stack_node **a,
									t_stack_node **b,
									t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack_node **stack,
								t_stack_node *cheapest_top_node,
								char stack_name)
{
	while (*stack != cheapest_top_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static	void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest_node(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				lenght_a;

	lenght_a = get_stack_len(*a);
	while (lenght_a-- > 3)
		pb(b, a, false);
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest_node(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
