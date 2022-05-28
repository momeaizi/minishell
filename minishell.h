/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:52:11 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/28 18:56:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_token
{
	char	*line;
	char	**tokens;
}	t_token;

typedef struct s_command
{
	char				*command;
	char				*command_path;
	char				**command_args;
	int					input;
	int					output;
	t_token				*tokens;
	struct s_command	*next;
}	t_command;

//					string
int			ft_strlen(char *str);
void		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strcmp(const char *s1, const char *s2);
char		*wrap_redirection_by_space(char *str);
//					split
void		split(char ***tokens, char *s, char c);
int			count_tokens(char *str, char c);
int			*tokens_length(char *str, char c);
void		replace_inside_quotes(char *str, char new, char old);
void		replace_all_strings(char **strs, char new, char old);
void		clear(char **paths, int *size, int j);
//					list
t_command	*ft_lstlast(t_command *lst);
void		ft_lstadd_back(t_command **lst, t_command *new);
void		ft_lstclear(t_command **head);
t_command	*create_node(t_command **head, char *line);
//					tokenizer
t_command	*tokenizer(char *str);

#endif