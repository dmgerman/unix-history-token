begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)entry.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * routines to deal with the entry addresses of blocks  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"runtime.h"
end_include

begin_include
include|#
directive|include
file|"frame.rep"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"sym.h"
end_include

begin_include
include|#
directive|include
file|"source.h"
end_include

begin_include
include|#
directive|include
file|"object.h"
end_include

begin_include
include|#
directive|include
file|"process/pxinfo.h"
end_include

begin_include
include|#
directive|include
file|"process/process.rep"
end_include

begin_comment
comment|/*  * Return the address of the beginning of the procedure/function  * associated with the given frame.  */
end_comment

begin_function
name|ADDRESS
name|entry
parameter_list|(
name|frp
parameter_list|)
specifier|register
name|FRAME
modifier|*
name|frp
decl_stmt|;
block|{
return|return
operator|(
name|frp
operator|->
name|blockp
operator|-
literal|2
operator|-
name|ENDOFF
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Find the entry address of the caller of the current block.  * This is only called in connection with breakpoints.  *  * This routine assumes it is at the very beginning of the block.  */
end_comment

begin_function
name|ADDRESS
name|caller_addr
parameter_list|()
block|{
name|FRAME
modifier|*
name|frp
decl_stmt|;
if|if
condition|(
operator|(
name|frp
operator|=
name|curframe
argument_list|()
operator|)
operator|==
name|NIL
condition|)
block|{
name|panic
argument_list|(
literal|"caller_addr(main program)"
argument_list|)
expr_stmt|;
block|}
name|frp
operator|=
name|nextframe
argument_list|(
name|frp
argument_list|)
expr_stmt|;
if|if
condition|(
name|frp
operator|==
name|NIL
condition|)
block|{
return|return
operator|(
name|codeloc
argument_list|(
name|program
argument_list|)
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
name|entry
argument_list|(
name|frp
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Find the return address of the current procedure/function.  *  * There are two special cases:  *  *	we're right at the beginning of the main program  *	we're right at the beginning of some procedure or function  *  * The first one is handled by returning the last instruction in  * the object code.  In the second case, we get the return address  * directly from the process' stack.  */
end_comment

begin_function
name|ADDRESS
name|return_addr
parameter_list|()
block|{
name|ADDRESS
name|addr
decl_stmt|;
name|FRAME
modifier|*
name|frp
decl_stmt|,
name|frame
decl_stmt|;
if|if
condition|(
name|pc
operator|==
name|codeloc
argument_list|(
name|program
argument_list|)
condition|)
block|{
name|addr
operator|=
name|lastaddr
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|frp
operator|=
name|curframe
argument_list|()
expr_stmt|;
if|if
condition|(
name|frp
operator|==
name|NIL
condition|)
block|{
name|dread
argument_list|(
operator|&
name|frame
argument_list|,
operator|(
name|ADDRESS
operator|)
name|process
operator|->
name|sp
argument_list|,
sizeof|sizeof
argument_list|(
name|FRAME
argument_list|)
argument_list|)
expr_stmt|;
name|addr
operator|=
name|frame
operator|.
name|save_pc
operator|-
name|ENDOFF
expr_stmt|;
block|}
else|else
block|{
name|addr
operator|=
name|frp
operator|->
name|save_pc
expr_stmt|;
block|}
block|}
return|return
name|addr
return|;
block|}
end_function

begin_comment
comment|/*  * Calculate the entry address for a procedure or function parameter,  * given the address of the descriptor.  */
end_comment

begin_function
name|ADDRESS
name|fparamaddr
parameter_list|(
name|a
parameter_list|)
name|ADDRESS
name|a
decl_stmt|;
block|{
name|ADDRESS
name|r
decl_stmt|;
name|dread
argument_list|(
operator|&
name|r
argument_list|,
name|a
argument_list|,
sizeof|sizeof
argument_list|(
name|r
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|-
name|ENDOFF
operator|)
return|;
block|}
end_function

end_unit

