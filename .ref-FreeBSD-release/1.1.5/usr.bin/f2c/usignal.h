begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SIGHUP
end_ifndef

begin_define
define|#
directive|define
name|SIGHUP
value|1
end_define

begin_comment
comment|/* hangup */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGQUIT
end_ifndef

begin_define
define|#
directive|define
name|SIGQUIT
value|3
end_define

begin_comment
comment|/* quit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

