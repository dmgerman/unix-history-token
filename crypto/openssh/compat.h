begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Markus Friedl.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* RCSID("$Id: compat.h,v 1.7 2000/05/08 17:42:24 markus Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|COMPAT_H
end_define

begin_define
define|#
directive|define
name|SSH_PROTO_UNKNOWN
value|0x00
end_define

begin_define
define|#
directive|define
name|SSH_PROTO_1
value|0x01
end_define

begin_define
define|#
directive|define
name|SSH_PROTO_1_PREFERRED
value|0x02
end_define

begin_define
define|#
directive|define
name|SSH_PROTO_2
value|0x04
end_define

begin_define
define|#
directive|define
name|SSH_BUG_SIGBLOB
value|0x01
end_define

begin_define
define|#
directive|define
name|SSH_BUG_PUBKEYAUTH
value|0x02
end_define

begin_define
define|#
directive|define
name|SSH_BUG_HMAC
value|0x04
end_define

begin_define
define|#
directive|define
name|SSH_BUG_X11FWD
value|0x08
end_define

begin_function_decl
name|void
name|enable_compat13
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|enable_compat20
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|compat_datafellows
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_spec
parameter_list|(
specifier|const
name|char
modifier|*
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|compat13
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|compat20
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|datafellows
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

