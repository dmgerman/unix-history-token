begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)subr_rmap.c	7.9 (Berkeley) 5/11/91  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"map.h"
end_include

begin_include
include|#
directive|include
file|"dmap.h"
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_comment
comment|/*  * Resource map handling routines.  */
end_comment

begin_comment
comment|/*  * Initialize map mp to have (mapsize-2) segments  * and to be called ``name'', which we print if  * the slots become so fragmented that we lose space.  * The map itself is initialized with size elements free  * starting at addr.  */
end_comment

begin_expr_stmt
name|rminit
argument_list|(
name|mp
argument_list|,
name|size
argument_list|,
name|addr
argument_list|,
name|name
argument_list|,
name|mapsize
argument_list|)
specifier|register
expr|struct
name|map
operator|*
name|mp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|long
name|size
decl_stmt|,
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mapsize
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

begin_function
name|long
name|rmalloc
parameter_list|(
name|mp
parameter_list|,
name|size
parameter_list|)
specifier|register
name|struct
name|map
modifier|*
name|mp
decl_stmt|;
name|long
name|size
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_macro
name|rmfree
argument_list|(
argument|mp
argument_list|,
argument|size
argument_list|,
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|map
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|size
decl_stmt|,
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

end_unit

