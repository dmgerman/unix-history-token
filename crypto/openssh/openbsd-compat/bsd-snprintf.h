begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: bsd-snprintf.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_SNPRINTF_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_SNPRINTF_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* For size_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SNPRINTF
end_ifndef

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|count
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SNPRINTF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VSNPRINTF
end_ifndef

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|count
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SNPRINTF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_SNPRINTF_H */
end_comment

end_unit

