begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1995 Eric P. Allman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)conf.h	8.170 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* **  CONF.H -- All user-configurable parameters for sendmail ** **	Send updates to sendmail@CS.Berkeley.EDU so they will be **	included in the next release. */
end_comment

begin_struct_decl
struct_decl|struct
name|rusage
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward declaration to get gcc to shut up in wait.h */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
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

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
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
value|200
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
name|MAXALIASDB
value|12
end_define

begin_comment
comment|/* max # of alias databases */
end_comment

begin_define
define|#
directive|define
name|MAXMAPSTACK
value|12
end_define

begin_comment
comment|/* max # of stacked or sequenced maps */
end_comment

begin_define
define|#
directive|define
name|MAXTOCLASS
value|8
end_define

begin_comment
comment|/* max # of message timeout classes */
end_comment

begin_define
define|#
directive|define
name|MAXMIMEARGS
value|20
end_define

begin_comment
comment|/* max args in Content-Type: */
end_comment

begin_define
define|#
directive|define
name|MAXMIMENESTING
value|20
end_define

begin_comment
comment|/* max MIME multipart nesting */
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
value|3000
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
name|NETUNIX
value|1
end_define

begin_comment
comment|/* include unix domain support */
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

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|NEWDB
argument_list|)
operator|||
name|defined
argument_list|(
name|HESIOD
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|USERDB
argument_list|)
end_if

begin_define
define|#
directive|define
name|USERDB
value|1
end_define

begin_comment
comment|/* look in user database */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************************************************************** **  0/1 Compilation options. **	#define these to 1 if they are available; **	#define them to 0 otherwise. **********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_BIND
end_ifndef

begin_define
define|#
directive|define
name|NAMED_BIND
value|1
end_define

begin_comment
comment|/* use Berkeley Internet Domain Server */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DSN
end_ifndef

begin_define
define|#
directive|define
name|DSN
value|1
end_define

begin_comment
comment|/* include delivery status notification code */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIME8TO7
end_ifndef

begin_define
define|#
directive|define
name|MIME8TO7
value|1
end_define

begin_comment
comment|/* 8->7 bit MIME conversions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIME7TO8
end_ifndef

begin_define
define|#
directive|define
name|MIME7TO8
value|1
end_define

begin_comment
comment|/* 7->8 bit MIME conversions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Most systems have symbolic links today, so default them on.  You **  can turn them off by #undef'ing this below. */
end_comment

begin_define
define|#
directive|define
name|HASLSTAT
value|1
end_define

begin_comment
comment|/* has lstat(2) call */
end_comment

begin_comment
comment|/* **  General "standard C" defines. ** **	These may be undone later, to cope with systems that claim to **	be Standard C but aren't.  Gcc is the biggest offender -- it **	doesn't realize that the library is part of the language. ** **	Life would be much easier if we could get rid of this sort **	of bozo problems. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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

begin_escape
end_escape

begin_comment
comment|/********************************************************************** **  Operating system configuration. ** **	Unless you are porting to a new OS, you shouldn't have to **	change these. **********************************************************************/
end_comment

begin_comment
comment|/* **  HP-UX -- tested for 8.07, 9.00, and 9.01. ** **	If V4FS is defined, compile for HP-UX 10.0. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_comment
comment|/* common definitions for HP-UX 9.x and 10.x */
end_comment

begin_undef
undef|#
directive|undef
name|m_flags
end_undef

begin_comment
comment|/* conflict between db.h& sys/sysmacros.h on HP 300 */
end_comment

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
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has useable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|seteuid
parameter_list|(
name|e
parameter_list|)
value|setresuid(-1, e, -1)
end_define

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_HPUX
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_PSTAT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* getusershell(3) causes core dumps */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|syslog
value|hard_syslog
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|int
name|syslog
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|V4FS
end_ifdef

begin_comment
comment|/* HP-UX 10.x */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/stand/vmunix"
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

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|1
end_define

