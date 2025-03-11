/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:52:22 by azorlutu          #+#    #+#             */
/*   Updated: 2025/01/11 19:52:23 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	append_node(t_stack_node **stack, int number)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = number;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack(t_stack_node **a, char **argv, bool argc_count_2)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, argc_count_2);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			error_free(a, argv, argc_count_2);
		if (error_repetition(*a, (int)number))
			error_free(a, argv, argc_count_2);
		append_node(a, (int)number);
		++i;
	}
	if (argc_count_2)
		free_matrix(argv);
}
