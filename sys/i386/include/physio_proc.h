begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: physio_proc.h,v 3.4 1999/07/23 20:47:03 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_PHYSIO_PROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_PHYSIO_PROC_H_
end_define

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|physio_proc
block|{ }
struct|;
end_struct

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|physio_proc
operator|*
name|physio_proc_enter
argument_list|(
expr|struct
name|buf
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|__inline
name|void
name|physio_proc_leave
parameter_list|(
name|struct
name|physio_proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|physio_proc
operator|*
name|physio_proc_enter
argument_list|(
argument|bp
argument_list|)
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
return|return
name|NULL
return|;
block|}
end_block

begin_function
specifier|static
name|__inline
name|void
name|physio_proc_leave
parameter_list|(
name|pp
parameter_list|)
name|struct
name|physio_proc
modifier|*
name|pp
decl_stmt|;
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_PHYSIO_PROC_H_ */
end_comment

end_unit

