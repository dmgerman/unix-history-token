begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)conf.h	5.28 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* **  CONF.H -- All user-configurable parameters for sendmail */
end_comment

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
name|MAXFIELD
value|4096
end_define

begin_comment
comment|/* max total length of a hdr field */
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
name|MAXHOP
value|17
end_define

begin_comment
comment|/* max value of HopCount */
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
value|30
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
name|MAXUSERENVIRON
value|40
end_define

begin_comment
comment|/* max # of items in user environ */
end_comment

begin_define
define|#
directive|define
name|QUEUESIZE
value|600
end_define

begin_comment
comment|/* max # of jobs per queue run */
end_comment

begin_define
define|#
directive|define
name|MAXMXHOSTS
value|10
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

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
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

end_unit

