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
literal|"@(#)step.c	8.1 (Berkeley) 6/6/93"
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
comment|/*  * Continue execution up to the next source line.  *  * We call "nextaddr" from the machine module to figure out  * what the object address is that corresponds to the next source line.  * If nextaddr returns -1, then the end of the program has been reached.  *  * There are two ways to define the next source line depending on what  * is desired when a procedure or function call is encountered.  Step  * stops at the beginning of the procedure or call; next skips over it.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"source.h"
end_include

begin_include
include|#
directive|include
file|"mappings.h"
end_include

begin_include
include|#
directive|include
file|"process.rep"
end_include

begin_comment
comment|/*  * Stepc is what is called when the step command is given.  * It has to play with the "isstopped" information.  */
end_comment

begin_macro
name|stepc
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|isstopped
condition|)
block|{
name|error
argument_list|(
literal|"can't continue execution"
argument_list|)
expr_stmt|;
block|}
name|isstopped
operator|=
name|FALSE
expr_stmt|;
name|dostep
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|isstopped
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_macro
name|next
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|isstopped
condition|)
block|{
name|error
argument_list|(
literal|"can't continue execution"
argument_list|)
expr_stmt|;
block|}
name|isstopped
operator|=
name|FALSE
expr_stmt|;
name|dostep
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
name|isstopped
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_macro
name|step
argument_list|()
end_macro

begin_block
block|{
name|dostep
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Resume execution up to the given address.  It is assumed that  * no breakpoints exist between the current address and the one  * we're stepping to.  This saves us from setting all the breakpoints.  */
end_comment

begin_macro
name|stepto
argument_list|(
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|ADDRESS
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|setbp
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|resume
argument_list|()
expr_stmt|;
name|unsetbp
argument_list|(
name|addr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isbperr
argument_list|()
condition|)
block|{
name|printstatus
argument_list|()
expr_stmt|;
block|}
block|}
end_block

begin_function
name|LOCAL
name|dostep
parameter_list|(
name|isnext
parameter_list|)
name|BOOLEAN
name|isnext
decl_stmt|;
block|{
specifier|register
name|ADDRESS
name|addr
decl_stmt|;
specifier|register
name|LINENO
name|line
decl_stmt|;
name|addr
operator|=
name|pc
expr_stmt|;
do|do
block|{
name|addr
operator|=
name|nextaddr
argument_list|(
name|addr
argument_list|,
name|isnext
argument_list|)
expr_stmt|;
name|line
operator|=
name|linelookup
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|line
operator|==
literal|0
operator|&&
operator|!
name|ss_instructions
condition|)
do|;
name|stepto
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|curline
operator|=
name|line
expr_stmt|;
block|}
end_function

end_unit

