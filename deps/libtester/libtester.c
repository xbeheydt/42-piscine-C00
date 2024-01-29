// Copyright Xavier Beheydt. All rights reserved.
#include "libtester.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/* Global variables */
LT_INTERN char	g_lt_buf[LT_BUFSIZE]	= {'\0'};
LT_INTERN int	g_lt_fd_pipe[2]			= {0, 0};
LT_INTERN int	g_lt_bck_fd				= 0;

/* Internal functions */
LT_INTERN void lt_clrbuf(void)
{
    int i = 0;
    while (i < LT_BUFSIZE)
        *(g_lt_buf + i++) = '\0';
}

LT_INTERN void lt_print_buf(void)
{
    printf(", Buffer: '%s'", g_lt_buf);
}

LT_INTERN void lt_fail(const char *msg)
{
    printf("[%sFAIL%s] %s", RED, RESET, msg);
}

LT_INTERN void lt_ok(const char *msg)
{
    printf("[%sOK%s] %s\n", GREEN, RESET, msg);
}
/* !Internal functions */

/* API functions */
LT_API void lt_init_redirect(void)
{
    lt_clrbuf();
    if (pipe(g_lt_fd_pipe) == -1)
        exit(EXIT_FAILURE);
    g_lt_bck_fd = dup(STDOUT_FILENO);
    dup2(g_lt_fd_pipe[1], STDOUT_FILENO);
    close(g_lt_fd_pipe[1]);
}

LT_API void lt_close_redirect(void)
{
    dup2(g_lt_bck_fd, STDOUT_FILENO);
    close(g_lt_bck_fd);
    close(g_lt_fd_pipe[0]);
    close(g_lt_fd_pipe[1]);
}

LT_API int lt_cmpstdout(const char *str, const char *msg)
{
	lt_clrbuf();
    read(g_lt_fd_pipe[0], g_lt_buf, LT_BUFSIZE);
    if (strcmp(g_lt_buf, str) == 0)
        lt_ok(msg);
    else
    {
        lt_fail(msg);
        if (DEBUG)
            lt_print_buf();
		printf("\n");
        return (EXIT_FAILURE);
    }
    lt_close_redirect();
    return (EXIT_SUCCESS);
}
/* !API functions */
