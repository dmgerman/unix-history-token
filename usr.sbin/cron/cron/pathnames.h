begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 1993,1994 by Paul Vixie  * All rights reserved  *  * Distribute freely, except: don't remove my name from the source or  * documentation (don't take credit for my work), mark your changes (don't  * get me blamed for your possible bugs), don't alter or remove this  * notice.  May be sold if buildable source is provided to buyer.  No  * warrantee of any kind, express or implied, is included with this  * software; use at your own risk, responsibility for damages (if any) to  * anyone resulting from the use of this software rests entirely with the  * user.  *  * Send bug reports, bug fixes, enhancements, requests, flames, etc., and  * I'll try to keep a version up to date.  I can be reached as follows:  * Paul Vixie<paul@vix.com>          uunet!decwrl!vixie!paul  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|||
name|defined
argument_list|(
name|__linux
argument_list|)
operator|||
name|defined
argument_list|(
name|AIX
argument_list|)
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
comment|/*BSD*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CRONDIR
end_ifndef

begin_comment
comment|/* CRONDIR is where crond(8) and crontab(1) both chdir 			 * to; SPOOL_DIR, ALLOW_FILE, DENY_FILE, and LOG_FILE 			 * are all relative to this directory. 			 */
end_comment

begin_define
define|#
directive|define
name|CRONDIR
value|"/var/cron"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPOOLDIR is where the crontabs live. 			 * This directory will have its modtime updated 			 * whenever crontab(1) changes a crontab; this is 			 * the signal for crond(8) to look at each individual 			 * crontab file and reload those whose modtimes are 			 * newer than they were last time around (or which 			 * didn't exist last time around...) 			 */
end_comment

begin_define
define|#
directive|define
name|SPOOL_DIR
value|"tabs"
end_define

begin_comment
comment|/* undefining these turns off their features.  note 			 * that ALLOW_FILE and DENY_FILE must both be defined 			 * in order to enable the allow/deny code.  If neither 			 * LOG_FILE or SYSLOG is defined, we don't log.  If 			 * both are defined, we log both ways. 			 */
end_comment

begin_define
define|#
directive|define
name|ALLOW_FILE
value|"allow"
end_define

begin_comment
comment|/*-*/
end_comment

begin_define
define|#
directive|define
name|DENY_FILE
value|"deny"
end_define

begin_comment
comment|/*-*/
end_comment

begin_comment
comment|/*#define LOG_FILE        "log"*/
end_comment

begin_comment
comment|/*-*/
end_comment

begin_comment
comment|/* where should the daemon stick its PID? 			 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_VARRUN
end_ifdef

begin_define
define|#
directive|define
name|PIDDIR
value|_PATH_VARRUN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIDDIR
value|"/etc/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PIDFILE
value|"%scron.pid"
end_define

begin_comment
comment|/* 4.3BSD-style crontab */
end_comment

begin_define
define|#
directive|define
name|SYSCRONTAB
value|"/etc/crontab"
end_define

begin_comment
comment|/* what editor to use if no EDITOR or VISUAL 			 * environment variable specified. 			 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_PATH_VI
argument_list|)
end_if

begin_define
define|#
directive|define
name|EDITOR
value|_PATH_VI
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EDITOR
value|"/usr/ucb/vi"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BSHELL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEFPATH
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|"/usr/bin:/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