begin_comment
comment|/* TCP/IP implementation fixed in 10.0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HP-UX 9.x */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/hp-ux"
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
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* Something is broken with getsockopt() */
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
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_comment
comment|/* use<sys/statfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
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
comment|/* **  Silicon Graphics IRIX ** **	Compiles on 4.0.1. ** **	Use IRIX64 instead of IRIX for 64-bit IRIX (6.0). **	Use IRIX5 instead of IRIX for IRIX 5.x. ** **	IRIX64 changes from Mark R. Levinson<ml@cvdev.rochester.edu>. **	IRIX5 changes from Kari E. Hurtta<Kari.Hurtta@fmi.fi>. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IRIX64
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX5
argument_list|)
end_if

begin_define
define|#
directive|define
name|IRIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* this is a System-V derived system */
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

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
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
name|setpgid
value|BSDsetpgrp
end_define

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX64
end_ifdef

begin_define
define|#
directive|define
name|NAMELISTMASK
value|0x7fffffffffffffff
end_define

begin_comment
comment|/* mask for nlist() values */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NAMELISTMASK
value|0x7fffffff
end_define

begin_comment
comment|/* mask for nlist() values */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IRIX64
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX5
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARGV_T
value|char *const *
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARGV_T
value|const char **
end_define

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  SunOS and Solaris ** **	Tested on SunOS 4.1.x (a.k.a. Solaris 1.1.x) and **	Solaris 2.4 (a.k.a. SunOS 5.4). */
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
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
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
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* DOES have getusershell(3) call in libc */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS_2_3
end_ifdef

begin_define
define|#
directive|define
name|SOLARIS
value|203
end_define

begin_comment
comment|/* for back compat only -- use -DSOLARIS=203 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS
end_ifdef

begin_comment
comment|/* Solaris 2.x (a.k.a. SunOS 5.x) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4__
end_ifndef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_comment
comment|/* use all System V Releae 4 defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BSD_COMP
value|1
end_define

begin_comment
comment|/* get BSD ioctl calls */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/dev/ksyms"
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
value|"/etc/mail/sendmail.cf"
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

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_HOSTS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_HOSTS
value|"/etc/inet/hosts"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_comment
comment|/* allow full size syslog buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SunOS 4.0.3 or 4.1.x */
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

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

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

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_include
include|#
directive|include
file|<vfork.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS403
end_ifdef

begin_comment
comment|/* special tweaking for SunOS 4.0.3 */
end_comment

begin_include
include|#
directive|include
file|<malloc.h>
end_include

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
name|NEEDSTRSTR
value|1
end_define

begin_comment
comment|/* need emulation of strstr(3) routine */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|HASUNAME
end_undef

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 4.1.x specifics */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has Posix setsid(2) call */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  DG/UX ** **	Tested on 5.4.2 and 5.4.3.  Use DGUX_5_4_2 to get the **	older support. **	5.4.3 changes from Mark T. Robinson<mtr@ornl.gov>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX_5_4_2
end_ifdef

begin_define
define|#
directive|define
name|DGUX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_DGUX
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
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has Posix setsid(2) call */
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
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_comment
comment|/* don't use setproctitle */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_comment
comment|/* these include files must be included early on DG/UX */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX_5_4_2
end_ifdef

begin_define
define|#
directive|define
name|inet_addr
value|dgux_inet_addr
end_define

begin_function_decl
specifier|extern
name|long
name|dgux_inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Digital Ultrix 4.2A or 4.3 ** **	Apparently, fcntl locking is broken on 4.2A, in that locks are **	not dropped when the process exits.  This causes major problems, **	so flock is the only alternative. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
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

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

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

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BROKEN_RES_SEARCH
end_ifndef

begin_define
define|#
directive|define
name|BROKEN_RES_SEARCH
value|1
end_define

begin_comment
comment|/* res_search(unknown) returns h_errno=0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* pre-4.4 TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  OSF/1 for Intel Paragon. ** **	Contributed by Jeff A. Earickson<jeff@ssd.intel.com> **	of Intel Scalable Systems Divison. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__PARAGON__
end_ifdef

begin_define
define|#
directive|define
name|__osf__
value|1
end_define

begin_comment
comment|/* get OSF/1 defines below */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILCF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILCF
value|"/var/adm/sendmail/sendmail.cf"
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
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has useable seteuid(2) call */
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
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

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

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/var/run/sendmail.pid"
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

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

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
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_define
define|#
directive|define
name|UID_T
value|int
end_define

