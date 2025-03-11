/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:07:49 by azorlutu          #+#    #+#             */
/*   Updated: 2025/01/08 22:07:51 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	bool	stack_sorted(t_stack_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	init_stack(&a, argv + 1, argc == 2);
	if (!stack_sorted(a))
	{
		if (get_stack_len(a) == 2)
			sa(&a, false);
		else if (get_stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
