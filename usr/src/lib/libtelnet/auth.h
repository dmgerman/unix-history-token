begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)auth.h	8.1 (Berkeley) 6/4/93  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1990 by the Massachusetts Institute of Technology  *  * Export of this software from the United States of America is assumed  * to require a specific license from the United States Government.  * It is the responsibility of any person or organization contemplating  * export to obtain such a license before exporting.  *  * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and  * distribute this software and its documentation for any purpose and  * without fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright notice and  * this permission notice appear in supporting documentation, and that  * the name of M.I.T. not be used in advertising or publicity pertaining  * to distribution of the software without specific, written prior  * permission.  M.I.T. makes no representations about the suitability of  * this software for any purpose.  It is provided "as is" without express  * or implied warranty.  */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|P
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
argument_list|(
argument|*init
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|XauthP
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*send
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|XauthP
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*is
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|XauthP
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*reply
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|XauthP
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*status
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|XauthP
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*printsub
argument_list|)
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
block|}
name|Authenticator
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"auth-proto.h"
end_include

begin_extern
extern|extern auth_debug_mode;
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

