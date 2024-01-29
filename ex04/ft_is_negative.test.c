/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:37:38 by xbeheydt          #+#    #+#             */
/*   Updated: 2024/01/29 13:41:45 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>

void	ft_is_negative(int n);

int main(void)
{
	lt_init_redirect();
	ft_is_negative(-2147483648);
	ft_is_negative(0);
	ft_is_negative(-1);
	ft_is_negative(1);
	lt_cmpstdout("NPNP", "ft_is_negative test");
	lt_close_redirect();
	return (0);
}
