begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: getcwd.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_GETCWD_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_GETCWD_H
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
name|HAVE_GETCWD
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|getcwd
parameter_list|(
name|char
modifier|*
name|pt
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_GETCWD) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_GETCWD_H */
end_comment

end_unit

