begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	syslog.h	4.2	84/04/25	*/
end_comment

begin_comment
comment|/*  *  SYSLOG.H -- declarations for system logging program  *  *	These are used as the first parameter to logmsg().  *	Their meanings are approximately as follows:  *  *	LOG_ALERT -- this priority should essentially never  *		be used.  It applies only to messages that  *		are so important that every user should be  *		aware of them, e.g., a serious hardware failure.  *	LOG_SALERT -- messages of this priority should be  *		issued only when immediate attention is needed  *		by a qualified system person, e.g., when some  *		valuable system resource dissappears.  They get  *		sent to a list of system people.  *	LOG_EMERG -- Emergency messages are not sent to users,  *		but represent major conditions.  An example  *		might be hard disk failures.  These could be  *		logged in a separate file so that critical  *		conditions could be easily scanned.  *	LOG_ERR -- these represent error conditions, such as soft  *		disk failures, etc.  *	LOG_CRIT -- such messages contain critical information,  *		but which can not be classed as errors, for example,  *		'su' attempts.  *	LOG_WARNING -- issued when an abnormal condition has been  *		detected, but recovery can take place.  *	LOG_NOTICE -- something that falls in the class of  *		"important information"; this class is informational  *		but important enough that you don't want to throw  *		it away casually.  *	LOG_INFO -- information level messages.  These messages  *		could be thrown away without problems, but should  *		be included if you want to keep a close watch on  *		your system.  *	LOG_DEBUG -- it may be useful to log certain debugging  *		information.  Normally this will be thrown away.  */
end_comment

begin_comment
comment|/* defines for priorities */
end_comment

begin_define
define|#
directive|define
name|LOG_ALERT
value|1
end_define

begin_comment
comment|/* alert -- send to all users */
end_comment

begin_define
define|#
directive|define
name|LOG_SALERT
value|2
end_define

begin_comment
comment|/* subalert -- send to special users */
end_comment

begin_define
define|#
directive|define
name|LOG_EMERG
value|3
end_define

begin_comment
comment|/* emergency conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_ERROR
value|4
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|LOG_ERR
value|4
end_define

begin_comment
comment|/* synonym of LOG_ERROR */
end_comment

begin_define
define|#
directive|define
name|LOG_CRIT
value|5
end_define

begin_comment
comment|/* critical information */
end_comment

begin_define
define|#
directive|define
name|LOG_WARNING
value|6
end_define

begin_comment
comment|/* warning */
end_comment

begin_define
define|#
directive|define
name|LOG_NOTICE
value|7
end_define

begin_comment
comment|/* important information */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO
value|8
end_define

begin_comment
comment|/* informational message */
end_comment

begin_define
define|#
directive|define
name|LOG_DEBUG
value|9
end_define

begin_comment
comment|/* debug level info */
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

end_unit