begin_comment
comment|/* compiler gripes on uid_t */
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
name|setpgid
value|setpgrp
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
value|LA_MACH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

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
value|"/etc/sendmail/sendmail.cf"
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
comment|/* **  4.4 BSD ** **	See also BSD defines. */
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

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has useable seteuid(2) call */
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

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|NETLINK
end_define

begin_comment
comment|/* supports AF_LINK */
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

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_PSSTRINGS
end_define

begin_comment
comment|/* use PS_STRINGS pointer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  BSD/386 (all versions) **	From Tony Sanders, BSDI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has the unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has the setsid(2) POSIX syscall */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has useable seteuid(2) call */
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

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|NETLINK
end_define

begin_comment
comment|/* supports AF_LINK */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
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

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_BSDI_VERSION
argument_list|)
operator|&&
name|_BSDI_VERSION
operator|>=
literal|199312
end_if

begin_comment
comment|/* version 1.1 or later */
end_comment

begin_undef
undef|#
directive|undef
name|SPT_TYPE
end_undef

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_BUILTIN
end_define

begin_comment
comment|/* setproctitle is in libc */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* version 1.0 or earlier */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OLD_NEWDB
end_ifndef

begin_define
define|#
directive|define
name|OLD_NEWDB
value|1
end_define

begin_comment
comment|/* old version of newdb library */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  386BSD / FreeBSD 1.0E / NetBSD (all architectures, all versions) ** **  4.3BSD clone, closer to 4.4BSD ** **	See also BSD defines. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__386BSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

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
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has the setsid(2) POSIX syscall */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has useable seteuid(2) call */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) syscall */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|NETLINK
end_define

begin_comment
comment|/* supports AF_LINK */
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

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Mach386 ** **	For mt Xinu's Mach386 system. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MACH
argument_list|)
operator|&&
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_define
define|#
directive|define
name|MACH386
value|1
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

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
name|NEEDSTRTOL
value|1
end_define

begin_comment
comment|/* need the strtol() function */
end_comment

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
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

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_undef
undef|#
directive|undef
name|HASSETVBUF
end_undef

begin_comment
comment|/* don't actually have setvbuf(3) */
end_comment

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

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
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
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
comment|/* **  4.3 BSD -- this is for very old systems ** **	Should work for mt Xinu MORE/BSD and Mips UMIPS-BSD 2.1. ** **	You'll also have to install a new resolver library. **	I don't guarantee that support for this environment is complete. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|oldBSD43
argument_list|)
operator|||
name|defined
argument_list|(
name|MORE_BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|umipsbsd
argument_list|)
end_if

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

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
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
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_typedef
typedef|typedef
name|short
name|pid_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  SCO Unix ** **	This includes two parts -- the first is for SCO Open Server 3.2v4 **	(contributed by Philippe Brand<phb@colombo.telesys-innov.fr>). **	The second is, I believe, for an older version. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SCO_unix_4_2
end_ifdef

begin_define
define|#
directive|define
name|_SCO_unix_
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
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* needs the fsync(2) call stub */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
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
value|"/usr/lib/sendmail.cf"
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
value|"/etc/sendmail.pid"
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
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
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
value|LA_SHORT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* use<sys/statfs.h> 4-arg impl */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_NAME
end_define

begin_comment
comment|/* use tm->tm_name */
end_comment

begin_undef
undef|#
directive|undef
name|NETUNIX
end_undef

begin_comment
comment|/* no unix domain socket support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  ISC (SunSoft) Unix. ** **	Contributed by J.J. Bailey<jjb@jagware.bcc.com> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_UNIX
end_ifdef

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

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
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
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
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* needs the fsync(2) call stub */
end_comment

begin_undef
undef|#
directive|undef
name|NETUNIX
end_undef

