begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)conf.h	8.19 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* **  CONF.H -- All user-configurable parameters for sendmail */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/********************************************************************** **  Table sizes, etc.... **	There shouldn't be much need to change these.... **********************************************************************/
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|2048
end_define

begin_comment
comment|/* max line length */
end_comment

begin_define
define|#
directive|define
name|MAXNAME
value|256
end_define

begin_comment
comment|/* max length of a name */
end_comment

begin_define
define|#
directive|define
name|MAXPV
value|40
end_define

begin_comment
comment|/* max # of parms to mailers */
end_comment

begin_define
define|#
directive|define
name|MAXATOM
value|200
end_define

begin_comment
comment|/* max atoms per address */
end_comment

begin_define
define|#
directive|define
name|MAXMAILERS
value|25
end_define

begin_comment
comment|/* maximum mailers known to system */
end_comment

begin_define
define|#
directive|define
name|MAXRWSETS
value|100
end_define

begin_comment
comment|/* max # of sets of rewriting rules */
end_comment

begin_define
define|#
directive|define
name|MAXPRIORITIES
value|25
end_define

begin_comment
comment|/* max values for Precedence: field */
end_comment

begin_define
define|#
directive|define
name|MAXMXHOSTS
value|20
end_define

begin_comment
comment|/* max # of MX records */
end_comment

begin_define
define|#
directive|define
name|SMTPLINELIM
value|990
end_define

begin_comment
comment|/* maximum SMTP line length */
end_comment

begin_define
define|#
directive|define
name|MAXKEY
value|128
end_define

begin_comment
comment|/* maximum size of a database key */
end_comment

begin_define
define|#
directive|define
name|MEMCHUNKSIZE
value|1024
end_define

begin_comment
comment|/* chunk size for memory allocation */
end_comment

begin_define
define|#
directive|define
name|MAXUSERENVIRON
value|100
end_define

begin_comment
comment|/* max envars saved, must be>= 3 */
end_comment

begin_define
define|#
directive|define
name|MAXIPADDR
value|16
end_define

begin_comment
comment|/* max # of IP addrs for this host */
end_comment

begin_define
define|#
directive|define
name|MAXALIASDB
value|12
end_define

begin_comment
comment|/* max # of alias databases */
end_comment

begin_define
define|#
directive|define
name|PSBUFSIZE
value|(MAXLINE + MAXATOM)
end_define

begin_comment
comment|/* size of prescan buffer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUEUESIZE
end_ifndef

begin_define
define|#
directive|define
name|QUEUESIZE
value|1000
end_define

begin_comment
comment|/* max # of jobs per queue run */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************************************************************** **  Compilation options. ** **	#define these if they are available; comment them out otherwise. **********************************************************************/
end_comment

begin_define
define|#
directive|define
name|LOG
value|1
end_define

begin_comment
comment|/* enable logging */
end_comment

begin_define
define|#
directive|define
name|UGLYUUCP
value|1
end_define

begin_comment
comment|/* output ugly UUCP From lines */
end_comment

begin_define
define|#
directive|define
name|NETINET
value|1
end_define

begin_comment
comment|/* include internet support */
end_comment

begin_define
define|#
directive|define
name|SETPROCTITLE
value|1
end_define

begin_comment
comment|/* munge argv to display current status */
end_comment

begin_define
define|#
directive|define
name|NAMED_BIND
value|1
end_define

begin_comment
comment|/* use Berkeley Internet Domain Server */
end_comment

begin_define
define|#
directive|define
name|MATCHGECOS
value|1
end_define

begin_comment
comment|/* match user names from gecos field */
end_comment

begin_define
define|#
directive|define
name|XDEBUG
value|1
end_define

begin_comment
comment|/* enable extended debugging */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEWDB
end_ifdef

begin_define
define|#
directive|define
name|USERDB
value|1
end_define

begin_comment
comment|/* look in user database (requires NEWDB) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Due to a "feature" in some operating systems such as Ultrix 4.3 and **  HPUX 8.0, if you receive a "No route to host" message (ICMP message **  ICMP_UNREACH_HOST) on _any_ connection, all connections to that host **  are closed.  Some firewalls return this error if you try to connect **  to the IDENT port (113), so you can't receive email from these hosts **  on these systems.  The firewall really should use a more specific **  message such as ICMP_UNREACH_PROTOCOL or _PORT or _NET_PROHIB.  This **  will get #undefed below as needed. */
end_comment

begin_define
define|#
directive|define
name|IDENTPROTO
value|1
end_define

