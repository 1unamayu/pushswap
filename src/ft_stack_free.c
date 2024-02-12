/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:26:03 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:19:40 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Free memory allocated for a stack.
 *
 * This function frees the memory allocated for a stack.
 *
 * @param list A pointer to a pointer to the head of the stack.
 */
void	ft_stack_free(t_stack **list)
{
	t_stack	*next;
	t_stack	*tmp;

	if (list && *list)
	{
		next = (*list)->next;
		while (next && (next != *list))
		{
			tmp = next;
			next = next->next;
			free(tmp);
		}
		free(*list);
		*list = NULL;
	}
}
