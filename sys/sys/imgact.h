begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, David Greenman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: imgact.h,v 1.8 1994/10/02 17:24:45 phk Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IMGACT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IMGACT_H_
end_define

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_struct
struct|struct
name|image_params
block|{
name|struct
name|proc
modifier|*
name|proc
decl_stmt|;
comment|/* our process struct */
name|struct
name|execve_args
modifier|*
name|uap
decl_stmt|;
comment|/* syscall arguments */
name|struct
name|vnode
modifier|*
name|vnodep
decl_stmt|;
comment|/* pointer to vnode of file to exec */
name|struct
name|vattr
modifier|*
name|attr
decl_stmt|;
comment|/* attributes of file */
specifier|const
name|char
modifier|*
name|image_header
decl_stmt|;
comment|/* head of file to exec */
name|char
modifier|*
name|stringbase
decl_stmt|;
comment|/* base address of tmp string storage */
name|char
modifier|*
name|stringp
decl_stmt|;
comment|/* current 'end' pointer of tmp strings */
name|int
name|stringspace
decl_stmt|;
comment|/* space left in tmp string storage area */
name|int
name|argc
decl_stmt|,
name|envc
decl_stmt|;
comment|/* count of argument and environment strings */
name|unsigned
name|long
name|entry_addr
decl_stmt|;
comment|/* entry address of target executable */
name|char
name|vmspace_destroyed
decl_stmt|;
comment|/* flag - we've blown away original vm space */
name|char
name|interpreted
decl_stmt|;
comment|/* flag - this executable is interpreted */
name|char
name|interpreter_name
index|[
literal|64
index|]
decl_stmt|;
comment|/* name of the interpreter */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|exec_extract_strings
name|__P
argument_list|(
operator|(
expr|struct
name|image_params
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|exec_new_vmspace
name|__P
argument_list|(
operator|(
expr|struct
name|image_params
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

