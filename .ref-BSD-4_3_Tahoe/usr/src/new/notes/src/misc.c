begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* signal processing */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SIGCHLD
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_comment
comment|/* for child status */
end_comment

begin_endif
endif|#
directive|endif
endif|SIGCHLD
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: misc.c,v 1.7.0.5 85/10/06 01:41:01 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_define
define|#
directive|define
name|LOCKTRY
value|10
end_define

begin_comment
comment|/* number of shots at grabbing */
end_comment

begin_define
define|#
directive|define
name|FORKTRY
value|10
end_define

begin_comment
comment|/* tries at forking */
end_comment

begin_comment
comment|/*  * dounix(charstring, flag) will execute that character string as a shell command  * stolen from shell, though this one catches more signals.  *  *	Depending on the RUNSUID flag the routine sets things back to  *	the users group or uid. Early versions were setuid and newer  *	versions only run setgid.  Don't get confused by the "hisuid"  *	argument: it really means "reset to his permissions".  *	R. Kolstad -- 11/2/80  *	modified: R. Essick January 1982, to clean up some signal processing  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|int
name|kidpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* passed by kidwatch() */
end_comment

begin_decl_stmt
specifier|static
name|union
name|wait
name|kidstatus
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|defined(SIGCHLD)
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FASTFORK
end_ifndef

begin_macro
name|dounix
argument_list|(
argument|linebuf
argument_list|,
argument|hisuid
argument_list|,
argument|ttymode
argument_list|)
end_macro

