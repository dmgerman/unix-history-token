begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)syslog.h	7.10 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  *  Facility codes  */
end_comment

begin_define
define|#
directive|define
name|LOG_KERN
value|(0<<3)
end_define

begin_comment
comment|/* kernel messages */
end_comment

begin_define
define|#
directive|define
name|LOG_USER
value|(1<<3)
end_define

begin_comment
comment|/* random user-level messages */
end_comment

begin_define
define|#
directive|define
name|LOG_MAIL
value|(2<<3)
end_define

begin_comment
comment|/* mail system */
end_comment

begin_define
define|#
directive|define
name|LOG_DAEMON
value|(3<<3)
end_define

begin_comment
comment|/* system daemons */
end_comment

begin_define
define|#
directive|define
name|LOG_AUTH
value|(4<<3)
end_define

begin_comment
comment|/* security/authorization messages */
end_comment

begin_define
define|#
directive|define
name|LOG_SYSLOG
value|(5<<3)
end_define

begin_comment
comment|/* messages generated internally by syslogd */
end_comment

begin_define
define|#
directive|define
name|LOG_LPR
value|(6<<3)
end_define

begin_comment
comment|/* line printer subsystem */
end_comment

begin_define
define|#
directive|define
name|LOG_NEWS
value|(7<<3)
end_define

begin_comment
comment|/* network news subsystem */
end_comment

begin_define
define|#
directive|define
name|LOG_UUCP
value|(8<<3)
end_define

begin_comment
comment|/* UUCP subsystem */
end_comment

begin_comment
comment|/* other codes through 15 reserved for system use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL0
value|(16<<3)
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL1
value|(17<<3)
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL2
value|(18<<3)
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL3
value|(19<<3)
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL4
value|(20<<3)
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL5
value|(21<<3)
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL6
value|(22<<3)
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL7
value|(23<<3)
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_NFACILITIES
value|24
end_define

begin_comment
comment|/* maximum number of facilities */
end_comment

begin_define
define|#
directive|define
name|LOG_FACMASK
value|0x03f8
end_define

begin_comment
comment|/* mask to extract facility part */
end_comment

begin_define
define|#
directive|define
name|LOG_FAC
parameter_list|(
name|p
parameter_list|)
value|(((p)& LOG_FACMASK)>> 3)
end_define

begin_comment
comment|/* facility of pri */
end_comment

begin_comment
comment|/*  *  Priorities (these are ordered)  */
end_comment

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
comment|/* normal but signification condition */
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

begin_define
define|#
directive|define
name|LOG_PRIMASK
value|0x0007
end_define

begin_comment
comment|/* mask to extract priority part (internal) */
end_comment

begin_define
define|#
directive|define
name|LOG_PRI
parameter_list|(
name|p
parameter_list|)
value|((p)& LOG_PRIMASK)
end_define

begin_comment
comment|/* extract priority */
end_comment

begin_define
define|#
directive|define
name|LOG_MAKEPRI
parameter_list|(
name|fac
parameter_list|,
name|pri
parameter_list|)
value|(((fac)<< 3) | (pri))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|LOG_PRINTF
value|-1
end_define

begin_comment
comment|/* pseudo-priority to indicate use of printf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * arguments to setlogmask.  */
end_comment

begin_define
define|#
directive|define
name|LOG_MASK
parameter_list|(
name|pri
parameter_list|)
value|(1<< (pri))
end_define

begin_comment
comment|/* mask for one priority */
end_comment

begin_define
define|#
directive|define
name|LOG_UPTO
parameter_list|(
name|pri
parameter_list|)
value|((1<< ((pri)+1)) - 1)
end_define

begin_comment
comment|/* all priorities through pri */
end_comment

begin_comment
comment|/*  *  Option flags for openlog.  *  *	LOG_ODELAY no longer does anything; LOG_NDELAY is the  *	inverse of what it used to be.  */
end_comment

begin_define
define|#
directive|define
name|LOG_PID
value|0x01
end_define

begin_comment
comment|/* log the pid with each message */
end_comment

begin_define
define|#
directive|define
name|LOG_CONS
value|0x02
end_define

begin_comment
comment|/* log on the console if errors in sending */
end_comment

begin_define
define|#
directive|define
name|LOG_ODELAY
value|0x04
end_define

begin_comment
comment|/* delay open until first syslog() (default) */
end_comment

begin_define
define|#
directive|define
name|LOG_NDELAY
value|0x08
end_define

begin_comment
comment|/* don't delay open */
end_comment

begin_define
define|#
directive|define
name|LOG_NOWAIT
value|0x10
end_define

begin_comment
comment|/* if forking to log on console, don't wait() */
end_comment

end_unit

