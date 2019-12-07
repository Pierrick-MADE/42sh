#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <err.h>

#include "jobs_array.h"
#include "../input_output/get_next_line.h"
#include "../memory/memory.h"

#define MAX_JOBS 512

extern void print_access_jobs(struct job *job, char *action)
{
    printf("[%d] %s%d %s\n", job->array_index, action, job->pid, job->name);
}


extern int get_next_slot(void)
{
    for (int i = 0; i < MAX_JOBS; i++)
    {
        if (g_env.childs_pid[i] == NULL) //No job at this slot
        {
            return i;
        }
    }

    return -1;
}


extern struct job *create_job(pid_t pid, char *name)
{
    struct job *job = xmalloc(sizeof(struct job));
    job->pid = pid;
    job->name = name;
    job->array_index = get_next_slot();

    if (job->array_index == -1)
    {
        free(job->name);
        warnx("Job array is full");
        return NULL;
    }

    g_env.childs_pid[job->array_index] = job;
    return job;
}


extern void terminate_job(struct job *job)
{
    g_env.childs_pid[job->array_index] = NULL;
    free(job->name);
    free(job);
}


extern void destroy_all_jobs(void)
{
    for (int i = 0; i < MAX_JOBS; i++)
    {
        if (g_env.childs_pid[i] != NULL)
        {
            kill(g_env.childs_pid[i]->pid, SIGTERM);
            int wstatus;
            waitpid(g_env.childs_pid[i]->pid, &wstatus, 0);
        }
    }
}


extern int check_if_jobs_running(void)
{
    for (int i = 0; i < MAX_JOBS; i++)
    {
        if (g_env.childs_pid[i])
            return 1;
    }

    return 0;
}
