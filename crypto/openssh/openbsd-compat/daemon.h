begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: daemon.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_DAEMON_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_DAEMON_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DAEMON
end_ifndef

begin_function_decl
name|int
name|daemon
parameter_list|(
name|int
name|nochdir
parameter_list|,
name|int
name|noclose
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_DAEMON */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_DAEMON_H */
end_comment

end_unit

