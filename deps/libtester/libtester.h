// Copyright Xavier Beheydt. All rights reserved.
#ifndef LIBTESTER_H
# define LIBTESTER_H

/* Includes*/
# include <stdlib.h>

/* Macros variables */
# ifndef LT_BUFSIZE
#  define LT_BUFSIZE 4096
# endif /* !LIBTESTER_BUFSIZE */

# ifndef DEBUG
#  define DEBUG 0
# else
#  define DEBUG 1
# endif /* !DEBUG */

/* Keyword indicates type of function*/
# define LT_INTERN	static
# define LT_API
# define LT_LIB		extern

/* Define colors */
# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define RESET  "\033[0m"

/* API functions */
LT_API void	lt_init_redirect(void);
LT_API void	lt_close_redirect(void);
LT_API int	lt_cmpstdout(const char *str, const char *msg);

#endif /* !LIBTESTER_H */
