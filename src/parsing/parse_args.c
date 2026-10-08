/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <ishtiahm@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:48:44 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/10/07 21:48:44 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

static void	set_strategy(t_config *config, char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		config->strategy = STRAT_SIMPLE;
	else if (!ft_strcmp(arg, "--medium"))
		config->strategy = STRAT_MEDIUM;
	else if (!ft_strcmp(arg, "--complex"))
		config->strategy = STRAT_COMPLEX;
	else if (!ft_strcmp(arg, "--adaptive"))
		config->strategy = STRAT_ADAPTIVE;
}

int	parse_args(int argc, char **argv, t_config *config)
{
	int	i;

	config->strategy = STRAT_ADAPTIVE;
	config->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--bench"))
			config->bench = 1;
		else if (!ft_strcmp(argv[i], "--simple")
			|| !ft_strcmp(argv[i], "--medium")
			|| !ft_strcmp(argv[i], "--complex")
			|| !ft_strcmp(argv[i], "--adaptive"))
			set_strategy(config, argv[i]);
		else
			break ;
		i++;
	}
	return (i);
}
