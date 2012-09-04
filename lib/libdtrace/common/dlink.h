begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * This file and its contents are supplied under the terms of the  * Common Development and Distribution License ("CDDL"), version 1.0.  * You may only use this file in accordance with the terms of version  * 1.0 of the CDDL.  *  * A full copy of the text of the CDDL should have accompanied this  * source.  A copy of the CDDL is also available via the Internet at  * http://www.illumos.org/license/CDDL.  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DLINK_H
end_ifndef

begin_define
define|#
directive|define
name|_DLINK_H
end_define

begin_include
include|#
directive|include
file|<link.h>
end_include

begin_include
include|#
directive|include
file|<sys/dtrace.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
specifier|const
name|char
modifier|*
name|devname
decl_stmt|;
specifier|extern
name|void
name|dprintf
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_link_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dtrace_link_dof
parameter_list|(
name|dof_hdr_t
modifier|*
parameter_list|,
name|Lmid_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DLINK_H */
end_comment

end_unit

