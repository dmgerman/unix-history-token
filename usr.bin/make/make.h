begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)make.h	8.3 (Berkeley) 6/13/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|make_h_a91074b9
end_ifndef

begin_define
define|#
directive|define
name|make_h_a91074b9
end_define

begin_comment
comment|/**  * make.h  *	The global definitions for make  */
end_comment

begin_include
include|#
directive|include
file|"util.h"
end_include

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

begin_struct_decl
struct_decl|struct
name|Buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Warning flags  */
end_comment

begin_enum
enum|enum
block|{
name|WARN_DIRSYNTAX
init|=
literal|0x0001
block|,
comment|/* syntax errors in directives */
block|}
enum|;
end_enum

begin_function_decl
name|int
name|Make_TimeStamp
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Make_OODate
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Make_HandleUse
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Make_Update
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Make_DoAllVar
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Make_Run
parameter_list|(
name|struct
name|Lst
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Main_ParseArgLine
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Main_ParseWarn
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
name|Main_AddSourceMakefile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* make_h_a91074b9 */
end_comment

end_unit

