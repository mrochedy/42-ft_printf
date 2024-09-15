/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:35:08 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/15 19:50:40 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	deal_with_flags(va_list *args_list, const char *str,
		int *i, t_print *to_print)
{
	if (str[*i] == '+')
		return (deal_with_plus(args_list, str, i, to_print));
	else if (str[*i] == ' ')
		return (deal_with_space(args_list, str, i, to_print));
	else if (str[*i] == '#')
		return (deal_with_hash(args_list, str, i, to_print));
	else
		return ((*i)--, add_char('%', to_print));
	return (0);
}

int	add_to_print(va_list *args_list, const char *str, int *i,
		t_print *to_print)
{
	if (str[*i] == 'c')
		return (add_char(va_arg(*args_list, int), to_print));
	else if (str[*i] == 's')
		return (add_str(va_arg(*args_list, char *), to_print));
	else if (str[*i] == 'p')
		return (add_addr(va_arg(*args_list, unsigned long),
				"0123456789abcdef", to_print));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (add_nbr(va_arg(*args_list, int), to_print));
	else if (str[*i] == 'u')
		return (add_nbr_base(va_arg(*args_list, unsigned int),
				"0123456789", to_print));
	else if (str[*i] == 'x')
		return (add_nbr_base(va_arg(*args_list, unsigned int),
				"0123456789abcdef", to_print));
	else if (str[*i] == 'X')
		return (add_nbr_base(va_arg(*args_list, unsigned int),
				"0123456789ABCDEF", to_print));
	else if (str[*i] == '%')
		return (add_char('%', to_print));
	else
		return (deal_with_flags(args_list, str, i, to_print));
}

t_print	*set_to_print(void)
{
	t_print	*to_print;

	to_print = malloc(sizeof(t_print));
	to_print->size = 0;
	to_print->str = malloc((MALLOC_SIZE + 1) * sizeof(char));
	if (!(to_print->str))
		return (NULL);
	return (to_print);
}

static int	make_the_printf(const char *str, va_list *args_list,
	t_print *to_print)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!add_to_print(args_list, str, &i, to_print))
				return (free(to_print->str), free(to_print), to_print->size);
		}
		else
			if (!add_char(str[i], to_print))
				return (free(to_print->str), free(to_print), to_print->size);
		i++;
	}
	return (to_print->size);
}

int	ft_printf(const char *str, ...)
{
	int			ret;
	va_list		args_list;
	t_print		*to_print;

	if (!str)
		return (-1);
	to_print = set_to_print();
	if (!to_print)
		return (-1);
	va_start(args_list, str);
	ret = make_the_printf(str, &args_list, to_print);
	return (va_end(args_list), write(1, to_print->str, to_print->size),
		free(to_print->str), free(to_print), ret);
}
