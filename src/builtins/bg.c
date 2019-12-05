#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include "../input_output/get_next_line.h"
#include "bg.h"


int bg(char **params)
{
    kill(g_env.pid, SIGCONT);
}