begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  CONF.H -- All user-configurable parameters for sendmail ** **	@(#)conf.h	3.2		%G% */
end_comment

begin_comment
comment|/* **  Table sizes, etc.... **	There shouldn't be much need to change these.... */
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|256
end_define

begin_comment
comment|/* max line length */
end_comment

begin_define
define|#
directive|define
name|MAXNAME
value|128
end_define

begin_comment
comment|/* max length of a name */
end_comment

begin_define
define|#
directive|define
name|MAXFIELD
value|2500
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
value|30
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

begin_comment
comment|/* **  Compilation options. */
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
name|DEBUG
value|1
end_define

begin_comment
comment|/* enable debugging */
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
comment|/* include the daemon (requires IPC) */
end_comment

end_unit

