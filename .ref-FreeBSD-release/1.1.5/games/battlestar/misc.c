begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)misc.c	5.3 (Berkeley) 6/1/90"
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
file|"externs.h"
end_include

begin_expr_stmt
name|card
argument_list|(
name|array
argument_list|,
name|size
argument_list|)
comment|/* for beenthere, injuries */
specifier|register
name|char
operator|*
name|array
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|end
init|=
name|array
operator|+
name|size
decl_stmt|;
specifier|register
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|array
operator|<
name|end
condition|)
if|if
condition|(
operator|*
name|array
operator|++
condition|)
name|i
operator|++
expr_stmt|;
return|return
operator|(
name|i
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|ucard
argument_list|(
name|array
argument_list|)
specifier|register
name|unsigned
operator|*
name|array
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|j
init|=
literal|0
decl_stmt|,
name|n
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|NUMOFOBJECTS
condition|;
name|n
operator|++
control|)
if|if
condition|(
name|testbit
argument_list|(
name|array
argument_list|,
name|n
argument_list|)
condition|)
name|j
operator|++
expr_stmt|;
return|return
operator|(
name|j
operator|)
return|;
block|}
end_block

end_unit

