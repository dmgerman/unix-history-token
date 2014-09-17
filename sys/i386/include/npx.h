begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)npx.h	5.3 (Berkeley) 1/18/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * 287/387 NPX Coprocessor Data Structures and Constants  * W. Jolitz 1/90  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_NPX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_NPX_H_
end_define

begin_include
include|#
directive|include
file|<x86/fpu.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|PCB_USER_FPU
parameter_list|(
name|pcb
parameter_list|)
value|(((pcb)->pcb_flags& PCB_KERNNPX) == 0)
end_define

begin_function_decl
name|int
name|npxdna
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|npxdrop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|npxexit
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|npxformat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|npxgetregs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|npxinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|npxresume
parameter_list|(
name|union
name|savefpu
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|npxsave
parameter_list|(
name|union
name|savefpu
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|npxsetregs
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|union
name|savefpu
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|npxsuspend
parameter_list|(
name|union
name|savefpu
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|npxtrap_x87
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|npxtrap_sse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|npxuserinited
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fpu_kern_ctx
modifier|*
name|fpu_kern_alloc_ctx
parameter_list|(
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpu_kern_free_ctx
parameter_list|(
name|struct
name|fpu_kern_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_kern_enter
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|fpu_kern_ctx
modifier|*
name|ctx
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_kern_leave
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|fpu_kern_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_kern_thread
parameter_list|(
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_fpu_kern_thread
parameter_list|(
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Flags for fpu_kern_enter() and fpu_kern_thread().  */
end_comment

begin_define
define|#
directive|define
name|FPU_KERN_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|FPU_KERN_NOWAIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|FPU_KERN_KTHR
value|0x0002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_NPX_H_ */
end_comment

end_unit

