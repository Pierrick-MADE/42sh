#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>

#include "../input_output/get_next_line.h"
#include "../job_control/jobs_array.h"
#include "fg.h"


int fg(char **params)
{
    struct job *job;
    int wstatus;

    if (!params[1])
    {
        job = g_env.last_job;
        if (!job)
        {
            warnx("Last job not set.");
            return 0;
        }
    }
    else
    {
        int current_job = atoi(params[1]);

        if (!current_job && strcmp(params[1], "0") != 0)
        {
            warnx("fg needs an array index");
            return 0;
        }

        job = g_env.childs_pid[current_job];

        if (!job)
        {
            warnx("No current job");
            return 1;
        }
    }

    print_access_jobs(job, "");
    g_env.last_job = job;
    g_env.last_pid = job->pid;
    kill(job->pid, SIGCONT);
    waitpid(job->pid, &wstatus, WUNTRACED);

    if (WIFEXITED(wstatus))
    {
        print_access_jobs(job, "Done ");
        terminate_job(job);
    }

    return WEXITSTATUS(wstatus);
}
