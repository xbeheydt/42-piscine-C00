/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:44 by xbeheydt          #+#    #+#             */
/*   Updated: 2024/01/29 13:22:49 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>

void	ft_print_numbers(void);

int	main(void)
{
	lt_init_redirect();
	ft_print_numbers();
	lt_cmpstdout("0123456789", "ft_print_numbers test");
	lt_close_redirect();
	return (0);
}
