begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_PCB_EXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_PCB_EXT_H_
end_define

begin_comment
comment|/*  * Extension to the 386 process control block  */
end_comment

begin_include
include|#
directive|include
file|<machine/tss.h>
end_include

begin_include
include|#
directive|include
file|<machine/vm86.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_struct
struct|struct
name|pcb_ext
block|{
name|struct
name|segment_descriptor
name|ext_tssd
decl_stmt|;
comment|/* tss descriptor */
name|struct
name|i386tss
name|ext_tss
decl_stmt|;
comment|/* per-process i386tss */
name|caddr_t
name|ext_iomap
decl_stmt|;
comment|/* i/o permission bitmap */
name|struct
name|vm86_kernel
name|ext_vm86
decl_stmt|;
comment|/* vm86 area */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcb_ldt
block|{
name|caddr_t
name|ldt_base
decl_stmt|;
name|int
name|ldt_len
decl_stmt|;
name|int
name|ldt_refcnt
decl_stmt|;
name|u_long
name|ldt_active
decl_stmt|;
name|struct
name|segment_descriptor
name|ldt_sd
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|USER_LDT
end_ifdef

begin_decl_stmt
name|void
name|set_user_ldt
name|__P
argument_list|(
operator|(
expr|struct
name|pcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pcb_ldt
modifier|*
name|user_ldt_alloc
name|__P
argument_list|(
operator|(
expr|struct
name|pcb
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|user_ldt_free
name|__P
argument_list|(
operator|(
expr|struct
name|pcb
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_PCB_EXT_H_ */
end_comment

end_unit

