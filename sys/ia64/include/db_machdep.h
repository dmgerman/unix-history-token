begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<machine/ia64_cpu.h>
end_include

begin_comment
comment|/* We define some of our own commands. */
end_comment

begin_define
define|#
directive|define
name|DB_MACHINE_COMMANDS
end_define

begin_comment
comment|/* We use Elf64 symbols in DDB. */
end_comment

begin_define
define|#
directive|define
name|DB_ELFSIZE
value|64
end_define

begin_comment
comment|/* Pretty arbitrary. */
end_comment

begin_define
define|#
directive|define
name|DB_SMALL_VALUE_MAX
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|DB_SMALL_VALUE_MIN
value|(-0x400001)
end_define

begin_typedef
typedef|typedef
name|vm_offset_t
name|db_addr_t
typedef|;
end_typedef

begin_comment
comment|/* address - unsigned */
end_comment

begin_typedef
typedef|typedef
name|long
name|db_expr_t
typedef|;
end_typedef

begin_comment
comment|/* expression - signed */
end_comment

begin_define
define|#
directive|define
name|PC_REGS
parameter_list|()
value|((kdb_thrctx->pcb_special.__spare == 0) ?	\ 	kdb_thrctx->pcb_special.rp :					\ 	kdb_thrctx->pcb_special.iip + ((kdb_thrctx->pcb_special.psr>>41)& 3))
end_define

begin_define
define|#
directive|define
name|BKPT_WRITE
parameter_list|(
name|addr
parameter_list|,
name|storage
parameter_list|)
value|db_bkpt_write(addr, storage)
end_define

begin_define
define|#
directive|define
name|BKPT_CLEAR
parameter_list|(
name|addr
parameter_list|,
name|storage
parameter_list|)
value|db_bkpt_clear(addr, storage)
end_define

begin_define
define|#
directive|define
name|BKPT_SKIP
value|db_bkpt_skip()
end_define

begin_define
define|#
directive|define
name|BKPT_INST_TYPE
value|uint64_t
end_define

begin_function_decl
name|void
name|db_bkpt_write
parameter_list|(
name|db_addr_t
parameter_list|,
name|BKPT_INST_TYPE
modifier|*
name|storage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_bkpt_clear
parameter_list|(
name|db_addr_t
parameter_list|,
name|uint64_t
modifier|*
name|storage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_bkpt_skip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
value|(type == IA64_VEC_BREAK)
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
value|0
end_define

begin_define
define|#
directive|define
name|inst_trap_return
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_branch
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_load
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_store
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_unconditional_flow_transfer
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|branch_taken
parameter_list|(
name|ins
parameter_list|,
name|pc
parameter_list|,
name|regs
parameter_list|)
value|pc
end_define

begin_comment
comment|/* Function call support. */
end_comment

begin_define
define|#
directive|define
name|DB_MAXARGS
value|8
end_define

begin_comment
comment|/* Only support arguments in registers. */
end_comment

begin_define
define|#
directive|define
name|DB_CALL
value|db_fncall_ia64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_DB_MACHDEP_H_ */
end_comment

end_unit

