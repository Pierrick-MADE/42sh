#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

#include "../input_output/get_next_line.h"
#include "bg.h"


int bg(char **params)
{
    params = params;
    kill(g_env.last_job->pid, SIGCONT);
    return 1;
}
