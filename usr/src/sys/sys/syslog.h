begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)syslog.h	7.16 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * priorities/facilities are encoded into a single 32-bit quantity, where the  * bottom 3 bits are the priority (0-7) and the top 28 bits are the facility  * (0-big number).  Both the priorities and the facilities map roughly  * one-to-one to strings in the syslogd(8) source code.  This mapping is  * included in this file.  *  * priorities (these are ordered)  */
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

begin_define
define|#
directive|define
name|LOG_PRIMASK
value|0x07
end_define

begin_comment
comment|/* mask to extract priority part (internal) */
end_comment

begin_comment
comment|/* extract priority */
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
name|SYSLOG_NAMES
end_ifdef

begin_define
define|#
directive|define
name|INTERNAL_NOPRI
value|0x10
end_define

begin_comment
comment|/* the "no priority" priority */
end_comment

begin_comment
comment|/* mark "facility" */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_MARK
value|LOG_MAKEPRI(LOG_NFACILITIES, 0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_code
block|{
name|char
modifier|*
name|c_name
decl_stmt|;
name|int
name|c_val
decl_stmt|;
block|}
name|CODE
typedef|;
end_typedef

begin_decl_stmt
name|CODE
name|prioritynames
index|[]
init|=
block|{
literal|"alert"
block|,
name|LOG_ALERT
block|,
literal|"crit"
block|,
name|LOG_CRIT
block|,
literal|"debug"
block|,
name|LOG_DEBUG
block|,
literal|"emerg"
block|,
name|LOG_EMERG
block|,
literal|"err"
block|,
name|LOG_ERR
block|,
literal|"error"
block|,
name|LOG_ERR
block|,
comment|/* DEPRECATED */
literal|"info"
block|,
name|LOG_INFO
block|,
literal|"none"
block|,
name|INTERNAL_NOPRI
block|,
comment|/* INTERNAL */
literal|"notice"
block|,
name|LOG_NOTICE
block|,
literal|"panic"
block|,
name|LOG_EMERG
block|,
comment|/* DEPRECATED */
literal|"warn"
block|,
name|LOG_WARNING
block|,
comment|/* DEPRECATED */
literal|"warning"
block|,
name|LOG_WARNING
block|,
name|NULL
block|,
operator|-
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* facility codes */
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

begin_define
define|#
directive|define
name|LOG_CRON
value|(9<<3)
end_define

begin_comment
comment|/* clock daemon */
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
comment|/* current number of facilities */
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

begin_comment
comment|/* facility of pri */
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

begin_ifdef
ifdef|#
directive|ifdef
name|SYSLOG_NAMES
end_ifdef

begin_decl_stmt
name|CODE
name|facilitynames
index|[]
init|=
block|{
literal|"auth"
block|,
name|LOG_AUTH
block|,
literal|"cron"
block|,
name|LOG_CRON
block|,
literal|"daemon"
block|,
name|LOG_DAEMON
block|,
literal|"kern"
block|,
name|LOG_KERN
block|,
literal|"lpr"
block|,
name|LOG_LPR
block|,
literal|"mail"
block|,
name|LOG_MAIL
block|,
literal|"mark"
block|,
name|INTERNAL_MARK
block|,
comment|/* INTERNAL */
literal|"news"
block|,
name|LOG_NEWS
block|,
literal|"security"
block|,
name|LOG_AUTH
block|,
comment|/* DEPRECATED */
literal|"syslog"
block|,
name|LOG_SYSLOG
block|,
literal|"user"
block|,
name|LOG_USER
block|,
literal|"uucp"
block|,
name|LOG_UUCP
block|,
literal|"local0"
block|,
name|LOG_LOCAL0
block|,
literal|"local1"
block|,
name|LOG_LOCAL1
block|,
literal|"local2"
block|,
name|LOG_LOCAL2
block|,
literal|"local3"
block|,
name|LOG_LOCAL3
block|,
literal|"local4"
block|,
name|LOG_LOCAL4
block|,
literal|"local5"
block|,
name|LOG_LOCAL5
block|,
literal|"local6"
block|,
name|LOG_LOCAL6
block|,
literal|"local7"
block|,
name|LOG_LOCAL7
block|,
name|NULL
block|,
operator|-
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Option flags for openlog.  *  * LOG_ODELAY no longer does anything.  * LOG_NDELAY is the inverse of what it used to be.  */
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
comment|/* don't wait for console forks: DEPRECATED */
end_comment

begin_define
define|#
directive|define
name|LOG_PERROR
value|0x20
end_define

begin_comment
comment|/* log to stderr as well */
end_comment

end_unit

