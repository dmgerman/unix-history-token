begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IPL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IPL_H_
end_define

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_comment
comment|/* for pal inlines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_comment
comment|/*  * Interprocessor interrupts for SMP.  */
end_comment

begin_define
define|#
directive|define
name|IPI_INVLTLB
value|0x0001
end_define

begin_define
define|#
directive|define
name|IPI_RENDEZVOUS
value|0x0002
end_define

begin_define
define|#
directive|define
name|IPI_AST
value|0x0004
end_define

begin_define
define|#
directive|define
name|IPI_CHECKSTATE
value|0x0008
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|0x0010
end_define

begin_function_decl
name|void
name|smp_ipi_selected
parameter_list|(
name|u_int32_t
name|cpus
parameter_list|,
name|u_int64_t
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_ipi_all
parameter_list|(
name|u_int64_t
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_ipi_all_but_self
parameter_list|(
name|u_int64_t
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_ipi_self
parameter_list|(
name|u_int64_t
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_handle_ipi
parameter_list|(
name|struct
name|trapframe
modifier|*
name|frame
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
comment|/* !_MACHINE_IPL_H_ */
end_comment

end_unit

