#ifndef DATA_H
# define DATA_H


// A process is a single process
typedef	struct s_process 
{
	struct process	*next;		// next process in pipeline
	char			**cmdv;		// for the execve() 2nd arg
	pid_t			pid;
	char			completed;	// true if process has completed
	char			stopped;	// true if process has stopped 
	int				status;		// exit status
} t_process;

// A job is a pipeline of processes

typedef	struct s_job 
{
	struct job		*next;			// next active job
	char			cmd;			// command line, used for messages
	t_process		*head_process;	// list of process in job
	pid_t			pgid;			// process group ID
	char			notified;		// true if user told about stopped job
	struct termios	tmodes;			// saved terminal modes
	int				stdin;
	int				stdout;
	int				stderr;
} t_job;

#endif
