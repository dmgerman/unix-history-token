begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: bsd_locl.h,v 1.111 1999/12/02 16:58:28 joda Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|LOGALL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERBEROS
end_ifndef

begin_define
define|#
directive|define
name|KERBEROS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KLOGIN_PARANOID
end_define

begin_define
define|#
directive|define
name|LOGIN_ACCESS
end_define

begin_define
define|#
directive|define
name|PASSWD_FALLBACK
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Any better way to test NO_MOTD? */
end_comment

begin_if
if|#
directive|if
operator|(
name|SunOS
operator|>=
literal|50
operator|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_MOTD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SHADOW_H
end_ifdef

begin_define
define|#
directive|define
name|SYSV_SHADOW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_IO_H
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIBUTIL_H
end_ifdef

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_TIME_H
argument_list|)
end_elif

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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISTXT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_ISVTX
end_ifdef

begin_define
define|#
directive|define
name|S_ISTXT
value|S_ISVTX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISTXT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DIRENT_H
end_ifdef

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_RESOURCE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_RESOURCE_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NCARGS
end_ifndef

begin_define
define|#
directive|define
name|NCARGS
value|0x100000
end_define

begin_comment
comment|/* (absolute) max # characters in exec arglist */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GRP_H
end_ifdef

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTIME_H
end_ifdef

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_SYSTM_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IP_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_TCP_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_INET_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDB_H
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
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
name|HAVE_SYS_IOCTL_H
argument_list|)
operator|&&
name|SunOS
operator|!=
literal|40
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
name|HAVE_SYS_IOCCOM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STREAM_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_UIO_H */
end_comment

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_STREAM_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PTYVAR_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PROC_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TTY_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PTYIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ptyio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ptyvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PTYVAR_H */
end_comment

begin_comment
comment|/* Cray stuff */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UDB_H
end_ifdef

begin_include
include|#
directive|include
file|<udb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_CATEGORY_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/category.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Strange ioctls that are not always defined */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIOCPKT_FLUSHWRITE
end_ifndef

begin_define
define|#
directive|define
name|TIOCPKT_FLUSHWRITE
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIOCPKT_NOSTOP
end_ifndef

begin_define
define|#
directive|define
name|TIOCPKT_NOSTOP
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIOCPKT_DOSTOP
end_ifndef

begin_define
define|#
directive|define
name|TIOCPKT_DOSTOP
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIOCPKT
end_ifndef

begin_define
define|#
directive|define
name|TIOCPKT
value|_IOW('t', 112, int)
end_define

begin_comment
comment|/* pty: set/clear packet mode */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LASTLOG_H
end_ifdef

begin_include
include|#
directive|include
file|<lastlog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOGIN_H
end_ifdef

begin_include
include|#
directive|include
file|<login.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TTYENT_H
end_ifdef

begin_include
include|#
directive|include
file|<ttyent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STROPTS_H
end_ifdef

begin_include
include|#
directive|include
file|<stropts.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTMP_H
end_ifdef

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|UT_NAMESIZE
end_ifndef

