begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* jobs.h -- structures and stuff used by the jobs.c file. */
end_comment

begin_include
include|#
directive|include
file|"quit.h"
end_include

begin_comment
comment|/* Defines controlling the fashion in which jobs are listed. */
end_comment

begin_define
define|#
directive|define
name|JLIST_STANDARD
value|0
end_define

begin_define
define|#
directive|define
name|JLIST_LONG
value|1
end_define

begin_define
define|#
directive|define
name|JLIST_PID_ONLY
value|2
end_define

begin_define
define|#
directive|define
name|JLIST_CHANGED_ONLY
value|3
end_define

begin_comment
comment|/* Cadmus machines are brain-dead from the moment of fission, like all    bacteria. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|cadmus
argument_list|)
operator|||
name|defined
argument_list|(
name|BrainDeath
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_WAIT_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BrainDeath */
end_comment

begin_comment
comment|/* HP/UX 6.x sys/wait.h is a complete loss when it comes to the WIF macros.    Pretend we don't have a wait.h. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_WAIT_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_WAIT_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"endian.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LITTLE_ENDIAN
argument_list|)
end_if

begin_union
union|union
name|wait
block|{
name|int
name|w_status
decl_stmt|;
comment|/* used in syscall */
comment|/* Terminated process status. */
struct|struct
block|{
name|unsigned
name|short
name|w_Termsig
range|:
literal|7
decl_stmt|,
comment|/* termination signal */
name|w_Coredump
range|:
literal|1
decl_stmt|,
comment|/* core dump indicator */
name|w_Retcode
range|:
literal|8
decl_stmt|,
comment|/* exit code if w_termsig==0 */
name|w_Fill1
range|:
literal|16
decl_stmt|;
comment|/* high 16 bits unused */
block|}
name|w_T
struct|;
comment|/* Stopped process status.  Returned        only for traced children unless requested        with the WUNTRACED option bit. */
struct|struct
block|{
name|unsigned
name|short
name|w_Stopval
range|:
literal|8
decl_stmt|,
comment|/* == W_STOPPED if stopped */
name|w_Stopsig
range|:
literal|8
decl_stmt|,
comment|/* actually zero on XENIX */
name|w_Fill2
range|:
literal|16
decl_stmt|;
comment|/* high 16 bits unused */
block|}
name|w_S
struct|;
block|}
union|;
end_union

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* if !LITTLE_ENDIAN */
end_comment

begin_comment
comment|/* This is for big-endian machines like the IBM RT, HP 9000, or Sun-3 */
end_comment

