begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log: db_trap.c,v $  * Revision 1.1  1992/03/25  21:45:31  pace  * Initial revision  *  * Revision 2.5  91/02/05  17:07:16  mrt  * 	Changed to new Mach copyright  * 	[91/01/31  16:19:35  mrt]  *   * Revision 2.4  91/01/08  15:09:17  rpd  * 	Changed db_stop_at_pc's arguments.  * 	Print db_inst_count, db_load_count, db_store_count.  * 	[90/11/27            rpd]  *   * Revision 2.3  90/10/25  14:44:11  rwd  * 	From rpd.  * 	[90/10/19  17:03:17  rwd]  *   * 	Generalized the watchpoint support.  * 	[90/10/16            rwd]  * 	Added watchpoint support.  * 	[90/10/16            rpd]  *   * Revision 2.2  90/08/27  21:52:52  dbg  * 	Assign to db_dot before calling the print function.  * 	[90/08/20            af]  * 	Reduce lint.  * 	[90/08/07            dbg]  * 	Created.  * 	[90/07/25            dbg]  *   */
end_comment

begin_comment
comment|/*  * 	Author: David B. Golub, Carnegie Mellon University  *	Date:	7/90  */
end_comment

begin_comment
comment|/*  * Trap entry point to kernel debugger.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|<ddb/db_command.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_break.h>
end_include

begin_function_decl
specifier|extern
name|void
name|db_restart_at_pc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean_t
name|db_stop_at_pc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|db_inst_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|db_load_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|db_store_count
decl_stmt|;
end_decl_stmt

begin_macro
name|db_trap
argument_list|(
argument|type
argument_list|,
argument|code
argument_list|)
end_macro

begin_decl_stmt
name|int
name|type
decl_stmt|,
name|code
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|boolean_t
name|bkpt
decl_stmt|;
name|boolean_t
name|watchpt
decl_stmt|;
name|bkpt
operator|=
name|IS_BREAKPOINT_TRAP
argument_list|(
name|type
argument_list|,
name|code
argument_list|)
expr_stmt|;
name|watchpt
operator|=
name|IS_WATCHPOINT_TRAP
argument_list|(
name|type
argument_list|,
name|code
argument_list|)
expr_stmt|;
if|if
condition|(
name|db_stop_at_pc
argument_list|(
operator|&
name|bkpt
argument_list|)
condition|)
block|{
if|if
condition|(
name|db_inst_count
condition|)
block|{
name|db_printf
argument_list|(
literal|"After %d instructions (%d loads, %d stores),\n"
argument_list|,
name|db_inst_count
argument_list|,
name|db_load_count
argument_list|,
name|db_store_count
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|bkpt
condition|)
name|db_printf
argument_list|(
literal|"Breakpoint at\t"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|watchpt
condition|)
name|db_printf
argument_list|(
literal|"Watchpoint at\t"
argument_list|)
expr_stmt|;
else|else
name|db_printf
argument_list|(
literal|"Stopped at\t"
argument_list|)
expr_stmt|;
name|db_dot
operator|=
name|PC_REGS
argument_list|(
name|DDB_REGS
argument_list|)
expr_stmt|;
name|db_print_loc_and_inst
argument_list|(
name|db_dot
argument_list|)
expr_stmt|;
name|db_command_loop
argument_list|()
expr_stmt|;
block|}
name|db_restart_at_pc
argument_list|(
name|watchpt
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

