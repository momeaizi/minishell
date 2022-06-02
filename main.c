/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:36:16 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/02 16:36:34 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int ac, char **av, char **env)
{
	int 		i;
	t_command	*head;
	t_command	*tmp;
	char		**tokens;

	head = NULL;
	tokens = NULL;
	// char *str = readline("bash$ ");
	char	str[] = "echo \"taha \'\" < >> ss";
	if (check_quotes(str))
	{
		head = tokenizer(str);
		parser(head, env);
	}
	// system("leaks minishell");
	return (0);
}
