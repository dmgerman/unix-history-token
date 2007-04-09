begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2007 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: conf.h,v 1.132 2007/03/21 23:56:18 ca Exp $  */
end_comment

begin_comment
comment|/* **  CONF.H -- All user-configurable parameters for sendmail ** **	Send updates to Sendmail.ORG so they will be **	included in the next release; see **	http://www.sendmail.org/email-addresses.html **	for current e-mail address. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_H
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_H
value|1
end_define

begin_include
include|#
directive|include
file|<sm/config.h>
end_include

begin_include
include|#
directive|include
file|<sm/varargs.h>
end_include

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

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/* **  Assume you have standard calls; can be #undefed below if necessary. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASLSTAT
end_ifndef

begin_define
define|#
directive|define
name|HASLSTAT
value|1
end_define

begin_comment
comment|/* has lstat(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASLSTAT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASNICE
end_ifndef

begin_define
define|#
directive|define
name|HASNICE
value|1
end_define

begin_comment
comment|/* has nice(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASNICE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASRRESVPORT
end_ifndef

begin_define
define|#
directive|define
name|HASRRESVPORT
value|1
end_define

begin_comment
comment|/* has rrsevport(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASRRESVPORT */
end_comment

begin_comment
comment|/********************************************************************** **  "Hard" compilation options. **	#define these if they are available; comment them out otherwise. **  These cannot be overridden from the Makefile, and should really not **  be turned off unless absolutely necessary. **********************************************************************/
end_comment

begin_define
define|#
directive|define
name|LOG
value|1
end_define

begin_comment
comment|/* enable logging -- don't turn off */
end_comment

begin_comment
comment|/********************************************************************** **  Operating system configuration. ** **	Unless you are porting to a new OS, you shouldn't have to **	change these. **********************************************************************/
end_comment

begin_comment
comment|/* **  HP-UX -- tested for 8.07, 9.00, and 9.01. ** **	If V4FS is defined, compile for HP-UX 10.0. **	11.x support from Richard Allen<ra@hp.is>. */
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
comment|/* conflict between Berkeley DB 1.85 db.h& sys/sysmacros.h on HP 300 */
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
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASSETRESGID
value|1
end_define

begin_comment
comment|/* use setresgid(2) to set saved gid */
end_comment

begin_define
define|#
directive|define
name|BOGUS_O_EXCL
value|1
end_define

begin_comment
comment|/* exclusive open follows symlinks */
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

begin_define
define|#
directive|define
name|LDA_USE_LOCKF
value|1
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

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX10
end_ifdef

begin_define
define|#
directive|define
name|_PATH_SENDMAIL
value|"/usr/sbin/sendmail"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SMRSH_CMDDIR
end_ifndef

begin_define
define|#
directive|define
name|SMRSH_CMDDIR
value|"/var/adm/sm.bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SMRSH_CMDDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX10 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX11
end_ifdef

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* setreuid(2) works on HP-UX 11.x */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) */
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

begin_comment
comment|/* ! BROKEN_RES_SEARCH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMRSH_CMDDIR
end_ifndef

begin_define
define|#
directive|define
name|SMRSH_CMDDIR
value|"/var/adm/sm.bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SMRSH_CMDDIR */
end_comment

begin_define
define|#
directive|define
name|_PATH_SENDMAIL
value|"/usr/sbin/sendmail"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HPUX11 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOT_SENDMAIL
end_ifndef

begin_define
define|#
directive|define
name|syslog
value|hard_syslog
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NOT_SENDMAIL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX11 */
end_comment

begin_define
define|#
directive|define
name|SAFENFSPATHCONF
value|1
end_define

begin_comment
comment|/* pathconf(2) pessimizes on NFS filesystems */
end_comment

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
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
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
comment|/* TCP/IP implementation fixed in 10.0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_include
include|#
directive|include
file|<sys/mpctl.h>
end_include

begin_comment
comment|/* for mpctl() in get_num_procs_online() */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* V4FS */
end_comment

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
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|hard_syslog
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_function_decl
specifier|extern
name|void
name|hard_syslog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|FDSET_CAST
value|(int *)
end_define

begin_comment
comment|/* cast for fd_set parameters to select */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V4FS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hpux */
end_comment

begin_comment
comment|/* **  IBM AIX 5.x */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX5
end_ifdef

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_define
define|#
directive|define
name|_AIX4
value|40300
end_define

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|socklen_t
end_define

begin_comment
comment|/* e.g., arg#3 to accept, getsockname */
end_comment

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|socklen_t
end_define

begin_comment
comment|/* arg#5 to getsockopt */
end_comment

begin_if
if|#
directive|if
name|_AIX5
operator|>=
literal|50200
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX5>= 50200 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX5 */
end_comment

begin_comment
comment|/* **  IBM AIX 4.x */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX4
end_ifdef

begin_define
define|#
directive|define
name|_AIX3
value|1
end_define

begin_comment
comment|/* pull in AIX3 stuff */
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
name|USESETEUID
value|1
end_define

begin_comment
comment|/* seteuid(2) works */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_NAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOCKOPT_LEN_T
end_ifndef

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|size_t
end_define

begin_comment
comment|/* arg#5 to getsockopt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOCKOPT_LEN_T */
end_comment

begin_if
if|#
directive|if
name|_AIX4
operator|>=
literal|40200
end_if

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* setreuid(2) works as of AIX 4.2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOCKADDR_LEN_T
end_ifndef

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|size_t
end_define

begin_comment
comment|/* e.g., arg#3 to accept, getsockname */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOCKADDR_LEN_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX4>= 40200 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ILS_MACROS
argument_list|)
end_if

begin_comment
comment|/* IBM versions aren't side-effect clean */
end_comment

begin_undef
undef|#
directive|undef
name|isascii
end_undef

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|!(c& ~0177)
end_define

begin_undef
undef|#
directive|undef
name|isdigit
end_undef

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|__a
parameter_list|)
value|(_IS(__a,_ISDIGIT))
end_define

begin_undef
undef|#
directive|undef
name|isspace
end_undef

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|__a
parameter_list|)
value|(_IS(__a,_ISSPACE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_ILS_MACROS) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX4 */
end_comment

begin_comment
comment|/* **  IBM AIX 3.x -- actually tested for 3.2.3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX3
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<sys/machine.h>
end_include

begin_comment
comment|/* to get byte order */
end_comment

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) */
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
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
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

begin_comment
comment|/* LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|FSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_AIX4
argument_list|)
operator|||
name|_AIX4
operator|<
literal|40300
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__BIT_TYPES_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|SM_INT32
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BIT_TYPES_DEFINED__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_AIX4) || _AIX4< 40300 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_AIX4
argument_list|)
operator|||
name|_AIX4
operator|<
literal|40200
end_if

begin_define
define|#
directive|define
name|SM_CONF_SYSLOG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_AIX4) || _AIX4< 40200 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX3 */
end_comment

begin_comment
comment|/* **  IBM AIX 2.2.1 -- actually tested for osupdate level 2706+1773 ** **	From Mark Whetzel<markw@wg.waii.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIX
end_ifdef

begin_comment
comment|/* AIX/RT compiler pre-defines this */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* AIX/RT resource.h does NOT include this */
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
name|HASFCHMOD
value|0
end_define

begin_comment
comment|/* does not have fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* use setreuid(2) -lbsd system call */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* use setvbuf(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|0
end_define

begin_comment
comment|/* does not have setrlimit call */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_comment
comment|/* does not have flock call - use fcntl */
end_comment

begin_define
define|#
directive|define
name|HASULIMIT
value|1
end_define

begin_comment
comment|/* use ulimit instead of setrlimit call */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_GETOPT
value|0
end_define

begin_comment
comment|/* Do we need theirs or ours */
end_comment

begin_define
define|#
directive|define
name|SYS5SETPGRP
value|1
end_define

begin_comment
comment|/* don't have setpgid on AIX/RT */
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
name|BSD4_3
value|1
end_define

begin_comment
comment|/* NOT bsd 4.4 or posix signals */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|int
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
value|LA_SUBR
end_define

begin_comment
comment|/* use our ported loadavgd daemon */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

begin_define
define|#
directive|define
name|ARBPTR_T
value|int *
end_define

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_comment
comment|/* RTisms for BSD compatibility, specified in the Makefile   define BSD		1   define BSD_INCLUDES		1   define BSD_REMAP_SIGNAL_TO_SIGVEC     RTisms needed above */
end_comment

begin_comment
comment|/* make this sendmail in a completely different place */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/local/newmail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/usr/local/newmail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|LDA_USE_LOCKF
value|1
end_define

begin_define
define|#
directive|define
name|LDA_USE_SETEUID
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_AIX) */
end_comment

begin_comment
comment|/* **  Silicon Graphics IRIX ** **	Compiles on 4.0.1. ** **	Use IRIX64 instead of IRIX for 64-bit IRIX (6.0). **	Use IRIX5 instead of IRIX for IRIX 5.x. ** **	IRIX64 changes from Mark R. Levinson<ml@cvdev.rochester.edu>. **	IRIX5 changes from Kari E. Hurtta<Kari.Hurtta@fmi.fi>. */
end_comment

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
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
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
name|SYSLOG_BUFSIZE
value|512
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SC_NPROC_ONLN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SC_NPROCESSORS_ONLN
argument_list|)
end_if

begin_comment
comment|/* _SC_NPROC_ONLN is 'mpadmin -u', total # of unrestricted processors */
end_comment

begin_define
define|#
directive|define
name|_SC_NPROCESSORS_ONLN
value|_SC_NPROC_ONLN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* if defined(_SC_NPROC_ONLN)&& !defined(_SC_NPROCESSORS_ONLN) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX6
end_ifdef

begin_define
define|#
directive|define
name|STAT64
value|1
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_IRIX6
end_define

begin_comment
comment|/* figure out at run time */
end_comment

begin_define
define|#
directive|define
name|SAFENFSPATHCONF
value|0
end_define

begin_comment
comment|/* pathconf(2) lies on NFS filesystems */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IRIX6 */
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
name|STAT64
value|1
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|unsigned long long
end_define

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

begin_comment
comment|/* IRIX64 */
end_comment

begin_define
define|#
directive|define
name|STAT64
value|0
end_define

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
comment|/* IRIX64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX6 */
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
operator|||
name|defined
argument_list|(
name|IRIX6
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|ARGV_T
value|char *const *
end_define

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(IRIX64) || defined(IRIX5) || defined(IRIX6) */
end_comment

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

begin_comment
comment|/* defined(IRIX64) || defined(IRIX5) || defined(IRIX6) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX */
end_comment

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

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

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
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
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
name|SAFENFSPATHCONF
value|1
end_define

begin_comment
comment|/* pathconf(2) pessimizes on NFS filesystems */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFCHOWN
end_ifndef

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* fchown(2) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFCHOWN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__svr4__
end_ifdef

begin_define
define|#
directive|define
name|LDA_USE_LOCKF
value|1
end_define

begin_define
define|#
directive|define
name|LDA_USE_SETEUID
value|1
end_define

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|"/var/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __svr4__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS_2_3
end_ifdef

begin_define
define|#
directive|define
name|SOLARIS
value|20300
end_define

begin_comment
comment|/* for back compat only -- use -DSOLARIS=20300 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS_2_3 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NOT_SENDMAIL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SOLARIS
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|SOLARIS
value|1
end_define

begin_comment
comment|/* unknown Solaris version */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NOT_SENDMAIL)&& !defined(SOLARIS)&& defined(sun)&& (defined(__svr4__) || defined(__SVR4)) */
end_comment

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
comment|/* use all System V Release 4 defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4__ */
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
name|USE_SA_SIGACTION
value|1
end_define

