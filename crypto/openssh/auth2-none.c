begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: auth2-none.c,v 1.15 2008/07/02 12:36:39 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"atomicio.h"
end_include

begin_include
include|#
directive|include
file|"xmalloc.h"
end_include

begin_include
include|#
directive|include
file|"key.h"
end_include

begin_include
include|#
directive|include
file|"hostfile.h"
end_include

begin_include
include|#
directive|include
file|"auth.h"
end_include

begin_include
include|#
directive|include
file|"packet.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"buffer.h"
end_include

begin_include
include|#
directive|include
file|"servconf.h"
end_include

begin_include
include|#
directive|include
file|"compat.h"
end_include

begin_include
include|#
directive|include
file|"ssh2.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|GSSAPI
end_ifdef

begin_include
include|#
directive|include
file|"ssh-gss.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"monitor_wrap.h"
end_include

begin_comment
comment|/* import */
end_comment

begin_decl_stmt
specifier|extern
name|ServerOptions
name|options
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "none" is allowed only one time */
end_comment

begin_decl_stmt
specifier|static
name|int
name|none_enabled
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|userauth_none
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|)
block|{
name|none_enabled
operator|=
literal|0
expr_stmt|;
name|packet_check_eom
argument_list|()
expr_stmt|;
if|if
condition|(
name|options
operator|.
name|password_authentication
condition|)
return|return
operator|(
name|PRIVSEP
argument_list|(
name|auth_password
argument_list|(
name|authctxt
argument_list|,
literal|""
argument_list|)
argument_list|)
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|Authmethod
name|method_none
init|=
block|{
literal|"none"
block|,
name|userauth_none
block|,
operator|&
name|none_enabled
block|}
decl_stmt|;
end_decl_stmt

end_unit

