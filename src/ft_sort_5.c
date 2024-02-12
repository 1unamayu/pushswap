/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:50:20 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:27:47 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a stack with 5 or more elements.
 *
 * This function sorts a stack with 5 or more elements 
 * using a specific sorting algorithm.
 * It divides the stack into two parts, pushes the minimum and maximum values
 * to a separate stack, sorts the remaining elements recursively,
 * and merges the two stacks.
 *
 * @param stack A pointer to the head of the stack to be sorted.
 */
void	ft_sort_5(t_stack *stack)
{
	int		min;
	int		max;
	t_stack	*stack_b;

	stack_b = NULL;
	min = ft_stack_min(stack);
	max = ft_stack_max(stack);
	while (ft_stack_len(stack) > 3)
	{
		if ((stack->data == min) || (stack->data == max))
			ft_push2other(&stack, &stack_b, 5);
		else
			ft_first2last(&stack, 6);
	}
	ft_sort_3(&stack);
	if ((stack_b->data < stack_b->next->data))
		ft_swap_2(&stack_b, 2);
	ft_push2other(&stack_b, &stack, 4);
	ft_first2last(&stack, 6);
	ft_push2other(&stack_b, &stack, 4);
	ft_stack_free(&stack_b);
}