begin_comment
comment|/* use sa_sigaction field */
end_comment

begin_define
define|#
directive|define
name|BROKEN_PTHREAD_SLEEP
value|1
end_define

begin_comment
comment|/* sleep after pthread_create() fails */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

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

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

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

begin_comment
comment|/* ! _PATH_HOSTS */
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

begin_comment
comment|/* allow full size syslog buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20300
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|203
operator|)
end_if

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* seteuid works as of 2.3 */
end_comment

begin_define
define|#
directive|define
name|LDA_CONTENTLENGTH
value|1
end_define

begin_comment
comment|/* Needs the Content-Length header */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20300 || (SOLARIS< 10000&& SOLARIS>= 203) */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20500
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|205
operator|)
end_if

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* setreuid works as of 2.5 */
end_comment

begin_define
define|#
directive|define
name|HASSETREGID
value|1
end_define

begin_comment
comment|/* use setregid(2) to set saved gid */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20600
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|206
operator|)
end_if

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3c) starting in 2.6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20600 || (SOLARIS< 10000&& SOLARIS>= 206) */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|<
literal|207
operator|||
operator|(
name|SOLARIS
operator|>
literal|10000
operator|&&
name|SOLARIS
operator|<
literal|20700
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_KSTAT
end_define

begin_comment
comment|/* use kstat(3k) -- may work in< 2.5 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RANDOMSHIFT
end_ifndef

begin_comment
comment|/* random() doesn't work well (sometimes) */
end_comment

begin_define
define|#
directive|define
name|RANDOMSHIFT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! RANDOMSHIFT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS< 207 || (SOLARIS> 10000&& SOLARIS< 20700) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS>= 20500 || (SOLARIS< 10000&& SOLARIS>= 205) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASRANDOM
end_ifndef

begin_define
define|#
directive|define
name|HASRANDOM
value|0
end_define

begin_comment
comment|/* doesn't have random(3) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASRANDOM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20500 || (SOLARIS< 10000&& SOLARIS>= 205) */
end_comment

begin_if
if|#
directive|if
operator|(
name|SOLARIS
operator|>
literal|10000
operator|&&
name|SOLARIS
operator|<
literal|20600
operator|)
operator|||
name|SOLARIS
operator|<
literal|206
end_if

begin_define
define|#
directive|define
name|SM_INT32
value|int
end_define

begin_comment
comment|/* 32bit integer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (SOLARIS> 10000&& SOLARIS< 20600) || SOLARIS< 206 */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20700
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|207
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_include
include|#
directive|include
file|<sys/loadavg.h>
end_include

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20900
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|209
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/pset.h>
end_include

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_PSET
end_define

begin_comment
comment|/* pset_getloadavg(3c) appears in 2.9 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS>= 20900 || (SOLARIS< 10000&& SOLARIS>= 209) */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_comment
comment|/* getloadavg(3c) appears in 2.7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20900 || (SOLARIS< 10000&& SOLARIS>= 209) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* getusershell(3c) bug fixed in 2.7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20700 || (SOLARIS< 10000&& SOLARIS>= 207) */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20800
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|208
operator|)
end_if

begin_undef
undef|#
directive|undef
name|_PATH_SENDMAILPID
end_undef

begin_comment
comment|/* tmpfs /var/run added in 2.8 */
end_comment

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/var/run/sendmail.pid"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SMRSH_CMDDIR
end_ifndef

begin_define
define|#
directive|define
name|SMRSH_CMDDIR
value|"/var/adm/sm.bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SMRSH_CMDDIR */
end_comment

begin_define
define|#
directive|define
name|SL_FUDGE
value|34
end_define

begin_comment
comment|/* fudge offset for SyslogPrefixLen */
end_comment

begin_define
define|#
directive|define
name|HASLDAPGETALIASBYNAME
value|1
end_define

begin_comment
comment|/* added in S8 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20800 || (SOLARIS< 10000&& SOLARIS>= 208) */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20900
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|209
operator|)
end_if

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* /dev/[u]random added in S9 */
end_comment

begin_define
define|#
directive|define
name|HASCLOSEFROM
value|1
end_define

begin_comment
comment|/* closefrom(3c) added in S9 */
end_comment

begin_define
define|#
directive|define
name|HASFDWALK
value|1
end_define

begin_comment
comment|/* fdwalk(3c) added in S9 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20900 || (SOLARIS< 10000&& SOLARIS>= 209) */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|21000
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|210
operator|)
end_if

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* unsetenv() added in S10 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 21000 || (SOLARIS< 10000&& SOLARIS>= 210) */
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
comment|/* getusershell(3) causes core dumps pre-2.7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS */
end_comment

begin_comment
comment|/* SunOS 4.0.3 or 4.1.x */
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

begin_comment
comment|/* ! HASFLOCK */
end_comment

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
name|TZ_TYPE
value|TZ_TM_ZONE
end_define

begin_comment
comment|/* use tm->tm_zone */
end_comment

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_include
include|#
directive|include
file|<vfork.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|strtoul
value|strtol
end_define

begin_comment
comment|/* gcc library bogosity */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|(bcopy((s), (d), (l)))
end_define

begin_define
define|#
directive|define
name|atexit
parameter_list|(
name|f
parameter_list|)
value|on_exit((f), 0)
end_define

begin_comment
comment|/* ugly hack for SunOS */
end_comment

begin_define
define|#
directive|define
name|SM_INT32
value|int
end_define

begin_comment
comment|/* 32bit integer */
end_comment

begin_define
define|#
directive|define
name|SM_ALIGN_SIZE
value|(sizeof(long))
end_define

begin_define
define|#
directive|define
name|GIDSET_T
value|int
end_define

begin_define
define|#
directive|define
name|SM_CONF_SYSLOG
value|0
end_define

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
name|BSD4_3
value|1
end_define

begin_comment
comment|/* 4.3 BSD-based */
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

begin_define
define|#
directive|define
name|MODE_T
value|int
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
comment|/* SUNOS403 */
end_comment

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
comment|/* has POSIX setsid(2) call */
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

begin_comment
comment|/* SUNOS403 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS */
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

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(sun)&& !defined(BSD) */
end_comment

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

begin_comment
comment|/* DGUX_5_4_2 */
end_comment

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
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* does not have<netinet/ip_var.h> */
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

begin_comment
comment|/* ! IDENTPROTO */
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
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|LDA_USE_LOCKF
value|1
end_define

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

begin_comment
comment|/* compiler doesn't understand const? */
end_comment

begin_define
define|#
directive|define
name|const
end_define

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

begin_comment
comment|/* DGUX_5_4_2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX */
end_comment

begin_comment
comment|/* **  Digital Ultrix 4.2 - 4.5 ** **	Apparently, fcntl locking is broken on 4.2A, in that locks are **	not dropped when the process exits.  This causes major problems, **	so flock is the only alternative. */
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

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) syscall */
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

begin_comment
comment|/* ! HASFLOCK */
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

begin_comment
comment|/* ! BROKEN_RES_SEARCH */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NEEDLOCAL_HOSTNAME_LENGTH
argument_list|)
operator|&&
name|NAMED_BIND
operator|&&
name|__RES
operator|>=
literal|19931104
operator|&&
name|__RES
operator|<
literal|19950621
end_if

begin_define
define|#
directive|define
name|NEEDLOCAL_HOSTNAME_LENGTH
value|1
end_define

begin_comment
comment|/* see sendmail/README */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NEEDLOCAL_HOSTNAME_LENGTH)&& NAMED_BIND&& __RES>= 19931104&& __RES< 19950621 */
end_comment

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

begin_comment
comment|/* vax */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax */
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

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|256
end_define

begin_define
define|#
directive|define
name|SM_CONF_SYSLOG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ultrix */
end_comment

begin_comment
comment|/* **  OSF/1 for KSR. ** **	Contributed by Todd C. Miller<Todd.Miller@cs.colorado.edu> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ksr__
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

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ksr__ */
end_comment

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

begin_comment
comment|/* ! TZ_TYPE */
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
name|MAXNAMLEN
value|NAME_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PARAGON__ */
end_comment

begin_comment
comment|/* **  Tru64 UNIX, formerly known as Digital UNIX, formerly known as DEC OSF/1 ** **	Tested for 3.2 and 4.0. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__osf__
end_ifdef

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) call */
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
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
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
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETLOGIN
value|1
end_define

begin_comment
comment|/* has setlogin(2) */
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
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
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
name|SM_INT32
value|int
end_define

begin_comment
comment|/* 32bit integer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_include
include|#
directive|include
file|<standards.h>
end_include

begin_if
if|#
directive|if
name|_XOPEN_SOURCE
operator|+
literal|0
operator|>=
literal|400
end_if

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_comment
comment|/* 5.0 and later has bad flock(2) call */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _XOPEN_SOURCE+0>= 400 */
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
comment|/* _XOPEN_SOURCE+0>= 400 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ALPHAOSF
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATVFS
end_define

begin_comment
comment|/* use<sys/statvfs.h> statfs() impl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/var/adm/sendmail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_if
if|#
directive|if
name|_FFR_DIGUNIX_SAFECHOWN
end_if

begin_comment
comment|/* **  Testing on a Digital UNIX 4.0a system showed this to be the correct **  setting but given the security consequences, more testing and **  verification is needed.  Unfortunately, the man page offers no **  assistance. */
end_comment

begin_define
define|#
directive|define
name|IS_SAFE_CHOWN
value|>= 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_DIGUNIX_SAFECHOWN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __osf__ */
end_comment

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
name|NEEDPUTENV
value|2
end_define

begin_comment
comment|/* need putenv(3) call; no setenv(3) call */
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

begin_comment
comment|/* ! HASFLOCK */
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
name|GID_T
value|int
end_define

begin_comment
comment|/* ditto for gid_t */
end_comment

begin_define
define|#
directive|define
name|MODE_T
value|int
end_define

begin_comment
comment|/* and mode_t */
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
name|NOT_SENDMAIL
end_ifndef

begin_define
define|#
directive|define
name|sleep
value|sleepX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NOT_SENDMAIL */
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
value|LA_MACH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwent
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_GETOPT
value|0
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

begin_undef
undef|#
directive|undef
name|WIFSTOPPED
end_undef

begin_undef
undef|#
directive|undef
name|WTERMSIG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/sendmail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/sendmail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_define
define|#
directive|define
name|SM_INT32
value|int
end_define

begin_comment
comment|/* 32bit integer */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TCPWRAPPERS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HASUNSETENV
end_ifndef

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASUNSETENV */
end_comment

