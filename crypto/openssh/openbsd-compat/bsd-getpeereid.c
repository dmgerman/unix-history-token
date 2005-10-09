begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002,2004 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: bsd-getpeereid.c,v 1.3 2004/02/17 05:49:55 djm Exp $"
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
name|socklen_t
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

