begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)auth.h	8.1 (Berkeley) 6/4/93  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1990 by the Massachusetts Institute of Technology  *  * Export of this software from the United States of America is assumed  * to require a specific license from the United States Government.  * It is the responsibility of any person or organization contemplating  * export to obtain such a license before exporting.  *  * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and  * distribute this software and its documentation for any purpose and  * without fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright notice and  * this permission notice appear in supporting documentation, and that  * the name of M.I.T. not be used in advertising or publicity pertaining  * to distribution of the software without specific, written prior  * permission.  M.I.T. makes no representations about the suitability of  * this software for any purpose.  It is provided "as is" without express  * or implied warranty.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AUTH__
end_ifndef

begin_define
define|#
directive|define
name|__AUTH__
end_define

begin_define
define|#
directive|define
name|AUTH_REJECT
value|0
end_define

begin_comment
comment|/* Rejected */
end_comment

begin_define
define|#
directive|define
name|AUTH_UNKNOWN
value|1
end_define

begin_comment
comment|/* We don't know who he is, but he's okay */
end_comment

begin_define
define|#
directive|define
name|AUTH_OTHER
value|2
end_define

begin_comment
comment|/* We know him, but not his name */
end_comment

begin_define
define|#
directive|define
name|AUTH_USER
value|3
end_define

begin_comment
comment|/* We know he name */
end_comment

begin_define
define|#
directive|define
name|AUTH_VALID
value|4
end_define

begin_comment
comment|/* We know him, and he needs no password */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|XauthP
block|{
name|int
name|type
decl_stmt|;
name|int
name|way
decl_stmt|;
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|XauthP
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|send
function_decl|)
parameter_list|(
name|struct
name|XauthP
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|is
function_decl|)
parameter_list|(
name|struct
name|XauthP
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|reply
function_decl|)
parameter_list|(
name|struct
name|XauthP
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|status
function_decl|)
parameter_list|(
name|struct
name|XauthP
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|printsub
function_decl|)
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
block|}
name|Authenticator
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"auth-proto.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|auth_debug_mode
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

