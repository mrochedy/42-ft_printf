/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:33:59 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/15 18:55:26 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*u_dest;
	const unsigned char	*u_src;

	if (!dest && !src)
		return (NULL);
	i = 0;
	u_dest = dest;
	u_src = src;
	while (i < n)
	{
		u_dest[i] = u_src[i];
		i++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	size_t	size_to_copy;
	void	*new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	size_to_copy = original_size;
	if (new_size < original_size)
		size_to_copy = new_size;
	ft_memcpy(new_ptr, ptr, size_to_copy);
	free(ptr);
	return (new_ptr);
}

int	new_atoi(const char *nptr, int *i)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	if (nptr[*i] == '-')
	{
		(*i)++;
		sign = -sign;
	}
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
		nbr = nbr * 10 + nptr[(*i)++] - '0';
	return (sign * nbr);
}
