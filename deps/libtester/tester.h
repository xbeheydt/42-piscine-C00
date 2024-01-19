/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:16:03 by xbeheydt          #+#    #+#             */
/*   Updated: 2024/01/19 09:17:38 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTESTER_H
# define LIBTESTER_H

/* Define variables*/

# ifndef LIBTESTER_BUFSIZE
#  define LIBTESTER_BUFSIZE 2048
# endif /* LIBTESTER_BUFSIZE */

# ifndef DEBUG
#  define DEBUG 0
# else
#  define DEBUG 1
# endif /* DEBUG */

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define RESET  "\033[0m"

#endif /* LIBTESTER_H */
