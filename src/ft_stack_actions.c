/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:43:02 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:19:19 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Moves the head of the stack to the next node.
 *
 * @param stack A pointer to a pointer to the head of the stack.
 * @param op An operation indicator.
 */
void	ft_first2last(t_stack **stack, int op)
{
	if (!(*stack))
		return ;
	*stack = (*stack)->next;
	if (op)
		ft_pr_action(op);
}

/**
 * @brief Moves the tail of the stack to the previous node.
 *
 * @param stack A pointer to a pointer to the head of the stack.
 * @param op An operation indicator.
 */
void	ft_last2first(t_stack **stack, int op)
{
	if (!(*stack))
		return ;
	*stack = (*stack)->prev;
	if (op)
		ft_pr_action(op);
}

/**
 * @brief Swaps the data and index values of the head node with the next node.
 *
 * @param stack A pointer to a pointer to the head of the stack.
 * @param op An operation indicator.
 */
void	ft_swap_2(t_stack **stack, int op)
{
	int	temp;

	if (!(*stack))
		return ;
	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = temp;
	if (op)
		ft_pr_action(op);
}

/**
 * @brief Deletes a node from the stack, updating pointers accordingly.
 *
 * @param nodel A pointer to a pointer to the node to be deleted.
 */
void	ft_delete_node(t_stack **nodel)
{
	if (*nodel == (*nodel)->next)
		*nodel = NULL;
	else
	{
		(*nodel)->next->prev = (*nodel)->prev;
		(*nodel)->prev->next = (*nodel)->next;
		*nodel = (*nodel)->next;
	}
}

/**
 * @brief Moves a node from one stack to another, updating pointers accordingly.
 *
 * @param from A pointer to a pointer to the head of the source stack.
 * @param to A pointer to a pointer to the head of the destination stack.
 * @param op An operation indicator.
 */
void	ft_push2other(t_stack **from, t_stack **to, int op)
{
	t_stack	*push;
	t_stack	*oldto;

	if (*from)
	{
		push = *from;
		ft_delete_node(from);
		if (!*to)
		{
			*to = push;
			(*to)->next = *to;
			(*to)->prev = *to;
		}
		else
		{
			oldto = (*to)->prev;
			(*to)->prev = push;
			(*to)->prev->next = *to;
			(*to)->prev->prev = oldto;
			(*to)->prev->prev->next = push;
			*to = (*to)->prev;
		}
		if (op)
			ft_pr_action(op);
	}
}