begin_undef
undef|#
directive|undef
name|NEEDPUTENV
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPWRAPPERS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__APPLE__
end_ifndef

begin_include
include|#
directive|include
file|<libc.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IRUSR
value|S_IREAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IRUSR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IWUSR
value|S_IWRITE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IWUSR */
end_comment

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|"/usr/spool/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __APPLE__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|isascii
end_ifndef

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|((unsigned)(c)<= 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! isascii */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeXT */
end_comment

begin_comment
comment|/* **  Apple Darwin **      Contributed by Wilfredo Sanchez<wsanchez@mit.edu> */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DARWIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) */
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
comment|/* has initgroups(3) */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* has setvbuf (3) */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|0
end_define

begin_comment
comment|/* setreuid(2) unusable */
end_comment

begin_define
define|#
directive|define
name|HASSETEUID
value|1
end_define

begin_comment
comment|/* has seteuid(2) */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has seteuid(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETEGID
value|1
end_define

begin_comment
comment|/* has setegid(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETREGID
value|1
end_define

begin_comment
comment|/* has setregid(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETRESGID
value|0
end_define

begin_comment
comment|/* no setresgid(2) */
end_comment

begin_define
define|#
directive|define
name|HASLSTAT
value|1
end_define

begin_comment
comment|/* has lstat(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) */
end_comment

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_comment
comment|/* has waitpid(2) */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in struct stat */
end_comment

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* has urandom(4) */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* had getusershell(3) */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_comment
comment|/* getgroups(2) takes gid_t */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_comment
comment|/* use getloadavg(3) */
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

begin_if
if|#
directive|if
name|DARWIN
operator|>=
literal|70000
end_if

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|socklen_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|DARWIN
operator|>=
literal|80000
end_if

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_REUSEARGV
end_define

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|socklen_t
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_PSSTRINGS
end_define

begin_comment
comment|/* use magic PS_STRINGS pointer for setproctitle */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* struct sockaddr has sa_len */
end_comment

begin_define
define|#
directive|define
name|SAFENFSPATHCONF
value|0
end_define

begin_comment
comment|/* unverified: pathconf(2) doesn't work on NFS */
end_comment

begin_define
define|#
directive|define
name|HAS_IN_H
value|1
end_define

begin_define
define|#
directive|define
name|NETLINK
value|1
end_define

begin_comment
comment|/* supports AF_LINK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOT_SENDMAIL
end_ifndef

begin_define
define|#
directive|define
name|sleep
value|sleepX
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|sleepX
name|__P
argument_list|(
operator|(
name|unsigned
name|int
name|seconds
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NOT_SENDMAIL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DARWIN) */
end_comment

begin_comment
comment|/* **  4.4 BSD ** **	See also BSD defines. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DARWIN
argument_list|)
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

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
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
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
name|NEED_PRINTF_PERCENTQ
value|1
end_define

begin_comment
comment|/* doesn't have %lld */
end_comment

begin_define
define|#
directive|define
name|NETLINK
value|1
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

begin_comment
comment|/* ! LA_TYPE */
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
comment|/* defined(BSD4_4)&& !defined(__bsdi__)&& !defined(__GNU__)&& !defined(DARWIN)*/
end_comment

begin_comment
comment|/* **  BSD/OS (was BSD/386) (all versions) **	From Tony Sanders, BSDI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

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
name|HASSETREUID
value|0
end_define

begin_comment
comment|/* BSD-OS has broken setreuid(2) emulation */
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
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETLOGIN
value|1
end_define

begin_comment
comment|/* has setlogin(2) */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
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
value|1
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

begin_comment
comment|/* ! LA_TYPE */
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
name|QUAD_T
value|quad_t
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
comment|/* defined(_BSDI_VERSION)&& _BSDI_VERSION>= 199312 */
end_comment

begin_comment
comment|/* version 1.0 or earlier */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_BSDI_VERSION)&& _BSDI_VERSION>= 199312 */
end_comment

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
literal|199701
end_if

begin_comment
comment|/* on 3.x */
end_comment

begin_define
define|#
directive|define
name|HASSETUSERCONTEXT
value|1
end_define

begin_comment
comment|/* has setusercontext */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_BSDI_VERSION)&& _BSDI_VERSION>= 199701 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_BSDI_VERSION
argument_list|)
operator|&&
name|_BSDI_VERSION
operator|<=
literal|199701
end_if

begin_comment
comment|/* 3.1 and earlier */
end_comment

begin_define
define|#
directive|define
name|MODE_T
value|int
end_define

begin_comment
comment|/* va_arg() can't handle less than int */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_BSDI_VERSION)&& _BSDI_VERSION<= 199701 */
end_comment

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
literal|199910
end_if

begin_comment
comment|/* on 4.x */
end_comment

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* has /dev/urandom(4) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_BSDI_VERSION)&& _BSDI_VERSION>= 199910 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __bsdi__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__QNX__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__QNXNTO__
argument_list|)
end_if

begin_comment
comment|/* QNX 6 */
end_comment

begin_include
include|#
directive|include
file|<unix.h>
end_include

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
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has POSIX setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
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
name|ERRLIST_PREDEFINED
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_define
define|#
directive|define
name|NETLINK
value|1
end_define

begin_comment
comment|/* supports AF_LINK */
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
name|QUAD_T
value|uint64_t
end_define

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) (all versions?) */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* **  We have a strrev() that doesn't allocate anything. **  Make sure the one here is used. */
end_comment

begin_define
define|#
directive|define
name|strrev
value|strrev_sendmail
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__QNXNTO__) */
end_comment

begin_comment
comment|/* **  QNX 4.2x **	Contributed by Glen McCready<glen@qnx.com>. ** **	Should work with all versions of QNX 4. */
end_comment

begin_include
include|#
directive|include
file|<unix.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_undef
undef|#
directive|undef
name|NGROUPS_MAX
end_undef

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
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

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
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_undef
undef|#
directive|undef
name|HASINITGROUPS
end_undef

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_GETOPT
value|0
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
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
name|TZ_TYPE
value|TZ_TMNAME
end_define

begin_comment
comment|/* use tmname variable */
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
value|LA_ZERO
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_NONE
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_REUSEARGV
end_define

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
name|HASGETUSERSHELL
value|0
end_define

begin_define
define|#
directive|define
name|_FILE_H_INCLUDED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__QNXNTO__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__QNX__) */
end_comment

begin_comment
comment|/* **  DragonFly BSD/ FreeBSD / NetBSD / OpenBSD (all architectures, all versions) ** **  4.3BSD clone, closer to 4.4BSD	for FreeBSD 1.x and NetBSD 0.9x **  4.4BSD-Lite based			for FreeBSD 2.x and NetBSD 1.x ** **	See also BSD defines. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__DragonFly__
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
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

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
comment|/* has POSIX setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
end_comment

begin_define
define|#
directive|define
name|NEED_PRINTF_PERCENTQ
value|1
end_define

begin_comment
comment|/* doesn't have %lld */
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
value|1
end_define

begin_comment
comment|/* supports AF_LINK */
end_comment

begin_define
define|#
directive|define
name|SAFENFSPATHCONF
value|1
end_define

begin_comment
comment|/* pathconf(2) pessimizes on NFS filesystems */
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
name|QUAD_T
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) (all versions?) */
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

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__NetBSD_Version__
argument_list|)
operator|&&
expr|\
operator|(
operator|(
name|__NetBSD_Version__
operator|>=
literal|200040000
operator|&&
name|__NetBSD_Version__
operator|<
literal|200090000
operator|)
operator|||
expr|\
operator|(
name|__NetBSD_Version__
operator|>=
literal|299000900
operator|)
operator|)
end_if

begin_undef
undef|#
directive|undef
name|SFS_TYPE
end_undef

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATVFS
end_define

begin_else
else|#
directive|else
end_else

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|(
name|NetBSD
operator|>
literal|199307
operator|||
name|NetBSD0_9
operator|>
literal|1
operator|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__NetBSD__)&& (NetBSD> 199307 || NetBSD0_9> 1) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|(
operator|(
name|__NetBSD_Version__
operator|>
literal|102070000
operator|)
operator|||
operator|(
name|NetBSD1_2
operator|>
literal|8
operator|)
operator|||
name|defined
argument_list|(
name|NetBSD1_4
argument_list|)
operator|||
name|defined
argument_list|(
name|NetBSD1_3
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* has /dev/urandom(4) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__NetBSD__)&& ((__NetBSD_Version__> 102070000) || (NetBSD1_2> 8) || defined(NetBSD1_4) || defined(NetBSD1_3)) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__NetBSD_Version__
argument_list|)
operator|&&
name|__NetBSD_Version__
operator|>=
literal|104170000
end_if

begin_define
define|#
directive|define
name|HASSETUSERCONTEXT
value|1
end_define

