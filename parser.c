/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:39:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/02 15:23:56 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_command *commands, char **env)
{
	int	i;
	t_command	*tmp;

	heredoc(commands, env);
	get_command(commands, env);
	tmp = commands;
	// while (tmp)
	// {
	// 	printf("command : %s\n", tmp->command_name);
	// 	i = -1;
	// 	printf("arguments\n");
	// 	while (tmp->command_args[++i])
	// 		printf("	%s\n", tmp->command_args[i]);
	// 	printf("//////\n");
	// 	tmp = tmp->next;
	// }
}