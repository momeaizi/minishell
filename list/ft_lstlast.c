/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:35:47 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/28 18:35:48 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*ft_lstlast(t_command *lst)
{
	t_command	*head;

	head = lst;
	if (!lst)
		return (lst);
	while (head->next)
		head = head->next;
	return (head);
}
