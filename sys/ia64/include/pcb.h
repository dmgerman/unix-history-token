begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Doug Rabson  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/_regset.h>
end_include

begin_comment
comment|/*  * PCB: process control block  */
end_comment

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|pcb
block|{
name|struct
name|_special
name|pcb_special
decl_stmt|;
name|struct
name|_callee_saved
name|pcb_preserved
decl_stmt|;
name|struct
name|_callee_saved_fp
name|pcb_preserved_fp
decl_stmt|;
name|struct
name|_high_fp
name|pcb_high_fp
decl_stmt|;
name|struct
name|pcpu
modifier|*
name|pcb_fpcpu
decl_stmt|;
name|struct
name|pmap
modifier|*
name|pcb_current_pmap
decl_stmt|;
name|uint64_t
name|pcb_onfault
decl_stmt|;
comment|/* for copy faults */
if|#
directive|if
name|IA32
name|uint64_t
name|pcb_ia32_cflg
decl_stmt|;
name|uint64_t
name|pcb_ia32_eflag
decl_stmt|;
name|uint64_t
name|pcb_ia32_fcr
decl_stmt|;
name|uint64_t
name|pcb_ia32_fdr
decl_stmt|;
name|uint64_t
name|pcb_ia32_fir
decl_stmt|;
name|uint64_t
name|pcb_ia32_fsr
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|savectx
parameter_list|(
name|p
parameter_list|)
value|swapctx(p, NULL)
end_define

begin_decl_stmt
name|void
name|restorectx
argument_list|(
expr|struct
name|pcb
operator|*
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|swapctx
parameter_list|(
name|struct
name|pcb
modifier|*
name|old
parameter_list|,
name|struct
name|pcb
modifier|*
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|IA32
end_if

begin_function_decl
name|void
name|ia32_restorectx
parameter_list|(
name|struct
name|pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia32_savectx
parameter_list|(
name|struct
name|pcb
modifier|*
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PCB_H_ */
end_comment

end_unit

