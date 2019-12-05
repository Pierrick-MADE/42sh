#include <sys/types.h>
#include <sys/wait.h>

#include "../input_output/get_next_line.h"
#include "fg.h"


int fg(char **params)
{
    int wstatus;
    waitpid(g_env.pid, &wstatus, 0);
    return WEXITSTATUS(wstatus);
}