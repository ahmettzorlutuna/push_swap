/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:28:27 by azorlutu          #+#    #+#             */
/*   Updated: 2025/01/13 20:28:27 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_stack_node	*find_smallest_node(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	smallest = LONG_MAX;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*find_highest_node(t_stack_node *stack)
{
	int				highest_int;
	t_stack_node	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest_int = INT_MIN;
	while (stack)
	{
		if (stack->value > highest_int)
		{
			highest_int = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack_node	*find_cheapest_node(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	get_stack_len(t_stack_node *stack)
{
	int	sum;

	sum = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		++sum;
		stack = stack->next;
	}
	return (sum);
}
