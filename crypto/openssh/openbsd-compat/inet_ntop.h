begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: inet_ntop.h,v 1.4 2001/08/09 00:56:53 mouring Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_INET_NTOP_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_INET_NTOP_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INET_NTOP
end_ifndef

begin_function_decl
specifier|const
name|char
modifier|*
name|inet_ntop
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
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
comment|/* !HAVE_INET_NTOP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_INET_NTOP_H */
end_comment

end_unit

