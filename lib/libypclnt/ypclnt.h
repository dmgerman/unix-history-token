begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_YPCLNT_H_INCLUDED
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|ypclnt
name|ypclnt_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ypclnt
block|{
name|char
modifier|*
name|domain
decl_stmt|;
comment|/* Domain name */
name|char
modifier|*
name|map
decl_stmt|;
comment|/* Map name */
name|char
modifier|*
name|server
decl_stmt|;
comment|/* Server name */
name|char
modifier|*
name|error
decl_stmt|;
comment|/* Error message */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|passwd
struct_decl|;
end_struct_decl

begin_function_decl
name|ypclnt_t
modifier|*
name|ypclnt_new
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ypclnt_free
parameter_list|(
name|ypclnt_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ypclnt_error
parameter_list|(
name|ypclnt_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ypclnt_connect
parameter_list|(
name|ypclnt_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ypclnt_passwd
parameter_list|(
name|ypclnt_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|passwd
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|YPCLNT_DEBUG
parameter_list|(
name|fmt
modifier|...
parameter_list|)
value|warnx(__FUNCTION__ ": " fmt, ##fmt)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|YPCLNT_DEBUG
parameter_list|(
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

