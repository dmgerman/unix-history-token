begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)process.h	8.1 (Berkeley) 6/6/93  */
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

