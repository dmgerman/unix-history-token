begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|BYTE_MSF
value|(1)
end_define

begin_typedef
typedef|typedef
name|vm_offset_t
name|db_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|db_expr_t
typedef|;
end_typedef

begin_struct
struct|struct
name|db_regs
block|{
name|u_long
name|dr_global
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|trapframe
name|db_regs_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|db_regs_t
name|ddb_regs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DDB_REGS
value|(&ddb_regs)
end_define

begin_define
define|#
directive|define
name|PC_REGS
parameter_list|(
name|regs
parameter_list|)
value|((db_addr_t)(regs)->tf_tpc)
end_define

begin_define
define|#
directive|define
name|BKPT_INST
value|(0)
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
name|FIXUP_PC_AFTER_BREAK
value|do {					\ 	ddb_regs.tf_tpc = ddb_regs.tf_tnpc;				\ 	ddb_regs.tf_tnpc += BKPT_SIZE;					\ } while (0);
end_define

begin_define
define|#
directive|define
name|db_clear_single_step
parameter_list|(
name|regs
parameter_list|)
end_define

begin_define
define|#
directive|define
name|db_set_single_step
parameter_list|(
name|regs
parameter_list|)
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
value|(0)
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

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|ins
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|ins
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|inst_load
parameter_list|(
name|ins
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|inst_store
parameter_list|(
name|ins
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|DB_SMALL_VALUE_MAX
value|(0x7fffffff)
end_define

begin_define
define|#
directive|define
name|DB_SMALL_VALUE_MIN
value|(-0x40001)
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

