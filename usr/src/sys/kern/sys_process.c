begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)sys_process.c	7.22 (Berkeley) 5/11/91  */
end_comment

begin_define
define|#
directive|define
name|IPCREG
end_define

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"seg.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"ptrace.h"
end_include

begin_include
include|#
directive|include
file|"machine/reg.h"
end_include

begin_include
include|#
directive|include
file|"machine/psl.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm.h"
end_include

begin_include
include|#
directive|include
file|"vm/vm_page.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_comment
comment|/*  * Process debugging system call.  */
end_comment

begin_macro
name|ptrace
argument_list|(
argument|curp
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|curp
decl_stmt|;
end_decl_stmt

begin_struct
specifier|register
struct|struct
name|args
block|{
name|int
name|req
decl_stmt|;
name|int
name|pid
decl_stmt|;
name|int
modifier|*
name|addr
decl_stmt|;
name|int
name|data
decl_stmt|;
block|}
modifier|*
name|uap
struct|;
end_struct

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|procxmt
argument_list|(
name|p
argument_list|)
specifier|register
expr|struct
name|proc
operator|*
name|p
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Enable process profiling system call.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|profil
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_struct
specifier|register
struct|struct
name|args
block|{
name|short
modifier|*
name|bufbase
decl_stmt|;
name|unsigned
name|bufsize
decl_stmt|;
name|unsigned
name|pcoffset
decl_stmt|;
name|unsigned
name|pcscale
decl_stmt|;
block|}
modifier|*
name|uap
struct|;
end_struct

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_block

end_unit

