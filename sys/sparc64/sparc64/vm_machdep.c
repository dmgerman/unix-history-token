begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_function
name|void
name|cpu_exit
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
block|{
name|TODO
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_fork
parameter_list|(
name|struct
name|proc
modifier|*
name|p1
parameter_list|,
name|struct
name|proc
modifier|*
name|p2
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|TODO
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_reset
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|cpu_set_fork_handler
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|TODO
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_wait
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
block|{
name|TODO
expr_stmt|;
block|}
end_function

begin_function
name|void
name|swi_vm
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
block|{
name|TODO
expr_stmt|;
block|}
end_function

begin_function
name|int
name|vm_fault_quick
parameter_list|(
name|caddr_t
name|v
parameter_list|,
name|int
name|prot
parameter_list|)
block|{
name|TODO
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|vmapbuf
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
name|TODO
expr_stmt|;
block|}
end_function

begin_function
name|void
name|vunmapbuf
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
name|TODO
expr_stmt|;
block|}
end_function

end_unit

