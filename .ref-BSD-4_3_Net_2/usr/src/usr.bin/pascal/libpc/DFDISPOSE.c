begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)DFDISPOSE.c	4.4 (Berkeley) 4/9/90"
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
comment|/*  * Close all active files within a dynamic record,  * then dispose of the record.  */
end_comment

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|"libpc.h"
end_include

begin_macro
name|DFDISPOSE
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
comment|/* pointer to pointer being deallocated */
end_comment

begin_decl_stmt
name|long
name|size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizeof(bletch) */
end_comment

begin_block
block|{
specifier|register
name|struct
name|iorec
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
name|struct
name|iorec
modifier|*
name|start
decl_stmt|,
modifier|*
name|end
decl_stmt|;
name|start
operator|=
operator|(
expr|struct
name|iorec
operator|*
operator|)
operator|(
operator|*
name|var
operator|)
expr_stmt|;
name|end
operator|=
operator|(
expr|struct
name|iorec
operator|*
operator|)
operator|(
operator|*
name|var
operator|+
name|size
operator|)
expr_stmt|;
name|prev
operator|=
operator|(
expr|struct
name|iorec
operator|*
operator|)
operator|(
operator|&
name|_fchain
operator|)
expr_stmt|;
name|next
operator|=
name|_fchain
operator|.
name|fchain
expr_stmt|;
while|while
condition|(
name|next
operator|!=
name|FILNIL
operator|&&
operator|(
name|next
operator|->
name|flev
operator|<
name|GLVL
operator|||
name|next
operator|<
name|start
operator|)
condition|)
block|{
name|prev
operator|=
name|next
expr_stmt|;
name|next
operator|=
name|next
operator|->
name|fchain
expr_stmt|;
block|}
while|while
condition|(
name|next
operator|!=
name|FILNIL
operator|&&
name|start
operator|<=
name|next
operator|&&
name|next
operator|<
name|end
condition|)
name|next
operator|=
name|PFCLOSE
argument_list|(
name|next
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|prev
operator|->
name|fchain
operator|=
name|next
expr_stmt|;
name|DISPOSE
argument_list|(
name|var
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

