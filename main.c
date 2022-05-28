#include "minishell.h"





int main(int ac, char **av, char **env)
{
	t_command	*head = NULL;
	t_command	*tmp;
	char **tokens = NULL;
	int i = -1;
	char	str[] = "<main.c cat>>ss '|' wc -l | echo \"$USER\">outfile";

	//		split by pipe
	split(tokens, str, '|');
	
	//

	while (tokens[++i])
	    create_node(&head, tokens[i]);
	tmp = head;
	while (tmp)
	{
		tmp->line = add_space(tmp->line);
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
	system("leaks a.out");
	return (0);
}