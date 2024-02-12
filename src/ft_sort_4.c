/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:47:19 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:28:49 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a stack with 4 elements.
 *
 * This function sorts a stack with 4 elements.
 * It pushes the minimum value to a separate stack,
 * sorts the remaining elements recursively,
 * and merges the two stacks.
 *
 * @param stack A pointer to the head of the stack to be sorted.
 */
void	ft_sort_4(t_stack *stack)
{
	int		min;
	t_stack	*stack_b;

	stack_b = NULL;
	min = ft_stack_min(stack);
	while (stack->data != min)
		ft_first2last(&stack, 6);
	ft_push2other(&stack, &stack_b, 5);
	ft_sort_3(&stack);
	ft_push2other(&stack_b, &stack, 4);
	ft_stack_free(&stack_b);
}
