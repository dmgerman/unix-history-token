begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)machine.h	8.1 (Berkeley) 6/6/93  */
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

