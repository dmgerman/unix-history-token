begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: setenv.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_SETENV_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_SETENV_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETENV
end_ifndef

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|register
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|register
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|int
name|rewrite
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SETENV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_SETENV_H */
end_comment

end_unit

