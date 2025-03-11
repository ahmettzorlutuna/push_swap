/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:47:52 by azorlutu          #+#    #+#             */
/*   Updated: 2025/01/12 14:47:53 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack_node **stack_a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest_node(*stack_a);
	if (*stack_a == highest_node)
		ra(stack_a, false);
	else if (((*stack_a)-> next) == highest_node)
		rra(stack_a, false);
	if ((*stack_a)-> value > (*stack_a)-> next -> value)
		sa(stack_a, false);
}
