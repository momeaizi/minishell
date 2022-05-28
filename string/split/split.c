/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:36:01 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/28 18:36:02 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	split(char ***tokens, char *s, char c)
{
	int		*size;
	int		j;
	int		i;

	j = 0;
	i = -1;
	size = tokens_length(s, c);
	*tokens = (char **)malloc(count_tokens(s, c) * sizeof(char *));
	if (!*tokens || !s)
		return ;
	while (s[++i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			(*tokens)[j] = (char *)malloc(size[j] * sizeof(char));
			if (!(*tokens)[j])
				break ;
			ft_strlcpy((*tokens)[j], ((char *)s + i), size[j]);
			j++;
		}
	}
	(*tokens)[j++] = NULL;
	if (j != count_tokens(s, c))
		clear(*tokens, size, j);
	replace_all_strings(*tokens, c, -1);
}