begin_comment
comment|/* use IDENT proto (RFC 1413) */
end_comment

begin_comment
comment|/********************************************************************** **  Operating system configuration. ** **	Unless you are porting to a new OS, you shouldn't have to **	change these. **********************************************************************/
end_comment

begin_comment
comment|/* **  Per-Operating System defines */
end_comment

begin_comment
comment|/* **  HP-UX -- tested for 8.07 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|setreuid
parameter_list|(
name|r
parameter_list|,
name|e
parameter_list|)
value|setresuid(r, e, -1)
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/hp-ux"
end_define

begin_undef
undef|#
directive|undef
name|IDENTPROTO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  IBM AIX 3.x -- actually tested for 3.2.3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX3
end_ifdef

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|FORK
value|fork
end_define

begin_comment
comment|/* no vfork primitive available */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Silicon Graphics IRIX ** **	Compiles on 4.0.1. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX
end_ifdef

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|FORK
value|fork
end_define

begin_comment
comment|/* no vfork primitive available */
end_comment

begin_define
define|#
directive|define
name|setpgrp
value|BSDsetpgrp
end_define

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  SunOS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS
end_ifdef

begin_comment
comment|/* Solaris 2.x (a.k.a. SunOS 5.x) */
end_comment

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* use System V definitions */
end_comment

begin_define
define|#
directive|define
name|setreuid
parameter_list|(
name|r
parameter_list|,
name|e
parameter_list|)
value|seteuid(e)
end_define

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/kernel/unix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILCF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILCF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILFC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILFC
value|"/etc/mail/sendmail.fc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SunOS 4.1.x */
end_comment

begin_define
define|#
directive|define
name|HASSTATFS
value|1
end_define

begin_comment
comment|/* has the statfs(2) syscall */
end_comment

begin_comment
comment|/* #  define HASFLOCK	1	/* has flock(2) call */
end_comment

begin_include
include|#
directive|include
file|<vfork.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Digital Ultrix 4.2A or 4.3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_define
define|#
directive|define
name|HASSTATFS
value|1
end_define

begin_comment
comment|/* has the statfs(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_comment
comment|/* # define HASFLOCK	1	/* has flock(2) call */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
end_define

begin_undef
undef|#
directive|undef
name|IDENTPROTO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  OSF/1 (tested on Alpha) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__osf__
end_ifdef

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_comment
comment|/* # define HASFLOCK	1	/* has flock(2) call */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  NeXTstep */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NeXT
end_ifdef

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_define
define|#
directive|define
name|sleep
value|sleepX
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILCF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILCF
value|"/etc/sendmail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILFC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILFC
value|"/etc/sendmail/sendmail.fc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  4.4 BSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_4
end_ifdef

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  4.3 BSD -- this is for very old systems ** **	You'll also have to install a new resolver library. **	I don't guarantee that support for this environment is complete. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|oldBSD43
end_ifdef

begin_define
define|#
directive|define
name|NEEDVPRINTF
value|1
end_define

begin_comment
comment|/* need a replacement for vprintf(3) */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|ARBPTR_T
value|char *
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILCF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILCF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILFC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILFC
value|"/usr/lib/sendmail.fc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  SCO Unix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SCO_unix_
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* SysV signal semantics -- reset on each sig */
end_comment

begin_define
define|#
directive|define
name|HASSTATFS
value|1
end_define

begin_comment
comment|/* has the statfs(2) syscall */
end_comment

begin_define
define|#
directive|define
name|FORK
value|fork
end_define

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATHSIZE
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  ConvexOS 11.0 and later */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CONVEX_SOURCE
end_ifdef

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_comment
comment|/* include all the BSD defines */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASSTATFS
value|1
end_define

begin_comment
comment|/* has the statfs(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has POSIX setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* need replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_undef
undef|#
directive|undef
name|IDENTPROTO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  RISC/os 4.51 ** **	Untested... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RISCOS
end_ifdef

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_comment
comment|/* # define HASFLOCK	1	/* has flock(2) call */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
end_define

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************************************************************** **  End of Per-Operating System defines **********************************************************************/
end_comment

begin_comment
comment|/********************************************************************** **  More general defines **********************************************************************/
end_comment

begin_comment
comment|/* general BSD defines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) call */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* general System V defines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTEM5
end_ifdef

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASUSTAT
value|1
end_define

