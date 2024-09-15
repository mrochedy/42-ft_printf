/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:08:50 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/15 18:54:24 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_char(char c, t_print *to_print)
{
	if (to_print->size && to_print->size % MALLOC_SIZE == 0)
	{
		to_print->str = ft_realloc(to_print->str,
				(to_print->size + 1) * sizeof(char),
				(to_print->size + MALLOC_SIZE + 1) * sizeof(char));
		if (!(to_print->str))
			return (0);
	}
	(to_print->str)[to_print->size] = c;
	to_print->size += 1;
	return (1);
}

int	add_str(char *str, t_print *to_print)
{
	int	i;

	if (!str)
		return (add_str("(null)", to_print));
	i = 0;
	while (str[i])
		if (!add_char(str[i++], to_print))
			return (0);
	return (1);
}

int	add_nbr(int nbr, t_print *to_print)
{
	if (nbr == -2147483648)
		return (add_str("-2147483648", to_print));
	if (nbr < 0)
	{
		if (!add_char('-', to_print))
			return (0);
		nbr = -nbr;
	}
	if (nbr < 10)
		return (add_char(nbr + '0', to_print));
	if (!add_nbr(nbr / 10, to_print))
		return (0);
	if (!add_char(nbr % 10 + '0', to_print))
		return (0);
	return (1);
}

int	add_nbr_base(unsigned int nbr, char *base, t_print *to_print)
{
	if (nbr < ft_strlen(base))
		return (add_char(base[nbr], to_print));
	if (!add_nbr_base(nbr / ft_strlen(base), base, to_print))
		return (0);
	if (!add_char(base[nbr % ft_strlen(base)], to_print))
		return (0);
	return (1);
}

int	add_addr(unsigned long addr, char *hex, t_print *to_print)
{
	if (addr < 16)
	{
		if (!addr)
			return (add_str("(nil)", to_print));
		if (!add_str("0x", to_print))
			return (0);
		return (add_char(hex[addr], to_print));
	}
	if (!add_addr(addr / 16, hex, to_print))
		return (0);
	if (!add_char(hex[addr % 16], to_print))
		return (0);
	return (1);
}
