/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:22:14 by harndt            #+#    #+#             */
/*   Updated: 2023/09/13 15:35:52 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	malloc_size;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		malloc_size = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (malloc_size > len)
		malloc_size = len;
	str = (char *)malloc(malloc_size + 1);
	if (!str)
		return (NULL);
	if (malloc_size == 0)
	{
		str[0] = '\0';
		return (str);
	}
	ft_strlcpy(str, (s + start), (malloc_size + 1));
	return (str);
}