begin_define
define|#
directive|define
name|UT_NAMESIZE
value|sizeof(((struct utmp *)0)->ut_name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTMPX_H
end_ifdef

begin_include
include|#
directive|include
file|<utmpx.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_USERPW_H
end_ifdef

begin_include
include|#
directive|include
file|<userpw.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_USERPW_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_USERSEC_H
end_ifdef

begin_struct_decl
struct_decl|struct
name|aud_rec
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<usersec.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_USERSEC_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OSFC2
end_ifdef

begin_include
include|#
directive|include
file|"/usr/include/prot.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIO_PROCESS
end_ifndef

begin_define
define|#
directive|define
name|PRIO_PROCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKS
end_ifdef

begin_include
include|#
directive|include
file|<socks.h>
end_include

begin_comment
comment|/* This doesn't belong here. */
end_comment

begin_function_decl
name|struct
name|tm
modifier|*
name|localtime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/des.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<kafs.h>
end_include

begin_function_decl
name|int
name|kcmd
parameter_list|(
name|int
modifier|*
name|sock
parameter_list|,
name|char
modifier|*
modifier|*
name|ahost
parameter_list|,
name|u_int16_t
name|rport
parameter_list|,
name|char
modifier|*
name|locuser
parameter_list|,
name|char
modifier|*
name|remuser
parameter_list|,
name|char
modifier|*
name|cmd
parameter_list|,
name|int
modifier|*
name|fd2p
parameter_list|,
name|KTEXT
name|ticket
parameter_list|,
name|char
modifier|*
name|service
parameter_list|,
name|char
modifier|*
name|realm
parameter_list|,
name|CREDENTIALS
modifier|*
name|cred
parameter_list|,
name|Key_schedule
name|schedule
parameter_list|,
name|MSG_DAT
modifier|*
name|msg_data
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|laddr
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|faddr
parameter_list|,
name|int32_t
name|authopts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krcmd
parameter_list|(
name|char
modifier|*
modifier|*
name|ahost
parameter_list|,
name|u_int16_t
name|rport
parameter_list|,
name|char
modifier|*
name|remuser
parameter_list|,
name|char
modifier|*
name|cmd
parameter_list|,
name|int
modifier|*
name|fd2p
parameter_list|,
name|char
modifier|*
name|realm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krcmd_mutual
parameter_list|(
name|char
modifier|*
modifier|*
name|ahost
parameter_list|,
name|u_int16_t
name|rport
parameter_list|,
name|char
modifier|*
name|remuser
parameter_list|,
name|char
modifier|*
name|cmd
parameter_list|,
name|int
modifier|*
name|fd2p
parameter_list|,
name|char
modifier|*
name|realm
parameter_list|,
name|CREDENTIALS
modifier|*
name|cred
parameter_list|,
name|Key_schedule
name|sched
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|klogin
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
name|char
modifier|*
name|instance
parameter_list|,
name|char
modifier|*
name|localhost
parameter_list|,
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|typedef struct {         int cnt;         char *buf; } BUF;
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|colon
parameter_list|(
name|char
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|okname
parameter_list|(
name|char
modifier|*
name|cp0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|susystem
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|int
name|userid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|forkpty
parameter_list|(
name|int
modifier|*
name|amaster
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|termios
modifier|*
name|termp
parameter_list|,
name|struct
name|winsize
modifier|*
name|winp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|forkpty_truncate
parameter_list|(
name|int
modifier|*
name|amaster
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|size_t
name|name_sz
parameter_list|,
name|struct
name|termios
modifier|*
name|termp
parameter_list|,
name|struct
name|winsize
modifier|*
name|winp
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|MODEMASK
end_ifndef

begin_define
define|#
directive|define
name|MODEMASK
value|(S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PATHS_H
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MAILLOCK_H
end_ifdef

begin_include
include|#
directive|include
file|<maillock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_function_decl
name|void
name|stty_default
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|utmpx_login
parameter_list|(
name|char
modifier|*
name|line
parameter_list|,
name|char
modifier|*
name|user
parameter_list|,
name|char
modifier|*
name|host
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|sysv_newenv
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|struct
name|passwd
modifier|*
name|pwd
parameter_list|,
name|char
modifier|*
name|term
parameter_list|,
name|int
name|pflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_access
parameter_list|(
name|struct
name|passwd
modifier|*
name|user
parameter_list|,
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
name|int
name|f
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|int
name|syserr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|LEFT_JUSTIFIED
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used in des_read and des_write */
end_comment

begin_define
define|#
directive|define
name|DES_RW_MAXWRITE
value|(1024*16)
end_define

begin_define
define|#
directive|define
name|DES_RW_BSIZE
value|(DES_RW_MAXWRITE+4)
end_define

begin_function_decl
name|void
name|sysv_defaults
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utmp_login
parameter_list|(
name|char
modifier|*
name|tty
parameter_list|,
name|char
modifier|*
name|username
parameter_list|,
name|char
modifier|*
name|hostname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sleepexit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETPRIORITY
end_ifndef

begin_define
define|#
directive|define
name|setpriority
parameter_list|(
name|which
parameter_list|,
name|who
parameter_list|,
name|niceval
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETPRIORITY
end_ifndef

begin_define
define|#
directive|define
name|getpriority
parameter_list|(
name|which
parameter_list|,
name|who
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS_H
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VDISABLE
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VDISABLE */
end_comment

begin_if
if|#
directive|if
name|SunOS
operator|==
literal|40
end_if

begin_include
include|#
directive|include
file|<sys/ttold.h>
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
name|HAVE_SYS_TERMIO_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TERMIOS_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/termio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CEOF
end_ifndef

begin_define
define|#
directive|define
name|CEOF
value|04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* concession to Sun */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGUSR1
end_ifndef

begin_define
define|#
directive|define
name|SIGUSR1
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIOCPKT_WINDOW
end_ifndef

begin_define
define|#
directive|define
name|TIOCPKT_WINDOW
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|get_shell_port
parameter_list|(
name|int
name|kerberos
parameter_list|,
name|int
name|encryption
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_login_port
parameter_list|(
name|int
name|kerberos
parameter_list|,
name|int
name|encryption
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|speed_t2int
parameter_list|(
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|speed_t
name|int2speed_t
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_options_and_die
parameter_list|(
name|int
name|sock
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|warning
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|clean_ttyname
parameter_list|(
name|char
modifier|*
name|tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|make_id
parameter_list|(
name|char
modifier|*
name|tty
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTMP_H
end_ifdef

begin_function_decl
name|void
name|prepare_utmp
parameter_list|(
name|struct
name|utmp
modifier|*
name|utmp
parameter_list|,
name|char
modifier|*
name|tty
parameter_list|,
name|char
modifier|*
name|username
parameter_list|,
name|char
modifier|*
name|hostname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|do_osfc2_magic
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|paranoid_setuid
parameter_list|(
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

end_unit