begin_comment
comment|/* no unix domain socket support */
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
value|1024
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SHORT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_comment
comment|/* use<sys/statfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
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
value|"/usr/lib/sendmail.cf"
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
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|short
name|pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Altos System V. **	Contributed by Tim Rice<timr@crl.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALTOS_SYS_V
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

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
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* no fsync(2) in system library */
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
value|LA_SHORT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_comment
comment|/* use<sys/statfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_NAME
end_define

begin_comment
comment|/* use tm->tm_name */
end_comment

begin_undef
undef|#
directive|undef
name|NETUNIX
end_undef

begin_comment
comment|/* no unix domain socket support */
end_comment

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_define
define|#
directive|define
name|strtoul
value|strtol
end_define

begin_comment
comment|/* gcc library bogosity */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  ConvexOS 11.0 and later ** **	"Todd C. Miller"<millert@mroe.cs.colorado.edu> claims this **	works on 9.1 as well. */
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
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* Something is broken with getsockopt() */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

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
name|S_IREAD
end_ifndef

begin_define
define|#
directive|define
name|S_IREAD
value|_S_IREAD
end_define

begin_define
define|#
directive|define
name|S_IWRITE
value|_S_IWRITE
end_define

begin_define
define|#
directive|define
name|S_IEXEC
value|_S_IEXEC
end_define

begin_define
define|#
directive|define
name|S_IFMT
value|_S_IFMT
end_define

begin_define
define|#
directive|define
name|S_IFCHR
value|_S_IFCHR
end_define

begin_define
define|#
directive|define
name|S_IFBLK
value|_S_IFBLK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  RISC/os 4.52 ** **	Gives a ton of warning messages, but otherwise compiles. */
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

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

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

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
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

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SIGFUNC_DEFINED
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sigfunc_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Linux 0.99pl10 and above... ** **  Thanks to, in reverse order of contact: ** **	John Kennedy<warlock@csuchico.edu> **	Andrew Pam<avatar@aus.xanadu.com> **	Florian La Roche<rzsfl@rz.uni-sb.de> **	Karl London<karl@borg.demon.co.uk> ** **  Last compiled against:	[05/25/95 @ 11:39:31 AM (Thursday)] **	sendmail 8.7.b.0	named 4.9.3-beta17	db-1.85 **	gcc 2.6.4-950518	libc-5.0.9		linux 1.2.8 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_comment
comment|/* include BSD defines */
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
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
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
name|ERRLIST_PREDEFINED
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_comment
comment|/* from<linux/types.h> */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* getusershell(3) broken in Slackware 2.0 */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* linux<= 1.2.8 doesn't support IP_OPTIONS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_comment
comment|/* flock(2) is broken after 0.99.13 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_PROCSTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() impl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/var/run/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TNAME
end_define

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_undef
undef|#
directive|undef
name|atol
end_undef

begin_comment
comment|/* wounded in<stdlib.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  DELL SVR4 Issue 2.2, and others **	From Kimmo Suominen<kim@grendel.lut.fi> ** **	It's on #ifdef DELL_SVR4 because Solaris also gets __svr4__ **	defined, and the definitions conflict. ** **	Peter Wemm<peter@perth.DIALix.oz.au> claims that the setreuid **	trick works on DELL 2.2 (SVR4.0/386 version 4.0) and ESIX 4.0.3A **	(SVR4.0/386 version 3.0). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DELL_SVR4
end_ifdef

begin_comment
comment|/* no changes necessary */
end_comment

begin_comment
comment|/* see general __svr4__ defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Apple A/UX 3.0 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AUX_SOURCE
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_define
define|#
directive|define
name|BSD
end_define

begin_comment
comment|/* has BSD routines */
end_comment

begin_define
define|#
directive|define
name|BROKEN_RES_SEARCH
value|1
end_define

begin_comment
comment|/* res_search(unknown) returns h_errno=0 */
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
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* we have setvbuf(3) in libc */
end_comment

begin_define
define|#
directive|define
name|SIGFUNC_DEFINED
end_define

begin_comment
comment|/* sigfunc_t already defined */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FORK
value|fork
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
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

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

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Encore UMAX V ** **	Not extensively tested. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UMAXV
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

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
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* we have setvbuf(3) in libc */
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
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
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
name|SYS5SETPGRP
value|1
end_define

