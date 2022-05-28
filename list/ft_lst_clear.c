#include "../minishell.h"

void	ft_lstclear(t_command **head)
{
	t_command	*current;

	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current->tokens->line);
		free(current->tokens);
		free(current);
	}
}