/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:36:16 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/28 18:52:05 by momeaizi         ###   ########.fr       */
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
	i = -1;
	char	str[] = "<main.c cat <<ss<infile | wc -l>outfile";
	tokenizer(str);
	return (0);
}