begin_comment
comment|/* BSDI-style login classes */
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
name|__NetBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__NetBSD_Version__
argument_list|)
operator|&&
expr|\
operator|(
operator|(
name|__NetBSD_Version__
operator|>=
literal|200060000
operator|&&
name|__NetBSD_Version__
operator|<
literal|200090000
operator|)
operator|||
expr|\
operator|(
name|__NetBSD_Version__
operator|>=
literal|299000900
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|HASCLOSEFROM
value|1
end_define

begin_comment
comment|/* closefrom(3) added in 2.0F */
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
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|USESYSCTL
value|1
end_define

begin_comment
comment|/* use sysctl(3) for getting ncpus */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

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
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASSETLOGIN
value|1
end_define

begin_comment
comment|/* has setlogin(2) */
end_comment

begin_define
define|#
directive|define
name|HASSRANDOMDEV
value|1
end_define

begin_comment
comment|/* has srandomdev(3) */
end_comment

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* has /dev/urandom(4) */
end_comment

begin_undef
undef|#
directive|undef
name|SPT_TYPE
end_undef

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_BUILTIN
end_define

begin_define
define|#
directive|define
name|HASSETUSERCONTEXT
value|1
end_define

begin_comment
comment|/* BSDI-style login classes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMRSH_CMDDIR
end_ifndef

begin_define
define|#
directive|define
name|SMRSH_CMDDIR
value|"/usr/libexec/sm.bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SMRSH_CMDDIR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMRSH_PATH
end_ifndef

begin_define
define|#
directive|define
name|SMRSH_PATH
value|"/bin:/usr/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SMRSH_PATH */
end_comment

begin_define
define|#
directive|define
name|USESYSCTL
value|1
end_define

begin_comment
comment|/* use sysctl(3) for getting ncpus */
end_comment

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__DragonFly__) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASSETLOGIN
value|1
end_define

begin_comment
comment|/* has setlogin(2) */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|227001
end_if

begin_define
define|#
directive|define
name|HASSRANDOMDEV
value|1
end_define

begin_comment
comment|/* has srandomdev(3) */
end_comment

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* has /dev/urandom(4) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 227001 */
end_comment

begin_undef
undef|#
directive|undef
name|SPT_TYPE
end_undef

begin_if
if|#
directive|if
name|__FreeBSD__
operator|>=
literal|2
end_if

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|199512
end_if

begin_comment
comment|/* 2.2-current when it appeared */
end_comment

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_BUILTIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 199512 */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|222000
end_if

begin_comment
comment|/* 2.2.2-release and later */
end_comment

begin_define
define|#
directive|define
name|HASSETUSERCONTEXT
value|1
end_define

begin_comment
comment|/* BSDI-style login classes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 222000 */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|330000
end_if

begin_comment
comment|/* 3.3.0-release and later */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMRSH_CMDDIR
end_ifndef

begin_define
define|#
directive|define
name|SMRSH_CMDDIR
value|"/usr/libexec/sm.bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SMRSH_CMDDIR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMRSH_PATH
end_ifndef

begin_define
define|#
directive|define
name|SMRSH_PATH
value|"/bin:/usr/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SMRSH_PATH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 330000 */
end_comment

begin_define
define|#
directive|define
name|USESYSCTL
value|1
end_define

begin_comment
comment|/* use sysctl(3) for getting ncpus */
end_comment

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__>= 2 */
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
value|SPT_REUSEARGV
end_define

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

begin_comment
comment|/* ! SPT_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__FreeBSD__) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

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

begin_define
define|#
directive|define
name|HASSETLOGIN
value|1
end_define

begin_comment
comment|/* has setlogin(2) */
end_comment

begin_if
if|#
directive|if
name|OpenBSD
operator|<
literal|200305
end_if

begin_define
define|#
directive|define
name|HASSETREUID
value|0
end_define

begin_comment
comment|/* setreuid(2) broken in OpenBSD< 3.3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OpenBSD< 200305 */
end_comment

begin_define
define|#
directive|define
name|HASSETEGID
value|1
end_define

begin_comment
comment|/* use setegid(2) to set saved gid */
end_comment

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* has /dev/urandom(4) */
end_comment

begin_if
if|#
directive|if
name|OpenBSD
operator|>=
literal|200006
end_if

begin_define
define|#
directive|define
name|HASSRANDOMDEV
value|1
end_define

begin_comment
comment|/* has srandomdev(3) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OpenBSD>= 200006 */
end_comment

begin_if
if|#
directive|if
name|OpenBSD
operator|>=
literal|200012
end_if

begin_define
define|#
directive|define
name|HASSETUSERCONTEXT
value|1
end_define

begin_comment
comment|/* BSDI-style login classes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OpenBSD>= 200012 */
end_comment

begin_if
if|#
directive|if
name|OpenBSD
operator|>=
literal|200405
end_if

begin_define
define|#
directive|define
name|HASCLOSEFROM
value|1
end_define

begin_comment
comment|/* closefrom(3) added in 3.5 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OpenBSD>= 200405 */
end_comment

begin_if
if|#
directive|if
name|OpenBSD
operator|>=
literal|200505
end_if

begin_undef
undef|#
directive|undef
name|NETISO
end_undef

begin_comment
comment|/* iso.h removed in 3.7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OpenBSD>= 200505 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__OpenBSD__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) */
end_comment

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
operator|&&
operator|!
name|defined
argument_list|(
name|__GNU__
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

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_GETOPT
value|0
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

begin_comment
comment|/* ! LA_TYPE */
end_comment

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
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MACH)&& defined(i386)&& !defined(__GNU__) */
end_comment

begin_comment
comment|/* **  GNU OS (hurd) **	Largely BSD& posix compatible. **	Port contributed by Miles Bader<miles@gnu.ai.mit.edu>. **	Updated by Mark Kettenis<kettenis@wins.uva.nl>. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) call */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) call */
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
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
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
name|SOCKADDR_LEN_T
value|socklen_t
end_define

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|socklen_t
end_define

begin_if
if|#
directive|if
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|1
operator|)
operator|||
name|__GLIBC__
operator|>
literal|2
end_if

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* (__GLIBC__ == 2&& __GLIBC_MINOR__> 1) || __GLIBC__> 2 */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_MACH
end_define

begin_comment
comment|/* GNU uses mach[34], which renames some rpcs from mach2.x. */
end_comment

begin_define
define|#
directive|define
name|host_self
value|mach_host_self
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (__GLIBC__ == 2&& __GLIBC_MINOR__> 1) || __GLIBC__> 2 */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_CHANGEARGV
end_define

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
value|1
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
value|1
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFCONF_IS_BROKEN
value|1
end_define

begin_comment
comment|/* SIOCGFCONF doesn't work */
end_comment

begin_define
define|#
directive|define
name|HAS_IN_H
value|1
end_define

begin_comment
comment|/* GNU has netinet/in.h. */
end_comment

begin_comment
comment|/* GNU has no MAXPATHLEN; ideally the code should be changed to not use it. */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GNU__)&& !defined(NeXT) */
end_comment

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
name|SM_CONF_GETOPT
value|0
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

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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

begin_comment
comment|/* ! IDENTPROTO */
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
comment|/* defined(oldBSD43) || defined(MORE_BSD) || defined(umipsbsd) */
end_comment

begin_comment
comment|/* **  SCO Unix ** **	This includes three parts: ** **	The first is for SCO OpenServer 5. **	(Contributed by Keith Reynolds<keithr@sco.COM>). ** **		SCO OpenServer 5 has a compiler version number macro, **		which we can use to figure out what version we're on. **		This may have to change in future releases. ** **	The second is for SCO UNIX 3.2v4.2/Open Desktop 3.0. **	(Contributed by Philippe Brand<phb@colombo.telesys-innov.fr>). ** **	The third is for SCO UNIX 3.2v4.0/Open Desktop 2.0 and earlier. */
end_comment

begin_comment
comment|/* SCO OpenServer 5 */
end_comment

begin_if
if|#
directive|if
name|_SCO_DS
operator|>=
literal|1
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|SIOCGIFNUM_IS_BROKEN
value|1
end_define

begin_comment
comment|/* SIOCGIFNUM returns bogus value */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) call */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) call */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has seteuid(2) call */
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
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) call */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_NEEDS_SYS_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|LDA_USE_LOCKF
value|1
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
value|LA_DEVSHORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|_PATH_AVENRUN
value|"/dev/table/avenrun"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SCO_unix_4_2
end_ifndef

begin_define
define|#
directive|define
name|_SCO_unix_4_2
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! _SCO_unix_4_2 */
end_comment

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|size_t
end_define

begin_comment
comment|/* e.g., arg#3 to accept, getsockname */
end_comment

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|size_t
end_define

begin_comment
comment|/* arg#5 to getsockopt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SCO_unix_4_2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCO_DS>= 1 */
end_comment

begin_comment
comment|/* SCO UNIX 3.2v4.2/Open Desktop 3.0 */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCO_unix_4_2 */
end_comment

begin_comment
comment|/* SCO UNIX 3.2v4.0 Open Desktop 2.0 and earlier */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SCO_unix_
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_comment
comment|/* needed for IP_SRCROUTE */
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
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|NOFTRUNCATE
value|0
end_define

begin_comment
comment|/* has (simulated) ftruncate call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_SIGLONGJMP
end_ifndef

begin_define
define|#
directive|define
name|USE_SIGLONGJMP
value|1
end_define

begin_comment
comment|/* sigsetjmp needed for signal handling */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_SIGLONGJMP */
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
name|SPT_TYPE
value|SPT_SCO
end_define

begin_comment
comment|/* write kernel u. area */
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

begin_define
define|#
directive|define
name|UID_T
value|uid_t
end_define

begin_define
define|#
directive|define
name|GID_T
value|gid_t
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
name|_PATH_UNIX
value|"/unix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_comment
comment|/* stuff fixed in later releases */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCO_unix_4_2
end_ifndef

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* SysV signal semantics -- reset on each sig */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SCO_unix_4_2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCO_DS
end_ifndef

begin_define
define|#
directive|define
name|ftruncate
value|chsize
end_define

begin_comment
comment|/* use chsize(2) to emulate ftruncate */
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
name|NETUNIX
value|0
end_define

begin_comment
comment|/* no unix domain socket support */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SHORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SCO_DS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCO_unix_ */
end_comment

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

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_comment
comment|/* needed for IP_SRCROUTE */
end_comment

begin_include
include|#
directive|include
file|<sys/bsdtypes.h>
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

begin_define
define|#
directive|define
name|NETUNIX
value|0
end_define

begin_comment
comment|/* no unix domain socket support */
end_comment

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
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_UNIX */
end_comment

begin_comment
comment|/* **  Altos System V (5.3.1) **	Contributed by Tim Rice<tim@trr.metro.net>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALTOS_SYSTEM_V
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

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
name|NEEDSTRSTR
value|1
end_define

begin_comment
comment|/* need emulation of the strstr(3) call */
end_comment

begin_define
define|#
directive|define
name|NOFTRUNCATE
value|1
end_define

begin_comment
comment|/* do not have ftruncate(2) */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
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
value|TZ_TZNAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

begin_define
define|#
directive|define
name|NETUNIX
value|0
end_define

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

begin_typedef
typedef|typedef
name|unsigned
name|long
name|mode_t
typedef|;
end_typedef

begin_comment
comment|/* some stuff that should have been in the include files */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
end_function_decl

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
name|struct
name|group
modifier|*
name|getgrgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrnam
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTOS_SYSTEM_V */
end_comment

begin_comment
comment|/* **  ConvexOS 11.0 and later ** **	"Todd C. Miller"<millert@mroe.cs.colorado.edu> claims this **	works on 9.1 as well. ** **  ConvexOS 11.5 and later, should work on 11.0 as defined. **  For pre-ConvexOOS 11.0, define SM_CONF_GETOPT=0, undef IDENTPROTO ** **	Eric Schnoebelen (eric@cirr.com) For CONVEX Computer Corp. **		(now the CONVEX Technologies Center of Hewlett Packard) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CONVEX_SOURCE
end_ifdef

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) */
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
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) */
end_comment

begin_define
define|#
directive|define
name|BROKEN_RES_SEARCH
value|1
end_define

begin_comment
comment|/* res_search(unknown) returns h_error=0 */
end_comment

begin_define
define|#
directive|define
name|NEEDPUTENV
value|1
end_define

begin_comment
comment|/* needs putenv (written in terms of setenv) */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_GETOPT
value|1
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
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
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

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

begin_comment
comment|/* ! S_IREAD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TIMEZONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHARE_V1
end_ifndef

begin_define
define|#
directive|define
name|SHARE_V1
value|1
end_define

begin_comment
comment|/* version 1 of the fair share scheduler */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SHARE_V1 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|UID_T
value|int
end_define

begin_comment
comment|/* GNUC gets it right, ConvexC botches */
end_comment

begin_define
define|#
directive|define
name|GID_T
value|int
end_define

begin_comment
comment|/* GNUC gets it right, ConvexC botches */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__GNUC__ ) */
end_comment

begin_if
if|#
directive|if
name|SECUREWARE
end_if

begin_define
define|#
directive|define
name|FORK
value|fork
end_define

begin_comment
comment|/* SecureWare wants the real fork! */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SECUREWARE */
end_comment

begin_define
define|#
directive|define
name|FORK
value|vfork
end_define

begin_comment
comment|/* the rest of the OS versions don't care */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SECUREWARE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CONVEX_SOURCE */
end_comment

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

