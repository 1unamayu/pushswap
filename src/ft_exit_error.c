/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:42:49 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:32:48 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Exits the program with an error message.
 *
 * This function writes an error message to the standard error output
 * and exits the program with an error status.
 */
void	ft_exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief Checks if the given character is a white-space character.
 *
 * This function checks if the given character is a white-space character.
 *
 * @param c The character to check.
 * @return Returns 1 if the character is a white-space character, otherwise 0.
 */
int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

/**
 * @brief Checks if the given character is a sign character ('+' or '-').
 *
 * This function checks if the given character is a sign character ('+' or '-').
 *
 * @param c The character to check.
 * @return Returns 1 if the character is a sign character, otherwise returns 0.
 */
int	ft_issign(int c)
{
	if ((c == 43) || (c == 45))
		return (1);
	return (0);
}

/**
 * @brief Converts a string to a long integer.
 *
 * This function converts the initial portion of the string pointed to by `str`
 * to a long integer representation.
 *
 * @param str The string to convert.
 * @return Returns the converted long integer value.
 */
long	ft_myatoi(const char *str)
{
	int		i;
	int		sign;
	long	atoi;

	i = 0;
	atoi = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if ((!str[i]) || (str[i] == '\0') || (str[i] < 48) || (str[i] > 57))
		return ((long) INT_MAX + 1);
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
		atoi = atoi * 10 + (str[i++] - 48);
	if (str[i])
		return ((long) INT_MAX + 1);
	return (atoi * sign);
}

/**
 * @brief Prints an action based on the provided operation code.
 *
 * This function prints an action based on the provided operation.
 *
 * @param op The operation code indicating the action to print.
 */
void	ft_pr_action(int op)
{
	if (op == 1)
		write(1, "sa\n", 3);
	if (op == 2)
		write(1, "sb\n", 3);
	if (op == 3)
		write(1, "ss\n", 3);
	if (op == 4)
		write(1, "pa\n", 3);
	if (op == 5)
		write(1, "pb\n", 3);
	if (op == 6)
		write(1, "ra\n", 3);
	if (op == 7)
		write(1, "rb\n", 3);
	if (op == 8)
		write(1, "rr\n", 3);
	if (op == 9)
		write(1, "rra\n", 4);
	if (op == 10)
		write(1, "rrb\n", 4);
	if (op == 11)
		write(1, "rrr\n", 4);
}
