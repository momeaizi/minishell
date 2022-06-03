/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:52:11 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/02 20:31:51 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
#include <errno.h>

typedef struct s_token
{
	char	**tokens;
	char	*line;
	char	**limiters;
	char	should_expand;
}	t_token;

typedef struct s_command
{
	char				*command_name;
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
char		*ft_strdup(char *s1);
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


void	parser(t_command *commands, char **env);

char	**ft_realloc(char **ptr, char *new);
int		ft_isalpha(char c);
int		ft_isnum(char c);
int		ft_isalnum(char c);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_getenv(char *var, char **env);
char	*expand_var(char *str, char **env, char expand_all);
char	*remove_quotes(char *str);



//
void	get_command(t_command *commands, char **env);
void    heredoc(t_command *commands, char **env);
int		redirect(char *token);


int		check_quotes(char *str);
void	check_redirect(t_command *commands);


void	*ft_calloc(size_t count, size_t size);
#endif