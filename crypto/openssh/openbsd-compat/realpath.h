begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: realpath.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_REALPATH_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_REALPATH_H
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
name|HAVE_REALPATH
argument_list|)
operator|||
name|defined
argument_list|(
name|BROKEN_REALPATH
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|realpath
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|resolved
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_REALPATH) || defined(BROKEN_REALPATH) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_REALPATH_H */
end_comment

end_unit

