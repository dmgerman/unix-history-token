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
literal|"@(#)lab.c	8.1 (Berkeley) 6/6/93"
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
comment|/*  * pxp - Pascal execution profiler  *  * Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_comment
comment|/*  * Label declaration part  */
end_comment

begin_macro
name|label
argument_list|(
argument|r
argument_list|,
argument|l
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|r
decl_stmt|,
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
operator|*
name|ll
expr_stmt|;
if|if
condition|(
name|nodecl
condition|)
name|printoff
argument_list|()
expr_stmt|;
name|puthedr
argument_list|()
expr_stmt|;
name|setline
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|ppnl
argument_list|()
expr_stmt|;
name|indent
argument_list|()
expr_stmt|;
name|ppkw
argument_list|(
literal|"label"
argument_list|)
expr_stmt|;
name|ppgoin
argument_list|(
name|DECL
argument_list|)
expr_stmt|;
name|ppnl
argument_list|()
expr_stmt|;
name|indent
argument_list|()
expr_stmt|;
name|ppbra
argument_list|(
name|NIL
argument_list|)
expr_stmt|;
name|ll
operator|=
name|r
expr_stmt|;
if|if
condition|(
name|ll
operator|!=
name|NIL
condition|)
for|for
control|(
init|;
condition|;
control|)
block|{
name|pplab
argument_list|(
name|ll
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|ll
operator|=
name|ll
index|[
literal|2
index|]
expr_stmt|;
if|if
condition|(
name|ll
operator|==
name|NIL
condition|)
break|break;
name|ppsep
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
block|}
else|else
name|ppid
argument_list|(
literal|"{label list}"
argument_list|)
expr_stmt|;
name|ppket
argument_list|(
literal|";"
argument_list|)
expr_stmt|;
name|putcml
argument_list|()
expr_stmt|;
name|ppgoout
argument_list|(
name|DECL
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Goto statement  */
end_comment

begin_macro
name|gotoop
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|gocnt
operator|++
expr_stmt|;
name|ppkw
argument_list|(
literal|"goto"
argument_list|)
expr_stmt|;
name|ppspac
argument_list|()
expr_stmt|;
name|pplab
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * A label on a statement  */
end_comment

begin_macro
name|labeled
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|linopr
argument_list|()
expr_stmt|;
name|indentlab
argument_list|()
expr_stmt|;
name|pplab
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|ppsep
argument_list|(
literal|":"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

