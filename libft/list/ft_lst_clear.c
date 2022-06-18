/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:46:32 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/18 18:46:38 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	p_ft_lstclear(t_command **head)
{
	int			i;
	t_command	*current;

	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current->tokens->line);
		i = -1;
		while (current->tokens->tokens[++i])
			free(current->tokens->tokens[i]);
		free(current->tokens->tokens);
		i = -1;
		while ((current)->tokens->limiters[++i])
			free((current)->tokens->limiters[i]);
		free(current->tokens->limiters);
		free(current->tokens);
		free(current);
	}
}

void	clear_tokens(t_command **head)
{
	int			i;
	t_command	*current;

	while (*head)
	{
		i = -1;
		current = *head;
		*head = (*head)->next;
		while (current->command_args[++i])
			free(current->command_args[i]);
		free(current->command_args);
		if (current->command_name)
			free(current->command_name);
		if (current->command_path)
			free(current->command_path);
	}
}
