begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1992 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon   * the rights to redistribute these changes.  *  *	$OpenBSD: db_machdep.h,v 1.2 1997/03/21 00:48:48 niklas Exp $  *	$NetBSD: db_machdep.h,v 1.4.22.1 2000/08/05 11:10:43 wiz Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine-dependent defines for new kernel debugger.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PPC_DB_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_PPC_DB_MACHDEP_H_
end_define

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_define
define|#
directive|define
name|DB_ELF_SYMBOLS
end_define

begin_define
define|#
directive|define
name|DB_ELFSIZE
value|32
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

begin_struct
struct|struct
name|powerpc_saved_state
block|{
name|u_int32_t
name|r
index|[
literal|32
index|]
decl_stmt|;
comment|/* data registers */
name|u_int32_t
name|iar
decl_stmt|;
name|u_int32_t
name|msr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|powerpc_saved_state
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
value|((db_addr_t)(regs)->iar)
end_define

begin_define
define|#
directive|define
name|BKPT_INST
value|0x7C810808
end_define

begin_comment
comment|/* breakpoint instruction */
end_comment

begin_define
define|#
directive|define
name|BKPT_SIZE
value|(4)
end_define

begin_comment
comment|/* size of breakpoint inst */
end_comment

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
parameter_list|(
name|regs
parameter_list|)
value|((regs)->iar -= 4)
end_define

begin_define
define|#
directive|define
name|SR_SINGLESTEP
value|0x400
end_define

begin_define
define|#
directive|define
name|db_clear_single_step
parameter_list|(
name|regs
parameter_list|)
value|((regs)->msr&= ~SR_SINGLESTEP)
end_define

begin_define
define|#
directive|define
name|db_set_single_step
parameter_list|(
name|regs
parameter_list|)
value|((regs)->msr |=  SR_SINGLESTEP)
end_define

begin_define
define|#
directive|define
name|T_BREAKPOINT
value|0xffff
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
value|((type) == T_BREAKPOINT)
end_define

begin_define
define|#
directive|define
name|T_WATCHPOINT
value|0xeeee
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|T_WATCHPOINT
end_ifdef

begin_define
define|#
directive|define
name|IS_WATCHPOINT_TRAP
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
value|((type) == T_WATCHPOINT)
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|M_RTS
value|0xfc0007fe
end_define

begin_define
define|#
directive|define
name|I_RTS
value|0x4c000020
end_define

begin_define
define|#
directive|define
name|M_BC
value|0xfc000000
end_define

begin_define
define|#
directive|define
name|I_BC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|M_B
value|0xfc000000
end_define

begin_define
define|#
directive|define
name|I_B
value|0x50000000
end_define

begin_define
define|#
directive|define
name|M_RFI
value|0xfc0007fe
end_define

begin_define
define|#
directive|define
name|I_RFI
value|0x4c000064
end_define

begin_define
define|#
directive|define
name|inst_trap_return
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&M_RFI) == I_RFI)
end_define

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&M_RTS) == I_RTS)
end_define

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&M_BC ) == I_BC  || \ 				 ((ins)&M_B  ) == I_B )
end_define

begin_define
define|#
directive|define
name|inst_load
parameter_list|(
name|ins
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|inst_store
parameter_list|(
name|ins
parameter_list|)
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|kdb_kintr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kdb_trap
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PPC_DB_MACHDEP_H_ */
end_comment

end_unit

