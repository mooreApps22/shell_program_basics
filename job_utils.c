#include "data.h"

//find the active job with the indicated pgid
job *find_job(pid_t pgid)
{
	t_job	*j;

	j = head_job;
	while (j)
	{
		if (j->pgid == pgid)
			return (j);
		j = j->next;
	}
	return (NULL);
}

// return true if all processes in job have stopped or completed
int	job_is_stopped(t_job *j)
{
	t_process	*p;

	p = j->head_process;
	while (p)
	{
		if (!p->completed && !p->stopped)
			return (0);
		p = p->next;
	}
	return (1);
}

// return true if all processes in the job have completed
int	job_is_completed(t_job *j)
{
	t_process *p;

	p = j->head_process;
	while (p)
	{
		if (!p->completed)
			return (0);
		p = p->next;
	}
	return (1);
}

int	main(void)
{
	t_job	head_job = NULL; 	
	pid_t shell_pgid;
	struct termios shell_tmodes;
	int shell_terminal;
	int shell_is_interactive;

	
}
