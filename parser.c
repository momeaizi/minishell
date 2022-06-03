/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:39:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/02 20:55:12 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_command *commands, char **env)
{
	int	i;
	t_command	*tmp;

	heredoc(commands, env);
	get_command(commands, env);
	// tmp = commands;
	// while (tmp)
	// {
	// 	i = -1;
	// 	while (tmp->tokens->tokens[++i])
	// 		printf(" %s\n", tmp->tokens->tokens[i]);
	// 	tmp = tmp->next;
	// }
}