begin_comment
comment|/* use System V setpgrp(2) syscall */
end_comment

begin_define
define|#
directive|define
name|FORK
value|fork
end_define

begin_comment
comment|/* no vfork(2) primitive available */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwent
argument_list|()
decl_stmt|,
modifier|*
name|getpwnam
argument_list|()
decl_stmt|,
modifier|*
name|getpwuid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|group
modifier|*
name|getgrent
argument_list|()
decl_stmt|,
modifier|*
name|getgrnam
argument_list|()
decl_stmt|,
modifier|*
name|getgrgid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Stardent Titan 3000 running TitanOS 4.2. ** **	Must be compiled in "cc -43" mode. ** **	From Kate Hedstrom<kate@ahab.rutgers.edu>. ** **	Note the tweaking below after the BSD defines are set. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|titan
end_ifdef

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Sequent DYNIX 3.2.0 ** **	From Jim Davis<jdavis@cs.arizona.edu>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sequent
end_ifdef

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_define
define|#
directive|define
name|BSD4_3
value|1
end_define

begin_comment
comment|/* to get signal() in conf.c */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_VERSION
end_ifdef

begin_undef
undef|#
directive|undef
name|_POSIX_VERSION
end_undef

begin_comment
comment|/* set in<unistd.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|HASSETVBUF
end_undef

begin_comment
comment|/* don't actually have setvbuf(3) */
end_comment

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_comment
comment|/* Have to redefine WIFEXITED to take an int, to work with waitfor() */
end_comment

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|s
parameter_list|)
value|(((union wait*)&(s))->w_stopval != WSTOPPED&& \ 			 ((union wait*)&(s))->w_termsig == 0)
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|s
parameter_list|)
value|(((union wait*)&(s))->w_retcode)
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|isgraph
parameter_list|(
name|c
parameter_list|)
value|(isprint(c)&& (c != ' '))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/dynix"
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Sequent DYNIX/ptx v2.0 (and higher) ** **	For DYNIX/ptx v1.x, undefine HASSETREUID. ** **	From Tim Wright<timw@sequent.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
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
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has POSIX setsid(2) call */
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
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_comment
comment|/* use<sys/statfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_comment
comment|/* don't use setproctitle */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

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
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
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
comment|/* **  Cray Unicos ** **	Ported by David L. Kensiski, Sterling Sofware<kensiski@nas.nasa.gov> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNICOS
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
name|MAXPATHLEN
value|PATHSIZE
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Apollo DomainOS ** **  From Todd Martin<tmartint@tus.ssi1.com>& Don Lewis<gdonl@gv.ssi1.com> ** **  15 Jan 1994 ** */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
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
comment|/* has initgroups(2) call */
end_comment

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_comment
comment|/* don't use setproctitle */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_comment
comment|/* use getloadavg.c */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

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
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|S_IFSOCK
end_undef

begin_comment
comment|/* S_IFSOCK and S_IFIFO are the same */
end_comment

begin_undef
undef|#
directive|undef
name|S_IFIFO
end_undef

begin_define
define|#
directive|define
name|S_IFIFO
value|0010000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  UnixWare 1.1.2. ** **	From Evan Champion<evanc@spatial.synapse.org>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIXWARE
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|SLEEP_T
value|unsigned
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATVFS
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
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
value|"/usr/ucblib/sendmail.cf"
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
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Intergraph CLIX 3.1 ** **	From Paul Southworth<pauls@locust.cic.net> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CLIX
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* looks like System V */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEV_BSIZE
value|512
end_define

begin_comment
comment|/* device block size not defined */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_undef
undef|#
directive|undef
name|LOG
end_undef

begin_comment
comment|/* syslog not available */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* no fsync in system library */
end_comment

begin_define
define|#
directive|define
name|GETSHORT
value|_getshort
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  NCR 3000 Series (SysVr4) ** **	From Kevin Darcy<kevin@tech.mis.cfc.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCR3000
end_ifdef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* Something is broken with getsockopt() */
end_comment

