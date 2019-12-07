#include "jobs.h"
#include "../input_output/get_next_line.h"
#include "../job_control/jobs_array.h"

extern int jobs(char **argv)
{
    argv = argv;

    for (int i = 0; i < 512; i++)
    {
        if (g_env.childs_pid[i])
            print_access_jobs(g_env.childs_pid[i], "");
    }

    return 1;
}
