begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)conf.h	6.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* **  CONF.H -- All user-configurable parameters for sendmail */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* **  Table sizes, etc.... **	There shouldn't be much need to change these.... */
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|1024
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
value|100
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
name|MAXTRUST
value|30
end_define

begin_comment
comment|/* maximum number of trusted users */
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
comment|/* **  Compilation options. ** **	#define these if they are available; comment them out otherwise. */
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
name|UGLYUUCP
value|1
end_define

begin_comment
comment|/* output ugly UUCP From lines */
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

begin_define
define|#
directive|define
name|BTREE_MAP
value|1
end_define

begin_comment
comment|/* enable BTREE mapping type (requires NEWDB) */
end_comment

begin_define
define|#
directive|define
name|HASH_MAP
value|1
end_define

begin_comment
comment|/* enable HASH mapping type (requires NEWDB) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NDBM
end_ifdef

begin_define
define|#
directive|define
name|DBM_MAP
value|1
end_define

begin_comment
comment|/* enable DBM mapping type (requires NDBM) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Some general configuration -- you shouldn't have to touch these */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTEM5
end_ifdef

begin_define
define|#
directive|define
name|LOCKF
value|1
end_define

begin_comment
comment|/* use System V lockf instead of flock */
end_comment

begin_define
define|#
directive|define
name|SYS5TZ
value|1
end_define

begin_comment
comment|/* use System V style timezones */
end_comment

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
name|VA_ARG_FORMAL
end_define

begin_define
define|#
directive|define
name|VA_ARG_DECL
end_define

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
name|VA_ARG_FORMAL
value|,va_alist
end_define

begin_define
define|#
directive|define
name|VA_ARG_DECL
value|va_dcl
end_define

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

end_unit

