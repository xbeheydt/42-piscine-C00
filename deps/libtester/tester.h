/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:16:03 by xbeheydt          #+#    #+#             */
/*   Updated: 2024/01/19 10:50:14 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTESTER_H
# define LIBTESTER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Define variables*/
# ifndef LIBTESTER_BUFSIZE
#  define LIBTESTER_BUFSIZE 2048
# endif /* LIBTESTER_BUFSIZE */

# ifndef DEBUG
#  define DEBUG 0
# else
#  define DEBUG 1
# endif /* DEBUG */

/* Define colors */
# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define RESET  "\033[0m"

/* Define global variables used in the tester */
char	__buf[LIBTESTER_BUFSIZE];
int		__fd_pipe[2];
int		__bck_fd = 0;
int		__i = 0;

/* Functions */
inline void	fail(char* msg) { printf("[%sFAIL%s] %s", RED, RESET, msg); }
inline void ok(char* msg) { printf("[%sOK%s] %s", GREEN, RESET, msg); }
inline void print_buffer(void) { printf(", buffer: \"%s\"", __buf); }

/* Macros Functions */
# define CLEAR_BUFFER() \
	__i = 0; \
	while (__i < LIBTESTER_BUFSIZE) \
	{ \
		__buf[__i] = '\0'; \
	}

# define REDIRECT_STDOUT() \
	if (pipe(__fd_pipe) == -1) \
		exit(EXIT_FAILURE); \
	__bck_fd = dup(STDOUT_FILENO); \
	dup2(__fd_pipe[1], STDOUT_FILENO); \
	close(__fd_pipe[1]);

# define RESTORE_STDOUT() \
	dup2(__bck_fd, STDOUT_FILENO); \
	close(__bck_fd);

# define CMP_STDOUT(str, msg) \
	REDIRECT_STDOUT(); \
	read(__fd_pipe[0], __buf, LIBTESTER_BUFSIZE); \
	CLEAR_BUFFER(); \
	if (strcmp(__buf, str) != 0) \
	{ \
		fail(msg); \
		if (DEBUG) \
			print_buffer(); \
		write(STDOUT_FILENO, "\n", 1); \
		exit(EXIT_FAILURE); /* TODO : make a cond to exit */ \
	} \
	else \
		ok(msg); \
	RESTORE_STDOUT();

#endif /* LIBTESTER_H */
