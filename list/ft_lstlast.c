#include "../minishell.h"

t_command	*ft_lstlast(t_command *lst)
{
	t_command	*head;

	head = lst;
	if (!lst)
		return (lst);
	while (head->next)
		head = head->next;
	return (head);
}
