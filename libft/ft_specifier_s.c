/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:38:59 by harndt            #+#    #+#             */
/*   Updated: 2023/09/13 15:37:02 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specifier_s(va_list arg_ptr)
{
	char	*string;
	int		length;

	string = va_arg(arg_ptr, char *);
	if (!string)
		string = "(null)";
	length = ft_strlen(string);
	ft_putstr(string);
	return (length);
}
