begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/amd/amd.c  *  */
end_comment

begin_comment
comment|/*  * Automounter  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<am_defs.h>
end_include

begin_include
include|#
directive|include
file|<amd.h>
end_include

begin_decl_stmt
name|struct
name|amu_global_options
name|gopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where global options are stored */
end_comment

begin_decl_stmt
name|char
name|pid_fsname
index|[
name|SIZEOF_PID_FSNAME
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "kiska.southseas.nz:(pid%d)" */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hostdomain
init|=
literal|"unknown.domain"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIZEOF_HOSTD
value|(2 * MAXHOSTNAMELEN + 1)
end_define

begin_comment
comment|/* Host+domain */
end_comment

begin_decl_stmt
name|char
name|hostd
index|[
name|SIZEOF_HOSTD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Host+domain */
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
name|char
modifier|*
name|cpu
init|=
name|HOST_CPU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CPU type */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PrimNetName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of primary network */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PrimNetNum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of primary network */
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
name|int
name|orig_umask
init|=
literal|022
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|select_intr_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|select_intr
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
name|struct
name|in_addr
name|myipaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (An) IP address of this host */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
end_ifdef

begin_decl_stmt
name|int
name|amd_use_autofs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_AUTOFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SIGACTION
end_ifdef

begin_decl_stmt
name|sigset_t
name|masked_sigs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIGACTION */
end_comment

begin_comment
comment|/*  * Signal handler:  * SIGINT - tells amd to do a full shutdown, including unmounting all  *       filesystem.  * SIGTERM - tells amd to shutdown now.  Just unmounts the automount nodes.  */
end_comment

begin_function
specifier|static
name|RETSIGTYPE
name|sigterm
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|REINSTALL_SIGNAL_HANDLER
name|signal
argument_list|(
name|sig
argument_list|,
name|sigterm
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* REINSTALL_SIGNAL_HANDLER */
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
name|RETSIGTYPE
name|sighup
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|REINSTALL_SIGNAL_HANDLER
name|signal
argument_list|(
name|sig
argument_list|,
name|sighup
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* REINSTALL_SIGNAL_HANDLER */
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
comment|/*    * Force a reload by zero'ing the timer    */
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
name|RETSIGTYPE
name|parent_exit
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
comment|/*    * This signal handler is called during Amd initialization.  The parent    * forks a child to do all the hard automounting work, and waits for a    * SIGQUIT signal from the child.  When the parent gets the signal it's    * supposed to call this handler and exit(3), thus completing the    * daemonizing process.  Alas, on some systems, especially Linux 2.4/2.6    * with Glibc, exit(3) doesn't always terminate the parent process.    * Worse, the parent process now refuses to accept any more SIGQUIT    * signals -- they are blocked.  What's really annoying is that this    * doesn't happen all the time, suggesting a race condition somewhere.    * (This happens even if I change the logic to use another signal.)  I    * traced this to something which exit(3) does in addition to exiting the    * process, probably some atexit() stuff or other side-effects related to    * signal handling.  Either way, since at this stage the parent process    * just needs to terminate, I'm simply calling _exit(2).  Note also that    * the OpenGroup doesn't list exit(3) as a recommended "Base Interface"    * but they do list _exit(2) as one.  This fix seems to work reliably all    * the time. -Erez (2/27/2005)    */
name|_exit
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
name|void
parameter_list|)
block|{
name|int
name|bgpid
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_SIGACTION
name|struct
name|sigaction
name|sa
decl_stmt|,
name|osa
decl_stmt|;
name|memset
argument_list|(
operator|&
name|sa
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|sa
argument_list|)
argument_list|)
expr_stmt|;
name|sa
operator|.
name|sa_handler
operator|=
name|parent_exit
expr_stmt|;
name|sa
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
operator|(
name|sa
operator|.
name|sa_mask
operator|)
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
operator|(
name|sa
operator|.
name|sa_mask
operator|)
argument_list|,
name|SIGQUIT
argument_list|)
expr_stmt|;
name|sigaction
argument_list|(
name|SIGQUIT
argument_list|,
operator|&
name|sa
argument_list|,
operator|&
name|osa
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* not HAVE_SIGACTION */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|parent_exit
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* not HAVE_SIGACTION */
name|bgpid
operator|=
name|background
argument_list|()
expr_stmt|;
if|if
condition|(
name|bgpid
operator|!=
literal|0
condition|)
block|{
comment|/*      * Now wait for the automount points to      * complete.      */
for|for
control|(
init|;
condition|;
control|)
name|pause
argument_list|()
expr_stmt|;
comment|/* should never reach here */
block|}
ifdef|#
directive|ifdef
name|HAVE_SIGACTION
name|sigaction
argument_list|(
name|SIGQUIT
argument_list|,
operator|&
name|osa
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* not HAVE_SIGACTION */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* not HAVE_SIGACTION */
comment|/*    * Record our pid to make it easier to kill the correct amd.    */
if|if
condition|(
name|gopt
operator|.
name|flags
operator|&
name|CFM_PRINT_PID
condition|)
block|{
if|if
condition|(
name|STREQ
argument_list|(
name|gopt
operator|.
name|pid_file
argument_list|,
literal|"/dev/stdout"
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"%ld\n"
argument_list|,
operator|(
name|long
operator|)
name|am_mypid
argument_list|)
expr_stmt|;
comment|/* flush stdout, just in case */
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|FILE
modifier|*
name|f
decl_stmt|;
name|mode_t
name|prev_umask
init|=
name|umask
argument_list|(
literal|0022
argument_list|)
decl_stmt|;
comment|/* set secure temporary umask */
name|f
operator|=
name|fopen
argument_list|(
name|gopt
operator|.
name|pid_file
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
condition|)
block|{
name|fprintf
argument_list|(
name|f
argument_list|,
literal|"%ld\n"
argument_list|,
operator|(
name|long
operator|)
name|am_mypid
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"cannot open %s (errno=%d)\n"
argument_list|,
name|gopt
operator|.
name|pid_file
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
name|umask
argument_list|(
name|prev_umask
argument_list|)
expr_stmt|;
comment|/* restore umask */
block|}
block|}
comment|/*    * Pretend we are in the foreground again    */
name|foreground
operator|=
literal|1
expr_stmt|;
comment|/*    * Dissociate from the controlling terminal    */
name|amu_release_controlling_tty
argument_list|()
expr_stmt|;
return|return
name|getppid
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/*  * Initialize global options structure.  */
end_comment

begin_function
specifier|static
name|void
name|init_global_options
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_UTSNAME_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_UNAME
argument_list|)
specifier|static
name|struct
name|utsname
name|un
decl_stmt|;
endif|#
directive|endif
comment|/* defined(HAVE_SYS_UTSNAME_H)&& defined(HAVE_UNAME) */
name|int
name|i
decl_stmt|;
name|memset
argument_list|(
operator|&
name|gopt
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|amu_global_options
argument_list|)
argument_list|)
expr_stmt|;
comment|/* name of current architecture */
name|gopt
operator|.
name|arch
operator|=
name|HOST_ARCH
expr_stmt|;
comment|/* automounter temp dir */
name|gopt
operator|.
name|auto_dir
operator|=
literal|"/a"
expr_stmt|;
comment|/* toplevel attribute cache timeout */
name|gopt
operator|.
name|auto_attrcache
operator|=
literal|0
expr_stmt|;
comment|/* cluster name */
name|gopt
operator|.
name|cluster
operator|=
name|NULL
expr_stmt|;
comment|/* executable map timeout */
name|gopt
operator|.
name|exec_map_timeout
operator|=
name|AMFS_EXEC_MAP_TIMEOUT
expr_stmt|;
comment|/*    * kernel architecture: this you must get from uname() if possible.    */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_UTSNAME_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_UNAME
argument_list|)
if|if
condition|(
name|uname
argument_list|(
operator|&
name|un
argument_list|)
operator|>=
literal|0
condition|)
name|gopt
operator|.
name|karch
operator|=
name|un
operator|.
name|machine
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* defined(HAVE_SYS_UTSNAME_H)&& defined(HAVE_UNAME) */
name|gopt
operator|.
name|karch
operator|=
name|HOST_ARCH
expr_stmt|;
comment|/* amd log file */
name|gopt
operator|.
name|logfile
operator|=
name|NULL
expr_stmt|;
comment|/* operating system name */
name|gopt
operator|.
name|op_sys
operator|=
name|HOST_OS_NAME
expr_stmt|;
comment|/* OS version */
name|gopt
operator|.
name|op_sys_ver
operator|=
name|HOST_OS_VERSION
expr_stmt|;
comment|/* full OS name and version */
name|gopt
operator|.
name|op_sys_full
operator|=
name|HOST_OS
expr_stmt|;
comment|/* OS version */
name|gopt
operator|.
name|op_sys_vendor
operator|=
name|HOST_VENDOR
expr_stmt|;
comment|/* pid file */
name|gopt
operator|.
name|pid_file
operator|=
literal|"/dev/stdout"
expr_stmt|;
comment|/* local domain */
name|gopt
operator|.
name|sub_domain
operator|=
name|NULL
expr_stmt|;
comment|/* reset NFS (and toplvl) retransmit counter and retry interval */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|AMU_TYPE_MAX
condition|;
operator|++
name|i
control|)
block|{
name|gopt
operator|.
name|amfs_auto_retrans
index|[
name|i
index|]
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* -1 means "never set before" */
name|gopt
operator|.
name|amfs_auto_timeo
index|[
name|i
index|]
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* -1 means "never set before" */
block|}
comment|/* cache duration */
name|gopt
operator|.
name|am_timeo
operator|=
name|AM_TTL
expr_stmt|;
comment|/* dismount interval */
name|gopt
operator|.
name|am_timeo_w
operator|=
name|AM_TTL_W
expr_stmt|;
comment|/* map reload intervl */
name|gopt
operator|.
name|map_reload_interval
operator|=
name|ONE_HOUR
expr_stmt|;
comment|/*    * various CFM_* flags that are on by default.    */
name|gopt
operator|.
name|flags
operator|=
name|CFM_DEFAULT_FLAGS
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_MAP_HESIOD
comment|/* Hesiod rhs zone */
name|gopt
operator|.
name|hesiod_base
operator|=
literal|"automount"
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_MAP_HESIOD */
ifdef|#
directive|ifdef
name|HAVE_MAP_LDAP
comment|/* LDAP base */
name|gopt
operator|.
name|ldap_base
operator|=
name|NULL
expr_stmt|;
comment|/* LDAP host ports */
name|gopt
operator|.
name|ldap_hostports
operator|=
name|NULL
expr_stmt|;
comment|/* LDAP cache */
name|gopt
operator|.
name|ldap_cache_seconds
operator|=
literal|0
expr_stmt|;
name|gopt
operator|.
name|ldap_cache_maxmem
operator|=
literal|131072
expr_stmt|;
comment|/* LDAP protocol version */
name|gopt
operator|.
name|ldap_proto_version
operator|=
literal|2
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_MAP_LDAP */
ifdef|#
directive|ifdef
name|HAVE_MAP_NIS
comment|/* YP domain name */
name|gopt
operator|.
name|nis_domain
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_MAP_NIS */
block|}
end_function

begin_comment
comment|/*  * Lock process text and data segment in memory (after forking the daemon)  */
end_comment

begin_function
specifier|static
name|void
name|do_memory_locking
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_PLOCK
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_MLOCKALL
argument_list|)
name|int
name|locked_ok
init|=
literal|0
decl_stmt|;
else|#
directive|else
comment|/* not HAVE_PLOCK and not HAVE_MLOCKALL */
name|plog
argument_list|(
name|XLOG_WARNING
argument_list|,
literal|"Process memory locking not supported by the OS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* not HAVE_PLOCK and not HAVE_MLOCKALL */
ifdef|#
directive|ifdef
name|HAVE_PLOCK
ifdef|#
directive|ifdef
name|_AIX
comment|/*    * On AIX you must lower the stack size using ulimit() before calling    * plock.  Otherwise plock will reserve a lot of memory space based on    * your maximum stack size limit.  Since it is not easily possible to    * tell what should the limit be, I print a warning before calling    * plock().  See the manual pages for ulimit(1,3,4) on your AIX system.    */
name|plog
argument_list|(
name|XLOG_WARNING
argument_list|,
literal|"AIX: may need to lower stack size using ulimit(3) before calling plock"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* _AIX */
if|if
condition|(
operator|!
name|locked_ok
operator|&&
name|plock
argument_list|(
name|PROCLOCK
argument_list|)
operator|!=
literal|0
condition|)
name|plog
argument_list|(
name|XLOG_WARNING
argument_list|,
literal|"Couldn't lock process pages in memory using plock(): %m"
argument_list|)
expr_stmt|;
else|else
name|locked_ok
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_PLOCK */
ifdef|#
directive|ifdef
name|HAVE_MLOCKALL
if|if
condition|(
operator|!
name|locked_ok
operator|&&
name|mlockall
argument_list|(
name|MCL_CURRENT
operator||
name|MCL_FUTURE
argument_list|)
operator|!=
literal|0
condition|)
name|plog
argument_list|(
name|XLOG_WARNING
argument_list|,
literal|"Couldn't lock process pages in memory using mlockall(): %m"
argument_list|)
expr_stmt|;
else|else
name|locked_ok
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_MLOCKALL */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_PLOCK
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_MLOCKALL
argument_list|)
if|if
condition|(
name|locked_ok
condition|)
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"Locked process pages in memory"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_PLOCK || HAVE_MLOCKALL */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MADVISE
argument_list|)
operator|&&
name|defined
argument_list|(
name|MADV_PROTECT
argument_list|)
name|madvise
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|MADV_PROTECT
argument_list|)
expr_stmt|;
comment|/* may be redundant of the above worked out */
endif|#
directive|endif
comment|/* defined(HAVE_MADVISE)&& defined(MADV_PROTECT) */
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|char
modifier|*
name|domdot
decl_stmt|,
modifier|*
name|verstr
decl_stmt|,
modifier|*
name|vertmp
decl_stmt|;
name|int
name|ppid
init|=
literal|0
decl_stmt|;
name|int
name|error
decl_stmt|;
name|char
modifier|*
name|progname
init|=
name|NULL
decl_stmt|;
comment|/* "amd" */
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
operator|+
literal|1
index|]
init|=
literal|"localhost"
decl_stmt|;
comment|/* Hostname */
comment|/*    * Make sure some built-in assumptions are true before we start    */
name|assert
argument_list|(
sizeof|sizeof
argument_list|(
name|nfscookie
argument_list|)
operator|>=
sizeof|sizeof
argument_list|(
name|u_int
argument_list|)
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
comment|/*    * Set processing status.    */
name|amd_state
operator|=
name|Start
expr_stmt|;
comment|/*    * Determine program name    */
if|if
condition|(
name|argv
index|[
literal|0
index|]
condition|)
block|{
name|progname
operator|=
name|strrchr
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|progname
operator|&&
name|progname
index|[
literal|1
index|]
condition|)
name|progname
operator|++
expr_stmt|;
else|else
name|progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|progname
condition|)
name|progname
operator|=
literal|"amd"
expr_stmt|;
name|am_set_progname
argument_list|(
name|progname
argument_list|)
expr_stmt|;
comment|/*    * Initialize process id.  This is kept    * cached since it is used for generating    * and using file handles.    */
name|am_set_mypid
argument_list|()
expr_stmt|;
comment|/*    * Get local machine name    */
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
return|return
literal|1
return|;
block|}
name|hostname
index|[
sizeof|sizeof
argument_list|(
name|hostname
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/*    * Check it makes sense    */
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
return|return
literal|1
return|;
block|}
comment|/*    * Initialize global options structure.    */
name|init_global_options
argument_list|()
expr_stmt|;
comment|/*    * Partially initialize hostd[].  This    * is completed in get_args().    */
if|if
condition|(
operator|(
name|domdot
operator|=
name|strchr
argument_list|(
name|hostname
argument_list|,
literal|'.'
argument_list|)
operator|)
condition|)
block|{
comment|/*      * Hostname already contains domainname.      * Split out hostname and domainname      * components      */
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
name|xstrlcpy
argument_list|(
name|hostd
argument_list|,
name|hostname
argument_list|,
sizeof|sizeof
argument_list|(
name|hostd
argument_list|)
argument_list|)
expr_stmt|;
name|am_set_hostname
argument_list|(
name|hostname
argument_list|)
expr_stmt|;
comment|/*    * Setup signal handlers    */
comment|/* SIGINT: trap interrupts for shutdowns */
name|setup_sighandler
argument_list|(
name|SIGINT
argument_list|,
name|sigterm
argument_list|)
expr_stmt|;
comment|/* SIGTERM: trap terminate so we can shutdown cleanly (some chance) */
name|setup_sighandler
argument_list|(
name|SIGTERM
argument_list|,
name|sigterm
argument_list|)
expr_stmt|;
comment|/* SIGHUP: hangups tell us to reload the cache */
name|setup_sighandler
argument_list|(
name|SIGHUP
argument_list|,
name|sighup
argument_list|)
expr_stmt|;
comment|/*    * SIGCHLD: trap Death-of-a-child.  These allow us to pick up the exit    * status of backgrounded mounts.  See "sched.c".    */
name|setup_sighandler
argument_list|(
name|SIGCHLD
argument_list|,
name|sigchld
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_SIGACTION
comment|/* construct global "masked_sigs" used in nfs_start.c */
name|sigemptyset
argument_list|(
operator|&
name|masked_sigs
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|masked_sigs
argument_list|,
name|SIGINT
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|masked_sigs
argument_list|,
name|SIGTERM
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|masked_sigs
argument_list|,
name|SIGHUP
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|masked_sigs
argument_list|,
name|SIGCHLD
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_SIGACTION */
comment|/*    * Fix-up any umask problems.  Most systems default    * to 002 which is not too convenient for our purposes    */
name|orig_umask
operator|=
name|umask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/*    * Figure out primary network name    */
name|getwire
argument_list|(
operator|&
name|PrimNetName
argument_list|,
operator|&
name|PrimNetNum
argument_list|)
expr_stmt|;
comment|/*    * Determine command-line arguments.    * (Also initialize amd.conf parameters, maps, and more.)    */
name|get_args
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/*    * Log version information.    */
name|vertmp
operator|=
name|get_version_string
argument_list|()
expr_stmt|;
name|verstr
operator|=
name|strtok
argument_list|(
name|vertmp
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"AM-UTILS VERSION INFORMATION:"
argument_list|)
expr_stmt|;
while|while
condition|(
name|verstr
condition|)
block|{
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"%s"
argument_list|,
name|verstr
argument_list|)
expr_stmt|;
name|verstr
operator|=
name|strtok
argument_list|(
name|NULL
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|XFREE
argument_list|(
name|vertmp
argument_list|)
expr_stmt|;
comment|/*    * Get our own IP address so that we can mount the automounter.  We pass    * localhost_address which could be used as the default localhost    * name/address in amu_get_myaddress().    */
name|amu_get_myaddress
argument_list|(
operator|&
name|myipaddr
argument_list|,
name|gopt
operator|.
name|localhost_address
argument_list|)
expr_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"My ip addr is %s"
argument_list|,
name|inet_ntoa
argument_list|(
name|myipaddr
argument_list|)
argument_list|)
expr_stmt|;
comment|/* avoid hanging on other NFS servers if started elsewhere */
if|if
condition|(
name|chdir
argument_list|(
literal|"/"
argument_list|)
operator|<
literal|0
condition|)
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"cannot chdir to /: %m"
argument_list|)
expr_stmt|;
comment|/*    * Now check we are root.    */
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
literal|"Must be root to mount filesystems (euid = %ld)"
argument_list|,
operator|(
name|long
operator|)
name|geteuid
argument_list|()
argument_list|)
expr_stmt|;
name|going_down
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
ifdef|#
directive|ifdef
name|HAVE_MAP_NIS
comment|/*    * If the domain was specified then bind it here    * to circumvent any default bindings that may    * be done in the C library.    */
if|if
condition|(
name|gopt
operator|.
name|nis_domain
operator|&&
name|yp_bind
argument_list|(
name|gopt
operator|.
name|nis_domain
argument_list|)
condition|)
block|{
name|plog
argument_list|(
name|XLOG_FATAL
argument_list|,
literal|"Can't bind to NIS domain \"%s\""
argument_list|,
name|gopt
operator|.
name|nis_domain
argument_list|)
expr_stmt|;
name|going_down
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
endif|#
directive|endif
comment|/* HAVE_MAP_NIS */
if|if
condition|(
name|amuDebug
argument_list|(
name|D_DAEMON
argument_list|)
condition|)
name|ppid
operator|=
name|daemon_mode
argument_list|()
expr_stmt|;
comment|/*    * Lock process text and data segment in memory.    */
if|if
condition|(
name|gopt
operator|.
name|flags
operator|&
name|CFM_PROCESS_LOCK
condition|)
block|{
name|do_memory_locking
argument_list|()
expr_stmt|;
block|}
name|do_mapc_reload
operator|=
name|clocktime
argument_list|(
name|NULL
argument_list|)
operator|+
name|gopt
operator|.
name|map_reload_interval
expr_stmt|;
comment|/*    * Register automounter with system.    */
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
name|ppid
argument_list|,
name|SIGALRM
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
comment|/*    * XXX this should be part of going_down(), but I can't move it there    * because it would be calling non-library code from the library... ugh    */
if|if
condition|(
name|amd_use_autofs
condition|)
name|destroy_autofs_service
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_FS_AUTOFS */
name|going_down
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
return|return
literal|1
return|;
comment|/* should never get here */
block|}
end_function

end_unit

