begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: strsep.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_STRSEP_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_STRSEP_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRSEP
end_ifndef

begin_function_decl
name|char
modifier|*
name|strsep
parameter_list|(
name|char
modifier|*
modifier|*
name|stringp
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRSEP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_STRSEP_H */
end_comment

end_unit

