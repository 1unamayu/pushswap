/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_keying.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:37:05 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:21:24 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Assigns key values to each node  based on their data values.
 *
 * This function assigns key values to each node based on their data values.
 * The key value of a node is incremented for each node in the stack 
 * with a greater data value.
 *
 * @param stack A pointer to a pointer to the head of the stack.
 */
void	ft_stack_keying(t_stack **stack)
{
	t_stack	*stack_ti;
	t_stack	*stack_tj;
	int		i;
	int		j;

	stack_ti = *stack;
	stack_tj = *stack;
	i = 0;
	while (i++ < ft_stack_len(stack_ti))
	{
		j = 0;
		while (j++ < ft_stack_len(stack_tj))
		{
			if (stack_ti->data > stack_tj->data)
				stack_ti->key++;
			stack_tj = stack_tj->next;
		}
		stack_ti = stack_ti->next;
	}
}
