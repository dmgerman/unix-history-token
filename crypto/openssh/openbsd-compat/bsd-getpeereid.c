begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 Damien Miller.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: bsd-getpeereid.c,v 1.1 2002/09/12 00:33:02 djm Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GETPEEREID
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SO_PEERCRED
argument_list|)
end_if

begin_function
name|int
name|getpeereid
parameter_list|(
name|int
name|s
parameter_list|,
name|uid_t
modifier|*
name|euid
parameter_list|,
name|gid_t
modifier|*
name|gid
parameter_list|)
block|{
name|struct
name|ucred
name|cred
decl_stmt|;
name|size_t
name|len
init|=
sizeof|sizeof
argument_list|(
name|cred
argument_list|)
decl_stmt|;
if|if
condition|(
name|getsockopt
argument_list|(
name|s
argument_list|,
name|SOL_SOCKET
argument_list|,
name|SO_PEERCRED
argument_list|,
operator|&
name|cred
argument_list|,
operator|&
name|len
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|*
name|euid
operator|=
name|cred
operator|.
name|uid
expr_stmt|;
operator|*
name|gid
operator|=
name|cred
operator|.
name|gid
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|getpeereid
parameter_list|(
name|int
name|s
parameter_list|,
name|uid_t
modifier|*
name|euid
parameter_list|,
name|gid_t
modifier|*
name|gid
parameter_list|)
block|{
operator|*
name|euid
operator|=
name|geteuid
argument_list|()
expr_stmt|;
operator|*
name|gid
operator|=
name|getgid
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(SO_PEERCRED) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_GETPEEREID) */
end_comment

end_unit

