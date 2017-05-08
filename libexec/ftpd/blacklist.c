begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Kurt Lidl under sponsorship from the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE. */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<blacklist.h>
end_include

begin_include
include|#
directive|include
file|"blacklist_client.h"
end_include

begin_decl_stmt
specifier|static
name|struct
name|blacklist
modifier|*
name|blstate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|use_blacklist
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|blacklist_init
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|use_blacklist
condition|)
name|blstate
operator|=
name|blacklist_open
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|blacklist_notify
parameter_list|(
name|int
name|action
parameter_list|,
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
if|if
condition|(
name|blstate
operator|==
name|NULL
condition|)
return|return;
operator|(
name|void
operator|)
name|blacklist_r
argument_list|(
name|blstate
argument_list|,
name|action
argument_list|,
name|fd
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

