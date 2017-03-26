begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner  * Copyright (c) 2014-2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_DB_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_DB_MACHDEP_H_
end_define

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_define
define|#
directive|define
name|T_BREAKPOINT
value|(EXCP_BRK)
end_define

begin_define
define|#
directive|define
name|T_WATCHPOINT
value|(EXCP_WATCHPT_EL1)
end_define

begin_typedef
typedef|typedef
name|vm_offset_t
name|db_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|db_expr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PC_REGS
parameter_list|()
value|((db_addr_t)kdb_thrctx->pcb_pc)
end_define

begin_define
define|#
directive|define
name|BKPT_INST
value|(0xd4200000)
end_define

begin_define
define|#
directive|define
name|BKPT_SIZE
value|(4)
end_define

begin_define
define|#
directive|define
name|BKPT_SET
parameter_list|(
name|inst
parameter_list|)
value|(BKPT_INST)
end_define

begin_define
define|#
directive|define
name|BKPT_SKIP
value|do {							\ 	kdb_frame->tf_elr += BKPT_SIZE; \ } while (0)
end_define

begin_define
define|#
directive|define
name|db_clear_single_step
value|kdb_cpu_clear_singlestep
end_define

begin_define
define|#
directive|define
name|db_set_single_step
value|kdb_cpu_set_singlestep
end_define

begin_define
define|#
directive|define
name|IS_BREAKPOINT_TRAP
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
value|(type == T_BREAKPOINT)
end_define

begin_define
define|#
directive|define
name|IS_WATCHPOINT_TRAP
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
value|(type == T_WATCHPOINT)
end_define

begin_define
define|#
directive|define
name|inst_trap_return
parameter_list|(
name|ins
parameter_list|)
value|(0)
end_define

begin_comment
comment|/* ret */
end_comment

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|ins
parameter_list|)
value|(((ins)& 0xfffffc1fu) == 0xd65f0000)
end_define

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|ins
parameter_list|)
value|(((ins)& 0xfc000000u) == 0x94000000u ||
comment|/* BL */
value|\ 				 ((ins)& 0xfffffc1fu) == 0xd63f0000u)
end_define

begin_comment
comment|/* BLR */
end_comment

begin_define
define|#
directive|define
name|inst_load
parameter_list|(
name|ins
parameter_list|)
value|({							\ 	uint32_t tmp_instr = db_get_value(PC_REGS(), sizeof(uint32_t), FALSE);	\ 	is_load_instr(tmp_instr);						\ })
end_define

begin_define
define|#
directive|define
name|inst_store
parameter_list|(
name|ins
parameter_list|)
value|({							\ 	uint32_t tmp_instr = db_get_value(PC_REGS(), sizeof(uint32_t), FALSE);	\ 	is_store_instr(tmp_instr);						\ })
end_define

begin_define
define|#
directive|define
name|is_load_instr
parameter_list|(
name|ins
parameter_list|)
value|((((ins)& 0x3b000000u) == 0x18000000u) ||
comment|/* literal */
value|\ 				 (((ins)& 0x3f400000u) == 0x08400000u) ||
comment|/* exclusive */
value|\ 				 (((ins)& 0x3bc00000u) == 0x28400000u) ||
comment|/* no-allocate pair */
value|\ 				 ((((ins)& 0x3b200c00u) == 0x38000400u)&& \ 				  (((ins)& 0x3be00c00u) != 0x38000400u)&& \ 				  (((ins)& 0xffe00c00u) != 0x3c800400u)) ||
comment|/* immediate post-indexed */
value|\ 				 ((((ins)& 0x3b200c00u) == 0x38000c00u)&& \ 				  (((ins)& 0x3be00c00u) != 0x38000c00u)&& \ 				  (((ins)& 0xffe00c00u) != 0x3c800c00u)) ||
comment|/* immediate pre-indexed */
value|\ 				 ((((ins)& 0x3b200c00u) == 0x38200800u)&& \ 				  (((ins)& 0x3be00c00u) != 0x38200800u)&& \ 				  (((ins)& 0xffe00c00u) != 0x3ca00c80u)) ||
comment|/* register offset */
value|\ 				 ((((ins)& 0x3b200c00u) == 0x38000800u)&& \ 				  (((ins)& 0x3be00c00u) != 0x38000800u)) ||
comment|/* unprivileged */
value|\ 				 ((((ins)& 0x3b200c00u) == 0x38000000u)&& \ 				  (((ins)& 0x3be00c00u) != 0x38000000u)&& \ 				  (((ins)& 0xffe00c00u) != 0x3c800000u)) ||
comment|/* unscaled immediate */
value|\ 				 ((((ins)& 0x3b000000u) == 0x39000000u)&& \ 				  (((ins)& 0x3bc00000u) != 0x39000000u)&& \ 				  (((ins)& 0xffc00000u) != 0x3d800000u))&&
comment|/* unsigned immediate */
value|\ 				 (((ins)& 0x3bc00000u) == 0x28400000u) ||
comment|/* pair (offset) */
value|\ 				 (((ins)& 0x3bc00000u) == 0x28c00000u) ||
comment|/* pair (post-indexed) */
value|\ 				 (((ins)& 0x3bc00000u) == 0x29800000u))
end_define

begin_comment
comment|/* pair (pre-indexed) */
end_comment

begin_define
define|#
directive|define
name|is_store_instr
parameter_list|(
name|ins
parameter_list|)
value|((((ins)& 0x3f400000u) == 0x08000000u) ||
comment|/* exclusive */
value|\ 				 (((ins)& 0x3bc00000u) == 0x28000000u) ||
comment|/* no-allocate pair */
value|\ 				 ((((ins)& 0x3be00c00u) == 0x38000400u) || \ 				  (((ins)& 0xffe00c00u) == 0x3c800400u)) ||
comment|/* immediate post-indexed */
value|\ 				 ((((ins)& 0x3be00c00u) == 0x38000c00u) || \ 				  (((ins)& 0xffe00c00u) == 0x3c800c00u)) ||
comment|/* immediate pre-indexed */
value|\ 				 ((((ins)& 0x3be00c00u) == 0x38200800u) || \ 				  (((ins)& 0xffe00c00u) == 0x3ca00800u)) ||
comment|/* register offset */
value|\ 				 (((ins)& 0x3be00c00u) == 0x38000800u) ||
comment|/* unprivileged */
value|\ 				 ((((ins)& 0x3be00c00u) == 0x38000000u) || \ 				  (((ins)& 0xffe00c00u) == 0x3c800000u)) ||
comment|/* unscaled immediate */
value|\ 				 ((((ins)& 0x3bc00000u) == 0x39000000u) || \ 				  (((ins)& 0xffc00000u) == 0x3d800000u)) ||
comment|/* unsigned immediate */
value|\ 				 (((ins)& 0x3bc00000u) == 0x28000000u) ||
comment|/* pair (offset) */
value|\ 				 (((ins)& 0x3bc00000u) == 0x28800000u) ||
comment|/* pair (post-indexed) */
value|\ 				 (((ins)& 0x3bc00000u) == 0x29800000u))
end_define

begin_comment
comment|/* pair (pre-indexed) */
end_comment

begin_define
define|#
directive|define
name|next_instr_address
parameter_list|(
name|pc
parameter_list|,
name|bd
parameter_list|)
value|((bd) ? (pc) : ((pc) + 4))
end_define

begin_define
define|#
directive|define
name|DB_ELFSIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_DB_MACHDEP_H_ */
end_comment

end_unit

