/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_med.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:49:11 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:24:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_new_a(t_stack **stack_a, t_stack **stack_b, size_t chunks);

/**
 * @brief Finds the maximum key value in the stack.
 *
 * This function finds the maximum key value in the stack and returns it.
 *
 * @param stack A pointer to the head of the stack.
 * @return Returns the maximum key value in the stack.
 */
int	ft_stack_max_k(t_stack *stack)
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
		if (stack->data >= max)
		{
			max = stack->data;
			maxk = stack->key;
		}
		stack = stack->next;
	}
	return (maxk);
}

/**
 * @brief Performs the best operation for stack A based on the minimum index.
 *
 * This function performs the best operation for stack A 
 * based on the minimum index value.
 * It adjusts the stack by rotating it to position the element 
 * with the minimum index at the top.
 *
 * @param stack A pointer to a pointer to the head of stack A.
 * @param min The minimum index value.
 */
void	ft_best_op_a(t_stack **stack, int min)
{
	int	len;

	len = ft_stack_len(*stack);
	if (len == 1)
		return ;
	if (min <= (len / 2))
	{
		while (min-- > 1)
		{
			*stack = (*stack)->prev;
			ft_first2last(stack, 6);
		}
	}
	else
	{
		min = len + 1 - min;
		while (min-- > 0)
		{
			*stack = (*stack)->next;
			ft_last2first(stack, 9);
		}
	}
}

/**
 * @brief Performs the best operation for stack B based on the maximum index.
 *
 * This function performs the best operation for stack B 
 * based on the maximum index value.
 * It adjusts the stack by rotating it to position the element 
 * with the maximum index at the top.
 *
 * @param stack A pointer to a pointer to the head of stack B.
 * @param max The maximum index value.
 */
void	ft_best_op_b(t_stack **stack, int max)
{
	int	len;

	len = ft_stack_len(*stack);
	if (len == 1)
		return ;
	if (max <= (len / 2))
	{
		while (max-- > 1)
		{
			*stack = (*stack)->prev;
			ft_first2last(stack, 7);
		}
	}
	else
	{
		max = len + 1 - max;
		while (max-- > 0)
		{
			*stack = (*stack)->next;
			ft_last2first(stack, 10);
		}
	}
}

/**
 * @brief Sorts the stack using a new sorting algorithm.
 *
 * This function sorts the stack using a new sorting algorithm.
 * It divides the stack into chunks and performs sorting operations.
 *
 * @param stack A pointer to the head of the stack to be sorted.
 * @param chunks The number of chunks to divide the stack into.
 */
void	ft_sort_new(t_stack *stack, size_t chunks)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (!stack)
		return ;
	ft_sort_new_a(&stack, &stack_b, chunks);
	ft_stack_indexing(&stack_b);
	while (stack_b != NULL)
	{
		if (stack_b->key == ft_stack_max_k(stack_b))
		{
			ft_best_op_b(&stack_b, stack_b->index);
			ft_push2other(&stack_b, &stack, 4);
			ft_stack_indexing(&stack_b);
		}
		else
			stack_b = stack_b->next;
	}
	ft_stack_free(&stack_b);
}

/**
 * @brief Sorts stack A and moves elements to stack B based on chunks.
 *
 * This function sorts stack A and moves elements to stack B based on chunks.
 *
 * @param stack_a A pointer to a pointer to the head of stack A.
 * @param stack_b A pointer to a pointer to the head of stack B.
 * @param chunks The number of chunks to divide stack A into.
 */
static void	ft_sort_new_a(t_stack **stack_a, t_stack **stack_b, size_t chunks)
{
	int		elem;
	int		chunk;
	int		tlen;

	tlen = ft_stack_len(*stack_a);
	chunk = tlen / chunks;
	elem = 0;
	while (*stack_a)
	{
		while (elem <= chunk && *stack_a)
		{
			if ((*stack_a)->key <= chunk)
			{
				ft_best_op_a(stack_a, (*stack_a)->index);
				ft_push2other(stack_a, stack_b, 5);
				ft_stack_indexing(stack_a);
				elem++;
			}
			else
				*stack_a = (*stack_a)->next;
		}
		chunk += tlen / chunks;
	}
}
