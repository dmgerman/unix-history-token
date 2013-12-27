begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Monthadar Al Jaberi, TerraNet AB  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Ioctl-related defintions for the Wireless TAP plugins.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VISIBILITY_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|_VISIBILITY_IOCTL_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_struct
struct|struct
name|link
block|{
name|int
name|op
decl_stmt|;
comment|//0 remove, 1 link
name|int
name|id1
decl_stmt|;
name|int
name|id2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VISIOCTLOPEN
value|_IOW('W', 3, int)
end_define

begin_comment
comment|// 0 close, 1 open
end_comment

begin_define
define|#
directive|define
name|VISIOCTLLINK
value|_IOW('W', 4, struct link)
end_define

begin_comment
comment|//
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

