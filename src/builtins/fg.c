#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include "../input_output/get_next_line.h"
#include "fg.h"


int fg(char **params)
{
    int wstatus;
    kill(g_env.pid, SIGCONT);
    waitpid(g_env.pid, &wstatus, WUNTRACED);
    return WEXITSTATUS(wstatus);
}