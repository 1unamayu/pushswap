/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:29:10 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:24:49 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_select(t_stack *stack_a)
{
	if (ft_stack_len(stack_a) < 4)
		ft_sort_3(&stack_a);
	if (ft_stack_len(stack_a) == 4)
		ft_sort_4(stack_a);
	if (ft_stack_len(stack_a) == 5)
		ft_sort_5(stack_a);
	if ((ft_stack_len(stack_a) > 5) && (ft_stack_len(stack_a) < 101))
		ft_sort_new(stack_a, 4);
	if (ft_stack_len(stack_a) > 100)
		ft_sort_big(stack_a);
}
