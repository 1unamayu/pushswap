/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_min_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:42:39 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:20:12 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Find the minimum value in a stack.
 *
 * This function finds the minimum value in a stack.
 *
 * @param stack A pointer to the head of the stack.
 * @return Returns the minimum value in the stack.
 */
int	ft_stack_min(t_stack *stack)
{
	int		min;
	int		i;

	if (!stack)
		return (0);
	min = INT_MAX;
	i = -1;
	while (i++ < ft_stack_len(stack))
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief Find the maximum value in a stack.
 *
 * This function finds the maximum value in a stack.
 *
 * @param stack A pointer to the head of the stack.
 * @return Returns the maximum value in the stack.
 */
int	ft_stack_max(t_stack *stack)
{
	int	i;
	int	max;

	if (!stack)
		return (0);
	max = INT_MIN;
	i = -1;
	while (i++ < ft_stack_len(stack))
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}
