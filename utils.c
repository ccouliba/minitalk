#include "minitalk.h"

t_lst	*new_elem(char c)
{
	t_lst *new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	else
	{
		new->content = c;
		new->next = NULL;
		new->last = new;
	}
	return (new);
}

t_lst	*add_elem(t_lst *lst, char c)
{
	t_lst *tmp;
	t_lst *tmp2;
	t_lst *new;

	tmp = lst;
	tmp2 = lst;
	if (!(new = new_elem(c)))
		return (NULL);
//	if (!tmp)
//		return (new);
	tmp = tmp->last;
	tmp2->last = new;
	tmp->next = new;
	return (lst);
}

void	print_lst(t_lst *lst)
{
	while (lst)
	{
		ft_putchar_fd(lst->content, 1);
		lst = lst->next;
	}
	write(1, "\n", 2);
}
