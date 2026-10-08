/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <ishtiahm@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:46:59 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/10/07 21:46:59 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

int	ft_strcmp(const char *s1, const char *s2);
int	parse_args(int argc, char **argv, t_config *config);
int	parse_number(const char *str, int *number);
t_node	*create_node(int value);
void	init_stack(t_stack *stack);
void	stack_add_back(t_stack *stack, t_node *new_node);
int	build_stack(t_stack *stack, int argc, char **argv, int start);
int	duplicate_check(t_stack *stack);
void	free_stack(t_stack *stack);
int	is_sorted(t_stack *stack);
#endif
