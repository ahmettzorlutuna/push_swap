/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:29:54 by azorlutu          #+#    #+#             */
/*   Updated: 2025/01/13 20:29:55 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i++]);
	}
	free(argv - 1);
}

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

void	error_free(t_stack_node **a, char **argv, bool argc_count_2)
{
	free_stack(a);
	if (argc_count_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_repetition(t_stack_node *a, int number)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == number)
			return (1);
		a = a->next;
	}
	return (0);
}
