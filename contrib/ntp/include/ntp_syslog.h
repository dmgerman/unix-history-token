begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * A hack for platforms which require specially built syslog facilities  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_SYSLOG_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_SYSLOG_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GIZMO
end_ifdef

begin_include
include|#
directive|include
file|"gizmo_syslog.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !GIZMO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|msyslog
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_VXWORKS
end_ifndef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GIZMO */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|syslogit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|syslog_file
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_VXWORKS
argument_list|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS || VXWORKS */
end_comment

begin_comment
comment|/*  * syslog output control  */
end_comment

begin_define
define|#
directive|define
name|NLOG_INFO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NLOG_EVENT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NLOG_STATUS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NLOG_STATIST
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NLOG_OSYS
value|0
end_define

begin_comment
comment|/* offset for system flags */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYSMASK
value|0x0000000F
end_define

begin_comment
comment|/* system log events */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYSINFO
value|0x00000001
end_define

begin_comment
comment|/* system info log events */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYSEVENT
value|0x00000002
end_define

begin_comment
comment|/* system events */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYSSTATUS
value|0x00000004
end_define

begin_comment
comment|/* system status (sync/unsync) */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYSSTATIST
value|0x00000008
end_define

begin_comment
comment|/* system statistics output */
end_comment

begin_define
define|#
directive|define
name|NLOG_OPEER
value|4
end_define

begin_comment
comment|/* offset for peer flags */
end_comment

begin_define
define|#
directive|define
name|NLOG_PEERMASK
value|0x000000F0
end_define

begin_comment
comment|/* peer log events */
end_comment

begin_define
define|#
directive|define
name|NLOG_PEERINFO
value|0x00000010
end_define

begin_comment
comment|/* peer info log events */
end_comment

begin_define
define|#
directive|define
name|NLOG_PEEREVENT
value|0x00000020
end_define

begin_comment
comment|/* peer events */
end_comment

begin_define
define|#
directive|define
name|NLOG_PEERSTATUS
value|0x00000040
end_define

begin_comment
comment|/* peer status (sync/unsync) */
end_comment

begin_define
define|#
directive|define
name|NLOG_PEERSTATIST
value|0x00000080
end_define

begin_comment
comment|/* peer statistics output */
end_comment

begin_define
define|#
directive|define
name|NLOG_OCLOCK
value|8
end_define

begin_comment
comment|/* offset for clock flags */
end_comment

begin_define
define|#
directive|define
name|NLOG_CLOCKMASK
value|0x00000F00
end_define

begin_comment
comment|/* clock log events */
end_comment

begin_define
define|#
directive|define
name|NLOG_CLOCKINFO
value|0x00000100
end_define

begin_comment
comment|/* clock info log events */
end_comment

begin_define
define|#
directive|define
name|NLOG_CLOCKEVENT
value|0x00000200
end_define

begin_comment
comment|/* clock events */
end_comment

begin_define
define|#
directive|define
name|NLOG_CLOCKSTATUS
value|0x00000400
end_define

begin_comment
comment|/* clock status (sync/unsync) */
end_comment

begin_define
define|#
directive|define
name|NLOG_CLOCKSTATIST
value|0x00000800
end_define

begin_comment
comment|/* clock statistics output */
end_comment

begin_define
define|#
directive|define
name|NLOG_OSYNC
value|12
end_define

begin_comment
comment|/* offset for sync flags */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYNCMASK
value|0x0000F000
end_define

begin_comment
comment|/* sync log events */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYNCINFO
value|0x00001000
end_define

begin_comment
comment|/* sync info log events */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYNCEVENT
value|0x00002000
end_define

begin_comment
comment|/* sync events */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYNCSTATUS
value|0x00004000
end_define

begin_comment
comment|/* sync status (sync/unsync) */
end_comment

begin_define
define|#
directive|define
name|NLOG_SYNCSTATIST
value|0x00008000
end_define

begin_comment
comment|/* sync statistics output */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|ntp_syslogmask
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NLOG
parameter_list|(
name|_X_
parameter_list|)
value|if (ntp_syslogmask& (_X_))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_SYSLOG_H */
end_comment

end_unit

