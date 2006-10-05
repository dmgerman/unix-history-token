begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TRAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TRAP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|T_DATA_MISS
value|0x31
end_define

begin_define
define|#
directive|define
name|T_ALIGNMENT
value|0x34
end_define

begin_define
define|#
directive|define
name|T_DATA_PROTECTION
value|0x6c
end_define

begin_define
define|#
directive|define
name|T_MEM_ADDRESS_NOT_ALIGNED
value|T_ALIGNMENT
end_define

begin_define
define|#
directive|define
name|T_RESERVED
value|0
end_define

begin_define
define|#
directive|define
name|T_INSTRUCTION_EXCEPTION
value|1
end_define

begin_define
define|#
directive|define
name|T_INSTRUCTION_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|T_INSTRUCTION_PROTECTION
value|3
end_define

begin_define
define|#
directive|define
name|T_ILLTRAP_INSTRUCTION
value|4
end_define

begin_define
define|#
directive|define
name|T_ILLEGAL_INSTRUCTION
value|5
end_define

begin_define
define|#
directive|define
name|T_PRIVILEGED_OPCODE
value|6
end_define

begin_define
define|#
directive|define
name|T_FP_DISABLED
value|7
end_define

begin_define
define|#
directive|define
name|T_FP_EXCEPTION_IEEE_754
value|8
end_define

begin_define
define|#
directive|define
name|T_INSTRUCTION_MISS
value|0x09
end_define

begin_define
define|#
directive|define
name|T_TAG_OVERFLOW
value|0x0a
end_define

begin_define
define|#
directive|define
name|T_DIVISION_BY_ZERO
value|0x0b
end_define

begin_define
define|#
directive|define
name|T_DATA_EXCEPTION
value|0x0c
end_define

begin_define
define|#
directive|define
name|T_DATA_ERROR
value|0x0d
end_define

begin_define
define|#
directive|define
name|T_PRIVILEGED_ACTION
value|0x10
end_define

begin_define
define|#
directive|define
name|T_ASYNC_DATA_ERROR
value|0x11
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_16
value|0x12
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_17
value|0x13
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_18
value|0x14
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_19
value|0x15
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_20
value|0x16
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_21
value|0x17
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_22
value|0x18
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_23
value|0x19
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_24
value|0x1a
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_25
value|0x1b
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_26
value|0x1c
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_27
value|0x1d
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_28
value|0x1e
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_29
value|0x1f
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_30
value|0x20
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_31
value|0x21
end_define

begin_define
define|#
directive|define
name|T_FP_EXCEPTION_OTHER
value|0x22
end_define

begin_define
define|#
directive|define
name|T_INTERRUPT
value|0x24
end_define

begin_define
define|#
directive|define
name|T_PA_WATCHPOINT
value|0x25
end_define

begin_define
define|#
directive|define
name|T_VA_WATCHPOINT
value|0x26
end_define

begin_define
define|#
directive|define
name|T_CORRECTED_ECC_ERROR
value|0x27
end_define

begin_define
define|#
directive|define
name|T_SPILL
value|0x28
end_define

begin_define
define|#
directive|define
name|T_FILL
value|0x29
end_define

begin_define
define|#
directive|define
name|T_FILL_RET
value|0x2a
end_define

begin_define
define|#
directive|define
name|T_BREAKPOINT
value|0x2b
end_define

begin_define
define|#
directive|define
name|T_CLEAN_WINDOW
value|0x2c
end_define

begin_define
define|#
directive|define
name|T_RANGE_CHECK
value|0x2d
end_define

begin_define
define|#
directive|define
name|T_FIX_ALIGNMENT
value|0x2e
end_define

begin_define
define|#
directive|define
name|T_INTEGER_OVERFLOW
value|0x2f
end_define

begin_define
define|#
directive|define
name|T_SYSCALL
value|0x30
end_define

begin_define
define|#
directive|define
name|T_RSTRWP_PHYS
end_define

begin_define
define|#
directive|define
name|T_RSTRWP_VIRT
end_define

begin_define
define|#
directive|define
name|T_KSTACK_FAULT
value|51
end_define

begin_define
define|#
directive|define
name|T_RESUMABLE_ERROR
value|52
end_define

begin_define
define|#
directive|define
name|T_NONRESUMABLE_ERROR
value|53
end_define

begin_define
define|#
directive|define
name|T_MAX
value|(T_NONRESUMABLE_ERROR + 1)
end_define

begin_define
define|#
directive|define
name|T_KERNEL
value|0x100
end_define

begin_define
define|#
directive|define
name|TRAP_MASK
value|((1<<8)-1)
end_define

begin_define
define|#
directive|define
name|TRAP_CTX_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_DEBUG
value|0
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_WTRAP
value|1
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_KMISS
value|2
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_KPROT_FAULT
value|3
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_ISM
value|4
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_MMUTRAP
value|5
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_TRAP
value|6
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_FPTRAP
value|7
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_INTR_REQ
value|8
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_TRACE_PTR
value|9
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_STACK
value|10
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_DTRACE_FLAGS
value|11
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_CTX_STEAL
value|12
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_ECC
value|13
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_HCALL
value|14
end_define

begin_define
define|#
directive|define
name|PTL1_BAD_GL
value|15
end_define

begin_define
define|#
directive|define
name|TL_CPU_MONDO
value|0x1
end_define

begin_define
define|#
directive|define
name|TL_DEV_MONDO
value|0x2
end_define

begin_define
define|#
directive|define
name|TL_TSB_MISS
value|0x3
end_define

begin_define
define|#
directive|define
name|TL_TL0_TRAP
value|0x4
end_define

begin_define
define|#
directive|define
name|TL_SET_ACKMASK
value|0x5
end_define

begin_comment
comment|/*  * These defines are used by the TL1 tlb miss handlers to calculate  * the pc to jump to in the case the entry was not found in the TSB.  */
end_comment

begin_define
define|#
directive|define
name|WTRAP_ALIGN
value|0x7f
end_define

begin_comment
comment|/* window handlers are 128 byte align */
end_comment

begin_define
define|#
directive|define
name|WTRAP_FAULTOFF
value|124
end_define

begin_comment
comment|/* last instruction in handler */
end_comment

begin_comment
comment|/* use the following defines to determine if trap was a fill or a spill */
end_comment

begin_define
define|#
directive|define
name|WTRAP_TTMASK
value|0x180
end_define

begin_define
define|#
directive|define
name|WTRAP_TYPE
value|0x080
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|trap_msg
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|trap_init
parameter_list|(
name|void
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
comment|/* !_MACHINE_TRAP_H_ */
end_comment

end_unit

