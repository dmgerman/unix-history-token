begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: auth2-passwd.c,v 1.9 2006/08/03 03:34:41 deraadt Exp $ */
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|"xmalloc.h"
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
file|"buffer.h"
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

begin_include
include|#
directive|include
file|"servconf.h"
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

begin_function
specifier|static
name|int
name|userauth_passwd
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|)
block|{
name|char
modifier|*
name|password
decl_stmt|,
modifier|*
name|newpass
decl_stmt|;
name|int
name|authenticated
init|=
literal|0
decl_stmt|;
name|int
name|change
decl_stmt|;
name|u_int
name|len
decl_stmt|,
name|newlen
decl_stmt|;
name|change
operator|=
name|packet_get_char
argument_list|()
expr_stmt|;
name|password
operator|=
name|packet_get_string
argument_list|(
operator|&
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|change
condition|)
block|{
comment|/* discard new password from packet */
name|newpass
operator|=
name|packet_get_string
argument_list|(
operator|&
name|newlen
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|newpass
argument_list|,
literal|0
argument_list|,
name|newlen
argument_list|)
expr_stmt|;
name|xfree
argument_list|(
name|newpass
argument_list|)
expr_stmt|;
block|}
name|packet_check_eom
argument_list|()
expr_stmt|;
if|if
condition|(
name|change
condition|)
name|logit
argument_list|(
literal|"password change not supported"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|PRIVSEP
argument_list|(
name|auth_password
argument_list|(
name|authctxt
argument_list|,
name|password
argument_list|)
argument_list|)
operator|==
literal|1
condition|)
name|authenticated
operator|=
literal|1
expr_stmt|;
name|memset
argument_list|(
name|password
argument_list|,
literal|0
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|xfree
argument_list|(
name|password
argument_list|)
expr_stmt|;
return|return
name|authenticated
return|;
block|}
end_function

begin_decl_stmt
name|Authmethod
name|method_passwd
init|=
block|{
literal|"password"
block|,
name|userauth_passwd
block|,
operator|&
name|options
operator|.
name|password_authentication
block|}
decl_stmt|;
end_decl_stmt

end_unit

