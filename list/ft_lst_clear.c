/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:35:42 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/28 18:39:49 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstclear(t_command **head)
{
	t_command	*current;

	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current->tokens->line);
		free(current->tokens);
		free(current);
	}
}
