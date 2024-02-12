/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:45:59 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:26:40 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_bit(t_stack *stack);
static int	ft_max_k(t_stack *stack);
static void	ft_sort_pos(t_stack **stack_a, t_stack **stack_b, int bit);

/**
 * @brief Sorts a large stack using a specific sorting algorithm.
 *
 * This function sorts a large stack using a specific sorting algorithm.
 * It divides the sorting process into iterations 
 * based on the maximum bit of the stack elements.
 *
 * @param stack A pointer to the head of the stack to be sorted.
 */
void	ft_sort_big(t_stack *stack)
{
	t_stack	*stack_b;
	int		bit;
	int		maxbit;

	maxbit = ft_find_bit(stack);
	stack_b = NULL;
	bit = 0;
	while (bit < maxbit)
	{
		ft_sort_pos(&stack, &stack_b, bit);
		bit++;
	}
	ft_stack_free(&stack_b);
}

/**
 * @brief Finds the maximum bit among the key values of the stack elements.
 *
 * This function finds the maximum bit among the key values
 * of the stack elements.
 *
 * @param stack A pointer to the head of the stack.
 * @return Returns the maximum bit among the key values of the stack elements.
 */
static int	ft_find_bit(t_stack *stack)
{
	int	num;
	int	bit;

	bit = 0;
	num = ft_max_k(stack);
	while ((num >> bit) != 0)
		bit++;
	return (bit);
}

/**
 * @brief Finds the maximum key value in the stack.
 *
 * This function finds the maximum key value in the stack and returns it.
 *
 * @param stack A pointer to the head of the stack.
 * @return Returns the maximum key value in the stack.
 */
static int	ft_max_k(t_stack *stack)
{
	int	i;
	int	max;
	int	maxk;

	if (!stack)
		return (0);
	max = INT_MIN;
	i = -1;
	while (i++ < ft_stack_len(stack))
	{
		if (stack->data > max)
		{
			max = stack->data;
			maxk = stack->key;
		}
		stack = stack->next;
	}
	return (maxk);
}

/**
 * @brief Sorts the stack based on a specific bit position.
 *
 * This function sorts the stack based on a specific bit position 
 * of the key values of the stack elements.
 *
 * @param stack_a A pointer to a pointer to the head of stack A.
 * @param stack_b A pointer to a pointer to the head of stack B.
 * @param bit The bit position used for sorting.
 */
static void	ft_sort_pos(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	slen;

	slen = ft_stack_len(*stack_a);
	while (slen)
	{
		if ((((*stack_a)->key >> bit) & 1) == 1)
			ft_first2last(stack_a, 6);
		else
			ft_push2other(stack_a, stack_b, 5);
		slen--;
	}
	while (*stack_b)
		ft_push2other(stack_b, stack_a, 4);
}
