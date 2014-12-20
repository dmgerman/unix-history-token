begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * system.c  */
end_comment

begin_comment
comment|/* Portions of this file are subject to the following copyright(s).  See  * the Net-SNMP's COPYING file for more details and other copyrights  * that may apply:  */
end_comment

begin_comment
comment|/***********************************************************         Copyright 1992 by Carnegie Mellon University                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of CMU not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  CMU DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL CMU BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ******************************************************************/
end_comment

begin_comment
comment|/*  * Portions of this file are copyrighted by:  * Copyright © 2003 Sun Microsystems, Inc. All rights reserved.  * Use is subject to license terms specified in the COPYING file  * distributed with the Net-SNMP package.  */
end_comment

begin_comment
comment|/*  * System dependent routines go here  */
end_comment

begin_include
include|#
directive|include
file|<net-snmp/net-snmp-config.h>
end_include

begin_undef
undef|#
directive|undef
name|PACKAGE_BUGREPORT
end_undef

begin_undef
undef|#
directive|undef
name|PACKAGE_NAME
end_undef

begin_undef
undef|#
directive|undef
name|PACKAGE_STRING
end_undef

begin_undef
undef|#
directive|undef
name|PACKAGE_TARNAME
end_undef

begin_undef
undef|#
directive|undef
name|PACKAGE_VERSION
end_undef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_NETSNMP_DAEMONIZE
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TIME_WITH_SYS_TIME
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|HAVE_NETINET_IN_H
end_if

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_WINSOCK_H
end_if

begin_include
include|#
directive|include
file|<winsock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SOCKET_H
end_if

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_NET_IF_H
end_if

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SOCKIO_H
end_if

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_IOCTL_H
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NLIST_H
end_ifdef

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_FILE_H
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_KSTAT_H
end_if

begin_include
include|#
directive|include
file|<kstat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_PARAM_H
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SYSCTL_H
end_if

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DMALLOC_H
end_if

begin_include
include|#
directive|include
file|<dmalloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux10
argument_list|)
operator|||
name|defined
argument_list|(
name|hpux11
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/pstat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_UTSNAME_H
end_if

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SYSTEMCFG_H
end_if

begin_include
include|#
directive|include
file|<sys/systemcfg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SYSTEMINFO_H
end_if

begin_include
include|#
directive|include
file|<sys/systeminfo.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net-snmp/types.h>
end_include

begin_include
include|#
directive|include
file|<net-snmp/output_api.h>
end_include

begin_include
include|#
directive|include
file|<net-snmp/utilities.h>
end_include

begin_include
include|#
directive|include
file|<net-snmp/library/system.h>
end_include

begin_comment
comment|/* for "internal" definitions */
end_comment

begin_include
include|#
directive|include
file|<net-snmp/library/snmp_api.h>
end_include

begin_include
include|#
directive|include
file|<net-snmp/library/read_config.h>
end_include

begin_comment
comment|/* for get_temp_file_pattern() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IFF_LOOPBACK
end_ifndef

begin_define
define|#
directive|define
name|IFF_LOOPBACK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INADDR_LOOPBACK
end_ifdef

begin_define
define|#
directive|define
name|LOOPBACK
value|INADDR_LOOPBACK
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOOPBACK
value|0x7f000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * fork current process into the background.  *  * This function forks a process into the background, in order to  * become a daemon process. It does a few things along the way:  *  * - becoming a process/session group leader, and  forking a second time so  *   that process/session group leader can exit.  *  * - changing the working directory to /  *  * - closing stdin, stdout and stderr (unless stderr_log is set) and  *   redirecting them to /dev/null  *  * @param quit_immediately : indicates if the parent process should  *                           exit after a successful fork.  * @param stderr_log       : indicates if stderr is being used for  *                           logging and shouldn't be closed  * @returns -1 : fork error  *           0 : child process returning  *>0 : parent process returning. returned value is the child PID.  */
end_comment

begin_function
name|int
name|netsnmp_daemonize
parameter_list|(
name|int
name|quit_immediately
parameter_list|,
name|int
name|stderr_log
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|int
name|saved_errno
decl_stmt|;
name|DEBUGMSGT
argument_list|(
operator|(
literal|"daemonize"
operator|,
literal|"deamonizing...\n"
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_WORKING_FORK
comment|/*      * Fork to return control to the invoking process and to      * guarantee that we aren't a process group leader.      */
name|i
operator|=
name|fork
argument_list|()
expr_stmt|;
if|if
condition|(
name|i
operator|!=
literal|0
condition|)
block|{
comment|/* Parent. */
name|saved_errno
operator|=
name|errno
expr_stmt|;
name|DEBUGMSGT
argument_list|(
operator|(
literal|"daemonize"
operator|,
literal|"first fork returned %d.\n"
operator|,
name|i
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
operator|-
literal|1
condition|)
block|{
name|snmp_log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"first fork failed (errno %d) in "
literal|"netsnmp_daemonize()\n"
argument_list|,
name|saved_errno
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|quit_immediately
condition|)
block|{
name|DEBUGMSGT
argument_list|(
operator|(
literal|"daemonize"
operator|,
literal|"parent exiting\n"
operator|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Child. */
ifdef|#
directive|ifdef
name|HAVE_SETSID
comment|/* Become a process/session group leader. */
name|setsid
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/*          * Fork to let the process/session group leader exit.          */
if|if
condition|(
operator|(
name|i
operator|=
name|fork
argument_list|()
operator|)
operator|!=
literal|0
condition|)
block|{
name|saved_errno
operator|=
name|errno
expr_stmt|;
name|DEBUGMSGT
argument_list|(
operator|(
literal|"daemonize"
operator|,
literal|"second fork returned %d.\n"
operator|,
name|i
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
operator|-
literal|1
condition|)
block|{
name|snmp_log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"second fork failed (errno %d) in "
literal|"netsnmp_daemonize()\n"
argument_list|,
name|saved_errno
argument_list|)
expr_stmt|;
block|}
comment|/* Parent. */
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|WIN32
else|else
block|{
comment|/* Child. */
name|DEBUGMSGT
argument_list|(
operator|(
literal|"daemonize"
operator|,
literal|"child continuing\n"
operator|)
argument_list|)
expr_stmt|;
comment|/* Avoid keeping any directory in use. */
name|chdir
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|stderr_log
condition|)
block|{
comment|/*                  * Close inherited file descriptors to avoid                  * keeping unnecessary references.                  */
name|close
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/*                  * Redirect std{in,out,err} to /dev/null, just in                  * case.                  */
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
name|dup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|dup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* !WIN32 */
block|}
endif|#
directive|endif
comment|/* HAVE_WORKING_FORK */
return|return
name|i
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NEED_NETSNMP_DAEMONIZE */
end_comment

begin_decl_stmt
name|int
name|netsnp_daemonize_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

