/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:29:48 by azorlutu          #+#    #+#             */
/*   Updated: 2025/02/23 12:29:51 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	*get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int		i;
	int		bytes_read;

	line = malloc(1024);
	i = 0;
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		line[i++] = buffer;
		if (buffer == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		bytes_read = read(fd, &buffer, 1);
	}
	if (bytes_read == -1 || (bytes_read == 0 && i == 0))
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

static	void	error(t_stack_node **a, t_stack_node **b, char *line)
{
	free_stack(a);
	free_stack(b);
	if (line)
		free(line);
	write(2, "Error\n", 6);
	exit(1);
}

static	void	parse_command(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, true);
	else
		error(a, b, command);
}

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
	char			*next_line;
	int				stack_len;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	init_stack(&a, argv + 1, argc == 2);
	stack_len = get_stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_command(&a, &b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a) && get_stack_len(a) == stack_len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack_both(&a, &b);
}