begin_undef
undef|#
directive|undef
name|BSD
end_undef

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Tandem NonStop-UX SVR4 ** **	From Rick McCarty<mccarty@mpd.tandem.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NonStop_UX_BXX
end_ifdef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Hitachi 3050R& 3050RX Workstations running HI-UX/WE2. ** **	Tested for 1.04 and 1.03 **	From Akihiro Hashimoto ("Hash")<hash@dominic.ipc.chiba-u.ac.jp>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__H3050R
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
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
end_define

begin_comment
comment|/* HI-UX has no setlinebuf */
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
value|gid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/HI-UX"
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
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* getusershell(3) causes core dumps */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* avoid m_flags conflict between db.h& sys/sysmacros.h on HIUX 3050 */
end_comment

begin_undef
undef|#
directive|undef
name|m_flags
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|int
name|syslog
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Amdahl UTS System V 2.1.5 (SVr3-based) ** **    From: Janet Jackson<janet@dialix.oz.au>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_UTS
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_undef
undef|#
directive|undef
name|HASLSTAT
end_undef

begin_comment
comment|/* has symlinks, but they cause problems */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* system fsync(2) fails on non-EFS filesys */
end_comment

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* System V signal semantics */
end_comment

begin_define
define|#
directive|define
name|SYS5SETPGRP
value|1
end_define

begin_comment
comment|/* use System V setpgrp(2) syscall */
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
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) function */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* has setvbuf(3) function */
end_comment

begin_define
define|#
directive|define
name|HASSIGSETMASK
value|0
end_define

begin_comment
comment|/* does not have sigsetmask(2) function */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) function */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_comment
comment|/* type of 2nd arg to getgroups(2) isn't int */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_comment
comment|/* doesn't have load average */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* use 4-arg statfs() */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
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
value|"/usr/lib/sendmail.cf"
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
comment|/* **  Cray Computer Corporation's CSOS ** **	From Scott Bolte<scott@craycos.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CRAYCOM
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
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* no fsync in system library */
end_comment

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

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|_POSIX_CHOWN_RESTRICTED
value|-1
end_define

begin_decl_stmt
specifier|extern
name|struct
name|group
modifier|*
name|getgrent
argument_list|()
decl_stmt|,
modifier|*
name|getgrnam
argument_list|()
decl_stmt|,
modifier|*
name|getgrgid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Sony NEWS-OS 4.2.1R and 6.0.3 ** **	From Motonori NAKAMURA<motonori@cs.ritsumei.ac.jp>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sony_news
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4
end_ifndef

begin_comment
comment|/* NEWS-OS 4.2.1R */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
end_define

begin_comment
comment|/* has BSD routines */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(2) call */
end_comment

begin_undef
undef|#
directive|undef
name|HASSETVBUF
end_undef

begin_comment
comment|/* don't actually have setvbuf(3) */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
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
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

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

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sigfunc_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SIGFUNC_DEFINED
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NEWS-OS 6.0.3 with /bin/cc */
end_comment

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
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has useable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has Posix setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* DOES have getusershell(3) call in libc */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_READKSYM
end_define

begin_comment
comment|/* use MIOC_READKSYM ioctl */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATVFS
end_define

begin_comment
comment|/* use<sys/statvfs.h> statvfs() impl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPT_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_SYSMIPS
end_define

begin_comment
comment|/* use sysmips() (OS 6.0.2 or later) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/stand/unix"
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Omron LUNA/UNIOS-B 3.0, LUNA2/Mach and LUNA88K Mach ** **	From Motonori NAKAMURA<motonori@cs.ritsumei.ac.jp>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|luna
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|uniosb
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|NEEDVPRINTF
value|1
end_define

begin_comment
comment|/* need a replacement for vprintf(3) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(2) call */
end_comment

begin_define
define|#
directive|define
name|NEEDPUTENV
value|1
end_define

begin_comment
comment|/* need putenv(3) call */
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
name|NEEDSTRSTR
value|1
end_define

