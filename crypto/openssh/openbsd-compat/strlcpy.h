begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: strlcpy.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_STRLCPY_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_STRLCPY_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|siz
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRLCPY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_STRLCPY_H */
end_comment

end_unit

