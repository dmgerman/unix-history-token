begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: amd.c,v 5.2 90/06/23 22:19:18 jsp Rel $  *  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)amd.c	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Automounter  */
end_comment

begin_include
include|#
directive|include
file|"am.h"
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|char
name|pid_fsname
index|[
literal|16
operator|+
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "kiska.southseas.nz:(pid%d)" */
end_comment

begin_decl_stmt
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "amd" */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_HOST
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|host_helper
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_HOST */
end_comment

begin_decl_stmt
name|char
modifier|*
name|auto_dir
init|=
literal|"/a"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hostdomain
init|=
literal|"unknown.domain"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hostname */
end_comment

begin_decl_stmt
name|char
name|hostd
index|[
literal|2
operator|*
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Host+domain */
end_comment

begin_decl_stmt
name|char
modifier|*
name|op_sys
init|=
name|OS_REP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of current op_sys */
end_comment

begin_decl_stmt
name|char
modifier|*
name|arch
init|=
name|ARCH_REP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of current architecture */
end_comment

begin_decl_stmt
name|char
modifier|*
name|endian
init|=
name|ARCH_ENDIAN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Big or Little endian */
end_comment

begin_decl_stmt
name|int
name|foreground
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the top-level server */
end_comment

begin_decl_stmt
name|int
name|mypid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current process id */
end_comment

begin_decl_stmt
name|int
name|immediate_abort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should close-down unmounts be retried */
end_comment

begin_decl_stmt
name|struct
name|in_addr
name|myipaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (An) IP address of this host */
end_comment

begin_decl_stmt
name|serv_state
name|amd_state
init|=
name|Start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|amd_stats
name|amd_stats
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Server statistics */
end_comment

begin_decl_stmt
name|time_t
name|do_mapc_reload
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mapc_reload() call required? */
end_comment

begin_decl_stmt
name|jmp_buf
name|select_intr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|select_intr_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|orig_umask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Signal handler:  * SIGINT - tells amd to do a full shutdown, including unmounting all filesystem.  * SIGTERM - tells amd to shutdown now.  Just unmounts the automount nodes.  */
end_comment

begin_function
specifier|static
name|void
name|sigterm
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|SYS5_SIGNALS
name|signal
argument_list|(
name|sig
argument_list|,
name|sigterm
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|* SYS5_SIGNALS */
switch|switch
condition|(
name|sig
condition|)
block|{
case|case
name|SIGINT
case|:
name|immediate_abort
operator|=
literal|15
expr_stmt|;
break|break;
case|case
name|SIGTERM
case|:
name|immediate_abort
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* fall through... */
default|default:
name|plog
argument_list|(
name|XLOG_WARNING
argument_list|,
literal|"WARNING: automounter going down on signal %d"
argument_list|,
name|sig
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|select_intr_valid
condition|)
name|longjmp
argument_list|(
name|select_intr
argument_list|,
name|sig
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Hook for cache reload.  * When a SIGHUP arrives it schedules a call to mapc_reload  */
end_comment

begin_function
specifier|static
name|void
name|sighup
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|SYS5_SIGNALS
name|signal
argument_list|(
name|sig
argument_list|,
name|sighup
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SUS5_SIGNALS */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|sig
operator|!=
name|SIGHUP
condition|)
name|dlog
argument_list|(
literal|"spurious call to sighup"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
comment|/* 	 * Force a reload by zero'ing the timer 	 */
if|if
condition|(
name|amd_state
operator|==
name|Run
condition|)
name|do_mapc_reload
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|parent_exit
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|daemon_mode
parameter_list|(
name|P_void
parameter_list|)
block|{
name|int
name|bgpid
init|=
name|background
argument_list|()
decl_stmt|;
if|if
condition|(
name|bgpid
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|print_pid
condition|)
block|{
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|bgpid
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
comment|/* 		 * Now wait for the automount points to 		 * complete. 		 */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|parent_exit
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
name|pause
argument_list|()
expr_stmt|;
block|}
comment|/* 	 * Pretend we are in the foreground again 	 */
name|foreground
operator|=
literal|1
expr_stmt|;
ifdef|#
directive|ifdef
name|TIOCNOTTY
block|{
name|int
name|t
init|=
name|open
argument_list|(
literal|"/dev/tty"
argument_list|,
name|O_RDWR
argument_list|)
decl_stmt|;
if|if
condition|(
name|t
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|ENXIO
condition|)
comment|/* not an error if already no controlling tty */
name|plog
argument_list|(
name|XLOG_WARNING
argument_list|,
literal|"Could not open controlling tty: %m"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ioctl
argument_list|(
name|t
argument_list|,
name|TIOCNOTTY
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
name|plog
argument_list|(
name|XLOG_WARNING
argument_list|,
literal|"Could not disassociate tty (TIOCNOTTY): %m"
argument_list|)
expr_stmt|;
block|}
block|}
else|#
directive|else
operator|(
name|void
operator|)
name|setpgrp
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* TIOCNOTTY */
return|return
name|getppid
argument_list|()
return|;
block|}
end_function

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|,
modifier|*
name|gethostbyname
argument_list|()
decl_stmt|;
name|char
modifier|*
name|domdot
decl_stmt|;
name|int
name|ppid
init|=
literal|0
decl_stmt|;
name|int
name|error
decl_stmt|;
comment|/* 	 * Make sure some built-in assumptions are true before we start 	 */
name|assert
argument_list|(
sizeof|sizeof
argument_list|(
name|nfscookie
argument_list|)
operator|>=
expr|sizeof
operator|(
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|>=
literal|4
argument_list|)
expr_stmt|;
comment|/* 	 * Set processing status. 	 */
name|amd_state
operator|=
name|Start
expr_stmt|;
comment|/* 	 * Get local machine name 	 */
if|if
condition|(
name|gethostname
argument_list|(
name|hostname
argument_list|,
sizeof|sizeof
argument_list|(
name|hostname
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
name|plog
argument_list|(
name|XLOG_FATAL
argument_list|,
literal|"gethostname: %m"
argument_list|)
expr_stmt|;
name|going_down
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Check it makes sense 	 */
if|if
condition|(
operator|!
operator|*
name|hostname
condition|)
block|{
name|plog
argument_list|(
name|XLOG_FATAL
argument_list|,
literal|"host name is not set"
argument_list|)
expr_stmt|;
name|going_down
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Partially initialise hostd[].  This 	 * is completed in get_args(). 	 */
if|if
condition|(
name|domdot
operator|=
name|strchr
argument_list|(
name|hostname
argument_list|,
literal|'.'
argument_list|)
condition|)
block|{
comment|/* 		 * Hostname already contains domainname. 		 * Split out hostname and domainname 		 * components 		 */
operator|*
name|domdot
operator|++
operator|=
literal|'\0'
expr_stmt|;
name|hostdomain
operator|=
name|domdot
expr_stmt|;
block|}
name|strcpy
argument_list|(
name|hostd
argument_list|,
name|hostname
argument_list|)
expr_stmt|;
comment|/* 	 * Trap interrupts for shutdowns. 	 */
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|sigterm
argument_list|)
expr_stmt|;
comment|/* 	 * Hangups tell us to reload the cache 	 */
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|sighup
argument_list|)
expr_stmt|;
comment|/* 	 * Trap Terminate so that we can shutdown gracefully (some chance) 	 */
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|sigterm
argument_list|)
expr_stmt|;
comment|/* 	 * Trap Death-of-a-child.  These allow us to 	 * pick up the exit status of backgrounded mounts. 	 * See "sched.c". 	 */
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGCHLD
argument_list|,
name|sigchld
argument_list|)
expr_stmt|;
comment|/* 	 * Initialise process id.  This is kept 	 * cached since it is used for generating 	 * and using file handles. 	 */
name|mypid
operator|=
name|getpid
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|notdef
comment|/*  * XXX - Doing this plugs most of a memory leak in  * gethostbyname on SunOS 4.  I see no good reason  * why the host database needs to grab 1.5K of  * private data space...  However, for the moment,  * I will take its word that it is a _good thing_  * (jsp)  */
operator|(
name|void
operator|)
name|sethostent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* notdef */
comment|/* 	 * Fix-up any umask problems.  Most systems default 	 * to 002 which is not too convenient for our purposes 	 */
name|orig_umask
operator|=
name|umask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * Determine command-line arguments 	 */
name|get_args
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* 	 * Get our own IP address so that we 	 * can mount the automounter.  There 	 * is probably a better way of doing 	 * this, but messing about with SIOCGIFCONF 	 * seems to be heading towards the non-portable 	 * arena. 	 */
name|hp
operator|=
name|gethostbyname
argument_list|(
name|hostname
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hp
operator|||
name|hp
operator|->
name|h_addrtype
operator|!=
name|AF_INET
condition|)
block|{
name|plog
argument_list|(
name|XLOG_FATAL
argument_list|,
literal|"Can't determine IP address of this host (%s)"
argument_list|,
name|hostname
argument_list|)
expr_stmt|;
name|going_down
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|myipaddr
operator|=
operator|*
operator|(
expr|struct
name|in_addr
operator|*
operator|)
name|hp
operator|->
name|h_addr
expr_stmt|;
comment|/* 	 * Now check we are root. 	 */
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|plog
argument_list|(
name|XLOG_FATAL
argument_list|,
literal|"Must be root to mount filesystems (euid = %d)"
argument_list|,
name|geteuid
argument_list|()
argument_list|)
expr_stmt|;
name|going_down
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|HAS_NIS_MAPS
comment|/* 	 * If the domain was specified then bind it here 	 * to circumvent any default bindings that may 	 * be done in the C library. 	 */
if|if
condition|(
name|domain
operator|&&
name|yp_bind
argument_list|(
name|domain
argument_list|)
condition|)
block|{
name|plog
argument_list|(
name|XLOG_FATAL
argument_list|,
literal|"Can't bind to domain \"%s\""
argument_list|,
name|domain
argument_list|)
expr_stmt|;
name|going_down
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* HAS_NIS_MAPS */
ifdef|#
directive|ifdef
name|DEBUG
name|Debug
argument_list|(
argument|D_DAEMON
argument_list|)
endif|#
directive|endif
comment|/* DEBUG */
name|ppid
operator|=
name|daemon_mode
argument_list|()
expr_stmt|;
name|sprintf
argument_list|(
name|pid_fsname
argument_list|,
literal|"%s:(pid%d)"
argument_list|,
name|hostname
argument_list|,
name|mypid
argument_list|)
expr_stmt|;
name|do_mapc_reload
operator|=
name|clocktime
argument_list|()
operator|+
name|ONE_HOUR
expr_stmt|;
comment|/* 	 * Register automounter with system 	 */
name|error
operator|=
name|mount_automounter
argument_list|(
name|ppid
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|&&
name|ppid
condition|)
name|kill
argument_list|(
name|SIGALRM
argument_list|,
name|ppid
argument_list|)
expr_stmt|;
name|going_down
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

