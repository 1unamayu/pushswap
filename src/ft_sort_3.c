/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:35:01 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:29:43 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a stack with 3 elements.
 *
 * This function sorts a stack with 3 elements.
 * It pushes the minimum value to a separate stack,
 * sorts the remaining elements recursively,
 * and merges the two stacks.
 *
 * @param stack A pointer to the head of the stack to be sorted.
 */
void	ft_sort_3(t_stack **stack)
{
	if (ft_issorted(*stack))
		return ;
	if ((*stack)->data < (*stack)->next->data)
	{
		ft_last2first(stack, 9);
		if (!(ft_issorted(*stack)))
			ft_swap_2(stack, 1);
	}
	else
	{
		if ((*stack)->next->data > (*stack)->next->next->data)
		{
			ft_first2last(stack, 6);
			ft_swap_2(stack, 1);
		}
		else
			if ((*stack)->next->next->data > (*stack)->data)
				ft_swap_2(stack, 1);
		else
			ft_first2last(stack, 6);
	}
}
