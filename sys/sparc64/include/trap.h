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
name|T_FP_EXCEPTION_OTHER
value|9
end_define

begin_define
define|#
directive|define
name|T_TAG_OVERFLOW
value|10
end_define

begin_define
define|#
directive|define
name|T_DIVISION_BY_ZERO
value|11
end_define

begin_define
define|#
directive|define
name|T_DATA_EXCEPTION
value|12
end_define

begin_define
define|#
directive|define
name|T_DATA_ERROR
value|13
end_define

begin_define
define|#
directive|define
name|T_DATA_PROTECTION
value|14
end_define

begin_define
define|#
directive|define
name|T_MEM_ADDRESS_NOT_ALIGNED
value|15
end_define

begin_define
define|#
directive|define
name|T_PRIVILEGED_ACTION
value|16
end_define

begin_define
define|#
directive|define
name|T_ASYNC_DATA_ERROR
value|17
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_16
value|18
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_17
value|19
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_18
value|20
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_19
value|21
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_20
value|22
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_21
value|23
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_22
value|24
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_23
value|25
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_24
value|26
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_25
value|27
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_26
value|28
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_27
value|29
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_28
value|30
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_29
value|31
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_30
value|32
end_define

begin_define
define|#
directive|define
name|T_TRAP_INSTRUCTION_31
value|33
end_define

begin_define
define|#
directive|define
name|T_INSTRUCTION_MISS
value|34
end_define

begin_define
define|#
directive|define
name|T_DATA_MISS
value|35
end_define

begin_define
define|#
directive|define
name|T_INTERRUPT
value|36
end_define

begin_define
define|#
directive|define
name|T_PA_WATCHPOINT
value|37
end_define

begin_define
define|#
directive|define
name|T_VA_WATCHPOINT
value|38
end_define

begin_define
define|#
directive|define
name|T_CORRECTED_ECC_ERROR
value|39
end_define

begin_define
define|#
directive|define
name|T_SPILL
value|40
end_define

begin_define
define|#
directive|define
name|T_FILL
value|41
end_define

begin_define
define|#
directive|define
name|T_FILL_RET
value|42
end_define

begin_define
define|#
directive|define
name|T_BREAKPOINT
value|43
end_define

begin_define
define|#
directive|define
name|T_CLEAN_WINDOW
value|44
end_define

begin_define
define|#
directive|define
name|T_RANGE_CHECK
value|45
end_define

begin_define
define|#
directive|define
name|T_FIX_ALIGNMENT
value|46
end_define

begin_define
define|#
directive|define
name|T_INTEGER_OVERFLOW
value|47
end_define

begin_define
define|#
directive|define
name|T_SYSCALL
value|48
end_define

begin_define
define|#
directive|define
name|T_RSTRWP_PHYS
value|49
end_define

begin_define
define|#
directive|define
name|T_RSTRWP_VIRT
value|50
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
name|T_MAX
value|(T_KSTACK_FAULT + 1)
end_define

begin_define
define|#
directive|define
name|T_KERNEL
value|64
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_function_decl
name|void
name|sun4u_set_traptable
parameter_list|(
name|void
modifier|*
name|tba_addr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|trap_msg
index|[]
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
comment|/* !_MACHINE_TRAP_H_ */
end_comment

end_unit