begin_comment
comment|/* need emulation of the strstr(3) call */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|uniosb
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|luna2m
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|luna88k
end_ifdef

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
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sigfunc_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SIGFUNC_DEFINED
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  NEC EWS-UX/V 4.2 (with /usr/ucb/cc) ** **	From Motonori NAKAMURA<motonori@cs.ritsumei.ac.jp>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|nec_ews_svr4
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4__
end_ifndef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_comment
comment|/* use all System V Releae 4 defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has Posix setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_READKSYM
end_define

begin_comment
comment|/* use MIOC_READSYM ioctl */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_USTAT
end_define

begin_comment
comment|/* use System V ustat(2) syscall */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_define
define|#
directive|define
name|NAMELISTMASK
value|0x7fffffff
end_define

begin_comment
comment|/* mask for nlist() values */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************************************************************** **  End of Per-Operating System defines **********************************************************************/
end_comment

begin_escape
end_escape

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
comment|/* has initgroups(3) call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IP_SRCROUTE
end_ifndef

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETRLIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_ZONE
end_define

begin_comment
comment|/* use tm->tm_zone variable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* general System V Release 4 defines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__svr4__
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has useable seteuid(2) call */
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

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETRLIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILCF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILCF
value|"/usr/ucblib/sendmail.cf"
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
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SFS_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATVFS
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
comment|/* general System V defines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTEM5
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

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
name|SYS5SETPGRP
value|1
end_define

begin_comment
comment|/* use System V setpgrp(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* we have setvbuf(3) in libc */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASULIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASULIMIT
value|1
end_define

begin_comment
comment|/* has the ulimit(2) syscall */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MIOC_READKSYM
end_ifdef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_READKSYM
end_define

begin_comment
comment|/* use MIOC_READKSYM ioctl */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_comment
comment|/* assume integer load average */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SFS_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_USTAT
end_define

begin_comment
comment|/* use System V ustat(2) syscall */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

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
comment|/* has Posix setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_comment
comment|/* has Posix waitpid(2) call */
end_comment