begin_comment
comment|/* ! HASFLOCK */
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
name|SM_CONF_GETOPT
value|0
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
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
name|NEEDSTRSTR
value|1
end_define

begin_comment
comment|/* need emulation of the strstr(3) call */
end_comment

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

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
value|(0)
end_define

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|int
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

begin_comment
comment|/* added for RISC/os 4.01...which is dumber than 4.50 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RISCOS_4_0
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ARBPTR_T
end_ifndef

begin_define
define|#
directive|define
name|ARBPTR_T
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! ARBPTR_T */
end_comment

begin_undef
undef|#
directive|undef
name|HASFLOCK
end_undef

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RISCOS_4_0 */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RISCOS */
end_comment

begin_comment
comment|/* **  Linux 0.99pl10 and above... ** **  Thanks to, in reverse order of contact: ** **	John Kennedy<warlock@csuchico.edu> **	Andrew Pam<avatar@aus.xanadu.com> **	Florian La Roche<rzsfl@rz.uni-sb.de> **	Karl London<karl@borg.demon.co.uk> ** **  NOTE: Override HASFLOCK as you will but, as of 1.99.6, mixed-style **	file locking is no longer allowed.  In particular, make sure **	your DBM library and sendmail are both using either flock(2) **	*or* fcntl(2) file locking, but not both. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|<linux/version.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL_VERSION
argument_list|)
end_if

begin_comment
comment|/* not defined in 2.0.x kernel series */
end_comment

begin_define
define|#
directive|define
name|KERNEL_VERSION
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(((a)<< 16) + ((b)<< 8) + (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(KERNEL_VERSION) */
end_comment

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
name|HASSETREGID
value|1
end_define

begin_comment
comment|/* use setregid(2) to set saved gid */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REQUIRES_DIR_FSYNC
end_ifndef

begin_define
define|#
directive|define
name|REQUIRES_DIR_FSYNC
value|1
end_define

begin_comment
comment|/* requires fsync() on directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REQUIRES_DIR_FSYNC */
end_comment

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
comment|/* has it due to POSIX, but doesn't work */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USESETEUID */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_GETOPT
value|0
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
comment|/* getusershell(3) broken in Slackware 2.0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASGETUSERSHELL */
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
value|0
end_define

begin_comment
comment|/* linux<= 1.2.8 doesn't support IP_OPTIONS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IP_SRCROUTE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_IN_H
end_ifndef

begin_define
define|#
directive|define
name|HAS_IN_H
value|1
end_define

begin_comment
comment|/* use netinet/in.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAS_IN_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_SIGLONGJMP
end_ifndef

begin_define
define|#
directive|define
name|USE_SIGLONGJMP
value|1
end_define

begin_comment
comment|/* sigsetjmp needed for signal handling */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_SIGLONGJMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|<
literal|66399
end_if

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_comment
comment|/* flock(2) is broken after 0.99.13 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LINUX_VERSION_CODE< 66399 */
end_comment

begin_if
if|#
directive|if
operator|(
name|LINUX_VERSION_CODE
operator|<
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|4
operator|,
literal|0
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* flock(2) fixed after 1.3.95 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* (LINUX_VERSION_CODE< KERNEL_VERSION(2,4,0)) */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_comment
comment|/* flock(2) is broken (again) after 2.4.0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (LINUX_VERSION_CODE< KERNEL_VERSION(2,4,0)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINUX_VERSION_CODE< 66399 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
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
value|LA_PROCSTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() impl */
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

begin_if
if|#
directive|if
operator|(
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|0
operator|,
literal|0
argument_list|)
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|HASURANDOMDEV
end_ifndef

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* 2.0 (at least) has linux/drivers/char/random.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASURANDOMDEV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (LINUX_VERSION_CODE>= KERNEL_VERSION(2,0,0)) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GLIBC_MINOR__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GLIBC__)&& defined(__GLIBC_MINOR__) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_NONE
end_define

begin_comment
comment|/* no standard for Linux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_if
if|#
directive|if
operator|(
name|__GLIBC__
operator|>=
literal|2
operator|)
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (__GLIBC__>= 2) */
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

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

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

begin_if
if|#
directive|if
name|NETINET6
end_if

begin_comment
comment|/*    **  Linux doesn't have a good way to tell userland what interfaces are    **  IPv6-capable.  Therefore, the BIND resolver can not determine if there    **  are IPv6 interfaces to honor AI_ADDRCONFIG.  Unfortunately, it assumes    **  that none are present.  (Excuse the macro name ADDRCONFIG_IS_BROKEN.)    */
end_comment

begin_define
define|#
directive|define
name|ADDRCONFIG_IS_BROKEN
value|1
end_define

begin_comment
comment|/*    **  Indirectly included from glibc's<feature.h>.  IPv6 support is native    **  in 2.1 and later, but the APIs appear before the functions.    */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GLIBC_MINOR__
argument_list|)
end_if

begin_define
define|#
directive|define
name|GLIBC_VERSION
value|((__GLIBC__<< 8) + __GLIBC_MINOR__)
end_define

begin_if
if|#
directive|if
operator|(
name|GLIBC_VERSION
operator|>=
literal|0x201
operator|)
end_if

begin_undef
undef|#
directive|undef
name|IPPROTO_ICMPV6
end_undef

begin_comment
comment|/* linux #defines, glibc enums */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* (GLIBC_VERSION>= 0x201) */
end_comment

begin_include
include|#
directive|include
file|<linux/in6.h>
end_include

begin_comment
comment|/* IPv6 support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (GLIBC_VERSION>= 0x201) */
end_comment

begin_if
if|#
directive|if
operator|(
name|GLIBC_VERSION
operator|>=
literal|0x201
operator|&&
operator|!
name|defined
argument_list|(
name|NEEDSGETIPNODE
argument_list|)
operator|)
end_if

begin_comment
comment|/* Have APIs in<netdb.h>, but no support in glibc */
end_comment

begin_define
define|#
directive|define
name|NEEDSGETIPNODE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (GLIBC_VERSION>= 0x201&& !defined(NEEDSGETIPNODE)) */
end_comment

begin_undef
undef|#
directive|undef
name|GLIBC_VERSION
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GLIBC__)&& defined(__GLIBC_MINOR__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETINET6 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFCHOWN
end_ifndef

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* fchown(2) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFCHOWN */
end_comment

begin_if
if|#
directive|if
operator|(
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|0
operator|,
literal|36
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|HASFCHMOD
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* fchmod(2) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (LINUX_VERSION_CODE>= KERNEL_VERSION(2,0,36))&& !defined(HASFCHMOD) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

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
comment|/* DELL_SVR4 */
end_comment

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
name|HASSETRLIMIT
value|0
end_define

begin_comment
comment|/* ... but not setrlimit(2) */
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
name|BOGUS_O_EXCL
value|1
end_define

begin_comment
comment|/* exclusive open follows symlinks */
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
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
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
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* has setvbuf(3) in libc */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|SIGFUNC_DEFINED
end_define

begin_comment
comment|/* sigfunc_t already defined */
end_comment

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
end_define

begin_comment
comment|/* POSIX-mode */
end_comment

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|void
end_define

begin_comment
comment|/* POSIX-mode */
end_comment

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
value|1
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

begin_comment
comment|/* ! IDENTPROTO */
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

begin_define
define|#
directive|define
name|FSHIFT
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
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
name|TZ_TYPE
value|TZ_TZNAME
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
value|"/unix"
end_define

begin_comment
comment|/* should be in<paths.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
comment|/* _AUX_SOURCE */
end_comment

begin_comment
comment|/* **  Encore UMAX V ** **	Not extensively tested. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UMAXV
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
comment|/* UMAXV */
end_comment

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
comment|/* titan */
end_comment

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

begin_comment
comment|/* _POSIX_VERSION */
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

begin_comment
comment|/* ! IDENTPROTO */
end_comment

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

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sequent */
end_comment

begin_comment
comment|/* **  Sequent DYNIX/ptx v2.0 (and higher) ** **	For DYNIX/ptx v1.x, undefine HASSETREUID. ** **	From Tim Wright<timw@sequent.com>. **	Update from Jack Woolley<jwoolley@sctcorp.com>, 26 Dec 1995, **		for DYNIX/ptx 4.0.2. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
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

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SEQUENT_ */
end_comment

begin_comment
comment|/* **  Cray UNICOS, UNICOS/mk, and UNICOS/mp ** **    UNICOS: **	Ported by David L. Kensiski, Sterling Sofware<kensiski@nas.nasa.gov> **	Update Brian Ginsbach<ginsbach@cray.com> **    UNICOS/mk (Cray T3E): **	Contributed by Manu Mahonen<mailadm@csc.fi> **	of Center for Scientific Computing. **	Update Brian Ginsbach<ginsbach@cray.com> **    UNICOS/mp: **	From Aaron Davis<awd@cray.com>& Brian Ginsbach<ginsbach@cray.com> */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_CRAY
argument_list|)
operator|||
name|defined
argument_list|(
name|UNICOS
argument_list|)
operator|||
name|defined
argument_list|(
name|_UNICOSMP
argument_list|)
end_if

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
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) */
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
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
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
name|SAFENFSPATHCONF
value|1
end_define

begin_comment
comment|/* pathconf(2) pessimizes on NFS filesystems */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNICOS
end_ifdef

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
name|LA_TYPE
value|LA_ZERO
end_define

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|"/usr/spool/mail"
end_define

begin_define
define|#
directive|define
name|GET_IPOPT_DST
parameter_list|(
name|dst
parameter_list|)
value|*(struct in_addr *)&(dst)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATHSIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MAXPATHLEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|UNICOSMK
end_ifdef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unicosmk.ar"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unicos"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNICOSMK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNICOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_UNICOSMP
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SC_NPROC_ONLN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SC_NPROCESSORS_ONLN
argument_list|)
end_if

begin_comment
comment|/* _SC_NPROC_ONLN is 'mpadmin -u', total # of unrestricted processors */
end_comment

begin_define
define|#
directive|define
name|_SC_NPROCESSORS_ONLN
value|_SC_NPROC_ONLN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* if defined(_SC_NPROC_ONLN)&& !defined(_SC_NPROCESSORS_ONLN) */
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
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) syscall */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_IRIX6
end_define

begin_comment
comment|/* figure out at run time */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|ARGV_T
value|char *const *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNICOSMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRAY */
end_comment

begin_comment
comment|/* **  Apollo DomainOS ** **  From Todd Martin<tmartint@tus.ssi1.com>& Don Lewis<gdonl@gv.ssi1.com> ** **  15 Jan 1994; updated 2 Aug 1995 ** */
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
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* does not have<netinet/ip_var.h> */
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

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

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

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_NEEDS_SYS_TIME_H
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NGROUPS_MAX
argument_list|)
operator|&&
operator|!
name|NGROUPS_MAX
end_if

begin_undef
undef|#
directive|undef
name|NGROUPS_MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NGROUPS_MAX)&& !NGROUPS_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_comment
comment|/* **  MPE-iX ** **	Requires MPE 6.0 or greater.  See sendmail/README for more info. ** **	From Mark Bixby<mark_bixby@hp.com> or<mark@bixby.org>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MPE
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* Sendmail stuff */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|0
end_define

