begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)herror.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: herror.c,v 1.2.4.1 1995/08/30 04:06:46 davidg Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
name|h_errlist
index|[]
init|=
block|{
literal|"Resolver Error 0 (no error)"
block|,
literal|"Unknown host"
block|,
comment|/* 1 HOST_NOT_FOUND */
literal|"Host name lookup failure"
block|,
comment|/* 2 TRY_AGAIN */
literal|"Unknown server error"
block|,
comment|/* 3 NO_RECOVERY */
literal|"No address associated with name"
block|,
comment|/* 4 NO_ADDRESS */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|h_nerr
init|=
block|{
sizeof|sizeof
argument_list|(
name|h_errlist
argument_list|)
operator|/
expr|sizeof
operator|(
name|h_errlist
index|[
literal|0
index|]
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * herror --  *	print the error indicated by the h_errno value.  */
end_comment

begin_function
name|void
name|herror
parameter_list|(
name|s
parameter_list|)
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|struct
name|iovec
name|iov
index|[
literal|4
index|]
decl_stmt|;
specifier|register
name|struct
name|iovec
modifier|*
name|v
init|=
name|iov
decl_stmt|;
if|if
condition|(
name|s
operator|&&
operator|*
name|s
condition|)
block|{
name|v
operator|->
name|iov_base
operator|=
operator|(
name|char
operator|*
operator|)
name|s
expr_stmt|;
name|v
operator|->
name|iov_len
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|v
operator|++
expr_stmt|;
name|v
operator|->
name|iov_base
operator|=
literal|": "
expr_stmt|;
name|v
operator|->
name|iov_len
operator|=
literal|2
expr_stmt|;
name|v
operator|++
expr_stmt|;
block|}
name|v
operator|->
name|iov_base
operator|=
operator|(
name|char
operator|*
operator|)
name|hstrerror
argument_list|(
name|h_errno
argument_list|)
expr_stmt|;
name|v
operator|->
name|iov_len
operator|=
name|strlen
argument_list|(
name|v
operator|->
name|iov_base
argument_list|)
expr_stmt|;
name|v
operator|++
expr_stmt|;
name|v
operator|->
name|iov_base
operator|=
literal|"\n"
expr_stmt|;
name|v
operator|->
name|iov_len
operator|=
literal|1
expr_stmt|;
name|writev
argument_list|(
name|STDERR_FILENO
argument_list|,
name|iov
argument_list|,
operator|(
name|v
operator|-
name|iov
operator|)
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|hstrerror
parameter_list|(
name|err
parameter_list|)
name|int
name|err
decl_stmt|;
block|{
if|if
condition|(
name|err
operator|<
literal|0
condition|)
return|return
operator|(
literal|"Resolver internal error"
operator|)
return|;
elseif|else
if|if
condition|(
name|err
operator|<
name|h_nerr
condition|)
return|return
operator|(
name|h_errlist
index|[
name|err
index|]
operator|)
return|;
return|return
operator|(
literal|"Unknown resolver error"
operator|)
return|;
block|}
end_function

end_unit