begin_union
union|union
name|wait
block|{
name|int
name|w_status
decl_stmt|;
comment|/* used in syscall */
comment|/* Terminated process status. */
struct|struct
block|{
name|unsigned
name|short
name|w_Fill1
range|:
literal|16
decl_stmt|;
comment|/* high 16 bits unused */
name|unsigned
name|w_Retcode
range|:
literal|8
decl_stmt|;
comment|/* exit code if w_termsig==0 */
name|unsigned
name|w_Coredump
range|:
literal|1
decl_stmt|;
comment|/* core dump indicator */
name|unsigned
name|w_Termsig
range|:
literal|7
decl_stmt|;
comment|/* termination signal */
block|}
name|w_T
struct|;
comment|/* Stopped process status.  Returned        only for traced children unless requested        with the WUNTRACED option bit. */
struct|struct
block|{
name|unsigned
name|short
name|w_Fill2
range|:
literal|16
decl_stmt|;
comment|/* high 16 bits unused */
name|unsigned
name|w_Stopsig
range|:
literal|8
decl_stmt|;
comment|/* signal that stopped us */
name|unsigned
name|w_Stopval
range|:
literal|8
decl_stmt|;
comment|/* == W_STOPPED if stopped */
block|}
name|w_S
struct|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|w_termsig
value|w_T.w_Termsig
end_define

begin_define
define|#
directive|define
name|w_coredump
value|w_T.w_Coredump
end_define

begin_define
define|#
directive|define
name|w_retcode
value|w_T.w_Retcode
end_define

begin_define
define|#
directive|define
name|w_stopval
value|w_S.w_Stopval
end_define

begin_define
define|#
directive|define
name|w_stopsig
value|w_S.w_Stopsig
end_define

begin_comment
comment|/* Note that sys/wait.h defines these for Posix systems. */
end_comment

begin_define
define|#
directive|define
name|WSTOPPED
value|0177
end_define

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|x
parameter_list|)
value|(((x) . w_stopval) == WSTOPPED)
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|x
parameter_list|)
value|((! (WIFSTOPPED (x)))&& (((x) . w_termsig) == 0))
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|x
parameter_list|)
value|((! (WIFSTOPPED (x)))&& (((x) . w_termsig) != 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_WAIT_H */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_define
define|#
directive|define
name|pid_t
value|int
end_define

begin_typedef
typedef|typedef
name|union
name|wait
name|WAIT
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|WAIT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
end_comment

begin_comment
comment|/* How to get the status of a job.  For Posix, this is just an int, but for    other systems we have to crack the union wait. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_define
define|#
directive|define
name|WSTATUS
parameter_list|(
name|t
parameter_list|)
value|(t)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WSTATUS
parameter_list|(
name|t
parameter_list|)
value|(t.w_status)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make sure that parameters to wait3 are defined. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WNOHANG
argument_list|)
end_if

begin_define
define|#
directive|define
name|WNOHANG
value|1
end_define

begin_define
define|#
directive|define
name|WUNTRACED
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WNOHANG */
end_comment

begin_comment
comment|/* More Posix P1003.1 definitions.  In these definitions, `s' is a    `union wait' (the 1003.1 spec says they are `int'). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WSTOPSIG
argument_list|)
end_if

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|s
parameter_list|)
value|((s).w_stopsig)
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|s
parameter_list|)
value|((s).w_termsig)
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|s
parameter_list|)
value|((s).w_retcode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WSTOPSIG */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WIFCORED
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIFCORED
parameter_list|(
name|s
parameter_list|)
value|((s).w_coredump)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WIFCORED
parameter_list|(
name|s
parameter_list|)
value|((s)& 0200)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIFCORED */
end_comment

begin_comment
comment|/* I looked it up.  For pretty_print_job ().  The real answer is 24. */
end_comment

begin_define
define|#
directive|define
name|LONGEST_SIGNAL_DESC
value|24
end_define

begin_comment
comment|/* We keep an array of jobs.  Each entry in the array is a linked list    of processes that are piped together.  The first process encountered is    the group leader. */
end_comment

begin_comment
comment|/* Each child of the shell is remembered in a STRUCT PROCESS.  A chain of    such structures is a pipeline.  The chain is circular. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|process
block|{
name|struct
name|process
modifier|*
name|next
decl_stmt|;
comment|/* Next process in the pipeline.  A circular chain. */
name|pid_t
name|pid
decl_stmt|;
comment|/* Process ID. */
name|WAIT
name|status
decl_stmt|;
comment|/* The status of this command as returned by wait. */
name|int
name|running
decl_stmt|;
comment|/* Non-zero if this process is running. */
name|char
modifier|*
name|command
decl_stmt|;
comment|/* The particular program that is running. */
block|}
name|PROCESS
typedef|;
end_typedef

begin_comment
comment|/* A description of a pipeline's state. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|JRUNNING
block|,
name|JSTOPPED
block|,
name|JDEAD
block|,
name|JMIXED
block|}
name|JOB_STATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|JOBSTATE
parameter_list|(
name|job
parameter_list|)
value|(jobs[(job)]->state)
end_define

begin_typedef
typedef|typedef
struct|struct
name|job
block|{
name|char
modifier|*
name|wd
decl_stmt|;
comment|/* The working directory at time of invocation. */
name|PROCESS
modifier|*
name|pipe
decl_stmt|;
comment|/* The pipeline of processes that make up this job. */
name|pid_t
name|pgrp
decl_stmt|;
comment|/* The process ID of the process group (necessary). */
name|int
name|foreground
decl_stmt|;
comment|/* Non-zero if this is running in the foreground. */
name|int
name|notified
decl_stmt|;
comment|/* Non-zero if already notified about job state. */
name|JOB_STATE
name|state
decl_stmt|;
comment|/* The state that this job is in. */
name|int
name|job_control
decl_stmt|;
comment|/* Non-zero if this job started under job control. */
ifdef|#
directive|ifdef
name|JOB_CONTROL
name|COMMAND
modifier|*
name|deferred
decl_stmt|;
comment|/* Commands that will execute when this job is done. */
endif|#
directive|endif
block|}
name|JOB
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NO_JOB
value|-1
end_define

