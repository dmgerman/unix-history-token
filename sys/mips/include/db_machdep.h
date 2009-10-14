begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: db_machdep.h,v 1.2 1998/09/15 10:50:12 pefo Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 Per Fogelstrom, Opsycon AB  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed under OpenBSD by  *	Per Fogelstrom, Opsycon AB, Sweden.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	JNPR: db_machdep.h,v 1.7 2006/10/16 12:30:34 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_DB_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_DB_MACHDEP_H_
end_define

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

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

begin_comment
comment|/* register state */
end_comment

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
name|intptr_t
name|db_expr_t
typedef|;
end_typedef

begin_comment
comment|/* expression - signed */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|BYTE_MSF
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SOFTWARE_SSTEP
end_define

begin_comment
comment|/* Need software single step */
end_comment

begin_define
define|#
directive|define
name|SOFTWARE_SSTEP_EMUL
end_define

begin_comment
comment|/* next_instr_address() emulates 100% */
end_comment

begin_function_decl
name|db_addr_t
name|next_instr_address
parameter_list|(
name|db_addr_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

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
name|ins
parameter_list|)
value|(BREAK_DDB)
end_define

begin_define
define|#
directive|define
name|DB_VALID_BREAKPOINT
parameter_list|(
name|addr
parameter_list|)
value|(((addr)& 3) == 0)
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
value|((type) == T_BREAK)
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

begin_comment
comment|/* XXX mips3 watchpoint */
end_comment

begin_define
define|#
directive|define
name|PC_REGS
parameter_list|()
value|((db_addr_t)kdb_thrctx->pcb_regs.pc)
end_define

begin_define
define|#
directive|define
name|BKPT_SKIP
define|\
value|do {							\ 		if((db_get_value(kdb_frame->pc, sizeof(int), FALSE)&	\ 		    ~BREAK_VAL_MASK) == BREAK_INSTR) {			\ 			kdb_frame->pc += BKPT_SIZE;			\ 			kdb_thrctx->pcb_regs.pc +=  BKPT_SIZE;		\ 		}							\ 	} while (0);
end_define

begin_comment
comment|/*  *  Test of instructions to see class.  */
end_comment

begin_define
define|#
directive|define
name|IT_CALL
value|0x01
end_define

begin_define
define|#
directive|define
name|IT_BRANCH
value|0x02
end_define

begin_define
define|#
directive|define
name|IT_LOAD
value|0x03
end_define

begin_define
define|#
directive|define
name|IT_STORE
value|0x04
end_define

begin_define
define|#
directive|define
name|inst_branch
parameter_list|(
name|i
parameter_list|)
value|(db_inst_type(i) == IT_BRANCH)
end_define

begin_define
define|#
directive|define
name|inst_trap_return
parameter_list|(
name|i
parameter_list|)
value|((i)& 0)
end_define

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|i
parameter_list|)
value|(db_inst_type(i) == IT_CALL)
end_define

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|i
parameter_list|)
value|((i) == 0x03e00008)
end_define

begin_define
define|#
directive|define
name|inst_load
parameter_list|(
name|i
parameter_list|)
value|(db_inst_type(i) == IT_LOAD)
end_define

begin_define
define|#
directive|define
name|inst_store
parameter_list|(
name|i
parameter_list|)
value|(db_inst_type(i) == IT_STORE)
end_define

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

begin_function_decl
name|int
name|db_inst_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_dump_tlb
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|db_addr_t
name|branch_taken
parameter_list|(
name|int
name|inst
parameter_list|,
name|db_addr_t
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stacktrace_subr
parameter_list|(
name|db_regs_t
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kdbpeek
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MIPS_DB_MACHDEP_H_ */
end_comment

end_unit

