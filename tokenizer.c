/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:36:19 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/28 18:49:39 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*tokenizer(char *str)
{
	int			i;
	t_command	*commands;
	t_command	*node;
	char		**lines;

	i = -1;
	commands = NULL;
	split(&lines, str, '|');
	if (!lines)
		return (NULL);
	while (lines[++i])
	{
		node = create_node(&commands, lines[i]);
		if (!node)
		{
			ft_lstclear(&commands);
			return (NULL);
		}
		node->tokens->line = wrap_redirection_by_space(node->tokens->line);
		split(&node->tokens->tokens, node->tokens->line, ' ');
	}
	return (commands);
}
