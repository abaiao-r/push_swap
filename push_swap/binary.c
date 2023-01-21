/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:06:37 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 21:22:35 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*conta digitos que um numero vai ter em binario*/
int	count_digits_binary(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 2;
		i++;
	}
	return (i);
}

/*Retorna o numero em binario num char*.
Comeca-se por contar o numero digitos em binario do rank max
(nº de elementos da lista) e do rank do numero que esta a ser convertido.
Aloca-se memoria para o char * (nº de digitos do valor maximo + 1 (null)).
Preenche-se com 0 a diferenca de digitos entre o max e o numero a converter e
depois mete-se o restantes numeros do final para o inicio.
Vai-se dividindo o numero por 2 e vai-se escrevendo o resto da divisao (0 ou 1)
para o char* */
char	*convert_binary(int num, int max)
{
	int		count_max;
	int		count_num;
	char	*bin;
	int		i;

	count_max = count_digits_binary(max);
	count_num = count_digits_binary(num);
	bin = (char *)ft_calloc(count_max, (sizeof(char) + 1));
	if (!bin)
		return (0);
	bin[count_max] = '\0';
	i = 0;
	while (i < (count_max - count_num))
		bin[i++] = '0';
	while (num > 0)
	{
		count_max--;
		bin[count_max] = num % 2 + '0';
		num = num / 2;
	}
	return (bin);
}

/*preenche o rank do numero na estrutura t_int_node
e converte para binario o numero do rank para ser
utilizado no algoritmo radix sort.
o rank e feito do mais pequeno para o maior.
o rank comeca a 1 se algum numero for menor do que
aquele que esta a ser comparado faz-se rank++
Repete-se este processo para todos os numeros da lista*/
int	rank_stack(t_int_node **stack)
{
	t_int_node	*temp;
	t_int_node	*comp;
	int			rank;

	temp = (*stack);
	comp = (*stack);
	while (temp != NULL)
	{
		rank = 1;
		comp = (*stack);
		while (comp != NULL)
		{
			if (comp->num < temp->num)
				rank++;
			comp = comp->next;
		}
		temp->rank = rank;
		temp->rank_bin = convert_binary(rank, ft_lstsize(*stack));
		if (!temp->rank_bin)
			return (0);
		temp = temp->next;
	}
	return (1);
}
