begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"_libdwarf.h"
end_include

begin_expr_stmt
name|ELFTC_VCSID
argument_list|(
literal|"$Id: dwarf_seterror.c 2075 2011-10-27 03:47:28Z jkoshy $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|_SET_FIELD
parameter_list|(
name|R
parameter_list|,
name|F
parameter_list|,
name|V
parameter_list|)
define|\
value|do {							\ 		(R) = (F);					\ 		(F) = (V);					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SET_FIELD
parameter_list|(
name|D
parameter_list|,
name|R
parameter_list|,
name|F
parameter_list|)
define|\
value|do {							\ 		if (D)						\ 			_SET_FIELD(R, (D)->dbg_##F, F);		\ 		else						\ 			_SET_FIELD(R, _libdwarf.F, F);		\ 	} while (0)
end_define

begin_function
name|Dwarf_Handler
name|dwarf_seterrhand
parameter_list|(
name|Dwarf_Debug
name|dbg
parameter_list|,
name|Dwarf_Handler
name|errhand
parameter_list|)
block|{
name|Dwarf_Handler
name|oldhandler
decl_stmt|;
name|SET_FIELD
argument_list|(
name|dbg
argument_list|,
name|oldhandler
argument_list|,
name|errhand
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldhandler
operator|)
return|;
block|}
end_function

begin_function
name|Dwarf_Ptr
name|dwarf_seterrarg
parameter_list|(
name|Dwarf_Debug
name|dbg
parameter_list|,
name|Dwarf_Ptr
name|errarg
parameter_list|)
block|{
name|Dwarf_Ptr
name|oldarg
decl_stmt|;
name|SET_FIELD
argument_list|(
name|dbg
argument_list|,
name|oldarg
argument_list|,
name|errarg
argument_list|)
expr_stmt|;
return|return
operator|(
name|oldarg
operator|)
return|;
block|}
end_function

end_unit

