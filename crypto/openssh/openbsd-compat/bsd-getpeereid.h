begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: bsd-getpeereid.h,v 1.1 2002/09/12 00:33:02 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_GETPEEREID_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_GETPEEREID_H
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
comment|/* For uid_t, gid_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETPEEREID
end_ifndef

begin_function_decl
name|int
name|getpeereid
parameter_list|(
name|int
parameter_list|,
name|uid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GETPEEREID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_GETPEEREID_H */
end_comment

end_unit

