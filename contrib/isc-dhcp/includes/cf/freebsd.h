begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* freebsd.h     System dependencies for FreeBSD... */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1996-2003 by Internet Software Consortium  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *   Internet Systems Consortium, Inc.  *   950 Charter Street  *   Redwood City, CA 94063  *<info@isc.org>  *   http://www.isc.org/  *  * This software has been written for Internet Systems Consortium  * by Ted Lemon in cooperation with Vixie Enterprises and Nominum, Inc.  * To learn more about Internet Systems Consortium, see  * ``http://www.isc.org/''.  To learn more about Vixie Enterprises,  * see ``http://www.vix.com''.   To learn more about Nominum, Inc., see  * ``http://www.nominum.com''.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
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
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INADDR_LOOPBACK
argument_list|)
end_if

begin_define
define|#
directive|define
name|INADDR_LOOPBACK
value|((u_int32_t)0x7f000001)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Varargs stuff... */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|VA_DOTDOTDOT
value|...
end_define

begin_define
define|#
directive|define
name|va_dcl
end_define

begin_define
define|#
directive|define
name|VA_start
parameter_list|(
name|list
parameter_list|,
name|last
parameter_list|)
value|va_start (list, last)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCPD_PID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCPD_PID
value|"/var/run/dhcpd.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCPD_DB
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCPD_DB
value|"/var/db/dhcpd.leases"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCLIENT_PID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCLIENT_PID
value|"/var/run/dhclient.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCLIENT_DB
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCLIENT_DB
value|"/var/db/dhclient.leases"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EOL
value|'\n'
end_define

begin_define
define|#
directive|define
name|VOIDPTR
value|void *
end_define

begin_comment
comment|/* Time stuff... */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|TIME
value|time_t
end_define

begin_define
define|#
directive|define
name|GET_TIME
parameter_list|(
name|x
parameter_list|)
value|time ((x))
end_define

begin_define
define|#
directive|define
name|HAVE_SA_LEN
end_define

begin_comment
comment|/* socklen_t was first defined on November 24 in sys/socket.h, and    __FreeBSD_version was changed to 400013 on December 4, so if you    get a compile error on this, and you updated between those dates,    that's why.   Also, it may be that some 3.x version after 3.4 will    have socklen_t, but no such change has been made so far. */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|400013
end_if

begin_define
define|#
directive|define
name|SOCKLEN_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RESCUE
end_ifdef

begin_define
define|#
directive|define
name|_PATH_DHCLIENT_SCRIPT
value|"/rescue/dhclient-script"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_DEFAULT_NETWORK
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_BPF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_PRAND_CONF
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DEV_RANDOM
end_ifndef

begin_define
define|#
directive|define
name|HAVE_DEV_RANDOM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_DEV_RANDOM */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cmds
index|[]
init|=
block|{
ifndef|#
directive|ifndef
name|RESCUE
comment|/* rescue environment can't rely on these ... */
comment|/* Actually, /sbin/dhclient shouldn't use these, either. */
literal|"/bin/ps -axlw 2>&1"
block|,
literal|"/usr/sbin/arp -an 2>&1"
block|,
literal|"/usr/bin/netstat -an 2>&1"
block|,
literal|"/bin/df  2>&1"
block|,
literal|"/usr/bin/dig com. soa +ti=1 +retry=0 2>&1"
block|,
literal|"/usr/bin/netstat -an 2>&1"
block|,
literal|"/usr/bin/dig . soa +ti=1 +retry=0 2>&1"
block|,
literal|"/usr/sbin/iostat  2>&1"
block|,
literal|"/usr/bin/vmstat  2>&1"
block|,
literal|"/usr/bin/w  2>&1"
block|,
endif|#
directive|endif
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|dirs
index|[]
init|=
block|{
ifndef|#
directive|ifndef
name|RESCUE
literal|"/tmp"
block|,
literal|"/usr/tmp"
block|,
literal|"."
block|,
literal|"/"
block|,
literal|"/var/spool"
block|,
literal|"/dev"
block|,
literal|"/var/mail"
block|,
literal|"/home"
block|,
literal|"/usr/home"
block|,
endif|#
directive|endif
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|files
index|[]
init|=
block|{
ifndef|#
directive|ifndef
name|RESCUE
literal|"/var/log/messages"
block|,
literal|"/var/log/wtmp"
block|,
literal|"/var/log/lastlog"
block|,
endif|#
directive|endif
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_PRAND_CONF */
end_comment

end_unit