begin_comment
comment|/* lacks fchown() */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* lacks getusershell() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HASNICE
end_ifdef

begin_undef
undef|#
directive|undef
name|HASNICE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASNICE */
end_comment

begin_define
define|#
directive|define
name|HASNICE
value|0
end_define

begin_comment
comment|/* lacks nice() */
end_comment

begin_define
define|#
directive|define
name|HASRANDOM
value|0
end_define

begin_comment
comment|/* lacks random() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HASRRESVPORT
end_ifdef

begin_undef
undef|#
directive|undef
name|HASRRESVPORT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASRRESVPORT */
end_comment

begin_define
define|#
directive|define
name|HASRRESVPORT
value|0
end_define

begin_comment
comment|/* lacks rresvport() */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* lacks IP source routing fields */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MATCHGECOS
end_ifdef

begin_undef
undef|#
directive|undef
name|MATCHGECOS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MATCHGECOS */
end_comment

begin_define
define|#
directive|define
name|MATCHGECOS
value|0
end_define

begin_comment
comment|/* lacks an initialized GECOS field */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* use sendmail's fsync() */
end_comment

begin_define
define|#
directive|define
name|NEEDLINK
value|1
end_define

begin_comment
comment|/* use sendmail's link() */
end_comment

begin_define
define|#
directive|define
name|NOFTRUNCATE
value|1
end_define

begin_comment
comment|/* lacks ftruncate() */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_NONE
end_define

begin_comment
comment|/* can't determine disk space */
end_comment

begin_define
define|#
directive|define
name|SM_CONF_SYSLOG
value|0
end_define

begin_comment
comment|/* use sendmail decl of syslog() */
end_comment

begin_define
define|#
directive|define
name|USE_DOUBLE_FORK
value|0
end_define

begin_comment
comment|/* don't fork an intermediate zombie */
end_comment

begin_define
define|#
directive|define
name|USE_ENVIRON
value|1
end_define

begin_comment
comment|/* use environ instead of envp */
end_comment

begin_comment
comment|/* Missing header stuff */
end_comment

begin_define
define|#
directive|define
name|AF_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|AF_MAX
value|AF_INET
end_define

begin_define
define|#
directive|define
name|IFF_LOOPBACK
value|0x8
end_define

begin_define
define|#
directive|define
name|IN_LOOPBACKNET
value|127
end_define

begin_define
define|#
directive|define
name|MAXNAMLEN
value|NAME_MAX
end_define

begin_define
define|#
directive|define
name|S_IEXEC
value|S_IXUSR
end_define

begin_define
define|#
directive|define
name|S_IREAD
value|S_IRUSR
end_define

begin_define
define|#
directive|define
name|S_IWRITE
value|S_IWUSR
end_define

begin_comment
comment|/* Present header stuff that needs to be missing */
end_comment

begin_undef
undef|#
directive|undef
name|NGROUPS_MAX
end_undef

begin_comment
comment|/* Shadow functions */
end_comment

begin_define
define|#
directive|define
name|bind
value|sendmail_mpe_bind
end_define

begin_define
define|#
directive|define
name|_exit
value|sendmail_mpe__exit
end_define

begin_define
define|#
directive|define
name|exit
value|sendmail_mpe_exit
end_define

begin_define
define|#
directive|define
name|fcntl
value|sendmail_mpe_fcntl
end_define

begin_define
define|#
directive|define
name|getegid
value|sendmail_mpe_getegid
end_define

begin_define
define|#
directive|define
name|geteuid
value|sendmail_mpe_geteuid
end_define

begin_define
define|#
directive|define
name|getpwnam
value|sendmail_mpe_getpwnam
end_define

begin_define
define|#
directive|define
name|getpwuid
value|sendmail_mpe_getpwuid
end_define

begin_define
define|#
directive|define
name|setgid
value|sendmail_mpe_setgid
end_define

begin_define
define|#
directive|define
name|setuid
value|sendmail_mpe_setuid
end_define

