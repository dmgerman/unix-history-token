begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPU_H_
end_define

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|tfp
parameter_list|)
value|((tfp)->tf_ra)
end_define

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|tfp
parameter_list|)
value|(((tfp)->tf_sepc& (1ul<< 63)) == 0)
end_define

begin_define
define|#
directive|define
name|cpu_getstack
parameter_list|(
name|td
parameter_list|)
value|((td)->td_frame->tf_sp)
end_define

begin_define
define|#
directive|define
name|cpu_setstack
parameter_list|(
name|td
parameter_list|,
name|sp
parameter_list|)
value|((td)->td_frame->tf_sp = (sp))
end_define

begin_define
define|#
directive|define
name|cpu_spinwait
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * 0x0000         CPU ID unimplemented  * 0x0001         UC Berkeley Rocket repo  * 0x0002Â­0x7FFE  Reserved for open-source repos  * 0x7FFF         Reserved for extension  * 0x8000         Reserved for anonymous source  * 0x8001Â­0xFFFE  Reserved for proprietary implementations  * 0xFFFF         Reserved for extension  */
end_comment

begin_define
define|#
directive|define
name|CPU_IMPL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_MASK
value|(0xffff<< CPU_IMPL_SHIFT)
end_define

begin_define
define|#
directive|define
name|CPU_IMPL
parameter_list|(
name|mimpid
parameter_list|)
value|((mimpid& CPU_IMPL_MASK)>> CPU_IMPL_SHIFT)
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_UNIMPLEMEN
value|0x0
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_UCB_ROCKET
value|0x1
end_define

begin_define
define|#
directive|define
name|CPU_PART_SHIFT
value|62
end_define

begin_define
define|#
directive|define
name|CPU_PART_MASK
value|(0x3ul<< CPU_PART_SHIFT)
end_define

begin_define
define|#
directive|define
name|CPU_PART
parameter_list|(
name|misa
parameter_list|)
value|((misa& CPU_PART_MASK)>> CPU_PART_SHIFT)
end_define

begin_define
define|#
directive|define
name|CPU_PART_RV32
value|0x1
end_define

begin_define
define|#
directive|define
name|CPU_PART_RV64
value|0x2
end_define

begin_define
define|#
directive|define
name|CPU_PART_RV128
value|0x3
end_define

begin_decl_stmt
specifier|extern
name|char
name|btext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|etext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_halt
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_reset
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fork_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|identify_cpu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swi_vm
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|uint64_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* TODO: This is bogus */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPU_H_ */
end_comment

end_unit

