/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:41:29 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/11 01:55:17 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"
# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int				data;
	int				index;
	int				key;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;
typedef struct s_dtint
{
	int	*nb;
	int	len;
}			t_dtint;

void	ft_sort_select(t_stack *stack_a);
void	ft_free_dtint(t_dtint *dt);
void	ft_stack_free(t_stack **stack);
int		ft_issorted(t_stack *stack);

void	ft_data_validation(char **data, int argc);
int		ft_is_all_num(char *data);
t_dtint	ft_data_load(char **data, int argc);

int		ft_check_dupl(t_dtint data);

void	ft_exit_error(void);
int		ft_isspace(int c);
int		ft_issign(int c);
long	ft_myatoi(const char *str);
void	ft_pr_action(int op);

t_stack	*ft_build_stack(t_dtint dt);
void	ft_delete_node(t_stack **nodel);
void	ft_print_stack(t_stack *node);
int		ft_stack_len(t_stack *stack);

void	ft_first2last(t_stack **stack, int op);
void	ft_last2first(t_stack **stack, int op);
void	ft_swap_2(t_stack **stack, int op);
void	ft_push2other(t_stack **from, t_stack **to, int op);

int		ft_stack_max(t_stack *stack);
void	ft_sort_big(t_stack *stack);
void	ft_sort_3(t_stack **stack);

void	ft_sort_4(t_stack *stack);
void	ft_sort_5(t_stack *stack);
int		ft_stack_min(t_stack *stack);
void	ft_stack_keying(t_stack **stack);

void	ft_best_op_a(t_stack **stack, int min);
void	ft_best_op_b(t_stack **stack, int max);

void	ft_stack_indexing(t_stack **stack);

int		ft_stack_max_k(t_stack *stack);
void	ft_sort_new(t_stack *stack, size_t chunks);

void	ft_exit_checker(t_stack **stack_a, t_stack **stack_b);
t_dtint	ft_checker_stacker(char **data, int argc);
#endif
