begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: getgrouplist.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_GETGROUPLIST_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_GETGROUPLIST_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETGROUPLIST
end_ifndef

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_function_decl
name|int
name|getgrouplist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

