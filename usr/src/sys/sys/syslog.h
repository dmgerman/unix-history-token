begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	syslog.h	4.3	85/01/31	*/
end_comment

begin_comment
comment|/*  *  Declarations for system logging program  *  *	These are used as the first parameter to syslog().  */
end_comment

begin_comment
comment|/* kernel priorities */
end_comment

begin_define
define|#
directive|define
name|KERN_EMERG
value|1
end_define

begin_comment
comment|/* emergency -- send to all users (wall) */
end_comment

begin_define
define|#
directive|define
name|KERN_ALERT
value|2
end_define

begin_comment
comment|/* alert -- system failure */
end_comment

begin_define
define|#
directive|define
name|KERN_ERR
value|3
end_define

begin_comment
comment|/* hard errors */
end_comment

begin_define
define|#
directive|define
name|KERN_FAIL
value|4
end_define

begin_comment
comment|/* table full/overflow */
end_comment

begin_define
define|#
directive|define
name|KERN_RECOV
value|5
end_define

begin_comment
comment|/* recoverable errors (softecc) */
end_comment

begin_define
define|#
directive|define
name|KERN_INFO
value|6
end_define

begin_comment
comment|/* inconsistency/configuration error */
end_comment

begin_comment
comment|/* user abnormal conditions priorities */
end_comment

begin_define
define|#
directive|define
name|LOG_EMERG
value|7
end_define

begin_comment
comment|/* system unusable -- send to all users */
end_comment

begin_define
define|#
directive|define
name|LOG_ALERT
value|8
end_define

begin_comment
comment|/* missing files (e.g., /etc/utmp) */
end_comment

begin_define
define|#
directive|define
name|LOG_CRIT
value|9
end_define

begin_comment
comment|/* critical conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_ERR
value|10
end_define

begin_comment
comment|/* init open faliures/fatal daemon errors */
end_comment

begin_define
define|#
directive|define
name|LOG_FAIL
value|11
end_define

begin_comment
comment|/* getty failing, interface dropped */
end_comment

begin_define
define|#
directive|define
name|LOG_WARN
value|12
end_define

begin_comment
comment|/* non-fatal daemon errs */
end_comment

begin_comment
comment|/* user priorities */
end_comment

begin_define
define|#
directive|define
name|LOG_SALERT
value|13
end_define

begin_comment
comment|/* important information */
end_comment

begin_define
define|#
directive|define
name|LOG_SECURITY
value|14
end_define

begin_comment
comment|/* root/su logins */
end_comment

begin_define
define|#
directive|define
name|LOG_FIXED
value|15
end_define

begin_comment
comment|/* abnormal condition fixed (recovery action) */
end_comment

begin_define
define|#
directive|define
name|LOG_MAIL
value|16
end_define

begin_comment
comment|/* mail failures */
end_comment

begin_define
define|#
directive|define
name|LOG_REJECT
value|17
end_define

begin_comment
comment|/* login/daemon rejections */
end_comment

begin_define
define|#
directive|define
name|LOG_NOTICE
value|18
end_define

begin_comment
comment|/* important info */
end_comment

begin_comment
comment|/* user information priorities */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO
value|19
end_define

begin_comment
comment|/* informational message */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO1
value|20
end_define

begin_comment
comment|/* informational message */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO2
value|21
end_define

begin_comment
comment|/* informational message */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO3
value|22
end_define

begin_comment
comment|/* informational message */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO4
value|23
end_define

begin_comment
comment|/* informational message */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO5
value|24
end_define

begin_comment
comment|/* informational message */
end_comment

begin_comment
comment|/* user debug/local priorities */
end_comment

begin_define
define|#
directive|define
name|LOG_DEBUG
value|25
end_define

begin_comment
comment|/* debugging info */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL1
value|26
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL2
value|27
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL3
value|28
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL4
value|29
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL5
value|30
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_define
define|#
directive|define
name|LOG_LOCAL6
value|31
end_define

begin_comment
comment|/* reserved for local use */
end_comment

begin_comment
comment|/*  *  Option flags for openlog.  */
end_comment

begin_define
define|#
directive|define
name|LOG_PID
value|01
end_define

begin_comment
comment|/* log the pid with each message */
end_comment

begin_define
define|#
directive|define
name|LOG_CONS
value|02
end_define

begin_comment
comment|/* log on the console if errors in sending */
end_comment

begin_define
define|#
directive|define
name|LOG_ODELAY
value|04
end_define

begin_comment
comment|/* delay open until syslog() is called */
end_comment

end_unit

