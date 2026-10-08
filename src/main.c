/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <ishtiahm@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:47:45 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/10/07 21:47:45 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	//test code for parsing arguments and numbers
    /*
    t_config	config;
	int			start;
	int			number;
	int			i;

	if (argc == 1)
		return (0);
	start = parse_args(argc, argv, &config);
	i = start;
	while (i < argc)
	{
		if (parse_number(argv[i], &number) == 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		write(1, "valid\n", 6);
		i++;
	}*/
    //(void)argc;
    //(void)argv;
    //test code for create_node and init_stack
    /*
    t_node	*node;

	node = create_node(42);
	if (!node)
		return (1);
	if (node->value == 42 && node->index == -1 && node->next == NULL)
		write(1, "create_node OK\n", 15);
	else
		write(1, "create_node ERROR\n", 18);
	free(node);*/
    //test code for init_stack
    /*t_stack	stack;

	init_stack(&stack);
	if (stack.top == NULL && stack.size == 0)
		write(1, "init_stack OK\n", 14);
	else
		write(1, "init_stack ERROR\n", 17);
    */
   //test code for stack_add_back
   /* t_stack	stack;
	t_node	*node;

	init_stack(&stack);

	node = create_node(10);
	stack_add_back(&stack, node);

	node = create_node(20);
	stack_add_back(&stack, node);

	node = create_node(30);
	stack_add_back(&stack, node);

	if (stack.size == 3
		&& stack.top->value == 10
		&& stack.top->next->value == 20
		&& stack.top->next->next->value == 30)
		write(1, "stack_add_back OK\n", 18);
	else
		write(1, "stack_add_back ERROR\n", 21);

	while (stack.top)
	{
		node = stack.top;
		stack.top = stack.top->next;
		free(node);
	}*/
    // test code for build_stack
    /*
    t_config	config;
	t_stack	stack;
	int			start;

	if (argc == 1)
		return (0);
	start = parse_args(argc, argv, &config);
	if (build_stack(&stack, argc, argv, start))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (stack.size == argc - start)
		write(1, "build_stack OK\n", 15);
	else
		write(1, "build_stack ERROR\n", 18);
	while (stack.top)
	{
		t_node	*node;

		node = stack.top;
		stack.top = stack.top->next;
		free(node);
	}
    */
   // test code for duplicate_check
    /*
    t_config	config;
	t_stack	stack;
	int			start;

	if (argc == 1)
		return (0);
	start = parse_args(argc, argv, &config);
	if (build_stack(&stack, argc, argv, start))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (duplicate_check(&stack))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	write(1, "Validation OK\n", 15);
    */
   // test code for free_stack
   /* t_stack	stack;
	t_node	*node;

	init_stack(&stack);
	node = create_node(10);
	stack_add_back(&stack, node);
	node = create_node(20);
	stack_add_back(&stack, node);
	node = create_node(30);
	stack_add_back(&stack, node);

	free_stack(&stack);
	if (stack.top == NULL && stack.size == 0)
		write(1, "free_stack OK\n", 14);
	else
		write(1, "free_stack ERROR\n", 17);*/
    // test code for is_sorted
	t_config	config;
	t_stack	stack;
	int			start;

	if (argc == 1)
		return (0);
	start = parse_args(argc, argv, &config);
	if (build_stack(&stack, argc, argv, start))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (duplicate_check(&stack))
	{
		free_stack(&stack);
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(&stack))
		write(1, "Already sorted\n", 15);
	else
		write(1, "Not sorted\n", 11);
	free_stack(&stack);

	return (0);
}
