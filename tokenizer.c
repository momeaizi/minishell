#include "minishell.h"

t_command	*tokenizer(char *str)
{
	int			i;
	char		**lines;
	char		**tokens;
	t_command	commands;
	t_command	*temp;

	i = -1;
	split(lines, str, '|');
	if (!lines)
		return (NULL);
	while (lines[++i])
	{
		if (!create_node(&commands, lines[i]))
		{
			ft_lstclear(&head);
			return (NULL);
		}
		commands->tokens->line = add_space_around_redirection(commands->tokens->line);
	}
}