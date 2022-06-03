/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:35:38 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/02 20:50:55 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_command	*create_node(t_command **head, char *line)
{
	t_command	*node;

	node = (t_command *)malloc(sizeof(t_command));
	if (!node)
		return (NULL);
	node->tokens = (t_token *)malloc(sizeof(t_token));
	if (!node->tokens)
	{
		free(node);
		return (NULL);
	}
	node->tokens->line = line;
	node->command_name = NULL;
	node->tokens->limiters = (char **)ft_calloc(1, sizeof(char *));
	node->command_args = (char **)ft_calloc(1, sizeof(char *));
	node->next = NULL;
	ft_lstadd_back(head, node);
	return (node);
}
