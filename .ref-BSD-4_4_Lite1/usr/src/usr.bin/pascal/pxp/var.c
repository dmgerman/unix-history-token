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
literal|"@(#)var.c	8.1 (Berkeley) 6/6/93"
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

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_decl_stmt
name|STATIC
name|int
name|varcnt
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Var declaration part  */
end_comment

begin_macro
name|varbeg
argument_list|(
argument|l
argument_list|,
argument|vline
argument_list|)
end_macro

begin_decl_stmt
name|int
name|l
decl_stmt|,
name|vline
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|line
operator|=
name|l
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
name|putcm
argument_list|()
expr_stmt|;
name|ppnl
argument_list|()
expr_stmt|;
name|indent
argument_list|()
expr_stmt|;
name|ppkw
argument_list|(
literal|"var"
argument_list|)
expr_stmt|;
name|ppgoin
argument_list|(
name|DECL
argument_list|)
expr_stmt|;
name|varcnt
operator|=
literal|0
expr_stmt|;
name|setline
argument_list|(
name|vline
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|var
argument_list|(
argument|vline
argument_list|,
argument|vidl
argument_list|,
argument|vtype
argument_list|)
end_macro

begin_decl_stmt
name|int
name|vline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
modifier|*
name|vidl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|vtype
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|varcnt
condition|)
name|putcm
argument_list|()
expr_stmt|;
name|setline
argument_list|(
name|vline
argument_list|)
expr_stmt|;
name|ppitem
argument_list|()
expr_stmt|;
if|if
condition|(
name|vidl
operator|!=
name|NIL
condition|)
for|for
control|(
init|;
condition|;
control|)
block|{
name|ppid
argument_list|(
name|vidl
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|vidl
operator|=
name|vidl
index|[
literal|2
index|]
expr_stmt|;
if|if
condition|(
name|vidl
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
literal|"{identifier list}"
argument_list|)
expr_stmt|;
name|ppsep
argument_list|(
literal|":"
argument_list|)
expr_stmt|;
name|gtype
argument_list|(
name|vtype
argument_list|)
expr_stmt|;
name|ppsep
argument_list|(
literal|";"
argument_list|)
expr_stmt|;
name|setinfo
argument_list|(
name|vline
argument_list|)
expr_stmt|;
name|putcml
argument_list|()
expr_stmt|;
name|varcnt
operator|++
expr_stmt|;
block|}
end_block

begin_macro
name|varend
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|varcnt
operator|==
operator|-
literal|1
condition|)
return|return;
if|if
condition|(
name|varcnt
operator|==
literal|0
condition|)
name|ppid
argument_list|(
literal|"{variable decls}"
argument_list|)
expr_stmt|;
name|ppgoout
argument_list|(
name|DECL
argument_list|)
expr_stmt|;
name|varcnt
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_block

end_unit

