begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: basename.h,v 1.3 2003/02/25 03:32:16 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BASENAME_H
end_ifndef

begin_define
define|#
directive|define
name|_BASENAME_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_BASENAME
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|basename
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_BASENAME) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BASENAME_H */
end_comment

end_unit