begin_decl_stmt
name|char
name|linebuf
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|dounix
argument_list|(
argument|hisuid
argument_list|,
argument|ttymode
argument_list|,
argument|arg0
argument_list|,
argument|arg1
argument_list|,
argument|arg2
argument_list|,
argument|arg3
argument_list|,
argument|arg4
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg0
decl_stmt|,
modifier|*
name|arg1
decl_stmt|,
modifier|*
name|arg2
decl_stmt|,
modifier|*
name|arg3
decl_stmt|,
modifier|*
name|arg4
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|pid
operator|,
name|forktry
operator|,
name|rpid
expr_stmt|;
name|int
argument_list|(
operator|*
name|p
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|q
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|r
argument_list|)
argument_list|()
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
name|int
function_decl|(
modifier|*
name|s
function_decl|)
parameter_list|()
function_decl|;
endif|#
directive|endif
endif|defined(SIGTSTP)
if|#
directive|if
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
name|int
function_decl|(
modifier|*
name|t
function_decl|)
parameter_list|()
function_decl|;
specifier|extern
name|int
name|watchkid
parameter_list|()
function_decl|;
comment|/* catch stopped kids */
endif|#
directive|endif
endif|defined(SIGCHLD)
name|int
name|retcode
decl_stmt|;
if|if
condition|(
name|ttymode
condition|)
name|ttystop
argument_list|()
expr_stmt|;
comment|/* give back to normal mode */
name|pid
operator|=
literal|0
expr_stmt|;
comment|/* satisfy init conditions */
name|forktry
operator|=
literal|0
expr_stmt|;
comment|/* init the counter */
while|while
condition|(
name|pid
operator|<=
literal|0
operator|&&
operator|++
name|forktry
operator|<
name|FORKTRY
condition|)
block|{
if|if
condition|(
operator|(
name|pid
operator|=
name|fork
argument_list|()
operator|)
operator|==
literal|0
condition|)
block|{
name|uncatchem
argument_list|()
expr_stmt|;
comment|/* reset this process signals */
comment|/* if user can get his hands on it */
if|if
condition|(
name|hisuid
condition|)
comment|/* only set uid if giving shell */
ifdef|#
directive|ifdef
name|RUNSUID
name|setuid
argument_list|(
name|globuid
argument_list|)
expr_stmt|;
comment|/* give him his uid */
else|#
directive|else
name|setgid
argument_list|(
name|getgid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* his group */
endif|#
directive|endif
endif|RUNSUID
for|for
control|(
name|rpid
operator|=
literal|3
init|;
name|rpid
operator|<
name|NOFILE
condition|;
name|rpid
operator|++
control|)
comment|/* close extra files */
name|close
argument_list|(
name|rpid
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|FASTFORK
if|if
condition|(
name|linebuf
operator|==
literal|0
condition|)
name|execl
argument_list|(
name|hisshell
argument_list|,
name|hisshell
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|execl
argument_list|(
name|DFLTSH
argument_list|,
literal|"sh"
argument_list|,
literal|"-c"
argument_list|,
name|linebuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Rats -- Couldn't load %s\n"
argument_list|,
name|DFLTSH
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|arg0
operator|==
literal|0
condition|)
name|execlp
argument_list|(
name|hisshell
argument_list|,
name|hisshell
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|execlp
argument_list|(
name|arg0
argument_list|,
name|arg0
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Rats - Couldn't load %s\n"
argument_list|,
name|arg0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|_exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
comment|/* if exec fails .. */
block|}
if|if
condition|(
name|pid
operator|<=
literal|0
condition|)
comment|/* if fork failed */
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* wait a bit */
block|}
if|if
condition|(
name|pid
operator|>
literal|0
condition|)
comment|/* only if have son */
block|{
name|p
operator|=
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|q
operator|=
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|r
operator|=
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
name|s
operator|=
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|defined(SIGTSTP)
if|#
directive|if
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
name|t
operator|=
name|signal
argument_list|(
name|SIGCHLD
argument_list|,
name|watchkid
argument_list|)
expr_stmt|;
comment|/* if he signals */
endif|#
directive|endif
endif|defined(SIGCHLD)
while|while
condition|(
operator|(
name|rpid
operator|=
name|wait
argument_list|(
operator|&
name|retcode
argument_list|)
operator|)
operator|!=
name|pid
operator|&&
name|rpid
operator|!=
operator|-
literal|1
condition|)
empty_stmt|;
if|if
condition|(
name|rpid
operator|==
operator|-
literal|1
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
comment|/*  *	watchkid() might have sucked down the status of the terminated  *	child, so we load whatever value it left for us in kidstatus  *	(provided that kidpid was ok)  */
if|if
condition|(
name|pid
operator|==
name|kidpid
condition|)
comment|/* the one we wanted */
name|retcode
operator|=
name|kidstatus
operator|.
name|w_status
expr_stmt|;
comment|/* from watchkid() */
else|else
name|retcode
operator|=
literal|1
operator|<<
literal|8
expr_stmt|;
comment|/* make an error */
else|#
directive|else
comment|/*  *	normal case, if the wait() failed for some reason we say that it  *	is an error.  */
name|retcode
operator|=
literal|1
operator|<<
literal|8
expr_stmt|;
comment|/* indicates error  */
endif|#
directive|endif
endif|defined(SIGCHLD)
block|}
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|q
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|r
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|defined(SIGTSTP)
if|#
directive|if
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
name|signal
argument_list|(
name|SIGCHLD
argument_list|,
name|t
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|defined(SIGCHLD)
block|}
else|else
name|retcode
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* some sort of error */
if|if
condition|(
name|ttymode
condition|)
name|ttystrt
argument_list|()
expr_stmt|;
comment|/* back into raw mode */
return|return
name|retcode
operator|>>
literal|8
return|;
comment|/* hand him the completion code */
block|}
end_block

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
end_if

begin_comment
comment|/*  *	watchkid()  *  *	called when we receive a SIGCHLD signal, indicating that a child's  *	status has changed.  This routine looks via wait3() to see if  *	the children have merely been suspended.  If so, it stops itself  *	so that it's parent can decide what to do.  *  *	This catches problems with programs like vi which run in raw mode  *	and catch ^z as a character. They later try to signal the entire  *	process group but are unable to signal the notes process since it  *	has a different effective uid. By watching the SIGCHLD signal, we  *	get notification when the vi process has stopped and we can stop  *	ourselves.   *				Ray Essick,	Augst 22, 1984  */
end_comment

begin_function
specifier|static
name|int
name|watchkid
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
name|kidpid
operator|=
name|wait3
argument_list|(
operator|&
name|kidstatus
argument_list|,
name|WUNTRACED
operator||
name|WNOHANG
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* get status */
if|if
condition|(
name|kidpid
operator|==
literal|0
condition|)
comment|/* nothing to report */
return|return
literal|0
return|;
comment|/* get out */
if|if
condition|(
name|kidpid
operator|==
operator|(
operator|-
literal|1
operator|)
condition|)
comment|/* no children at all */
return|return
literal|0
return|;
comment|/* get out */
if|if
condition|(
name|WIFSTOPPED
argument_list|(
name|kidstatus
argument_list|)
condition|)
comment|/* stopped himself */
block|{
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGTSTP
argument_list|)
expr_stmt|;
comment|/* stop myself */
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
endif|defined(SIGCHLD)
end_endif

begin_comment
comment|/*  *	If the condition is TRUE (non-zero) abort the program.  *  *	Print the supplied message and halt.  *	Leave an optional core dump for debugging later.  *  *	Ray Essick 10/23/80  */
end_comment

begin_macro
name|x
argument_list|(
argument|cond
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|cond
operator|==
literal|0
condition|)
return|return;
comment|/* didnt fail */
name|perror
argument_list|(
literal|"notes"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Fatal Internal Notesfile Error: %s\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|ttystop
argument_list|()
expr_stmt|;
comment|/* back to normal */
ifdef|#
directive|ifdef
name|DUMPCORE
if|if
condition|(
name|chdir
argument_list|(
name|Mstdir
argument_list|)
operator|<
literal|0
condition|)
comment|/* go to known place */
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
comment|/* drop out */
if|if
condition|(
name|chdir
argument_list|(
name|UTILITY
argument_list|)
operator|<
literal|0
condition|)
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
comment|/* drop out */
if|if
condition|(
name|chdir
argument_list|(
name|DUMPCORE
argument_list|)
operator|<
literal|0
condition|)
comment|/* writeable to all */
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
comment|/* drop out */
ifdef|#
directive|ifdef
name|RUNSUID
name|setuid
argument_list|(
name|globuid
argument_list|)
expr_stmt|;
comment|/* won't dump if euid != uid */
else|#
directive|else
name|setgid
argument_list|(
name|getgid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* no gift groups */
endif|#
directive|endif
endif|RUNSUID
endif|#
directive|endif
endif|DUMPCORE
ifdef|#
directive|ifdef
name|NFMAINT
comment|/*  *	This code is kind of risky.  If the NFMAINT notesfile ever  *	gets trashed and starts calling this routine, look out because  *	it will recursively fail. This is the unfortunate byproduct  *	of the fact that the "x" routine doesn't know what the   *	current notesfile is.  */
block|{
name|char
name|pbuf
index|[
literal|512
index|]
decl_stmt|;
comment|/* hold message */
name|char
name|pbuf2
index|[
literal|128
index|]
decl_stmt|;
comment|/* and title */
name|char
name|pbuf3
index|[
literal|256
index|]
decl_stmt|;
comment|/* core image */
name|char
modifier|*
name|tail
decl_stmt|;
comment|/* end of invocation */
name|sprintf
argument_list|(
name|pbuf2
argument_list|,
literal|"%s: aborted"
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|pbuf
argument_list|,
literal|"Program:\t%s\nMessage:\t%s\n\nerrno:\t\t%d  (%s)\n"
argument_list|,
name|Invokedas
argument_list|,
name|p
argument_list|,
name|errno
argument_list|,
name|errno
operator|>=
name|sys_nerr
condition|?
literal|"Unknown error code"
else|:
name|sys_errlist
index|[
name|errno
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DUMPCORE
if|if
condition|(
operator|(
name|tail
operator|=
name|rindex
argument_list|(
name|Invokedas
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|==
name|NULL
condition|)
comment|/* pathname? */
name|tail
operator|=
name|Invokedas
expr_stmt|;
comment|/* simple invocation */
else|else
name|tail
operator|++
expr_stmt|;
comment|/* strip the slash */
name|sprintf
argument_list|(
name|pbuf3
argument_list|,
literal|"%s/%s/%s/%s"
argument_list|,
name|Mstdir
argument_list|,
name|UTILITY
argument_list|,
name|DUMPCORE
argument_list|,
name|tail
argument_list|)
expr_stmt|;
name|nfabort
argument_list|(
name|NFMAINT
argument_list|,
name|pbuf
argument_list|,
name|pbuf2
argument_list|,
name|pbuf3
argument_list|,
name|BAD
argument_list|)
expr_stmt|;
comment|/* log& abort */
else|#
directive|else
else|! DUMPCORE
name|nfcomment
argument_list|(
name|NFMAINT
argument_list|,
name|pbuf
argument_list|,
name|pbuf2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* actual insertion */
endif|#
directive|endif
endif|DUMPCORE
block|}
endif|#
directive|endif
endif|NFMAINT
comment|/*  *	Handle the exit if NFMAINT is undefined.  */
ifdef|#
directive|ifdef
name|DUMPCORE
name|abort
argument_list|()
expr_stmt|;
comment|/* dump in "core" */
else|#
directive|else
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
comment|/* for production */
endif|#
directive|endif
endif|DUMPCORE
block|}
end_block

begin_comment
comment|/*  *	lock creates a lock file, or waits until it can create the lock.  *	lock files are of the form lock#  where # is a character passed  *	to the routine.  *  *	Rob Kolstad	10/20/80  *	modified: rbe December 1981 to add full path name for lock file   */
end_comment

begin_macro
name|locknf
argument_list|(
argument|io
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|io_f
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|holderr
decl_stmt|,
name|trys
decl_stmt|;
name|char
name|p
index|[
name|WDLEN
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|p
argument_list|,
literal|"%s/%s/%c%s"
argument_list|,
name|Mstdir
argument_list|,
name|LOCKS
argument_list|,
name|c
argument_list|,
name|io
operator|->
name|nf
argument_list|)
expr_stmt|;
comment|/* generate file name */
name|trys
operator|=
name|LOCKTRY
expr_stmt|;
comment|/* set him up */
while|while
condition|(
operator|(
name|i
operator|=
name|creat
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|trys
operator|--
operator|==
literal|0
condition|)
block|{
name|holderr
operator|=
name|errno
expr_stmt|;
comment|/* before it's abused */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"lock %c (%s) permanently locked - consult a guru\n"
argument_list|,
name|c
argument_list|,
name|io
operator|->
name|nf
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NFMAINT
if|if
condition|(
name|strcmp
argument_list|(
name|NFMAINT
argument_list|,
name|io
operator|->
name|nf
argument_list|)
condition|)
comment|/* avoid loops */
block|{
name|char
name|pbuf
index|[
literal|256
index|]
decl_stmt|;
comment|/* for error logging */
name|char
name|tbuf
index|[
literal|256
index|]
decl_stmt|;
comment|/* title */
name|sprintf
argument_list|(
name|pbuf
argument_list|,
literal|"lock %c failed for %s,\nerrno = %d (%s)\nProgram = %s\n"
argument_list|,
name|c
argument_list|,
name|io
operator|->
name|fullname
argument_list|,
name|holderr
argument_list|,
name|sys_errlist
index|[
name|holderr
index|]
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|tbuf
argument_list|,
literal|"%s: locked (%c)"
argument_list|,
name|io
operator|->
name|nf
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|nfcomment
argument_list|(
name|NFMAINT
argument_list|,
name|pbuf
argument_list|,
name|tbuf
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|NFMAINT
name|ttystop
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* guarantee at least 1 */
block|}
name|ignoresigs
operator|++
expr_stmt|;
comment|/* critical section */
comment|/*  *	could be above getting the lock, but wanted to be able to suspend  *	while getting the lock.  The interuptable window is very small  */
name|close
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	unlock takes the same arguements as the lock routine, and it  *	will remove the corresponding lock file  *  *	Rob Kolstad 10/20/80  *	modified: rbe December 1981 to add full path name for lock name  */
end_comment

begin_macro
name|unlocknf
argument_list|(
argument|io
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|io_f
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|p
index|[
name|WDLEN
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|p
argument_list|,
literal|"%s/%s/%c%s"
argument_list|,
name|Mstdir
argument_list|,
name|LOCKS
argument_list|,
name|c
argument_list|,
name|io
operator|->
name|nf
argument_list|)
expr_stmt|;
comment|/* generate file name */
name|x
argument_list|(
name|unlink
argument_list|(
name|p
argument_list|)
operator|<
literal|0
argument_list|,
literal|"unlock: unlink lock"
argument_list|)
expr_stmt|;
name|ignoresigs
operator|--
expr_stmt|;
comment|/* no longer critical */
block|}
end_block

begin_comment
comment|/*  *	glock creates a lock file, or waits until it can create the lock.  *	lock files are of the form lock#  where # is a character passed  *	to the routine.  *		This lock file is a GLOBAL lock - across all notefiles  *  *	taken from lock routine above by R. Essick December 1981  */
end_comment

begin_macro
name|glocknf
argument_list|(
argument|io
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|io_f
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unused in this routine */
end_comment

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|holderr
decl_stmt|,
name|trys
decl_stmt|;
name|char
name|p
index|[
name|WDLEN
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|p
argument_list|,
literal|"%s/%s/%c"
argument_list|,
name|Mstdir
argument_list|,
name|LOCKS
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|/* generate file name */
name|trys
operator|=
name|LOCKTRY
expr_stmt|;
while|while
condition|(
operator|(
name|i
operator|=
name|creat
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|trys
operator|--
operator|==
literal|0
condition|)
block|{
name|holderr
operator|=
name|errno
expr_stmt|;
comment|/* before it's abused */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"lock%c combo lost - consult your local guru\n"
argument_list|,
name|c
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NFMAINT
if|if
condition|(
name|strcmp
argument_list|(
name|NFMAINT
argument_list|,
name|io
operator|->
name|nf
argument_list|)
condition|)
comment|/* don't loop on self */
block|{
name|char
name|pbuf
index|[
literal|256
index|]
decl_stmt|;
comment|/* for error logging */
name|char
name|pbuf2
index|[
literal|256
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|pbuf
argument_list|,
literal|"glock %c failed for %s, errno = %d (%s)\nProgram = %s\n"
argument_list|,
name|c
argument_list|,
name|io
operator|->
name|fullname
argument_list|,
name|holderr
argument_list|,
name|sys_errlist
index|[
name|holderr
index|]
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|pbuf2
argument_list|,
literal|"Frozen Global Lock (%c)"
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|nfcomment
argument_list|(
name|NFMAINT
argument_list|,
name|pbuf
argument_list|,
name|pbuf2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|NFMAINT
name|ttystop
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* is there a smaller time interval */
block|}
name|close
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	gunlock takes the same arguements as the lock routine, and it  *	will remove the corresponding lock file  *		This is GLOBAL locking - across all notefiles  *  *	copy of code from unlock, with minor changes  *	Ray Essick	December 1981  */
end_comment

begin_macro
name|gunlocknf
argument_list|(
argument|io
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|io_f
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* not used by this routine */
end_comment

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|p
index|[
name|WDLEN
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|p
argument_list|,
literal|"%s/%s/%c"
argument_list|,
name|Mstdir
argument_list|,
name|LOCKS
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|/* make the file name */
name|x
argument_list|(
name|unlink
argument_list|(
name|p
argument_list|)
operator|<
literal|0
argument_list|,
literal|"gunlock: unlink lock"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * length tells us max(length of string, 1)  */
end_comment

begin_macro
name|len
argument_list|(
argument|p
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
name|n
expr_stmt|;
name|p
operator|+=
name|n
expr_stmt|;
while|while
condition|(
operator|*
operator|--
name|p
operator|==
literal|' '
operator|&&
operator|--
name|i
condition|)
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|i
operator|=
literal|1
expr_stmt|;
return|return
name|i
return|;
block|}
end_block

begin_comment
comment|/*  *	shell - give the user a shell  *	this includes:  *	1) changing to the directory where he came in from  *	2) giving him a shell  *	3) return to the notefile directory  *  *	original author: Ray Essick may 29, 1981  *  */
end_comment

begin_macro
name|gshell
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|FASTFORK
name|dounix
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* give him his shell */
else|#
directive|else
name|dounix
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_block

begin_comment
comment|/*	copydate merely moves a when_f structure from 'from' to 'to' */
end_comment

begin_comment
comment|/*	ray essick - 20-nov-1981	*/
end_comment

begin_macro
name|copydate
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|when_f
modifier|*
name|from
decl_stmt|,
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|to
operator|=
operator|*
name|from
expr_stmt|;
comment|/* use block move */
block|}
end_block

begin_comment
comment|/*	strmove - copy a null terminated string to another */
end_comment

begin_comment
comment|/*	returns the count of characters moved, this count includes the */
end_comment

begin_comment
comment|/*	null terminator.. */
end_comment

begin_comment
comment|/*	r. essick 20-nov-81 */
end_comment

begin_macro
name|strmove
argument_list|(
argument|p
argument_list|,
argument|q
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from p to q */
end_comment

begin_block
block|{
name|int
name|count
decl_stmt|;
specifier|register
name|char
modifier|*
name|pp
decl_stmt|,
modifier|*
name|qq
decl_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
comment|/* start with no characters moved */
name|pp
operator|=
name|p
expr_stmt|;
name|qq
operator|=
name|q
expr_stmt|;
comment|/* use registers for speed */
while|while
condition|(
operator|*
name|qq
operator|++
operator|=
operator|*
name|pp
operator|++
condition|)
name|count
operator|++
expr_stmt|;
return|return
name|count
return|;
comment|/* return count of characters moved */
comment|/* don't include the terminator */
block|}
end_block

begin_comment
comment|/*	copyauth(from, to) struct auth_f *from,*auth  *	copys author from from to to  *	Ray Essick December 1981  *  *	SHOULD USE STRUCTURE ASSIGNMENT IN ALL PLACES THAT CALL THIS  */
end_comment

begin_macro
name|copyauth
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|auth_f
modifier|*
name|from
decl_stmt|,
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|strncpy
argument_list|(
name|to
operator|->
name|aname
argument_list|,
name|from
operator|->
name|aname
argument_list|,
name|NAMESZ
argument_list|)
expr_stmt|;
comment|/* author name */
name|strncpy
argument_list|(
name|to
operator|->
name|asystem
argument_list|,
name|from
operator|->
name|asystem
argument_list|,
name|HOMESYSSZ
argument_list|)
expr_stmt|;
comment|/* home machine */
name|to
operator|->
name|aid
operator|=
name|from
operator|->
name|aid
expr_stmt|;
comment|/* and user id */
block|}
end_block

begin_comment
comment|/*	listget, listconv - parse a list of numbers.   *	this is all taken ( sort of ) from Rob Kolstad's getpg  *	program   */
end_comment

begin_macro
name|listget
argument_list|(
argument|buf
argument_list|,
argument|ptr
argument_list|,
argument|start
argument_list|,
argument|finish
argument_list|)
end_macro

begin_decl_stmt
name|char
name|buf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|ptr
decl_stmt|,
modifier|*
name|start
decl_stmt|,
modifier|*
name|finish
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|(
name|buf
index|[
operator|*
name|ptr
index|]
operator|<
literal|'0'
operator|||
name|buf
index|[
operator|*
name|ptr
index|]
operator|>
literal|'9'
operator|)
operator|&&
name|buf
index|[
operator|*
name|ptr
index|]
operator|!=
literal|' '
condition|)
block|{
return|return
literal|0
return|;
comment|/* end of this list */
block|}
operator|*
name|start
operator|=
name|listconv
argument_list|(
name|buf
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
comment|/* get the first */
operator|*
name|finish
operator|=
operator|*
name|start
expr_stmt|;
comment|/* default to single */
if|if
condition|(
name|buf
index|[
operator|*
name|ptr
index|]
operator|==
literal|'-'
condition|)
block|{
operator|++
operator|(
operator|*
name|ptr
operator|)
expr_stmt|;
comment|/* trash that separator */
operator|*
name|finish
operator|=
name|listconv
argument_list|(
name|buf
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
comment|/* grab second */
operator|++
operator|(
operator|*
name|ptr
operator|)
expr_stmt|;
comment|/* bump past delimiter */
return|return
literal|2
return|;
comment|/* parsed 2 arguements */
block|}
else|else
block|{
if|if
condition|(
name|buf
index|[
operator|*
name|ptr
index|]
operator|!=
literal|'\0'
condition|)
operator|++
operator|(
operator|*
name|ptr
operator|)
expr_stmt|;
comment|/* dump delimiter */
return|return
literal|1
return|;
block|}
block|}
end_block

begin_macro
name|listconv
argument_list|(
argument|buf
argument_list|,
argument|ptr
argument_list|)
end_macro

begin_decl_stmt
name|char
name|buf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|buf
index|[
operator|*
name|ptr
index|]
operator|==
literal|' '
condition|)
operator|++
operator|(
operator|*
name|ptr
operator|)
expr_stmt|;
while|while
condition|(
name|buf
index|[
operator|*
name|ptr
index|]
operator|>=
literal|'0'
operator|&&
name|buf
index|[
operator|*
name|ptr
index|]
operator|<=
literal|'9'
condition|)
block|{
name|i
operator|=
literal|10
operator|*
name|i
operator|+
name|buf
index|[
operator|*
name|ptr
index|]
operator|-
literal|'0'
expr_stmt|;
operator|++
operator|(
operator|*
name|ptr
operator|)
expr_stmt|;
comment|/* bump him */
block|}
return|return
operator|(
name|i
operator|)
return|;
block|}
end_block

begin_comment
comment|/*	tolcase - check to see if upper case, and convert to lcase */
end_comment

begin_comment
comment|/*	R. Essick	Feb 1982 */
end_comment

begin_macro
name|tolcase
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|isascii
argument_list|(
name|c
argument_list|)
operator|&&
name|isupper
argument_list|(
name|c
argument_list|)
condition|)
return|return
operator|(
name|tolower
argument_list|(
name|c
argument_list|)
operator|)
return|;
comment|/* to lower case */
return|return
operator|(
name|c
operator|)
return|;
comment|/* leave as is */
block|}
end_block

begin_comment
comment|/*  *	Date printing stuff.  *  *	CHANGE TO CTIME(III) FORMAT EVENTUALLY  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mnames
index|[
literal|13
index|]
init|=
comment|/* so indexes work right */
block|{
literal|"???"
block|,
literal|"Jan"
block|,
literal|"Feb"
block|,
literal|"Mar"
block|,
literal|"Apr"
block|,
literal|"May"
block|,
literal|"Jun"
block|,
literal|"Jul"
block|,
literal|"Aug"
block|,
literal|"Sep"
block|,
literal|"Oct"
block|,
literal|"Nov"
block|,
literal|"Dec"
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|sprdate
argument_list|(
argument|w
argument_list|,
argument|str
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|when_f
modifier|*
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|m
decl_stmt|;
name|int
name|h
decl_stmt|,
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|/* temps to print 0's or funny strings */
name|m
operator|=
literal|"am"
expr_stmt|;
name|h
operator|=
name|w
operator|->
name|w_hours
expr_stmt|;
if|if
condition|(
name|h
operator|>=
literal|12
condition|)
name|m
operator|=
literal|"pm"
expr_stmt|;
if|if
condition|(
name|h
operator|==
literal|0
condition|)
name|h
operator|=
literal|12
expr_stmt|;
if|if
condition|(
name|h
operator|>
literal|12
condition|)
name|h
operator|-=
literal|12
expr_stmt|;
name|i
operator|=
name|w
operator|->
name|w_mins
operator|/
literal|10
expr_stmt|;
name|j
operator|=
name|w
operator|->
name|w_mins
operator|%
literal|10
expr_stmt|;
comment|/* get those leading zeroes */
name|sprintf
argument_list|(
name|str
argument_list|,
literal|"%2d:%d%d %2s  %3s %2d, %4d"
argument_list|,
name|h
argument_list|,
name|i
argument_list|,
name|j
argument_list|,
name|m
argument_list|,
name|mnames
index|[
name|w
operator|->
name|w_month
index|]
argument_list|,
name|w
operator|->
name|w_day
argument_list|,
name|w
operator|->
name|w_year
argument_list|)
expr_stmt|;
comment|/* sprintf puts it into a string */
block|}
end_block

begin_macro
name|prdate
argument_list|(
argument|zdate
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|when_f
modifier|*
name|zdate
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|line
index|[
name|DATELEN
index|]
decl_stmt|;
name|sprdate
argument_list|(
name|zdate
argument_list|,
name|line
argument_list|)
expr_stmt|;
comment|/* format it */
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|line
argument_list|)
expr_stmt|;
comment|/* and print it */
block|}
end_block

begin_comment
comment|/*  *	Saves a string with malloc() and returns a pointer  *	to where it wound up.  Useful for building lists of  *	stuff.  *  *	Courtesy of Lou Salkind& Rick Spickelmier.  */
end_comment

begin_function
name|char
modifier|*
name|strsave
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
name|p
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|s
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|p
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	substr(a,b)	see if A is a substring of B  *  *	uses: strlen.  */
end_comment

begin_macro
name|substr
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
name|first
decl_stmt|;
specifier|register
name|int
name|length
decl_stmt|;
comment|/* length of a */
specifier|register
name|int
name|count
decl_stmt|;
comment|/* max checks */
name|first
operator|=
operator|*
name|a
expr_stmt|;
comment|/* get first */
name|length
operator|=
name|strlen
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* for strncmp */
name|count
operator|=
name|strlen
argument_list|(
name|b
argument_list|)
operator|-
name|length
operator|+
literal|1
expr_stmt|;
comment|/* max checks */
while|while
condition|(
name|count
operator|--
operator|>
literal|0
condition|)
comment|/* can try */
block|{
if|if
condition|(
operator|*
name|b
operator|==
name|first
operator|&&
operator|!
name|strncmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|length
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* is a substring */
name|b
operator|++
expr_stmt|;
comment|/* on to next */
block|}
return|return
operator|(
literal|0
operator|)
return|;
comment|/* not a substring */
block|}
end_block

begin_comment
comment|/*  *	routine to process a string and remove any  *	nasties like control characters and escape codes.  */
end_comment

begin_function
name|int
name|strclean
parameter_list|(
name|p
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
block|{
if|if
condition|(
name|p
operator|==
operator|(
name|char
operator|*
operator|)
name|NULL
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
return|return
literal|0
return|;
do|do
block|{
if|if
condition|(
operator|!
name|isascii
argument_list|(
operator|*
name|p
argument_list|)
operator|||
name|iscntrl
argument_list|(
operator|*
name|p
argument_list|)
condition|)
operator|*
name|p
operator|=
literal|'_'
expr_stmt|;
comment|/* kill controls */
block|}
do|while
condition|(
operator|*
operator|++
name|p
operator|!=
literal|'\0'
condition|)
do|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

