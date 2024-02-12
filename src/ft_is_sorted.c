/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:24:44 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:30:40 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the stack is sorted in non-decreasing order.
 *
 * This function checks if the stack is sorted in non-decreasing order.
 * It iterates through the stack and counts the number of times a node's data
 * is less than the data of its previous node. If the count is zero, the stack
 * is considered sorted.
 *
 * @param stack A pointer to the head of the stack.
 * @return Returns 1 if the stack is sorted, otherwise returns 0.
 */
int	ft_issorted(t_stack *stack)
{
	t_stack	*head;
	int		sort;

	head = stack;
	stack = stack->next;
	sort = 0;
	while (stack != head)
	{
		if (stack->data < stack->prev->data)
			sort++;
		stack = stack->next;
	}
	if (!sort)
		return (1);
	return (0);
}
