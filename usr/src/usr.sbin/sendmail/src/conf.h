begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)conf.h	5.17 (Berkeley) %G%  */
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

begin_comment
comment|/* **  Compilation options. ** **	#define these if they are available; comment them out otherwise. */
end_comment

begin_define
define|#
directive|define
name|DBM
value|1
end_define

begin_comment
comment|/* use DBM library (requires -ldbm) */
end_comment

begin_define
define|#
directive|define
name|NDBM
value|1
end_define

begin_comment
comment|/* new DBM library available (requires DBM) */
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

begin_comment
comment|/* 	 * Use query type of ANY if possible (NO_WILDCARD_MX), which will 	 * find types CNAME, A, and MX, and will cause all existing records 	 * to be cached by our local server.  If there is (might be) a 	 * wildcard MX record in the local domain or its parents that are 	 * searched, we can't use ANY; it would cause fully-qualified names 	 * to match as names in a local domain. 	 */
end_comment

begin_define
define|#
directive|define
name|NO_WILDCARD_MX
value|1
end_define

end_unit