begin_decl_stmt
specifier|extern
name|int
name|sendmail_mpe_fcntl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|sendmail_mpe_getpwnam
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|sendmail_mpe_getpwuid
name|__P
argument_list|(
operator|(
name|uid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MPE */
end_comment

begin_comment
comment|/* **  System V Rel 5.x (a.k.a Unixware7 w/o BSD-Compatibility Libs ie. native) ** **	Contributed by Paul Gampe<paulg@apnic.net> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__svr5__
end_ifdef

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) call */
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
name|HASSETREUID
value|1
end_define

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
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
name|SOCKADDR_LEN_T
value|size_t
end_define

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|size_t
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
value|"/stand/unix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
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
comment|/* unsure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_undef
undef|#
directive|undef
name|offsetof
end_undef

begin_comment
comment|/* avoid stddefs.h, sys/sysmacros.h conflict */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SM_SET_H_ERRNO
argument_list|)
operator|&&
name|defined
argument_list|(
name|_REENTRANT
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_SET_H_ERRNO
parameter_list|(
name|err
parameter_list|)
value|set_h_errno((err))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_SET_H_ERRNO&& _REENTRANT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __svr5__ */
end_comment

begin_comment
comment|/* ###################################################################### */
end_comment

begin_comment
comment|/* **  UnixWare 2.x */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIXWARE2
end_ifdef

begin_define
define|#
directive|define
name|UNIXWARE
value|1
end_define

begin_undef
undef|#
directive|undef
name|offsetof
end_undef

begin_comment
comment|/* avoid stddefs.h, sys/sysmacros.h conflict */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIXWARE2 */
end_comment

begin_comment
comment|/* **  UnixWare 1.1.2. ** **	Updated by Petr Lampa<lampa@fee.vutbr.cz>. **	From Evan Champion<evanc@spatial.synapse.org>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIXWARE
end_ifdef

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

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
name|HASSETREUID
value|1
end_define

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

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/ucblib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

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
comment|/* UNIXWARE */
end_comment

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

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

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
comment|/* CLIX */
end_comment

begin_comment
comment|/* **  NCR MP-RAS 2.x (SysVr4) with Wollongong TCP/IP ** **	From Kevin Darcy<kevin@tech.mis.cfc.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCR_MP_RAS2
end_ifdef

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

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

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCR_MP_RAS2 */
end_comment

begin_comment
comment|/* **  NCR MP-RAS 3.x (SysVr4) with STREAMware TCP/IP ** **	From Tom Moore<Tom.Moore@DaytonOH.NCR.COM> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCR_MP_RAS3
end_ifdef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) call */
end_comment

begin_define
define|#
directive|define
name|LDA_USE_LOCKF
value|1
end_define

begin_define
define|#
directive|define
name|SIOCGIFNUM_IS_BROKEN
value|1
end_define

begin_comment
comment|/* SIOCGIFNUM has non-std interface */
end_comment

begin_define
define|#
directive|define
name|SO_REUSEADDR_IS_BROKEN
value|1
end_define

begin_comment
comment|/* doesn't work if accept() fails */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|"/var/mail"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_XOPEN_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_XOPEN_SOURCE
end_define

begin_define
define|#
directive|define
name|_XOPEN_SOURCE_EXTENDED
value|1
end_define

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_undef
undef|#
directive|undef
name|_XOPEN_SOURCE
end_undef

begin_undef
undef|#
directive|undef
name|_XOPEN_SOURCE_EXTENDED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _XOPEN_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCR_MP_RAS3 */
end_comment

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
comment|/* NonStop_UX_BXX */
end_comment

begin_comment
comment|/* **  Hitachi 3050R/3050RX and 3500 Workstations running HI-UX/WE2. ** **	Tested for 1.04, 1.03 **	From Akihiro Hashimoto ("Hash")<hash@dominic.ipc.chiba-u.ac.jp>. ** **	Tested for 4.02, 6.10 and 7.10 **	From Motonori NAKAMURA<motonori@media.kyoto-u.ac.jp>. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_H3050R
argument_list|)
operator|||
name|defined
argument_list|(
name|_HIUX_SOURCE
argument_list|)
operator|)
end_if

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
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
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

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETVBUF
end_ifndef

begin_define
define|#
directive|define
name|HASSETVBUF
end_define

begin_comment
comment|/* HI-UX has no setlinebuf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASSETVBUF */
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

begin_comment
comment|/* ! GIDSET_T */
end_comment

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

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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

begin_comment
comment|/* ! IDENTPROTO */
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
comment|/* getusershell(3) causes core dumps */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_define
define|#
directive|define
name|FDSET_CAST
value|(int *)
end_define

begin_comment
comment|/* cast for fd_set parameters to select */
end_comment

begin_comment
comment|/* **  avoid m_flags conflict between Berkeley DB 1.85 db.h& sys/sysmacros.h **  on HIUX 3050 */
end_comment

begin_undef
undef|#
directive|undef
name|m_flags
end_undef

begin_define
define|#
directive|define
name|SM_CONF_SYSLOG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__hpux)&& (defined(_H3050R) || defined(_HIUX_SOURCE)) */
end_comment

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

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

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
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UTS */
end_comment

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
comment|/* _CRAYCOM */
end_comment

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

begin_comment
comment|/* ! BSD */
end_comment

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

begin_comment
comment|/* ! HASFLOCK */
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

begin_define
define|#
directive|define
name|MODE_T
value|int
end_define

begin_comment
comment|/* system include files have no mode_t */
end_comment

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

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
value|(0)
end_define

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __svr4 */
end_comment

begin_comment
comment|/* NEWS-OS 6.0.3 with /bin/cc */
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
comment|/* use all System V Release 4 defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4__ */
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

begin_comment
comment|/* ! SPT_TYPE */
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

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/stand/unix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sony_news */
end_comment

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

begin_comment
comment|/* ! IDENTPROTO */
end_comment

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
name|SM_CONF_GETOPT
value|0
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

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_ZONE
end_define

begin_comment
comment|/* use tm->tm_zone */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* uniosb */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|luna2
end_ifdef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_ZONE
end_define

begin_comment
comment|/* use tm->tm_zone */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* luna2 */
end_comment

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

begin_comment
comment|/* luna88k */
end_comment

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

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
value|(0)
end_define

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|int
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* luna */
end_comment

begin_comment
comment|/* **  NEC EWS-UX/V 4.2 (with /usr/ucb/cc) ** **	From Motonori NAKAMURA<motonori@cs.ritsumei.ac.jp>. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|nec_ews_svr4
argument_list|)
operator|||
name|defined
argument_list|(
name|_nec_ews_svr4
argument_list|)
end_if

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
comment|/* use all System V Release 4 defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4__ */
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
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has POSIX setsid(2) call */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/ucblib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
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

begin_comment
comment|/* allow full size syslog buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(nec_ews_svr4) || defined(_nec_ews_svr4) */
end_comment

begin_comment
comment|/* **  Fujitsu/ICL UXP/DS (For the DS/90 Series) ** **	From Diego R. Lopez<drlopez@cica.es>. **	Additional changes from Fumio Moriya and Toshiaki Nomura of the **		Fujitsu Fresoftware group<dsfrsoft@oai6.yk.fujitsu.co.jp>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__uxp__
end_ifdef

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/stand/unix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/ucblib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __uxp__ */
end_comment

begin_comment
comment|/* **  Pyramid DC/OSx ** **	From Earle Ake<akee@wpdiss1.wpafb.af.mil>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DCOSx
end_ifdef

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
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

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCOSx */
end_comment

begin_comment
comment|/* **  Concurrent Computer Corporation Maxion ** **	From Donald R. Laster Jr.<laster@access.digex.net>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MAXION__
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_define
define|#
directive|define
name|__svr4__
value|1
end_define

begin_comment
comment|/* SVR4.2MP */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* have setreuid(2) */
end_comment

begin_define
define|#
directive|define
name|HASLSTAT
value|1
end_define

begin_comment
comment|/* have lstat(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* have setrlimit(2) */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* have getdtablesize(2) */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* have getusershell(3) */
end_comment

begin_define
define|#
directive|define
name|NOFTRUNCATE
value|1
end_define

begin_comment
comment|/* do not have ftruncate(2) */
end_comment

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
name|SFS_BAVAIL
value|f_bavail
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|256
end_define

begin_comment
comment|/* Use 256 bytes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_undef
undef|#
directive|undef
name|WUNTRACED
end_undef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WIFSIGNALED
end_undef

begin_undef
undef|#
directive|undef
name|WIFSTOPPED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WTERMSIG
end_undef

begin_undef
undef|#
directive|undef
name|WSTOPSIG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MAXION__ */
end_comment

begin_comment
comment|/* **  Harris Nighthawk PowerUX (nh6000 box) ** **  Contributed by Bob Miorelli, Pratt& Whitney<miorelli@pweh.com> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PowerUX
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_typedef
typedef|typedef
name|struct
name|msgb
name|mblk_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|offsetof
end_undef

begin_comment
comment|/* avoid stddefs.h and sys/sysmacros.h conflict */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PowerUX */
end_comment

begin_comment
comment|/* **  Siemens Nixdorf Informationssysteme AG SINIX ** **	Contributed by Gerald Rinske of Siemens Business Services VAS. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sinix
end_ifdef

begin_define
define|#
directive|define
name|HASRANDOM
value|0
end_define

begin_comment
comment|/* has random(3) */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|SM_INT32
value|int
end_define

begin_comment
comment|/* 32bit integer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sinix */
end_comment

begin_comment
comment|/* **  Motorola 922, MC88110, UNIX SYSTEM V/88 Release 4.0 Version 4.3 ** **	Contributed by Sergey Rusanov<rsm@utfoms.udmnet.ru> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTO
end_ifdef

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|0
end_define

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
name|HASSETREUID
value|1
end_define

begin_define
define|#
directive|define
name|HASULIMIT
value|1
end_define

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_define
define|#
directive|define
name|RES_DNSRCH_VARIABLE
value|_res_dnsrch
end_define

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/sendmail.cf"
end_define

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

begin_comment
comment|/* MOTO */
end_comment

begin_comment
comment|/* **  Interix **	Contributed by Nedelcho Stanev<nedelcho.stanev@atlanticsky.com> ** **	Used for Interix support. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__INTERIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_define
define|#
directive|define
name|HASSTRERROR
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
name|HASFCHOWN
value|1
end_define

begin_undef
undef|#
directive|undef
name|HAVE_SYS_ERRLIST
end_undef

begin_define
define|#
directive|define
name|sys_errlist
value|__sys_errlist
end_define

begin_define
define|#
directive|define
name|sys_nerr
value|__sys_nerr
end_define

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|major
end_ifndef

begin_define
define|#
directive|define
name|major
parameter_list|(
name|dev
parameter_list|)
value|((int)(((dev)>> 8)& 0xff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! major */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|minor
end_ifndef

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|dev
parameter_list|)
value|((int)((dev)& 0xff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! minor */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__INTERIX) */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETREUID
end_ifndef

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASSETREUID */
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

begin_comment
comment|/* ! IP_SRCROUTE */
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

begin_comment
comment|/* ! HASSETRLIMIT */
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

begin_comment
comment|/* ! HASFLOCK */
end_comment

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

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

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
comment|/* has usable seteuid(2) call */
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
name|BSD_COMP
value|1
end_define

begin_comment
comment|/* get BSD ioctl calls */
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

begin_comment
comment|/* ! HASSETRLIMIT */
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

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFCHMOD
end_ifndef

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* most (all?) SVr4s seem to have fchmod(2) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFCHMOD */
end_comment

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

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/ucblib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
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
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
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
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

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

begin_comment
comment|/* ! SFS_TYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_SIGLONGJMP
end_ifndef

begin_define
define|#
directive|define
name|USE_SIGLONGJMP
value|1
end_define

begin_comment
comment|/* sigsetjmp needed for signal handling */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_SIGLONGJMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __svr4__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__SVR4
end_ifdef

begin_define
define|#
directive|define
name|LDA_USE_LOCKF
value|1
end_define

begin_define
define|#
directive|define
name|LDA_USE_SETEUID
value|1
end_define

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|"/var/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SVR4 */
end_comment

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

begin_comment
comment|/* ! HASULIMIT */
end_comment

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

begin_comment
comment|/* MIOC_READKSYM */
end_comment

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

begin_comment
comment|/* MIOC_READKSYM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

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

begin_comment
comment|/* ! SFS_TYPE */
end_comment

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

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSTEM5 */
end_comment

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
comment|/* has POSIX setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_comment
comment|/* has POSIX waitpid(2) call */
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
comment|/* has usable seteuid(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION>= 199500&& !defined(USESETEUID) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
end_comment

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

begin_comment
comment|/* titan */
end_comment

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

begin_comment
comment|/* _CRAYCOM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTO
end_ifdef

begin_undef
undef|#
directive|undef
name|USESETEUID
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOTO */
end_comment

begin_comment
comment|/* **  Due to a "feature" in some operating systems such as Ultrix 4.3 and **  HPUX 8.0, if you receive a "No route to host" message (ICMP message **  ICMP_UNREACH_HOST) on _any_ connection, all connections to that host **  are closed.  Some firewalls return this error if you try to connect **  to the IDENT port (113), so you can't receive email from these hosts **  on these systems.  The firewall really should use a more specific **  message such as ICMP_UNREACH_PROTOCOL or _PORT or _FILTER_PROHIB.  If **  not explicitly set to zero above, default it on. */
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

begin_comment
comment|/* ! IDENTPROTO */
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
comment|/* Detect IP source routing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IP_SRCROUTE */
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
value|1
end_define

begin_comment
comment|/* libc has getusershell(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETUNIX
end_ifndef

begin_define
define|#
directive|define
name|NETUNIX
value|1
end_define

begin_comment
comment|/* include unix domain support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NETUNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASRANDOM
end_ifndef

begin_define
define|#
directive|define
name|HASRANDOM
value|1
end_define

begin_comment
comment|/* has random(3) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASRANDOM */
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
comment|/* assume no flock(2) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

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

begin_comment
comment|/* ! HASSETREUID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFCHMOD
end_ifndef

begin_define
define|#
directive|define
name|HASFCHMOD
value|0
end_define

begin_comment
comment|/* assume no fchmod(2) syscall */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFCHMOD */
end_comment

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

begin_comment
comment|/* ! USESETEUID */
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
value|0
end_define

begin_comment
comment|/* assume no setrlimit(2) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASSETRLIMIT */
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
value|0
end_define

begin_comment
comment|/* assume no ulimit(2) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASULIMIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SECUREWARE
end_ifndef

begin_define
define|#
directive|define
name|SECUREWARE
value|0
end_define

begin_comment
comment|/* assume no SecureWare C2 auditing hooks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SECUREWARE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_DOUBLE_FORK
end_ifndef

begin_define
define|#
directive|define
name|USE_DOUBLE_FORK
value|1
end_define

begin_comment
comment|/* avoid intermediate zombies */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_DOUBLE_FORK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_ENVIRON
end_ifndef

begin_define
define|#
directive|define
name|USE_ENVIRON
value|0
end_define

begin_comment
comment|/* use main() envp instead of extern environ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_ENVIRON */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_SIGLONGJMP
end_ifndef

begin_define
define|#
directive|define
name|USE_SIGLONGJMP
value|0
end_define

begin_comment
comment|/* assume setjmp handles signals properly */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_SIGLONGJMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FDSET_CAST
end_ifndef

begin_define
define|#
directive|define
name|FDSET_CAST
end_define

begin_comment
comment|/* (empty) cast for fd_set arg to select */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FDSET_CAST */
end_comment

begin_comment
comment|/* **  Pick a mailer setuid method for changing the current uid */
end_comment

begin_define
define|#
directive|define
name|USE_SETEUID
value|0
end_define

begin_define
define|#
directive|define
name|USE_SETREUID
value|1
end_define

begin_define
define|#
directive|define
name|USE_SETUID
value|2
end_define

begin_if
if|#
directive|if
name|USESETEUID
end_if

begin_define
define|#
directive|define
name|MAILER_SETUID_METHOD
value|USE_SETEUID
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USESETEUID */
end_comment

begin_if
if|#
directive|if
name|HASSETREUID
end_if

begin_define
define|#
directive|define
name|MAILER_SETUID_METHOD
value|USE_SETREUID
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HASSETREUID */
end_comment

begin_define
define|#
directive|define
name|MAILER_SETUID_METHOD
value|USE_SETUID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASSETREUID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USESETEUID */
end_comment

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
comment|/* ! GIDSET_T */
end_comment

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

begin_comment
comment|/* ! UID_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GID_T
end_ifndef

begin_define
define|#
directive|define
name|GID_T
value|gid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GID_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MODE_T
end_ifndef

begin_define
define|#
directive|define
name|MODE_T
value|mode_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MODE_T */
end_comment

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

begin_comment
comment|/* ! ARGV_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOCKADDR_LEN_T
end_ifndef

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SOCKADDR_LEN_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOCKOPT_LEN_T
end_ifndef

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SOCKOPT_LEN_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUAD_T
end_ifndef

begin_define
define|#
directive|define
name|QUAD_T
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! QUAD_T */
end_comment

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

begin_comment
comment|/* ! S_ISREG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|foo
parameter_list|)
value|((foo& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISDIR */
end_comment

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

begin_comment
comment|/* !defined(S_ISLNK)&& defined(S_IFLNK) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISFIFO
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|foo
parameter_list|)
value|((foo& S_IFMT) == S_IFIFO)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(S_IFIFO) */
end_comment

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|foo
parameter_list|)
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(S_IFIFO) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(S_ISFIFO) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IRUSR
value|0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IRUSR */
end_comment

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

begin_comment
comment|/* ! S_IWUSR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IRGRP
value|0040
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IRGRP */
end_comment

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

begin_comment
comment|/* ! S_IWGRP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IROTH
end_ifndef

begin_define
define|#
directive|define
name|S_IROTH
value|0004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IROTH */
end_comment

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
comment|/* ! S_IWOTH */
end_comment

begin_comment
comment|/* close-on-exec flag */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_CLOEXEC
end_ifndef

