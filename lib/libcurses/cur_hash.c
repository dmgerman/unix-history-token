begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)cur_hash.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * __hash() is "hashpjw" from the Dragon Book, Aho, Sethi& Ullman, p.436.  */
end_comment

begin_function
name|u_int
name|__hash
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
name|unsigned
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
specifier|register
name|u_int
name|h
decl_stmt|,
name|g
decl_stmt|,
name|i
decl_stmt|;
name|h
operator|=
literal|0
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|len
condition|)
block|{
name|h
operator|=
operator|(
name|h
operator|<<
literal|4
operator|)
operator|+
name|s
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|g
operator|=
name|h
operator|&
literal|0xf0000000
operator|)
condition|)
block|{
name|h
operator|=
name|h
operator|^
operator|(
name|g
operator|>>
literal|24
operator|)
expr_stmt|;
name|h
operator|=
name|h
operator|^
name|g
expr_stmt|;
block|}
name|i
operator|++
expr_stmt|;
block|}
return|return
name|h
return|;
block|}
end_function

end_unit

