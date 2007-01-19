begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCB_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXWIN
value|8
end_define

begin_define
define|#
directive|define
name|PCB_FEF
value|(1<< 0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/* NOTE: pcb_ufp must be aligned on a 64 byte boundary. */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|struct
name|rwindow
name|pcb_rw
index|[
name|MAXWIN
index|]
decl_stmt|;
comment|/* wbuf for page faults during spill / fill trap handling */
name|uint32_t
name|pcb_kfp
index|[
literal|64
index|]
decl_stmt|;
comment|/* used for regs in handling kernel floating point exc */
name|uint32_t
name|pcb_ufp
index|[
literal|64
index|]
decl_stmt|;
comment|/* used for regs in handling user floating point exc */
name|uint64_t
name|pcb_rwsp
index|[
name|MAXWIN
index|]
decl_stmt|;
comment|/* spbuf sp's for each wbuf */
name|uint64_t
name|pcb_flags
decl_stmt|;
name|uint64_t
name|pcb_nsaved
decl_stmt|;
comment|/* number of windows saved in pcb_rw */
name|uint64_t
name|pcb_pc
decl_stmt|;
name|uint64_t
name|pcb_sp
decl_stmt|;
name|uint64_t
name|pcb_kstack
decl_stmt|;
comment|/* pcb's kernel stack */
name|uint64_t
name|pcb_tstate
decl_stmt|;
name|uint64_t
name|pcb_tpc
decl_stmt|;
name|uint64_t
name|pcb_tnpc
decl_stmt|;
name|uint64_t
name|pcb_tt
decl_stmt|;
name|uint64_t
name|pcb_sfar
decl_stmt|;
name|uint64_t
name|pcb_pad
index|[
literal|7
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|64
argument_list|)
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|makectx
parameter_list|(
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|,
name|struct
name|pcb
modifier|*
name|pcb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|savectx
parameter_list|(
name|struct
name|pcb
modifier|*
name|pcb
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PCB_H_ */
end_comment

end_unit

