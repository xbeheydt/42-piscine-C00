/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.test.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:51:15 by xbeheydt          #+#    #+#             */
/*   Updated: 2024/01/29 11:52:57 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>

int	ft_print_reverse_alphabet(void);

int main(void)
{
	lt_init_redirect();
	ft_print_reverse_alphabet();
	lt_cmpstdout("zyxwvutsrqponmlkjihgfedcba", "ft_print_reverse_alphabet test");
	lt_close_redirect();
	return (0);
}
