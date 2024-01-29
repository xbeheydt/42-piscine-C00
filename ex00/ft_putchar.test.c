/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:51:27 by xbeheydt          #+#    #+#             */
/*   Updated: 2024/01/29 10:58:42 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>

void 	ft_putchar(char c);

int main(void)
{
    lt_init_redirect();
    ft_putchar('a');
    ft_putchar('g');
    ft_putchar('u');
    ft_putchar('b');
    ft_putchar('j');
    ft_putchar('4');
    ft_putchar('^');
    lt_cmpstdout("agubj4^", "ft_putchar test");
    lt_close_redirect();
    return (0);
}
