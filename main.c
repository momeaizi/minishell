/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:36:16 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/30 15:22:55 by momeaizi         ###   ########.fr       */
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
	char	str[] = "<main.c cat <<ss<\"te\"st<test2<test2>outfile1 taha | wc -l>outfile1337";
	head = tokenizer(str);
	parser(head);
	// system("leaks a.out");
	return (0);
}
