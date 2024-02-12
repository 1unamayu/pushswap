/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:42:53 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/12 13:12:10 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_all_space(char *data);

/**
 * @brief Validate the command-line arguments.
 *
 * This function performs data validation passed to the program.
 * It first performs a preliminary validation.
 * If any validation errors are found, it exits with an error message.
 *
 * @param data An array of strings representing the command-line arguments.
 * @param argc The number of command-line arguments.
 */
void	ft_data_validation(char **data, int argc)
{
	char	**argument;
	char	**temp;
	int		i;
	long	chk;
	int		validation;

	i = 0;
	validation = 0;
	while (++i < argc)
	{
		argument = ft_split(data[i], ' ');
		temp = argument;
		while (*argument)
		{
			chk = ft_myatoi(*argument);
			if (!(ft_is_all_num(*argument)) || (ft_is_all_space(*argument)) \
					|| ((chk < INT_MIN) || (chk > INT_MAX)))
				validation++;
			free(*argument);
			argument++;
		}
		free(temp);
	}
	if (validation)
		ft_exit_error();
}

static int	ft_is_all_space(char *data)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = data;
	while (*tmp)
	{
		if ((*tmp > 8 && *tmp < 14) || (*tmp == 32))
			i++;
		tmp++;
	}
	if (i == ft_strlen(data))
		return (1);
	return (0);
}

int	ft_is_all_num(char *data)
{
	if (!data)
		return (0);
	while (*data)
	{
		if (!ft_isdigit(*data))
			if (!ft_isspace(*data) && !ft_issign(*data))
				return (0);
		data++;
	}
	return (1);
}
