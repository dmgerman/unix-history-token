begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)process.h	5.2 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * Definitions for process module.  *  * This module contains the routines to manage the execution and  * tracing of the debuggee process.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|process
name|PROCESS
typedef|;
end_typedef

begin_decl_stmt
name|PROCESS
modifier|*
name|process
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|initstart
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initial process start up */
end_comment

begin_function_decl
name|int
name|run
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* start program running */
end_comment

begin_function_decl
name|int
name|arginit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize program arguments */
end_comment

begin_function_decl
name|int
name|setargs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* special argument handling */
end_comment

begin_function_decl
name|int
name|newarg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add a new argument to list for program */
end_comment

begin_function_decl
name|int
name|inarg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set standard input for program */
end_comment

begin_function_decl
name|int
name|outarg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set standard output for program */
end_comment

begin_function_decl
name|int
name|cont
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* continue execution where last left off */
end_comment

begin_function_decl
name|int
name|step
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* single step */
end_comment

begin_function_decl
name|int
name|stepc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* single step command */
end_comment

begin_function_decl
name|int
name|stepto
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* execute up to a given address */
end_comment

begin_function_decl
name|int
name|next
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* single step, skip over calls */
end_comment

begin_function_decl
name|int
name|endprogram
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* note the termination of the program */
end_comment

begin_function_decl
name|int
name|printstatus
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print current error */
end_comment

begin_function_decl
name|int
name|printwhere
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print current source line and file */
end_comment

begin_function_decl
name|BOOLEAN
name|isfinished
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* TRUE if process has terminated */
end_comment

begin_decl_stmt
name|int
name|iread
argument_list|()
decl_stmt|,
name|dread
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read from the process' address space */
end_comment

begin_decl_stmt
name|int
name|iwrite
argument_list|()
decl_stmt|,
name|dwrite
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* write to the process' address space */
end_comment

end_unit

