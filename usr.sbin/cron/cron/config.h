begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 1988,1990,1993,1994 by Paul Vixie  * All rights reserved  *  * Distribute freely, except: don't remove my name from the source or  * documentation (don't take credit for my work), mark your changes (don't  * get me blamed for your possible bugs), don't alter or remove this  * notice.  May be sold if buildable source is provided to buyer.  No  * warrantee of any kind, express or implied, is included with this  * software; use at your own risk, responsibility for damages (if any) to  * anyone resulting from the use of this software rests entirely with the  * user.  *  * Send bug reports, bug fixes, enhancements, requests, flames, etc., and  * I'll try to keep a version up to date.  I can be reached as follows:  * Paul Vixie<paul@vix.com>          uunet!decwrl!vixie!paul  */
end_comment

begin_comment
comment|/* config.h - configurables for Vixie Cron  *  * $Id: config.h,v 1.1.1.1 1994/08/27 13:43:04 jkh Exp $  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_PATH_SENDMAIL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_SENDMAIL
value|"/usr/lib/sendmail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*SENDMAIL*/
end_comment

begin_comment
comment|/*  * these are site-dependent  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUGGING
end_ifndef

begin_define
define|#
directive|define
name|DEBUGGING
value|1
end_define

begin_comment
comment|/* 1 or 0 -- do you want debugging code built in? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 			 * choose one of these MAILCMD commands.  I use 			 * /bin/mail for speed; it makes biff bark but doesn't 			 * do aliasing.  /usr/lib/sendmail does aliasing but is 			 * a hog for short messages.  aliasing is not needed 			 * if you make use of the MAILTO= feature in crontabs. 			 * (hint: MAILTO= was added for this reason). 			 */
end_comment

begin_define
define|#
directive|define
name|MAILCMD
value|_PATH_SENDMAIL
end_define

begin_comment
comment|/*-*/
end_comment

begin_define
define|#
directive|define
name|MAILARGS
value|"%s -FCronDaemon -odi -oem %s"
end_define

begin_comment
comment|/*-*/
end_comment

begin_comment
comment|/* -Fx	 = set full-name of sender 			 * -odi	 = Option Deliverymode Interactive 			 * -oem	 = Option Errors Mailedtosender 			 */
end_comment

begin_comment
comment|/* #define MAILCMD "/bin/mail"			/*-*/
end_comment

begin_comment
comment|/* #define MAILARGS "%s -d  %s"			/*-*/
end_comment

begin_comment
comment|/* -d = undocumented but common flag: deliver locally? 			 */
end_comment

begin_comment
comment|/* #define MAILCMD "/usr/mmdf/bin/submit"	/*-*/
end_comment

begin_comment
comment|/* #define MAILARGS "%s -mlrxto %s"		/*-*/
end_comment

begin_comment
comment|/* #define MAIL_DATE				/*-*/
end_comment

begin_comment
comment|/* should we include an ersatz Date: header in 			 * generated mail?  if you are using sendmail 			 * for MAILCMD, it is better to let sendmail 			 * generate the Date: header. 			 */
end_comment

begin_comment
comment|/* if ALLOW_FILE and DENY_FILE are not defined or are 			 * defined but neither exists, should crontab(1) be 			 * usable only by root? 			 */
end_comment

begin_comment
comment|/*#define ALLOW_ONLY_ROOT			/*-*/
end_comment

begin_comment
comment|/* if you want to use syslog(3) instead of appending 			 * to CRONDIR/LOG_FILE (/var/cron/log, e.g.), define 			 * SYSLOG here.  Note that quite a bit of logging 			 * info is written, and that you probably don't want 			 * to use this on 4.2bsd since everything goes in 			 * /usr/spool/mqueue/syslog.  On 4.[34]bsd you can 			 * tell /etc/syslog.conf to send cron's logging to 			 * a separate file. 			 * 			 * Note that if this and LOG_FILE in "pathnames.h" 			 * are both defined, then logging will go to both 			 * places. 			 */
end_comment

begin_define
define|#
directive|define
name|SYSLOG
end_define

begin_comment
comment|/*-*/
end_comment

end_unit