begin_comment
comment|/* An impossible job array index. */
end_comment

begin_define
define|#
directive|define
name|DUP_JOB
value|-2
end_define

begin_comment
comment|/* A possible return value for get_job_spec (). */
end_comment

begin_comment
comment|/* A value which cannot be a process ID. */
end_comment

begin_define
define|#
directive|define
name|NO_PID
value|(pid_t)-1
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sigmask
argument_list|)
end_if

begin_define
define|#
directive|define
name|sigmask
parameter_list|(
name|x
parameter_list|)
value|(1<< ((x)-1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !POSIX&& !sigmask */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGABRT
end_ifndef

begin_define
define|#
directive|define
name|SIGABRT
value|SIGIOT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGCHLD
end_ifndef

begin_define
define|#
directive|define
name|SIGCHLD
value|SIGCLD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIG_BLOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIG_BLOCK
value|2
end_define

begin_define
define|#
directive|define
name|SIG_SETMASK
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIG_BLOCK */
end_comment

begin_comment
comment|/* Type of a signal set. */
end_comment

begin_define
define|#
directive|define
name|sigset_t
value|int
end_define

begin_comment
comment|/* Make sure there is nothing inside the signal set. */
end_comment

begin_define
define|#
directive|define
name|sigemptyset
parameter_list|(
name|set
parameter_list|)
value|(*(set) = 0)
end_define

begin_comment
comment|/* Add SIG to the contents of SET. */
end_comment

begin_define
define|#
directive|define
name|sigaddset
parameter_list|(
name|set
parameter_list|,
name|sig
parameter_list|)
value|*(set) |= sigmask (sig)
end_define

begin_comment
comment|/* Suspend the process until the reception of one of the signals    not present in SET. */
end_comment

begin_define
define|#
directive|define
name|sigsuspend
parameter_list|(
name|set
parameter_list|)
value|sigpause (*(set))
end_define

begin_comment
comment|/* END of POSIX 1003.1 definitions. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
end_comment

begin_comment
comment|/* These definitions are used both in POSIX and non-POSIX implementations. */
end_comment

begin_define
define|#
directive|define
name|BLOCK_SIGNAL
parameter_list|(
name|sig
parameter_list|,
name|nvar
parameter_list|,
name|ovar
parameter_list|)
define|\
value|sigemptyset (&nvar); \   sigaddset (&nvar, sig); \   sigemptyset (&ovar); \   sigprocmask (SIG_BLOCK,&nvar,&ovar)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
end_if

begin_define
define|#
directive|define
name|BLOCK_CHILD
parameter_list|(
name|nvar
parameter_list|,
name|ovar
parameter_list|)
value|BLOCK_SIGNAL (SIGCHLD, nvar, ovar)
end_define

begin_define
define|#
directive|define
name|UNBLOCK_CHILD
parameter_list|(
name|ovar
parameter_list|)
value|sigprocmask (SIG_SETMASK,&ovar, (sigset_t *) NULL)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_POSIX_VERSION */
end_comment

begin_define
define|#
directive|define
name|BLOCK_CHILD
parameter_list|(
name|nvar
parameter_list|,
name|ovar
parameter_list|)
value|ovar = sigblock (sigmask (SIGCHLD))
end_define

begin_define
define|#
directive|define
name|UNBLOCK_CHILD
parameter_list|(
name|ovar
parameter_list|)
value|sigsetmask (ovar)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_VERSION */
end_comment

begin_comment
comment|/* System calls. */
end_comment

begin_decl_stmt
specifier|extern
name|pid_t
name|fork
argument_list|()
decl_stmt|,
name|getpid
argument_list|()
decl_stmt|,
name|getpgrp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stuff from the jobs.c file. */
end_comment

begin_decl_stmt
specifier|extern
name|pid_t
name|original_pgrp
decl_stmt|,
name|shell_pgrp
decl_stmt|,
name|pipeline_pgrp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pid_t
name|last_made_pid
decl_stmt|,
name|last_asynchronous_pid
decl_stmt|,
name|make_child
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_job
decl_stmt|,
name|previous_job
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|asynchronous_notification
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|JOB
modifier|*
modifier|*
name|jobs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|job_slots
decl_stmt|;
end_decl_stmt

end_unit

