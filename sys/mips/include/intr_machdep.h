begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Juli Mallett<jmallett@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INTR_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INTR_MACHDEP_H_
end_define

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_RMI
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_NLM
argument_list|)
end_if

begin_define
define|#
directive|define
name|XLR_MAX_INTR
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NHARD_IRQS
value|6
end_define

begin_define
define|#
directive|define
name|NSOFT_IRQS
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|cpu_init_interrupts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_establish_hardintr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|driver_filter_t
modifier|*
parameter_list|,
name|driver_intr_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_establish_softintr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|driver_filter_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_intr
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allow a platform to override the default hard interrupt mask and unmask  * functions. The 'arg' can be cast safely to an 'int' and holds the mips  * hard interrupt number to mask or unmask.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cpu_intr_mask_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cpu_intr_unmask_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|cpu_set_hardintr_mask_func
parameter_list|(
name|cpu_intr_mask_t
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_set_hardintr_unmask_func
parameter_list|(
name|cpu_intr_unmask_t
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Opaque datatype that represents intr counter  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
modifier|*
name|mips_intrcnt_t
typedef|;
end_typedef

begin_function_decl
name|mips_intrcnt_t
name|mips_intrcnt_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mips_intrcnt_setname
parameter_list|(
name|mips_intrcnt_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|mips_intrcnt_inc
parameter_list|(
name|mips_intrcnt_t
name|counter
parameter_list|)
block|{
if|if
condition|(
name|counter
condition|)
name|atomic_add_long
argument_list|(
name|counter
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|VM_CNT_INC
argument_list|(
name|v_intr
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_INTR_MACHDEP_H_ */
end_comment

end_unit

