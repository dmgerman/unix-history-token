begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)REWRITE.c	8.1 (Berkeley) 6/6/93"
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
file|"h00vars.h"
end_include

begin_expr_stmt
name|REWRITE
argument_list|(
name|filep
argument_list|,
name|name
argument_list|,
name|maxnamlen
argument_list|,
name|datasize
argument_list|)
specifier|register
expr|struct
name|iorec
operator|*
name|filep
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|maxnamlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|datasize
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|filep
operator|=
name|GETNAME
argument_list|(
name|filep
argument_list|,
name|name
argument_list|,
name|maxnamlen
argument_list|,
name|datasize
argument_list|)
expr_stmt|;
name|filep
operator|->
name|fbuf
operator|=
name|fopen
argument_list|(
name|filep
operator|->
name|fname
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|filep
operator|->
name|fbuf
operator|==
name|NULL
condition|)
block|{
name|PERROR
argument_list|(
literal|"Could not create "
argument_list|,
name|filep
operator|->
name|pfname
argument_list|)
expr_stmt|;
return|return;
block|}
name|filep
operator|->
name|funit
operator||=
operator|(
name|EOFF
operator||
name|FWRITE
operator|)
expr_stmt|;
if|if
condition|(
name|filep
operator|->
name|fblk
operator|>
name|PREDEF
condition|)
block|{
name|setbuf
argument_list|(
name|filep
operator|->
name|fbuf
argument_list|,
operator|&
name|filep
operator|->
name|buf
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

