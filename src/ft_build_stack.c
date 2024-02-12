/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:23:13 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:36:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_load_nodes(t_dtint dt, t_stack **fnode, t_stack **lnode, \
		t_stack **stack);

/**
 * @brief Builds a stack from the given data.
 *
 * This function constructs a stack from the data provided in the `dt` parameter.
 * It allocates memory for each node in the stack, initializes the data,
 * index, and key values,
 * and establishes the links between nodes to form a circular doubly linked list.
 *
 * @param dt The data structure containing the elements to populate the stack.
 * @return Returns a pointer to the head of the constructed stack.
 */	
t_stack	*ft_build_stack(t_dtint dt)
{
	t_stack	*stack;
	t_stack	*first_node;
	t_stack	*last_node;

	stack = (t_stack *) malloc(sizeof (t_stack));
	if (!stack)
		ft_exit_error();
	stack->data = dt.nb[0];
	stack->index = 0;
	stack->key = 0;
	stack->next = stack;
	stack->prev = stack;
	first_node = stack;
	ft_load_nodes(dt, &first_node, &last_node, &stack);
	last_node = stack;
	stack = stack->next;
	stack->prev = last_node;
	return (stack);
}

/**
 * @brief Loads additional nodes into the stack.
 *
 * This function is a helper function used internally by `ft_build_stack`
 * to load additional nodes
 * into the stack based on the data provided in the `dt` parameter.
 * It allocates memory for each node,initializes the data, index, 
 * and key values, and establishes the links between nodes to form a circular
 * doubly linked list.
 *
 * @param dt The data structure containing the elements to populate the stack.
 * @param fnode A pointer to a pointer to the first node in the stack.
 * @param lnode A pointer to a pointer to the last node in the stack.
 * @param stack A pointer to a pointer to the current node in the stack.
 */
static void	ft_load_nodes(t_dtint dt, t_stack **fnode, t_stack **lnode, \
		t_stack **stack)
{
	t_stack	*next_node;
	int		i;

	i = 1;
	while (i < dt.len)
	{
		next_node = (t_stack *) malloc(sizeof (t_stack));
		if (!next_node)
			ft_exit_error();
		next_node->data = dt.nb[i];
		next_node->index = 0;
		next_node->key = 0;
		next_node->next = *fnode;
		(*stack)->next = next_node;
		*lnode = *stack;
		*stack = next_node;
		(*stack)->prev = *lnode;
		i++;
	}
}
