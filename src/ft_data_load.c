/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:11:24 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:33:28 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_num_elem(char **data, int argc);

/**
 * @brief Load data from command-line arguments.
 *
 * This function loads data from the command-line arguments into an array.
 *
 * @param data An array of strings representing the command-line arguments.
 * @param argc The number of command-line arguments.
 * @return Returns a structure containing the loaded data and its length.
 */
t_dtint	ft_data_load(char **data, int argc)
{
	char	**argument;
	char	**temp;
	t_dtint	datareturn;
	int		i;
	int		k;

	i = 1;
	k = 0;
	datareturn.nb = (int *) malloc(sizeof (int *) * (ft_num_elem(data, argc)));
	while (i < argc)
	{
		argument = ft_split(data[i++], ' ');
		temp = argument;
		while (*argument)
		{
			datareturn.nb[k] = ft_myatoi(*argument);
			free(*argument);
			argument++;
			k++;
		}
		free(temp);
	}
	datareturn.len = k;
	return (datareturn);
}

static int	ft_num_elem(char **data, int argc)
{
	char	**argument;
	char	**temp;
	int		i;
	int		elements;

	i = 1;
	elements = 0;
	while (i < argc)
	{
		argument = ft_split(data[i], ' ');
		temp = argument;
		while (*argument)
		{
			elements++;
			free(*argument);
			argument++;
		}
		free(temp);
		i++;
	}
	return (elements);
}
