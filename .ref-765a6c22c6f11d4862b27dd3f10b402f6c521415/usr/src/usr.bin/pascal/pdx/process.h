begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_comment
comment|/* static char sccsid[] = "@(#)process.h 1.5 %G%"; */
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

begin_expr_stmt
name|initstart
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* initial process start up */
end_comment

begin_expr_stmt
name|run
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* start program running */
end_comment

begin_expr_stmt
name|arginit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* initialize program arguments */
end_comment

begin_expr_stmt
name|setargs
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* special argument handling */
end_comment

begin_expr_stmt
name|newarg
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* add a new argument to list for program */
end_comment

begin_expr_stmt
name|inarg
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set standard input for program */
end_comment

begin_expr_stmt
name|outarg
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set standard output for program */
end_comment

begin_expr_stmt
name|cont
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* continue execution where last left off */
end_comment

begin_expr_stmt
name|step
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* single step */
end_comment

begin_expr_stmt
name|stepc
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* single step command */
end_comment

begin_expr_stmt
name|stepto
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* execute up to a given address */
end_comment

begin_expr_stmt
name|next
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* single step, skip over calls */
end_comment

begin_expr_stmt
name|endprogram
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* note the termination of the program */
end_comment

begin_expr_stmt
name|printstatus
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* print current error */
end_comment

begin_expr_stmt
name|printwhere
argument_list|()
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|iread
argument_list|()
operator|,
name|dread
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* read from the process' address space */
end_comment

begin_expr_stmt
name|iwrite
argument_list|()
operator|,
name|dwrite
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* write to the process' address space */
end_comment

end_unit

