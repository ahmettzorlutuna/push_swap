/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:50:31 by azorlutu          #+#    #+#             */
/*   Updated: 2025/01/12 12:50:32 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest_b, t_stack_node **source_a)
{
	t_stack_node	*node_to_push;

	if (*source_a == NULL)
		return ;
	node_to_push = *source_a;
	*source_a = (*source_a)->next;
	if (*source_a)
		(*source_a)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dest_b == NULL)
	{
		*dest_b = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest_b;
		node_to_push->next->prev = node_to_push;
		*dest_b = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
