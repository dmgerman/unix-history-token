begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp_syslog.h,v 3.1 1993/07/06 01:06:59 jbj Exp  * A hack for platforms which require specially built syslog facilities  */
end_comment

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

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSLOG_FILE
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
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
comment|/* GIZMO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSLOG_FILE
end_ifdef

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|syslog_file
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|syslog
value|msyslog
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

