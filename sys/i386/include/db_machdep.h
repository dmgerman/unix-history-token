begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * Machine-dependent defines for new kernel debugger.  */
end_comment

begin_comment
comment|/* #include<mach/i386/vm_types.h> */
end_comment

begin_comment
comment|/* #include<mach/i386/vm_param.h> */
end_comment

begin_include
include|#
directive|include
file|<vm/vm_prot.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_inherit.h>
end_include

begin_include
include|#
directive|include
file|<vm/lock.h>
end_include

begin_comment
comment|/* #include<i386/thread.h> */
end_comment

begin_comment
comment|/* for thread_status */
end_comment

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_comment
comment|/* for struct trapframe */
end_comment

begin_comment
comment|/* #include<i386/eflags.h> */
end_comment

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_comment
comment|/* #include<i386/trap.h> */
end_comment

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_define
define|#
directive|define
name|i386_saved_state
value|trapframe
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
name|int
name|db_expr_t
typedef|;
end_typedef

begin_comment
comment|/* expression - signed */
end_comment

begin_typedef
typedef|typedef
name|struct
name|i386_saved_state
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
value|(((regs)->tf_cs& 0xfffc) == 0x08 \ 			 ? (db_addr_t)(regs)->tf_eip : 0)
end_define

begin_define
define|#
directive|define
name|BKPT_INST
value|0xcc
end_define

begin_comment
comment|/* breakpoint instruction */
end_comment

begin_define
define|#
directive|define
name|BKPT_SIZE
value|(1)
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
value|ddb_regs.tf_eip -= 1;
end_define

begin_define
define|#
directive|define
name|db_clear_single_step
parameter_list|(
name|regs
parameter_list|)
value|((regs)->tf_eflags&= ~PSL_T)
end_define

begin_define
define|#
directive|define
name|db_set_single_step
parameter_list|(
name|regs
parameter_list|)
value|((regs)->tf_eflags |=  PSL_T)
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
value|((type) == T_BPTFLT)
end_define

begin_comment
comment|/*  * Watchpoints are not supported.  The debug exception type is in %dr6  * and not yet in the args to this macro.  */
end_comment

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
name|I_CALL
value|0xe8
end_define

begin_define
define|#
directive|define
name|I_CALLI
value|0xff
end_define

begin_define
define|#
directive|define
name|I_RET
value|0xc3
end_define

begin_define
define|#
directive|define
name|I_IRET
value|0xcf
end_define

begin_define
define|#
directive|define
name|inst_trap_return
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&0xff) == I_IRET)
end_define

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&0xff) == I_RET)
end_define

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&0xff) == I_CALL || \ 				 (((ins)&0xff) == I_CALLI&& \ 				  ((ins)&0x3800) == 0x1000))
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

begin_comment
comment|/* access capability and access macros */
end_comment

begin_define
define|#
directive|define
name|DB_ACCESS_LEVEL
value|2
end_define

begin_comment
comment|/* access any space */
end_comment

begin_define
define|#
directive|define
name|DB_CHECK_ACCESS
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|,
name|task
parameter_list|)
define|\
value|db_check_access(addr,size,task)
end_define

begin_define
define|#
directive|define
name|DB_PHYS_EQ
parameter_list|(
name|task1
parameter_list|,
name|addr1
parameter_list|,
name|task2
parameter_list|,
name|addr2
parameter_list|)
define|\
value|db_phys_eq(task1,addr1,task2,addr2)
end_define

begin_define
define|#
directive|define
name|DB_VALID_KERN_ADDR
parameter_list|(
name|addr
parameter_list|)
define|\
value|((addr)>= VM_MIN_KERNEL_ADDRESS&& 			\ 	 (addr)< VM_MAX_KERNEL_ADDRESS)
end_define

begin_define
define|#
directive|define
name|DB_VALID_ADDRESS
parameter_list|(
name|addr
parameter_list|,
name|user
parameter_list|)
define|\
value|((!(user)&& DB_VALID_KERN_ADDR(addr)) ||		\ 	 ((user)&& (addr)< VM_MIN_KERNEL_ADDRESS))
end_define

begin_function_decl
name|boolean_t
name|db_check_access
parameter_list|(
comment|/* vm_offset_t, int, task_t */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|db_phys_eq
parameter_list|(
comment|/* task_t, vm_offset_t, task_t, vm_offset_t */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* macros for printing OS server dependent task name */
end_comment

begin_define
define|#
directive|define
name|DB_TASK_NAME
parameter_list|(
name|task
parameter_list|)
value|db_task_name(task)
end_define

begin_define
define|#
directive|define
name|DB_TASK_NAME_TITLE
value|"COMMAND                "
end_define

begin_define
define|#
directive|define
name|DB_TASK_NAME_LEN
value|23
end_define

begin_define
define|#
directive|define
name|DB_NULL_TASK_NAME
value|"?                      "
end_define

begin_function_decl
name|void
name|db_task_name
parameter_list|(
comment|/* task_t */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* macro for checking if a thread has used floating-point */
end_comment

begin_define
define|#
directive|define
name|db_thread_fp_used
parameter_list|(
name|thread
parameter_list|)
value|((thread)->pcb->ims.ifps != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_DB_MACHDEP_H_ */
end_comment

end_unit

