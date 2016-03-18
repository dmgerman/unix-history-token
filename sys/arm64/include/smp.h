begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner<andrew@FreeBSD.org>  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SMP_H_
end_define

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_enum
enum|enum
block|{
name|IPI_AST
block|,
name|IPI_PREEMPT
block|,
name|IPI_RENDEZVOUS
block|,
name|IPI_STOP
block|,
name|IPI_STOP_HARD
block|,
name|IPI_HARDCLOCK
block|,
name|INTR_IPI_COUNT
block|, }
enum|;
end_enum

begin_function_decl
name|void
name|ipi_all_but_self
parameter_list|(
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_cpu
parameter_list|(
name|int
name|cpu
parameter_list|,
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_selected
parameter_list|(
name|cpuset_t
name|cpus
parameter_list|,
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global data in mp_machdep.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pcb
name|stoppcbs
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SMP_H_ */
end_comment

end_unit