begin_define
define|#
directive|define
name|FD_CLOEXEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FD_CLOEXEC */
end_comment

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
comment|/* ! EX_CONFIG */
end_comment

begin_comment
comment|/* pseudo-codes */
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

begin_define
define|#
directive|define
name|EX_RESTART
value|23
end_define

begin_comment
comment|/* restart sendmail daemon */
end_comment

begin_define
define|#
directive|define
name|EX_SHUTDOWN
value|24
end_define

begin_comment
comment|/* shutdown sendmail daemon */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EX_NOTFOUND
end_ifndef

begin_define
define|#
directive|define
name|EX_NOTFOUND
value|EX_NOHOST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! EX_NOTFOUND */
end_comment

begin_comment
comment|/* pseudo-code used for mci_setstat */
end_comment

begin_define
define|#
directive|define
name|EX_NOTSTICKY
value|(-5)
end_define

begin_comment
comment|/* don't save persistent status */
end_comment

begin_comment
comment|/* **  An "impossible" file mode to indicate that the file does not exist. */
end_comment

begin_define
define|#
directive|define
name|ST_MODE_NOFILE
value|0171147
end_define

begin_comment
comment|/* unlikely to occur */
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

begin_comment
comment|/* ! ARBPTR_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_include
include|#
directive|include
file|"sm/cdefs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __P */
end_comment

begin_if
if|#
directive|if
name|HESIOD
operator|&&
operator|!
name|defined
argument_list|(
name|NAMED_BIND
argument_list|)
end_if

begin_define
define|#
directive|define
name|NAMED_BIND
value|1
end_define

begin_comment
comment|/* not one without the other */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HESIOD&& !defined(NAMED_BIND) */
end_comment

begin_if
if|#
directive|if
name|NAMED_BIND
operator|&&
operator|!
name|defined
argument_list|(
name|__ksr__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|h_errno
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_BIND&& !defined( __ksr__ )&& !defined( h_errno ) */
end_comment

begin_if
if|#
directive|if
name|NEEDPUTENV
end_if

begin_decl_stmt
specifier|extern
name|int
name|putenv
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEEDPUTENV */
end_comment

begin_if
if|#
directive|if
operator|!
name|HASUNSETENV
end_if

begin_decl_stmt
specifier|extern
name|void
name|unsetenv
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HASUNSETENV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LDAPMAP
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<lber.h>
end_include

begin_include
include|#
directive|include
file|<ldap.h>
end_include

begin_comment
comment|/* Some LDAP constants */
end_comment

begin_define
define|#
directive|define
name|LDAPMAP_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|LDAPMAP_TRUE
value|1
end_define

begin_comment
comment|/* **  ldap_init(3) is broken in Umich 3.x and OpenLDAP 1.0/1.1. **  Use the lack of LDAP_OPT_SIZELIMIT to detect old API implementations **  and assume (falsely) that all old API implementations are broken. **  (OpenLDAP 1.2 and later have a working ldap_init(), add -DUSE_LDAP_INIT) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LDAP_OPT_SIZELIMIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_LDAP_INIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LDAP_INIT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LDAP_OPT_SIZELIMIT)&& !defined(USE_LDAP_INIT) */
end_comment

begin_comment
comment|/* **  LDAP_OPT_SIZELIMIT is not defined under Umich 3.x nor OpenLDAP 1.x, **  hence ldap_set_option() must not exist. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LDAP_OPT_SIZELIMIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_LDAP_SET_OPTION
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LDAP_SET_OPTION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LDAP_OPT_SIZELIMIT)&& !defined(USE_LDAP_SET_OPTION) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDAPMAP */
end_comment

begin_if
if|#
directive|if
name|HASUNAME
end_if

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

begin_comment
comment|/* newstr */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HASUNAME */
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
name|ALTOS_SYSTEM_V
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

begin_comment
comment|/* !defined(MAXHOSTNAMELEN)&& !defined(_SCO_unix_)&& !defined(NonStop_UX_BXX)&& !defined(ALTOS_SYSTEM_V) */
end_comment

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

begin_comment
comment|/* !defined(SIGCHLD)&& defined(SIGCLD) */
end_comment

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

begin_comment
comment|/* ! STDIN_FILENO */
end_comment

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

begin_comment
comment|/* ! STDOUT_FILENO */
end_comment

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

begin_comment
comment|/* ! STDERR_FILENO */
end_comment

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

begin_comment
comment|/* ! LOCK_SH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IXOTH
value|(S_IEXEC>> 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IXOTH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IXGRP
value|(S_IEXEC>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IXGRP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IXUSR
value|(S_IEXEC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IXUSR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_ACCMODE
end_ifndef

begin_define
define|#
directive|define
name|O_ACCMODE
value|(O_RDONLY|O_WRONLY|O_RDWR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! O_ACCMODE */
end_comment

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

begin_comment
comment|/* ! SEEK_SET */
end_comment

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
comment|/* ! SIG_ERR */
end_comment

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

begin_comment
comment|/* ! WEXITSTATUS */
end_comment

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

begin_comment
comment|/* ! WIFEXITED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIFSTOPPED
end_ifndef

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|st
parameter_list|)
value|(((st)& 0100) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! WIFSTOPPED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WCOREDUMP
end_ifndef

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|st
parameter_list|)
value|(((st)& 0200) != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! WCOREDUMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WTERMSIG
end_ifndef

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|st
parameter_list|)
value|(((st)& 0177))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! WTERMSIG */
end_comment

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
comment|/* ! SIGFUNC_DEFINED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGFUNC_RETURN
end_ifndef

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SIGFUNC_RETURN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGFUNC_DECL
end_ifndef

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SIGFUNC_DECL */
end_comment

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
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_comment
comment|/* for FD_SET() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SETSIZE
end_ifndef

begin_define
define|#
directive|define
name|FD_SETSIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FD_SETSIZE */
end_comment

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
value|fork
end_define

begin_comment
comment|/* function to call to fork mailer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FORK */
end_comment

begin_comment
comment|/* setting h_errno */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_SET_H_ERRNO
end_ifndef

begin_define
define|#
directive|define
name|SM_SET_H_ERRNO
parameter_list|(
name|err
parameter_list|)
value|h_errno = (err)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_SET_H_ERRNO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_GETOPT
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_GETOPT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_GETOPT */
end_comment

begin_comment
comment|/* random routine -- set above using #ifdef _osname_ or in Makefile */
end_comment

begin_if
if|#
directive|if
name|HASRANDOM
end_if

begin_define
define|#
directive|define
name|get_random
parameter_list|()
value|random()
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HASRANDOM */
end_comment

begin_define
define|#
directive|define
name|get_random
parameter_list|()
value|((long) rand())
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RANDOMSHIFT
end_ifndef

begin_define
define|#
directive|define
name|RANDOMSHIFT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! RANDOMSHIFT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASRANDOM */
end_comment

begin_comment
comment|/* **  Default to using scanf in readcf. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCANF
end_ifndef

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

begin_comment
comment|/* ! SCANF */
end_comment

begin_comment
comment|/* XXX  32 bit type */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_INT32
end_ifndef

begin_define
define|#
directive|define
name|SM_INT32
value|int32_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_INT32 */
end_comment

begin_comment
comment|/* **  SVr4 and similar systems use different routines for setjmp/longjmp **  with signal support */
end_comment

begin_if
if|#
directive|if
name|USE_SIGLONGJMP
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|jmp_buf
end_ifdef

begin_undef
undef|#
directive|undef
name|jmp_buf
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* jmp_buf */
end_comment

begin_define
define|#
directive|define
name|jmp_buf
value|sigjmp_buf
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|setjmp
end_ifdef

begin_undef
undef|#
directive|undef
name|setjmp
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* setjmp */
end_comment

begin_define
define|#
directive|define
name|setjmp
parameter_list|(
name|env
parameter_list|)
value|sigsetjmp(env, 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|longjmp
end_ifdef

begin_undef
undef|#
directive|undef
name|longjmp
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* longjmp */
end_comment

begin_define
define|#
directive|define
name|longjmp
parameter_list|(
name|env
parameter_list|,
name|val
parameter_list|)
value|siglongjmp(env, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_SIGLONGJMP */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NGROUPS_MAX
argument_list|)
operator|&&
name|defined
argument_list|(
name|NGROUPS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|NGROUPS
end_define

begin_comment
comment|/* POSIX naming convention */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NGROUPS_MAX)&& defined(NGROUPS) */
end_comment

begin_comment
comment|/* **  Some snprintf() implementations are rumored not to NUL terminate. */
end_comment

begin_if
if|#
directive|if
name|SNPRINTF_IS_BROKEN
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|snprintf
end_ifdef

begin_undef
undef|#
directive|undef
name|snprintf
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* snprintf */
end_comment

begin_define
define|#
directive|define
name|snprintf
value|sm_snprintf
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vsnprintf
end_ifdef

begin_undef
undef|#
directive|undef
name|vsnprintf
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vsnprintf */
end_comment

begin_define
define|#
directive|define
name|vsnprintf
value|sm_vsnprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SNPRINTF_IS_BROKEN */
end_comment

begin_comment
comment|/* **  If we don't have a system syslog, simulate it. */
end_comment

begin_if
if|#
directive|if
operator|!
name|LOG
end_if

begin_define
define|#
directive|define
name|LOG_EMERG
value|0
end_define

begin_comment
comment|/* system is unusable */
end_comment

begin_define
define|#
directive|define
name|LOG_ALERT
value|1
end_define

begin_comment
comment|/* action must be taken immediately */
end_comment

begin_define
define|#
directive|define
name|LOG_CRIT
value|2
end_define

begin_comment
comment|/* critical conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_ERR
value|3
end_define

begin_comment
comment|/* error conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_WARNING
value|4
end_define

begin_comment
comment|/* warning conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_NOTICE
value|5
end_define

begin_comment
comment|/* normal but significant condition */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO
value|6
end_define

begin_comment
comment|/* informational */
end_comment

begin_define
define|#
directive|define
name|LOG_DEBUG
value|7
end_define

begin_comment
comment|/* debug-level messages */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_SYSLOG
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_SYSLOG
value|1
end_define

begin_comment
comment|/* syslog.h has prototype for syslog() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SYSLOG */
end_comment

begin_if
if|#
directive|if
operator|!
name|SM_CONF_SYSLOG
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|syslog
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_function_decl
specifier|extern
name|void
name|syslog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_SYSLOG */
end_comment

begin_comment
comment|/* portable(?) definition for alignment */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_ALIGN_SIZE
end_ifndef

begin_struct
struct|struct
name|sm_align
block|{
name|char
name|al_c
decl_stmt|;
union|union
block|{
name|long
name|al_l
decl_stmt|;
name|void
modifier|*
name|al_p
decl_stmt|;
name|double
name|al_d
decl_stmt|;
name|void
argument_list|(
argument|*al_f
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
block|}
name|al_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SM_ALIGN_SIZE
value|offsetof(struct sm_align, al_u)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_ALIGN_SIZE */
end_comment

begin_define
define|#
directive|define
name|SM_ALIGN_BITS
value|(SM_ALIGN_SIZE - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CONF_H */
end_comment

end_unit

