#include "../minishell.h"

t_command	*create_node(t_command **head, char *line)
{
	t_command	*node;

	node = (t_command *)malloc(sizeof(t_command));
	if (!node)
		return (NULL);
	node->tokens = (t_token *)malloc(sizeof(t_token));
	if (!node->tokens)
	{
		free(node);
		return (NULL);
	}
	node->tokens->line = line;
	node->next = NULL;
	ft_lstadd_back(head, node);
	return (node);
}
