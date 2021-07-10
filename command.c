#include "push_swap.h"

void	swap(t_deque *deque, int flag)
{
	t_node *top_node;

	if (deque == NULL)
		return ;
	if (deque->size == 0 || deque->size == 1)
		return ;
	top_node = deque->top;
	if (deque->size == 2)
	{
		remove_front(deque);
		push_back(deque, top_node);
		return ;
	}
	remove_front(deque);
	top_node->next = deque->top->next;
	deque->top->next->prev = top_node;
	deque->top->next = top_node;
	top_node->prev = deque->top;
	if (flag == 'a')
		ft_printf("sa\n");
	else if (flag == 'b')
		ft_printf("sb\n");
}

void	push(t_deque *src, t_deque *dest, int flag)
{
	if (src == NULL || dest == NULL)
		return ;
	if (src->size == 0)
		return ;
	push_front(dest, node_new(src->top->data));
	remove_front(src);
	if (flag == 'a')
		ft_printf("pa\n");
	else if (flag == 'b')
		ft_printf("pb\n");
}

// void	rotate(t_node **li, int flag)
// {
// 	if (*li == NULL | (*li)->next == NULL)
// 		return ;
// 	*li = (*li)->next;
// 	(*li)->prev->prev = list_last(*li);
// 	list_last(*li)->next = (*li)->prev;
// 	(*li)->prev->next = NULL;
// 	(*li)->prev = NULL;
// 	if (flag == 'a')
// 		ft_printf("ra\n");
// 	else if (flag == 'b')
// 		ft_printf("rb\n");
// }

// void	reverse(t_node **li, int flag)
// {
// 	if (*li == NULL | (*li)->next == NULL)
// 		return ;
// 	(*li)->prev = list_last(*li);
// 	(*li)->prev->next = (*li);
// 	(*li)->prev->prev->next = NULL;
// 	(*li) = (*li)->prev;
// 	(*li)->prev = NULL;
// 	if (flag == 'a')
// 		ft_printf("rra\n");
// 	else if (flag == 'b')
// 		ft_printf("rrb\n");
// }

// void	command(t_info *io, char *str)
// {
// 	if (!ft_strcmp(str, "sa"))
// 		swap(&(io->a), 'a');
// 	else if (!ft_strcmp(str, "sb"))
// 		swap(&(io->b), 'b');
// 	else if (!ft_strcmp(str, "ss"))
// 		swap_both(&(io->a), &(io->b));
// 	else if (!ft_strcmp(str, "pa"))
// 		push(&(io->b), &(io->a), 'a');
// 	else if (!ft_strcmp(str, "pb"))
// 		push(&(io->a), &(io->b), 'b');
// 	else if (!ft_strcmp(str, "rra"))
// 		reverse(&(io->a), 'a');
// 	else if (!ft_strcmp(str, "rrb"))
// 		reverse(&(io->b), 'b');
// 	else if (!ft_strcmp(str, "rrr"))
// 		reverse_both(&(io->a), &(io->b));
// 	else if (!ft_strcmp(str, "ra"))
// 		rotate(&(io->a), 'a');
// 	else if (!ft_strcmp(str, "rb"))
// 		rotate(&(io->b), 'b');
// 	else if (!ft_strcmp(str, "rr"))
// 		rotate_both(&(io->a), &(io->b));
// 	else
// 		print_error("command");

// }
