begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mappings.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * Mappings definitions.  *  * The mappings module is the interface between the object code and  * source file representations of the program.  *  * This module is strongly tied to the object module, and needs the  * most of the data defined in "object.h".  */
end_comment

begin_function_decl
name|ADDRESS
name|objaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get the object address corresponding to a line */
end_comment

begin_function_decl
name|char
modifier|*
name|srcfilename
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get the nearest source file<= a given address */
end_comment

begin_function_decl
name|LINENO
name|srcline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get the nearest source line<= a given address */
end_comment

begin_function_decl
name|LINENO
name|linelookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* look for a line number with exactly given address */
end_comment

begin_function_decl
name|int
name|newfunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* record the appearance of a new function */
end_comment

begin_function_decl
name|SYM
modifier|*
name|whatblock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find the function associated with an address */
end_comment

begin_function_decl
name|int
name|clrfunctab
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* re-initialize function table */
end_comment

end_unit

