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
file|<netdb.h>
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
comment|/* EAI_PROTOCOL */
block|}
decl_stmt|;
end_decl_stmt

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

