/** @file
* @brief 
* @author Coder : 
* @author Tester :
* @author Reviewer :
* @author Integrator :
*/

#pragma once

#define MAX_JOBS 512

struct job {
    pid_t pid;
    int array_index;
    char *name;
    char *status;
};


extern void print_access_jobs(struct job *job, char *action);

extern int get_next_slot(void);

extern struct job *create_job(pid_t pid, char *name);

extern void terminate_job(struct job *job);

extern void destroy_all_jobs(void);

extern int check_if_jobs_running(void);

extern int is_pid_in_array(pid_t pid);
