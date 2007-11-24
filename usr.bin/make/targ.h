begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|targ_h_6ded1830
end_ifndef

begin_define
define|#
directive|define
name|targ_h_6ded1830
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/*  * The TARG_ constants are used when calling the Targ_FindNode and  * Targ_FindList functions in targ.c. They simply tell the functions what to  * do if the desired node(s) is (are) not found. If the TARG_CREATE constant  * is given, a new, empty node will be created for the target, placed in the  * table of all targets and its address returned. If TARG_NOCREATE is given,  * a NULL pointer will be returned.  */
end_comment

begin_define
define|#
directive|define
name|TARG_CREATE
value|0x01
end_define

begin_comment
comment|/* create node if not found */
end_comment

begin_define
define|#
directive|define
name|TARG_NOCREATE
value|0x00
end_define

begin_comment
comment|/* don't create it */
end_comment

begin_struct_decl
struct_decl|struct
name|GNode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|Lst
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|Targ_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|GNode
modifier|*
name|Targ_NewGN
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|GNode
modifier|*
name|Targ_FindNode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_FindList
parameter_list|(
name|struct
name|Lst
modifier|*
parameter_list|,
name|struct
name|Lst
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Targ_Ignore
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Targ_Silent
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Targ_Precious
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_SetMain
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Targ_PrintCmd
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Targ_FmtTime
parameter_list|(
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_PrintType
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_PrintGraph
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* targ_h_6ded1830 */
end_comment

end_unit

