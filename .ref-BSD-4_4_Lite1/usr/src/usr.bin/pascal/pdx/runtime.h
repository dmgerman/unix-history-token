begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)runtime.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * Definitions for the runtime environment.  *  * In general, runtime organization is language, machine, and  * even compiler dependent.  */
end_comment

begin_function_decl
name|BOOLEAN
name|isactive
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tell if a symbol is currently active */
end_comment

begin_function_decl
name|ADDRESS
name|entry_addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* entry address of current proc/func */
end_comment

begin_function_decl
name|ADDRESS
name|entry_point
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* point where environment is setup */
end_comment

begin_function_decl
name|ADDRESS
name|return_addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return address of current proc/func */
end_comment

begin_function_decl
name|ADDRESS
name|caller_addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* entry of caller of current proc/func */
end_comment

begin_function_decl
name|int
name|where
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print out currently active procedures */
end_comment

begin_function_decl
name|int
name|dump
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* dump the world */
end_comment

begin_function_decl
name|int
name|callproc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* call a procedure */
end_comment

begin_function_decl
name|int
name|procreturn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return from a "call"-ed procedure */
end_comment

begin_function_decl
name|ADDRESS
name|address
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address of a variable */
end_comment

begin_function_decl
name|ADDRESS
name|firstline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address of first line in a procedure */
end_comment

begin_function_decl
name|int
name|findbeginning
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find address of beginning of a procedure */
end_comment

begin_function_decl
name|int
name|runtofirst
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* step to first line in current procedure */
end_comment

begin_function_decl
name|ADDRESS
name|lastaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address of last line in program */
end_comment

begin_function_decl
name|ADDRESS
name|fparamaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* entry address of a function parameter */
end_comment

end_unit

