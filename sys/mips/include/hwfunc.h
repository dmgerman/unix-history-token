begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2004 Juli Mallett.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_HWFUNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_HWFUNC_H_
end_define

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timecounter
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Hooks downward into hardware functionality.  */
end_comment

begin_function_decl
name|void
name|platform_halt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_intr
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_start
parameter_list|(
name|__register_t
parameter_list|,
name|__register_t
parameter_list|,
name|__register_t
parameter_list|,
name|__register_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For clocks and ticks and such */
end_comment

begin_function_decl
name|void
name|platform_initclocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|platform_get_frequency
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|platform_get_timecount
parameter_list|(
name|struct
name|timecounter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For hardware specific CPU initialization */
end_comment

begin_function_decl
name|void
name|platform_cpu_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_secondary_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_comment
comment|/*  * Spin up the AP so that it starts executing MP bootstrap entry point: mpentry  *  * Returns 0 on sucess and non-zero on failure.  */
end_comment

begin_function_decl
name|int
name|platform_start_ap
parameter_list|(
name|int
name|processor_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Platform-specific initialization that needs to be done when an AP starts  * running. This function is called from the MP bootstrap code in mpboot.S  */
end_comment

begin_function_decl
name|void
name|platform_init_ap
parameter_list|(
name|int
name|processor_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a plaform-specific interrrupt number that is used to deliver IPIs.  *  * This hardware interrupt is used to deliver IPIs exclusively and must  * not be used for any other interrupt source.  */
end_comment

begin_function_decl
name|int
name|platform_ipi_intrnum
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Trigger a IPI interrupt on 'cpuid'.  */
end_comment

begin_function_decl
name|void
name|platform_ipi_send
parameter_list|(
name|int
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Quiesce the IPI interrupt source on the current cpu.  */
end_comment

begin_function_decl
name|void
name|platform_ipi_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the processor id.  *  * Note that this function is called in early boot when stack is not available.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|platform_processor_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the number of processors available on this platform.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|platform_num_processors
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_HWFUNC_H_ */
end_comment

end_unit