begin_comment
comment|/* use System V ustat(2) syscall */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|(memmove((d), (s), (l)))
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|(memset((d), '\0', (l)))
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|(memcmp((s), (d), (l)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* general "standard C" defines */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|SYSTEM5
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* we have setvbuf(3) in libc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* general POSIX defines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_VERSION
end_ifdef

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_comment
comment|/* has waitpid(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  If no type for argument two of getgroups call is defined, assume **  it's an integer -- unfortunately, there seem to be several choices **  here. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GIDSET_T
end_ifndef

begin_define
define|#
directive|define
name|GIDSET_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Remaining definitions should never have to be changed.  They are **  primarily to provide back compatibility for older systems -- for **  example, it includes some POSIX compatibility definitions */
end_comment

begin_comment
comment|/* System 5 compatibility */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|foo
parameter_list|)
value|((foo& S_IFREG) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IWGRP
value|020
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IWOTH
value|002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Older systems don't have this error code -- it should be in **  /usr/include/sysexits.h. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EX_CONFIG
end_ifndef

begin_define
define|#
directive|define
name|EX_CONFIG
value|78
end_define

begin_comment
comment|/* configuration error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  These are used in a few cases where we need some special **  error codes, but where the system doesn't provide something **  reasonable.  They are printed in errstring. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|E_PSEUDOBASE
end_ifndef

begin_define
define|#
directive|define
name|E_PSEUDOBASE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EOPENTIMEOUT
value|(E_PSEUDOBASE + 0)
end_define

begin_comment
comment|/* timeout on open */
end_comment

begin_define
define|#
directive|define
name|E_DNSBASE
value|(E_PSEUDOBASE + 20)
end_define

begin_comment
comment|/* base for DNS h_errno */
end_comment

begin_comment
comment|/* type of arbitrary pointer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARBPTR_T
end_ifndef

begin_define
define|#
directive|define
name|ARBPTR_T
value|void *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_include
include|#
directive|include
file|"cdefs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Do some required dependencies */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NETINET
argument_list|)
operator|||
name|defined
argument_list|(
name|NETISO
argument_list|)
end_if

begin_define
define|#
directive|define
name|SMTP
value|1
end_define

begin_comment
comment|/* enable user and server SMTP */
end_comment

begin_define
define|#
directive|define
name|QUEUE
value|1
end_define

begin_comment
comment|/* enable queueing */
end_comment

begin_define
define|#
directive|define
name|DAEMON
value|1
end_define

begin_comment
comment|/* include the daemon (requires IPC& SMTP) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Arrange to use either varargs or stdargs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|VA_LOCAL_DECL
value|va_list ap;
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|f
parameter_list|)
value|va_start(ap, f)
end_define

begin_define
define|#
directive|define
name|VA_END
value|va_end(ap)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_define
define|#
directive|define
name|VA_LOCAL_DECL
value|va_list ap;
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|f
parameter_list|)
value|va_start(ap)
end_define

begin_define
define|#
directive|define
name|VA_END
value|va_end(ap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HASUNAME
end_ifdef

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|newstr
end_ifdef

begin_undef
undef|#
directive|undef
name|newstr
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HASUNAME */
end_comment

begin_define
define|#
directive|define
name|NODE_LENGTH
value|32
end_define

begin_struct
struct|struct
name|utsname
block|{
name|char
name|nodename
index|[
name|NODE_LENGTH
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASUNAME */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAXHOSTNAMELEN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SCO_unix_
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|256
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
name|SIGCHLD
argument_list|)
operator|&&
name|defined
argument_list|(
name|SIGCLD
argument_list|)
end_if

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

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HASFLOCK
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_SH
end_ifndef

begin_define
define|#
directive|define
name|LOCK_SH
value|0x01
end_define

begin_comment
comment|/* shared lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_EX
value|0x02
end_define

begin_comment
comment|/* exclusive lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_NB
value|0x04
end_define

begin_comment
comment|/* non-blocking lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_UN
value|0x08
end_define

begin_comment
comment|/* unlock */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_ERR
end_ifndef

begin_define
define|#
directive|define
name|SIG_ERR
value|((void (*)()) -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Size of tobuf (deliver.c) **	Tweak this to match your syslog implementation.  It will have to **	allow for the extra information printed. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TOBUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|TOBUFSIZE
value|(1024 - 256)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* fork routine -- set above using #ifdef _osname_ or in Makefile */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORK
end_ifndef

begin_define
define|#
directive|define
name|FORK
value|vfork
end_define

begin_comment
comment|/* function to call to fork mailer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

