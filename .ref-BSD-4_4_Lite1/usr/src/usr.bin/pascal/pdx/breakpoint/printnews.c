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
literal|"@(#)printnews.c	8.1 (Berkeley) 6/6/93"
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
comment|/*  * Print out news during single step tracing.  *  * We have to handle all the single stepping possibilities,  * including combinations.  A combination of single stepping  * by line and by instruction causes "curline" to be 0 but  * "ss_lines" to be TRUE.  We avoid trying to print lines in this case.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"breakpoint.h"
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
file|"mappings.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_macro
name|printnews
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|ss_variables
condition|)
block|{
name|prvarnews
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|trcond
argument_list|()
condition|)
block|{
if|if
condition|(
name|ss_lines
operator|&&
name|curline
operator|>
literal|0
condition|)
block|{
name|skimsource
argument_list|(
name|srcfilename
argument_list|(
name|pc
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"trace:  "
argument_list|)
expr_stmt|;
name|printlines
argument_list|(
name|curline
argument_list|,
name|curline
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ss_instructions
condition|)
block|{
name|printf
argument_list|(
literal|"inst trace: "
argument_list|)
expr_stmt|;
name|printinst
argument_list|(
name|pc
argument_list|,
name|pc
argument_list|)
expr_stmt|;
block|}
block|}
name|bpact
argument_list|()
expr_stmt|;
if|if
condition|(
name|stopcond
argument_list|()
condition|)
block|{
name|isstopped
operator|=
name|TRUE
expr_stmt|;
name|curline
operator|=
name|srcline
argument_list|(
name|pc
argument_list|)
expr_stmt|;
name|printstatus
argument_list|()
expr_stmt|;
block|}
block|}
end_block

end_unit

