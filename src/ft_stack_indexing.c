/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_indexing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:42:28 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:21:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_indexing(t_stack **stack)
{
	int		ord;
	t_stack	*stack_i;

	if (!stack)
		return ;
	ord = 1;
	stack_i = *stack;
	while (ord <= ft_stack_len(stack_i))
	{
		stack_i->index = ord++;
		stack_i = stack_i->next;
	}
}
