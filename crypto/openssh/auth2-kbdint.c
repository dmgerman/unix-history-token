begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: auth2-kbdint.c,v 1.5 2006/08/03 03:34:41 deraadt Exp $ */
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
name|userauth_kbdint
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|)
block|{
name|int
name|authenticated
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|lang
decl_stmt|,
modifier|*
name|devs
decl_stmt|;
name|lang
operator|=
name|packet_get_string
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|devs
operator|=
name|packet_get_string
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|packet_check_eom
argument_list|()
expr_stmt|;
name|debug
argument_list|(
literal|"keyboard-interactive devs %s"
argument_list|,
name|devs
argument_list|)
expr_stmt|;
if|if
condition|(
name|options
operator|.
name|challenge_response_authentication
condition|)
name|authenticated
operator|=
name|auth2_challenge
argument_list|(
name|authctxt
argument_list|,
name|devs
argument_list|)
expr_stmt|;
name|xfree
argument_list|(
name|devs
argument_list|)
expr_stmt|;
name|xfree
argument_list|(
name|lang
argument_list|)
expr_stmt|;
return|return
name|authenticated
return|;
block|}
end_function

begin_decl_stmt
name|Authmethod
name|method_kbdint
init|=
block|{
literal|"keyboard-interactive"
block|,
name|userauth_kbdint
block|,
operator|&
name|options
operator|.
name|kbd_interactive_authentication
block|}
decl_stmt|;
end_decl_stmt

end_unit

