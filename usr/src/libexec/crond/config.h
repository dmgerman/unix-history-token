begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h - configurables for Vixie Cron  *  * $Header: config.h,v 2.1 90/07/18 00:24:35 vixie Exp $  */
end_comment

begin_comment
comment|/* Copyright 1988,1990 by Paul Vixie  * All rights reserved  *  * Distribute freely, except: don't remove my name from the source or  * documentation (don't take credit for my work), mark your changes (don't  * get me blamed for your possible bugs), don't alter or remove this  * notice.  May be sold if buildable source is provided to buyer.  No  * warrantee of any kind, express or implied, is included with this  * software; use at your own risk, responsibility for damages (if any) to  * anyone resulting from the use of this software rests entirely with the  * user.  *  * Send bug reports, bug fixes, enhancements, requests, flames, etc., and  * I'll try to keep a version up to date.  I can be reached as follows:  * Paul Vixie, 329 Noe Street, San Francisco, CA, 94114, (415) 864-7013,  * paul@vixie.sf.ca.us || {hoptoad,pacbell,decwrl,crash}!vixie!paul  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_FLAG
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_FLAG
end_define

begin_comment
comment|/*  * these are site-dependent  */
end_comment

begin_comment
comment|/* 			 * choose one of these MAILCMD commands.  I use 			 * /bin/mail for speed; it makes biff bark but doesn't 			 * do aliasing.  /usr/lib/sendmail does aliasing but is 			 * a hog for short messages.  aliasing is not needed 			 * if you make use of the MAILTO= feature in crontabs. 			 * (hint: MAILTO= was added for this reason). 			 */
end_comment

begin_define
define|#
directive|define
name|MAILCMD
value|"/usr/sbin/sendmail -F\"Cron Daemon\" -odi -oem -or0s %s"
end_define

begin_comment
comment|/*-*/
end_comment

begin_comment
comment|/* -Fx	 = set full-name of sender 			 * -odi	 = Option Deliverymode Interactive 			 * -oem	 = Option Errors Mailedtosender 			 * -or0s = Option Readtimeout -- don't time out 			 */
end_comment

begin_comment
comment|/* # define MAILCMD "/bin/mail -d  %s"		/*-*/
end_comment

begin_comment
comment|/* -d = undocumented but common flag: deliver locally? 			 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CRONDIR
end_ifndef

begin_comment
comment|/* CRONDIR is where crond(8) and crontab(1) both chdir 			 * to; SPOOL_DIR, ALLOW_FILE, DENY_FILE, and LOG_FILE 			 * are all relative to this directory. 			 * 			 * this can and should be set in the Makefile. 			 */
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

begin_define
define|#
directive|define
name|LOG_FILE
value|"log"
end_define

begin_comment
comment|/*-*/
end_comment

begin_comment
comment|/* if ALLOW_FILE and DENY_FILE are not defined or are 			 * defined but neither exists, should crontab(1) be 			 * usable only by root? 			 */
end_comment

begin_comment
comment|/*#define ALLOW_ONLY_ROOT			/*-*/
end_comment

begin_comment
comment|/* if you want to use syslog(3) instead of appending 			 * to CRONDIR/LOG_FILE (/var/cron/log, e.g.), define 			 * SYSLOG here.  Note that quite a bit of logging 			 * info is written, and that you probably don't want 			 * to use this on 4.2bsd since everything goes in 			 * /usr/spool/mqueue/syslog.  On 4.[34]bsd you can 			 * tell /etc/syslog.conf to send cron's logging to 			 * a separate file. 			 */
end_comment

begin_comment
comment|/*#define SYSLOG	 			/*-*/
end_comment

begin_comment
comment|/* this is the name of the environment variable 			 * that contains the user name.  it isn't read by 			 * cron, but it is SET by crond in the environments 			 * it creates for subprocesses.  on BSD, it will 			 * always be USER; on SysV it could be LOGNAME or 			 * something else. 			 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|USERENV
value|"USER"
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
name|ATT
argument_list|)
end_if

begin_define
define|#
directive|define
name|USERENV
value|"LOGNAME"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* where should the daemon stick its PID? 			 */
end_comment

begin_define
define|#
directive|define
name|PIDFILE
value|"/var/run/crond.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*CONFIG_FLAG*/
end_comment

end_unit

