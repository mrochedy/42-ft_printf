/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:08:21 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/15 18:55:01 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	deal_with_plus(va_list *args_list, const char *str,
		int *i, t_print *to_print)
{
	va_list	list_copy;

	va_copy(list_copy, *args_list);
	*i = *i + 1;
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		if (va_arg(list_copy, int) >= 0)
			if (!add_char('+', to_print))
				return (0);
		return (add_nbr(va_arg(*args_list, int), to_print));
	}
	else
		return (add_to_print(args_list, str, i, to_print));
	va_end(list_copy);
}

static int	multiple_spaces(va_list *args_list, const char *str,
		int *i, t_print *to_print)
{
	int		spaces_amount;
	int		str_len;
	va_list	list_copy;

	spaces_amount = new_atoi(str, i);
	if (!spaces_amount || str[*i] != 's')
		return (add_to_print(args_list, str, i, to_print));
	va_copy(list_copy, *args_list);
	str_len = ft_strlen(va_arg(list_copy, char *));
	while (spaces_amount > 0 && str_len++ < spaces_amount)
		if (!add_char(' ', to_print))
			return (va_end(list_copy), 0);
	if (!add_str(va_arg(*args_list, char *), to_print))
		return (va_end(list_copy), 0);
	while (spaces_amount < 0 && str_len++ < -spaces_amount)
		if (!add_char(' ', to_print))
			return (va_end(list_copy), 0);
	return (va_end(list_copy), 1);
}

int	deal_with_space(va_list *args_list, const char *str,
		int *i, t_print *to_print)
{
	va_list	list_copy;

	*i = *i + 1;
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		va_copy(list_copy, *args_list);
		if (va_arg(list_copy, int) >= 0)
			if (!add_char(' ', to_print))
				return (va_end(list_copy), 0);
		return (va_end(list_copy), add_nbr(va_arg(*args_list, int),
				to_print));
	}
	else
		return (multiple_spaces(args_list, str, i, to_print));
}

int	deal_with_hash(va_list *args_list, const char *str,
		int *i, t_print *to_print)
{
	va_list	list_copy;

	va_copy(list_copy, *args_list);
	*i = *i + 1;
	if (str[*i] == 'x')
	{
		if (va_arg(list_copy, int) != 0)
			if (!add_str("0x", to_print))
				return (0);
		return (add_nbr_base(va_arg(*args_list, unsigned int),
				"0123456789abcdef", to_print));
	}
	else if (str[*i] == 'X')
	{
		if (va_arg(list_copy, int) != 0)
			if (!add_str("0X", to_print))
				return (0);
		return (add_nbr_base(va_arg(*args_list, unsigned int),
				"0123456789ABCDEF", to_print));
	}
	else
		return (add_to_print(args_list, str, i, to_print));
	va_end(list_copy);
}
