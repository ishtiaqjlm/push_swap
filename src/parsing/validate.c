/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <ishtiahm@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:47:58 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/10/07 22:47:58 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
    t_node	*current;

    if (!stack || stack->size <= 1)
        return (1);
    current = stack->top;
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int	is_valid(t_stack *stack_a, t_stack *stack_b)
{
    return (is_sorted(stack_a) && is_sorted(stack_b));
}

int duplicate_check(t_stack *stack)
{
    t_node *current;
    t_node *runner;

    if (!stack || stack->size <= 1)
        return (0);
    current = stack->top;
    while (current)
    {
        runner = current->next;
        while (runner)
        {
            if (current->value == runner->value)
                return (1);
            runner = runner->next;
        }
        current = current->next;
    }
    return (0);
}
