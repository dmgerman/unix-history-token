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
literal|"@(#)NEW.c	8.1 (Berkeley) 6/6/93"
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

begin_macro
name|NEW
argument_list|(
argument|var
argument_list|,
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
modifier|*
name|var
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to item being deallocated */
end_comment

begin_decl_stmt
name|long
name|size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizeof struct pointed to by var */
end_comment

begin_block
block|{
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
name|char
modifier|*
name|memblk
decl_stmt|;
name|memblk
operator|=
name|malloc
argument_list|(
operator|(
name|int
operator|)
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|memblk
operator|==
literal|0
condition|)
block|{
name|ERROR
argument_list|(
literal|"Ran out of memory\n"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
operator|*
name|var
operator|=
name|memblk
expr_stmt|;
if|if
condition|(
name|memblk
operator|<
name|_minptr
condition|)
name|_minptr
operator|=
name|memblk
expr_stmt|;
if|if
condition|(
name|memblk
operator|+
name|size
operator|>
name|_maxptr
condition|)
name|_maxptr
operator|=
name|memblk
operator|+
name|size
expr_stmt|;
block|}
end_block

end_unit

