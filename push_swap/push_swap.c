/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:49:36 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/07 16:37:22 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_int_node **stack)
{
	t_int_node	*temp;

	temp = *stack;
	while ((*stack) != NULL)
	{
		temp = (*stack)->next;
		free((*stack)->rank_bin);
		free(*stack);
		*stack = temp;
	}
	free(stack);
	stack = NULL;
}

/*conta nº de argumentos passados*/
int	count_args(char **args)
{
	int	i;

	i = 0;
	if (args == NULL)
		return (0);
	while (args[i] != 0)
		i++;
	return (i);
}

/*cria memoria para a stack_a e preenche-a com os numeros passados
adicionando-os sempre no fim da lista (1º numero passado é o top of stack)
retorna o duplo ponteiro que aponta para o ponteiro do inicio da lista.
Se ocorrer algum problema durante a criação da lista faz-se free
da stack_a e da stack_b e retorna-se NULL*/
t_int_node	**ft_create_stack(int n_args, char **argv, t_int_node **stack_b)
{
	t_int_node	**stack_a;
	t_int_node	*num;
	int			i;

	stack_a = (t_int_node **)ft_calloc(1, sizeof(t_int_node *));
	if (!(stack_a))
	{
		ft_lstclear(stack_b);
		return (0);
	}
	i = 0;
	while (i < n_args)
	{
		num = ft_new_t_int_node(ft_atoi(argv[i]), i);
		if (!num)
		{
			ft_lstclear(stack_a);
			ft_lstclear(stack_b);
			return (0);
		}
		ft_lstadd_back(stack_a, num);
		i++;
	}
	return (stack_a);
}

/*trata os argumentos passados (arg_parser)
faz check dos argumentos passados 
(se respeitam o formato pedido - digitos e sem nº duplicados)
cria memoria para a stack_b e
cria memoria para a stack_a (preenchendo-a com os numeros passados)
acrescenta um campo com o ranking do numero e 
chama-se a funcao para os ordenar e liberta-se a memoria utilizada.
Caso haja algum problema na memoria alocada durante o decorrer do programa
faz-se free a toda a memoria utilizada (free_args e frees na ft_create_stack)*/
int	main(int argc, char **argv)
{
	t_int_node	**stack_a;
	t_int_node	**stack_b;
	char		**args;
	int			n_args;

	if (argc == 1)
		return (0);
	args = arg_parser(argc, argv);
	n_args = count_args(args);
	if (!(check_argv_type(args)) || !(check_argv_dups(args)))
		return (free_args(args, n_args, argc));
	stack_b = 0;
	if (!(stack_b))
		return (free_args(args, n_args, argc));
	stack_a = ft_create_stack(n_args, args, stack_b);
	if (!(stack_a))
		return (free_args(args, n_args, argc));
	if (rank_stack(stack_a))
		sort_final(stack_a, stack_b);
	free_args(args, n_args, argc);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	return (1);
}
