/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:17:41 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:36:50 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check for duplicate elements in the data.
 *
 * This function checks for duplicate elements in the array of integers.
 *
 * @param data The structure containing the loaded data.
 * @return Returns 1 if duplicates are found, otherwise returns 0.
 */
int	ft_check_dupl(t_dtint data)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < data.len)
	{
		while (++k < data.len)
		{
			if ((data.nb[i] == data.nb[k]) && (i != k))
				return (1);
		}
		k = 0;
		i++;
	}
	return (0);
}