begin_if
if|#
directive|if
name|_POSIX_VERSION
operator|>=
literal|199500
operator|&&
operator|!
name|defined
argument_list|(
name|USESETEUID
argument_list|)
end_if

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has useable seteuid(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* **  Tweaking for systems that (for example) claim to be BSD or POSIX **  but don't have all the standard BSD or POSIX routines (boo hiss). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|titan
end_ifdef

begin_undef
undef|#
directive|undef
name|HASINITGROUPS
end_undef

begin_comment
comment|/* doesn't have initgroups(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_CRAYCOM
end_ifdef

begin_undef
undef|#
directive|undef
name|HASSETSID
end_undef

begin_comment
comment|/* despite POSIX claim, doesn't have setsid */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_UNIX
end_ifdef

begin_undef
undef|#
directive|undef
name|bcopy
end_undef

begin_comment
comment|/* despite SystemV claim, uses BSD bcopy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ALTOS_SYS_V
end_ifdef

begin_undef
undef|#
directive|undef
name|bcopy
end_undef

begin_comment
comment|/* despite SystemV claim, uses BSD bcopy */
end_comment

begin_undef
undef|#
directive|undef
name|bzero
end_undef

begin_comment
comment|/* despite SystemV claim, uses BSD bzero */
end_comment

begin_undef
undef|#
directive|undef
name|bcmp
end_undef

begin_comment
comment|/* despite SystemV claim, uses BSD bcmp */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Due to a "feature" in some operating systems such as Ultrix 4.3 and **  HPUX 8.0, if you receive a "No route to host" message (ICMP message **  ICMP_UNREACH_HOST) on _any_ connection, all connections to that host **  are closed.  Some firewalls return this error if you try to connect **  to the IDENT port (113), so you can't receive email from these hosts **  on these systems.  The firewall really should use a more specific **  message such as ICMP_UNREACH_PROTOCOL or _PORT or _NET_PROHIB.  If **  not explicitly set to zero above, default it on. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|1
end_define

begin_comment
comment|/* use IDENT proto (RFC 1413) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IP_SRCROUTE
end_ifndef

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* Detect IP source routing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* libc has getusershell(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_comment
comment|/* assume no flock(2) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETREUID
end_ifndef

begin_define
define|#
directive|define
name|HASSETREUID
value|0
end_define

begin_comment
comment|/* assume no setreuid(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USESETEUID
end_ifndef

begin_define
define|#
directive|define
name|USESETEUID
value|0
end_define

begin_comment
comment|/* assume no seteuid(2) call or no saved ids */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETRLIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|0
end_define

begin_comment
comment|/* assume no setrlimit(2) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASULIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASULIMIT
value|0
end_define

begin_comment
comment|/* assume no ulimit(2) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OLD_NEWDB
end_ifndef

begin_define
define|#
directive|define
name|OLD_NEWDB
value|0
end_define

begin_comment
comment|/* assume newer version of newdb */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* heuristic setting of HASSETSIGMASK; can override above */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASSIGSETMASK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SIGVTALRM
end_ifdef

begin_define
define|#
directive|define
name|HASSETSIGMASK
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HASSETSIGMASK
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

begin_ifndef
ifndef|#
directive|ifndef
name|UID_T
end_ifndef

begin_define
define|#
directive|define
name|UID_T
value|uid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_T
end_ifndef

begin_define
define|#
directive|define
name|SIZE_T
value|size_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARGV_T
end_ifndef

begin_define
define|#
directive|define
name|ARGV_T
value|char **
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/********************************************************************** **  Remaining definitions should never have to be changed.  They are **  primarily to provide back compatibility for older systems -- for **  example, it includes some POSIX compatibility definitions **********************************************************************/
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
value|((foo& S_IFMT) == S_IFREG)
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
name|S_ISLNK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFLNK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|foo
parameter_list|)
value|((foo& S_IFMT) == S_IFLNK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IWUSR
value|0200
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
value|0020
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
value|0002
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
comment|/* pseudo-code used in server SMTP */
end_comment

begin_define
define|#
directive|define
name|EX_QUIT
value|22
end_define

begin_comment
comment|/* drop out of server immediately */
end_comment

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

begin_if
if|#
directive|if
name|NAMED_BIND
end_if

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__svr4__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NOERROR
end_ifdef

begin_undef
undef|#
directive|undef
name|NOERROR
end_undef

begin_comment
comment|/* avoid compiler conflict with stream.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  The size of an IP address -- can't use sizeof because of problems **  on Crays, where everything is 64 bits.  This will break if/when **  IP addresses are expanded to eight bytes. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INADDRSZ
end_ifndef

begin_define
define|#
directive|define
name|INADDRSZ
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  The size of various known types -- for reading network protocols. **  Again, we can't use sizeof because of compiler randomness. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT16SZ
end_ifndef

begin_define
define|#
directive|define
name|INT16SZ
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT32SZ
end_ifndef

begin_define
define|#
directive|define
name|INT32SZ
value|4
end_define

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
operator|&&
operator|!
name|defined
argument_list|(
name|NonStop_UX_BXX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ALTOS_SYS_V
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
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|st
parameter_list|)
value|(((st)>> 8)& 0377)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|st
parameter_list|)
value|(((st)& 0377) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGFUNC_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*sigfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* size of syslog buffer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
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

begin_if
if|#
directive|if
operator|(
name|SYSLOG_BUFSIZE
operator|)
operator|>
literal|512
end_if

begin_define
define|#
directive|define
name|TOBUFSIZE
value|(SYSLOG_BUFSIZE - 256)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TOBUFSIZE
value|256
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
comment|/* **  Size of prescan buffer. **	Despite comments in the _sendmail_ book, this probably should **	not be changed; there are some hard-to-define dependencies. */
end_comment

begin_define
define|#
directive|define
name|PSBUFSIZE
value|(MAXNAME + MAXATOM)
end_define

begin_comment
comment|/* size of prescan buffer */
end_comment

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

begin_comment
comment|/* **  If we are going to link scanf anyway, use it in readcf */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HASUNAME
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SCANF
argument_list|)
end_if

begin_define
define|#
directive|define
name|SCANF
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

