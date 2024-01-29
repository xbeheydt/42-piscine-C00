/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:31:55 by xbeheydt          #+#    #+#             */
/*   Updated: 2024/01/29 11:32:44 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>

void	ft_print_alphabet(void);

int main(void)
{
	lt_init_redirect();
	ft_print_alphabet();
	lt_cmpstdout("abcdefghijklmnopqrstuvwxyz", "ft_print_alphabet test");
	lt_close_redirect();
	return (0);
}
