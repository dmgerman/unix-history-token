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
literal|"@(#)yycopy.c	8.1 (Berkeley) 6/6/93"
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
file|"whoami.h"
end_include

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree_ty.h"
end_include

begin_comment
comment|/* must be included for yy.h */
end_comment

begin_include
include|#
directive|include
file|"yy.h"
end_include

begin_macro
name|OYcopy
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
modifier|*
name|r0
init|=
operator|(
operator|(
name|int
operator|*
operator|)
operator|&
name|OY
operator|)
decl_stmt|;
specifier|register
name|int
modifier|*
name|r1
init|=
operator|(
operator|(
name|int
operator|*
operator|)
operator|&
name|Y
operator|)
decl_stmt|;
specifier|register
name|int
name|r2
init|=
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|yytok
argument_list|)
operator|)
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|)
decl_stmt|;
do|do
block|{
operator|*
name|r0
operator|++
operator|=
operator|*
name|r1
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|r2
operator|>
literal|0
condition|)
do|;
block|}
end_block

end_unit

