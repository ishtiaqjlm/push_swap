/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <ishtiahm@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 23:03:16 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/10/07 23:03:16 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	stack_add_back(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (!stack->top)
	{
		stack->top = new_node;
		stack->size++;
		return ;
	}
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = new_node;
	stack->size++;
}

int	build_stack(t_stack *stack, int argc, char **argv, int start)
{
	int		i;
	int		number;
	t_node	*node;

	init_stack(stack);
	i = start;
	while (i < argc)
	{
		if (parse_number(argv[i], &number))
			return (1);
		node = create_node(number);
		if (!node)
			return (1);
		stack_add_back(stack, node);
		i++;
	}
	return (0);
}
