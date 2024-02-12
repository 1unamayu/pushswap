/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:32:52 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:20:28 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculate the length of a stack.
 *
 * This function calculates the length of a stack.
 *
 * @param stack A pointer to the head of the stack.
 * @return Returns the length of the stack.
 */
int	ft_stack_len(t_stack *stack)
{
	t_stack	*head;
	int		len;

	if (!stack)
		return (0);
	head = stack;
	stack = stack->next;
	len = 1;
	while (stack != head)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
