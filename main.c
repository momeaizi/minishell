/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:36:16 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/02 21:01:20 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int ac, char **av, char **env)
{
	int 		i;
	t_command	*head;
	t_command	*tmp;
	char		**tokens;
	char	*new;

	head = NULL;
	tokens = NULL;
	// char *str = readline("bash$ ");
	char	*str = malloc(28);
	ft_strlcpy(str, "cat << ss<<tt|wc -l << taha", 28);
	if (check_quotes(str))
	{
		head = tokenizer(str);
		parser(head, env);
	}
	return (0);
}
