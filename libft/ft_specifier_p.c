/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:39:38 by harndt            #+#    #+#             */
/*   Updated: 2023/09/13 15:37:07 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier_p(va_list arg_ptr)
{
	char	*string;
	int		length;

	string = ft_utoa_base((va_arg(arg_ptr, unsigned long)), HEX);
	if (*string == '0')
	{
		ft_putstr("(nil)");
		free(string);
		return (5);
	}
	length = ft_strlen(string);
	if (string && *string)
		ft_putstr("0x");
	ft_putstr(string);
	if (string)
		free(string);
	return (2 + length);
}
