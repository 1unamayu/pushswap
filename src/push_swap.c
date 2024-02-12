/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:42:08 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 00:29:54 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Main function of the program.
 *
 * This function serves as the entry point to the program. 
 * Validates input data, loads data, checks for duplicates, builds the stack,
 * and sorts the stack if necessary. 
 * Finally, it frees allocated memory and exits with a success status.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the command-line arguments.
 * @return Returns 0 upon successful execution.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_dtint	data;

	ft_data_validation(argv, argc);
	data = ft_data_load(argv, argc);
	if (ft_check_dupl(data))
	{
		free(data.nb);
		ft_exit_error();
	}
	stack_a = ft_build_stack(data);
	if (!ft_issorted(stack_a))
	{
		ft_stack_keying(&stack_a);
		ft_stack_indexing(&stack_a);
		ft_sort_select(stack_a);
	}
	free(data.nb);
	ft_stack_free(&stack_a);
	return (0);
}
