begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NLS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<nl_types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"reentrant.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_comment
comment|/* Entries EAI_ADDRFAMILY (1) and EAI_NODATA (7) are obsoleted, but left */
end_comment

begin_comment
comment|/* for backward compatibility with userland code prior to 2553bis-02 */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|ai_errlist
index|[]
init|=
block|{
literal|"Success"
block|,
comment|/* 0 */
literal|"Address family for hostname not supported"
block|,
comment|/* 1 */
literal|"Temporary failure in name resolution"
block|,
comment|/* EAI_AGAIN */
literal|"Invalid value for ai_flags"
block|,
comment|/* EAI_BADFLAGS */
literal|"Non-recoverable failure in name resolution"
block|,
comment|/* EAI_FAIL */
literal|"ai_family not supported"
block|,
comment|/* EAI_FAMILY */
literal|"Memory allocation failure"
block|,
comment|/* EAI_MEMORY */
literal|"No address associated with hostname"
block|,
comment|/* 7 */
literal|"hostname nor servname provided, or not known"
block|,
comment|/* EAI_NONAME */
literal|"servname not supported for ai_socktype"
block|,
comment|/* EAI_SERVICE */
literal|"ai_socktype not supported"
block|,
comment|/* EAI_SOCKTYPE */
literal|"System error returned in errno"
block|,
comment|/* EAI_SYSTEM */
literal|"Invalid value for hints"
block|,
comment|/* EAI_BADHINTS */
literal|"Resolved protocol is unknown"
block|,
comment|/* EAI_PROTOCOL */
literal|"Argument buffer overflow"
comment|/* EAI_OVERFLOW */
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NLS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|gai_buf
index|[
name|NL_TEXTMAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|once_t
name|gai_init_once
init|=
name|ONCE_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|thread_key_t
name|gai_key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|gai_keycreated
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|gai_keycreate
parameter_list|(
name|void
parameter_list|)
block|{
name|gai_keycreated
operator|=
operator|(
name|thr_keycreate
argument_list|(
operator|&
name|gai_key
argument_list|,
name|free
argument_list|)
operator|==
literal|0
operator|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|const
name|char
modifier|*
name|gai_strerror
parameter_list|(
name|int
name|ecode
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|NLS
argument_list|)
name|nl_catd
name|catd
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
if|if
condition|(
name|thr_main
argument_list|()
operator|!=
literal|0
condition|)
name|buf
operator|=
name|gai_buf
expr_stmt|;
else|else
block|{
if|if
condition|(
name|thr_once
argument_list|(
operator|&
name|gai_init_once
argument_list|,
name|gai_keycreate
argument_list|)
operator|!=
literal|0
operator|||
operator|!
name|gai_keycreated
condition|)
goto|goto
name|thr_err
goto|;
if|if
condition|(
operator|(
name|buf
operator|=
name|thr_getspecific
argument_list|(
name|gai_key
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
operator|(
name|buf
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|gai_buf
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
goto|goto
name|thr_err
goto|;
if|if
condition|(
name|thr_setspecific
argument_list|(
name|gai_key
argument_list|,
name|buf
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
goto|goto
name|thr_err
goto|;
block|}
block|}
block|}
name|catd
operator|=
name|catopen
argument_list|(
literal|"libc"
argument_list|,
name|NL_CAT_LOCALE
argument_list|)
expr_stmt|;
if|if
condition|(
name|ecode
operator|>
literal|0
operator|&&
name|ecode
operator|<
name|EAI_MAX
condition|)
name|strlcpy
argument_list|(
name|buf
argument_list|,
name|catgets
argument_list|(
name|catd
argument_list|,
literal|3
argument_list|,
name|ecode
argument_list|,
name|ai_errlist
index|[
name|ecode
index|]
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|gai_buf
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|ecode
operator|==
literal|0
condition|)
name|strlcpy
argument_list|(
name|buf
argument_list|,
name|catgets
argument_list|(
name|catd
argument_list|,
literal|3
argument_list|,
name|NL_MSGMAX
operator|-
literal|1
argument_list|,
literal|"Success"
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|gai_buf
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|strlcpy
argument_list|(
name|buf
argument_list|,
name|catgets
argument_list|(
name|catd
argument_list|,
literal|3
argument_list|,
name|NL_MSGMAX
argument_list|,
literal|"Unknown error"
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|gai_buf
argument_list|)
argument_list|)
expr_stmt|;
name|catclose
argument_list|(
name|catd
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
name|thr_err
label|:
endif|#
directive|endif
if|if
condition|(
name|ecode
operator|>=
literal|0
operator|&&
name|ecode
operator|<
name|EAI_MAX
condition|)
return|return
name|ai_errlist
index|[
name|ecode
index|]
return|;
return|return
literal|"Unknown error"
return|;
block|}
end_function

end_unit

