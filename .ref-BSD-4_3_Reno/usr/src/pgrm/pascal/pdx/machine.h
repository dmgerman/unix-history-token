begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)machine.h	5.3 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * Definitions for the machine module.  *  * This module has the low level machine interface.  This consists  * mostly of dealing with machine instructions and also setting  * and unsetting breakpoints.  */
end_comment

begin_decl_stmt
name|ADDRESS
name|pc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current program counter */
end_comment

begin_decl_stmt
name|LINENO
name|curline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number associated with pc */
end_comment

begin_decl_stmt
name|SYM
modifier|*
name|curfunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to active function symbol */
end_comment

begin_function_decl
name|int
name|setbp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set a breakpoint */
end_comment

begin_function_decl
name|int
name|unsetbp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* unset a breakpoint */
end_comment

begin_function_decl
name|BOOLEAN
name|isbperr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if a breakpoint has occurred */
end_comment

begin_function_decl
name|int
name|printerror
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print out an execution error message */
end_comment

begin_function_decl
name|ADDRESS
name|nextaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address of next line to be executed */
end_comment

begin_function_decl
name|BOOLEAN
name|isendofproc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if address is at end of procedure */
end_comment

begin_decl_stmt
name|int
name|printinst
argument_list|()
decl_stmt|,
name|printninst
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print the instruction at a given address */
end_comment

begin_decl_stmt
name|int
name|printdata
argument_list|()
decl_stmt|,
name|printndata
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print the contents of a given data address */
end_comment

end_unit

