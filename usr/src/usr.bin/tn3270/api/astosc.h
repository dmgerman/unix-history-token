begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)astosc.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * This defines the structure used to translate:  *  *	ascii name ==> (scancode, shiftstate)  *  * (Actually, map3270 does "ascii name ==> index", and  * termin does "index ==> (scancode, shiftstate)".  Both  * mappings use this structure.)  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_ASTOSC
end_define

begin_struct
struct|struct
name|astosc
block|{
name|unsigned
name|char
name|scancode
decl_stmt|,
comment|/* Scan code for this function */
name|shiftstate
decl_stmt|;
comment|/* Shift state for this function */
name|enum
name|ctlrfcn
name|function
decl_stmt|;
comment|/* Internal function identifier */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of this function */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ascii_to_index
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Function to feed InitControl() */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|astosc
name|astosc
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

end_unit

